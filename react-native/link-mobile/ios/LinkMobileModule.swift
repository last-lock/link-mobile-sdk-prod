import Foundation
import LinkMobile
import React

@objc(LinkMobileController)
class LinkMobileController: NSObject {
    @objc var onDeviceDiscovered: ((NSDictionary) -> Void)?
    @objc var onDeviceConnected: ((NSDictionary) -> Void)?
    @objc var onDeviceDisconnected: ((NSDictionary) -> Void)?
    @objc var onBLEStateChanged: ((NSDictionary) -> Void)?
    @objc var onCredentialExchangeResult: ((NSDictionary) -> Void)?
    @objc var onDFUStateChanged: ((NSDictionary) -> Void)?
    @objc var onHeartbeat: ((NSDictionary) -> Void)?
    @objc var onProxyStreamStateChanged: ((NSDictionary) -> Void)?

    private var serverAddress: String?
    private var serviceUUID: String?
    private var linkBridge: Bridge?
    private var events: LinkMobileEventBridge?
    private var rescanning = false
    private var streamWatch: Task<Void, Never>?
    private var dfuReadyDevices = Set<String>()

    @objc(initialize:resolve:reject:)
    func initialize(
        _ serverAddress: String,
        resolve: @escaping RCTPromiseResolveBlock,
        reject _: @escaping RCTPromiseRejectBlock
    ) {
        self.serverAddress = serverAddress
        resolve("Bridge ready for \(serverAddress)")
    }

    @objc(start:resolve:reject:)
    func start(
        _ uuid: String,
        resolve: @escaping RCTPromiseResolveBlock,
        reject: @escaping RCTPromiseRejectBlock
    ) {
        guard let serverAddress else {
            reject("ERROR", "Bridge not initialized. Call initialize first.", nil)
            return
        }

        DispatchQueue.main.async {
            self.serviceUUID = uuid
            if self.linkBridge == nil {
                let bridge = Bridge(serverAddress: serverAddress, uuid: uuid)
                bridge.setLogsEnabled(isEnabled: true)
                let events = LinkMobileEventBridge(controller: self)
                self.events = events
                self.linkBridge = bridge
                bridge.getBlueLink().addListener(listener: events, prependListener: false)
                bridge.getCredLink().credentialExchangeDelegate = events
                bridge.observeDFUState { [weak self] state in
                    self?.emitDFUState(state)
                }
                self.watchProxyStream()
                self.rescan()
                resolve("Bridge started with UUID: \(uuid)")
                return
            }
            Task {
                await self.linkBridge?.restart(serverAddress: serverAddress, uuid: uuid)
                resolve("Bridge restarted for \(serverAddress) UUID: \(uuid)")
            }
        }
    }

    func heartbeatTimestamp(_ data: KotlinByteArray) -> Int64? {
        linkBridge?.getBlueLink().heartbeatParser.parseHeartbeat(data: data)?.lastOobServerTimestamp?.int64Value
    }

    private func watchProxyStream() {
        streamWatch?.cancel()
        streamWatch = Task { [weak self] in
            var last: String?
            while !Task.isCancelled {
                let alive: Bool
                if let proxy = self?.linkBridge?.getBLEProxy() {
                    alive = (try? await proxy.isStreamAlive())?.boolValue ?? false
                } else {
                    alive = false
                }
                let state = alive ? "connected" : "disconnected"
                if state != last {
                    last = state
                    let payload = ["state": state] as NSDictionary
                    await MainActor.run {
                        self?.onProxyStreamStateChanged?(payload)
                    }
                }
                try? await Task.sleep(nanoseconds: 3_000_000_000)
            }
        }
    }

    func rescan() {
        guard !rescanning, let serviceUUID, let linkBridge else { return }
        rescanning = true
        linkBridge.getBlueLink().stopBLEScan()
        linkBridge.start(UUID: serviceUUID)
        rescanning = false
    }

    @objc(identify:resolve:reject:)
    func identify(
        _ identifier: String,
        resolve: @escaping RCTPromiseResolveBlock,
        reject: @escaping RCTPromiseRejectBlock
    ) {
        runProxy(identifier, reject: reject) { bridge, device in
            let payload = OobPayloads.identify(deviceId: UInt32(device.deviceId))
            let queued = try await bridge.getBLEProxy().identifyDevice(deviceId: device.deviceId, payload: payload)
            if queued != true {
                throw LinkMobileError("Device \(identifier) is not tracked by the proxy.")
            }
            resolve(true)
        }
    }

    @objc(setLockEngagedState:engaged:resolve:reject:)
    func setLockEngagedState(
        _ identifier: String,
        engaged: Bool,
        resolve: @escaping RCTPromiseResolveBlock,
        reject: @escaping RCTPromiseRejectBlock
    ) {
        runProxy(identifier, reject: reject) { bridge, device in
            let payload = OobPayloads.lockEngaged(deviceId: UInt32(device.deviceId), engaged: engaged)
            let queued = try await bridge.getBLEProxy().setLockEngagedState(
                deviceId: UInt32(device.deviceId),
                payload: payload
            )
            if queued != true {
                throw LinkMobileError("Device \(identifier) is not tracked by the proxy.")
            }
            resolve(true)
        }
    }

    @objc(sendOutOfBandPayload:payloadBase64:resolve:reject:)
    func sendOutOfBandPayload(
        _ identifier: String,
        payloadBase64: String,
        resolve: @escaping RCTPromiseResolveBlock,
        reject: @escaping RCTPromiseRejectBlock
    ) {
        guard let payload = Data(base64Encoded: payloadBase64) else {
            reject("ERROR", "Out-of-band payload is not valid base64.", nil)
            return
        }
        guard let bridge = linkBridge else {
            reject("ERROR", "Bridge not started. Call start first.", nil)
            return
        }
        guard let device = events?.device(identifier: identifier) else {
            reject("ERROR", "Device \(identifier) has not been discovered.", nil)
            return
        }
        bridge.getBLEProxy().sendOOBToDevice(
            deviceId: UInt32(device.deviceId),
            payload: kotlinBytes(payload)
        )
        resolve("Out-of-band payload queued for \(identifier)")
    }

    @objc(checkForDFU:resolve:reject:)
    func checkForDFU(
        _ identifier: String,
        resolve: @escaping RCTPromiseResolveBlock,
        reject: @escaping RCTPromiseRejectBlock
    ) {
        guard let bridge = linkBridge else {
            reject("ERROR", "Bridge not started. Call start first.", nil)
            return
        }
        guard let device = events?.device(identifier: identifier) else {
            reject("ERROR", "Device \(identifier) has not been discovered.", nil)
            return
        }
        Task {
            do {
                let result = try await bridge.getDFUService().checkForDFU(device: device, timeoutMs: 15000)
                if result is CheckDFUResult.Timeout {
                    resolve([
                        "status": "timeout",
                        "firmwareVersion": "",
                        "availableVersion": "",
                    ])
                    return
                }
                guard let state = bridge.getDFUService().uiState.value_ as? DFUUiState else {
                    reject("ERROR", "DFU state was unavailable.", nil)
                    return
                }
                let current = (result as? CheckDFUResult.Success)?.firmwareVersion
                resolve([
                    "status": state.dfuAvailable ? "update_available" : "up_to_date",
                    "firmwareVersion": firmwareText(current),
                    "availableVersion": state.dfuImage?.dfuVersion ?? "",
                ])
            } catch {
                reject("ERROR", error.localizedDescription, error)
            }
        }
    }

    @objc(startDFU:resolve:reject:)
    func startDFU(
        _ identifier: String,
        resolve: @escaping RCTPromiseResolveBlock,
        reject: @escaping RCTPromiseRejectBlock
    ) {
        guard let bridge = linkBridge else {
            reject("ERROR", "Bridge not started. Call start first.", nil)
            return
        }
        guard let device = events?.device(identifier: identifier) else {
            reject("ERROR", "Device \(identifier) has not been discovered.", nil)
            return
        }
        guard dfuReadyDevices.contains(identifier) else {
            reject("ERROR", "Check for a firmware update before starting DFU.", nil)
            return
        }
        waitForMode(
            bridge: bridge,
            device: device,
            identifier: identifier,
            dfuRequired: true,
            success: "DFU started for \(identifier)",
            resolve: resolve,
            reject: reject
        )
    }

    @objc(waitForDeviceMode:dfuRequired:resolve:reject:)
    func waitForDeviceMode(
        _ identifier: String,
        dfuRequired: Bool,
        resolve: @escaping RCTPromiseResolveBlock,
        reject: @escaping RCTPromiseRejectBlock
    ) {
        guard let bridge = linkBridge else {
            reject("ERROR", "Bridge not started. Call start first.", nil)
            return
        }
        guard let device = events?.device(identifier: identifier) else {
            reject("ERROR", "Device \(identifier) has not been discovered.", nil)
            return
        }
        let mode = dfuRequired ? "DFU" : "install"
        waitForMode(
            bridge: bridge,
            device: device,
            identifier: identifier,
            dfuRequired: dfuRequired,
            success: "Device \(identifier) entered \(mode) mode.",
            resolve: resolve,
            reject: reject
        )
    }

    @objc(exitDFUInstallMode:resolve:reject:)
    func exitDFUInstallMode(
        _ identifier: String,
        resolve: @escaping RCTPromiseResolveBlock,
        reject: @escaping RCTPromiseRejectBlock
    ) {
        guard let bridge = linkBridge else {
            reject("ERROR", "Bridge not started. Call start first.", nil)
            return
        }
        guard let device = events?.device(identifier: identifier) else {
            reject("ERROR", "Device \(identifier) has not been discovered.", nil)
            return
        }
        let deviceId = UInt32(device.deviceId)
        let payload = OobPayloads.installReboot(deviceId: deviceId)
        Task {
            do {
                let sent = try await bridge.getDFUService().exitInstallMode(device: device, exitOOB: payload).boolValue
                if !sent {
                    reject("ERROR", "Failed to send the DFU reboot.", nil)
                    return
                }
                let result = try await bridge.getBLEProxy().waitForInstallModeExit(deviceId: deviceId, timeoutMs: 20000)
                if result is InstallOOBResult.Timeout {
                    reject("ERROR", "Timed out waiting for the lock to leave DFU.", nil)
                    return
                }
                resolve("Device \(identifier) left install mode.")
            } catch {
                reject("ERROR", error.localizedDescription, error)
            }
        }
    }

    @objc(fetchTokenUnlockPublicKey:resolve:reject:)
    func fetchTokenUnlockPublicKey(
        _ namespace: String,
        resolve: @escaping RCTPromiseResolveBlock,
        reject: @escaping RCTPromiseRejectBlock
    ) {
        guard let bridge = linkBridge else {
            reject("ERROR", "Bridge not started. Call start first.", nil)
            return
        }
        if namespace.isEmpty {
            reject("ERROR", "Token unlock namespace is required.", nil)
            return
        }
        Task {
            do {
                let publicKey = try await bridge.getCredLink().fetchPublicCredential(namespace: namespace, force: false).toData()
                if publicKey.isEmpty {
                    reject("ERROR", "Token unlock public key is empty.", nil)
                    return
                }
                resolve(publicKey.base64EncodedString())
            } catch {
                reject("ERROR", error.localizedDescription, error)
            }
        }
    }

    @objc(storeTokenUnlockPass:accessDocumentBase64:readerGroupIdBase64:issuerCaPublicKeyBase64:issuerCaCertificateBase64:resolve:reject:)
    func storeTokenUnlockPass(
        _ namespace: String,
        accessDocumentBase64: String,
        readerGroupIdBase64: String,
        issuerCaPublicKeyBase64: String,
        issuerCaCertificateBase64: String,
        resolve: @escaping RCTPromiseResolveBlock,
        reject: @escaping RCTPromiseRejectBlock
    ) {
        guard let bridge = linkBridge else {
            reject("ERROR", "Bridge not started. Call start first.", nil)
            return
        }
        guard let accessDocument = Data(base64Encoded: accessDocumentBase64),
              let readerGroupId = Data(base64Encoded: readerGroupIdBase64),
              let issuerCaPublicKey = Data(base64Encoded: issuerCaPublicKeyBase64),
              let certificate = Data(base64Encoded: issuerCaCertificateBase64) else {
            reject("ERROR", "Token unlock material is not valid base64.", nil)
            return
        }
        let pass = TokenUnlockPass(
            accessDocument: kotlinBytes(accessDocument),
            readerGroups: [
                ReaderGroupTrust(
                    readerGroupIdentifier: kotlinBytes(readerGroupId),
                    issuerCAPublicKey: kotlinBytes(issuerCaPublicKey),
                    issuerCACertificateDer: kotlinBytes(certificate)
                ),
            ]
        )
        Task {
            do {
                let stored = try await bridge.getCredLink().storeTokenUnlockPass(namespace: namespace, tokenUnlockPass: pass).boolValue
                if !stored {
                    reject("ERROR", "Unable to store the token unlock pass.", nil)
                    return
                }
                resolve(true)
            } catch {
                reject("ERROR", error.localizedDescription, error)
            }
        }
    }

    @objc(tokenUnlock:tokenNamespace:resolve:reject:)
    func tokenUnlock(
        _ identifier: String,
        tokenNamespace: String,
        resolve: @escaping RCTPromiseResolveBlock,
        reject: @escaping RCTPromiseRejectBlock
    ) {
        guard let bridge = linkBridge else {
            reject("ERROR", "Bridge not started. Call start first.", nil)
            return
        }
        guard let device = events?.device(identifier: identifier) else {
            reject("ERROR", "Device \(identifier) has not been discovered.", nil)
            return
        }
        if tokenNamespace.isEmpty {
            reject("ERROR", "Token unlock namespace is required.", nil)
            return
        }
        Task {
            do {
                try await bridge.getCredLink().performCredLinkOperation(
                    peripheral: device,
                    operation: CredLinkOperationTokenUnlock(namespace: tokenNamespace)
                )
                resolve("Token unlock started for \(identifier)")
            } catch {
                reject("ERROR", error.localizedDescription, error)
            }
        }
    }

    private func waitForMode(
        bridge: Bridge,
        device: BluetoothDevice,
        identifier: String,
        dfuRequired: Bool,
        success: String,
        resolve: @escaping RCTPromiseResolveBlock,
        reject: @escaping RCTPromiseRejectBlock
    ) {
        let deviceId = UInt32(device.deviceId)
        Task {
            do {
                let result = try await bridge.getBLEProxy().deliverInstallOOBAndWaitForMode(
                    deviceId: deviceId,
                    dfuRequired: dfuRequired,
                    timeoutMs: 20000
                )
                if result is InstallOOBResult.Timeout {
                    let mode = dfuRequired ? "DFU" : "install"
                    reject("ERROR", "Timed out waiting for the lock to enter \(mode) mode.", nil)
                    return
                }
                resolve(success)
            } catch {
                reject("ERROR", error.localizedDescription, error)
            }
        }
    }

    @objc(cancelDFU:reject:)
    func cancelDFU(
        _ resolve: @escaping RCTPromiseResolveBlock,
        reject: @escaping RCTPromiseRejectBlock
    ) {
        guard let bridge = linkBridge else {
            reject("ERROR", "Bridge not started. Call start first.", nil)
            return
        }
        bridge.getDFUService().cancelDFU()
        resolve("DFU cancelled")
    }

    private func runProxy(
        _ identifier: String,
        reject: @escaping RCTPromiseRejectBlock,
        body: @escaping (Bridge, BluetoothDevice) async throws -> Void
    ) {
        guard let bridge = linkBridge else {
            reject("ERROR", "Bridge not started. Call start first.", nil)
            return
        }
        guard let device = events?.device(identifier: identifier) else {
            reject("ERROR", "Device \(identifier) has not been discovered.", nil)
            return
        }
        Task {
            do {
                try await body(bridge, device)
            } catch {
                reject("ERROR", error.localizedDescription, error)
            }
        }
    }

    private func emitDFUState(_ state: DFUUiState) {
        if state.dfuAvailable, let image = state.dfuImage {
            dfuReadyDevices.insert(String(image.deviceId))
        }
        let payload: [String: Any] = [
            "flowState": state.flowState.name,
            "installProgress": NSNumber(value: state.installProgress),
            "postInstallProgress": NSNumber(value: state.postInstallProgress),
            "dfuAvailable": NSNumber(value: state.dfuAvailable),
            "dfuImageLoading": NSNumber(value: state.dfuImageLoading),
            "availableVersion": state.dfuImage?.dfuVersion ?? "",
        ]
        let send = { [weak self] in
            self?.onDFUStateChanged?(payload as NSDictionary)
            return ()
        }
        if Thread.isMainThread {
            send()
        } else {
            DispatchQueue.main.async(execute: send)
        }
    }

}

class LinkMobileEventBridge: BlueLinkEventListener, CredentialExchangeDelegate {
    weak var controller: LinkMobileController?
    private let devicesLock = NSLock()
    private var devices: [String: BluetoothDevice] = [:]
    private var oobTimestamps: [String: Double] = [:]

    init(controller: LinkMobileController) {
        self.controller = controller
        super.init()
    }

    func device(identifier: String) -> BluetoothDevice? {
        devicesLock.lock()
        defer { devicesLock.unlock() }
        return devices[identifier]
    }

    private func remember(_ device: BluetoothDevice) {
        let identifier = String(device.deviceId)
        devicesLock.lock()
        devices[identifier] = device
        devicesLock.unlock()
    }

    override func onBLEStateChanged(newState: Bool) {
        emit(controller?.onBLEStateChanged, ["state": newState])
        if newState {
            controller?.rescan()
        }
    }

    override func onDeviceDiscovered(
        device: BluetoothDevice,
        advertisementData: BluetoothAdvertisement,
        rssi: Int32,
        signalStrength: SignalStrength,
        connectionStatus: BlueLinkDeviceConnectionStatus
    ) {
        remember(device)
        let identifier = String(device.deviceId)
        NSLog("LinkMobile discovered %@ rssi=%d", identifier, rssi)
        devicesLock.lock()
        let oobTimestamp = oobTimestamps[identifier] ?? 0
        devicesLock.unlock()
        emit(controller?.onDeviceDiscovered, [
            "name": device.name,
            "identifier": identifier,
            "rssi": NSNumber(value: rssi),
            "connectionStatus": connectionStatus.name,
            "signalStrength": signalStrength.name,
            "installMode": advertisementData.isInInstallMode(),
            "dfuMode": advertisementData.isInDFU(),
            "hibernate": advertisementData.isHibernating(),
            "serviceMode": advertisementData.isInServiceMode(),
            "lowBattery": advertisementData.hasLowBatteryStatus(),
            "criticalBattery": advertisementData.hasCriticalBattery(),
            "cooldown": advertisementData.isInCooldown(),
            "emergency": advertisementData.isInEmergencyState(),
            "busy": advertisementData.isBusy(),
            "timeSyncRequest": advertisementData.hasTimeSyncRequest(),
            "overridingMode": advertisementData.overridingMode().name,
            "deviceStateCounter": Int("\(advertisementData.deviceStateCounter)") ?? 0,
            "serverStateCounter": Int("\(advertisementData.serverStateCounter)") ?? 0,
            "oobTimestamp": NSNumber(value: oobTimestamp),
        ])
    }

    override func onHeartbeat(device: BluetoothDevice, heartbeatData: KotlinByteArray) {
        guard let timestamp = controller?.heartbeatTimestamp(heartbeatData) else {
            return
        }
        let identifier = String(device.deviceId)
        devicesLock.lock()
        oobTimestamps[identifier] = Double(timestamp)
        devicesLock.unlock()
        emit(controller?.onHeartbeat, [
            "identifier": identifier,
            "oobTimestamp": NSNumber(value: timestamp),
        ])
    }

    override func onDeviceConnected(device: BluetoothDevice) {
        remember(device)
        emit(controller?.onDeviceConnected, [
            "name": device.name,
            "identifier": String(device.deviceId),
        ])
    }

    override func onDeviceDisconnected(device: BluetoothDevice, reason _: KotlinInt?) {
        emit(controller?.onDeviceDisconnected, [
            "name": device.name,
            "identifier": String(device.deviceId),
        ])
    }

    func credExchangeCallback(for peripheral: BluetoothDevice, operationResult result: CredentialExchangeResult) {
        emit(controller?.onCredentialExchangeResult, [
            "name": peripheral.name,
            "identifier": String(peripheral.deviceId),
            "result": resultName(result),
            "message": result.description,
        ])
    }

    private func resultName(_ result: CredentialExchangeResult) -> String {
        switch result {
        case .ACCESS_GRANTED: return "ACCESS_GRANTED"
        case .ACCESS_DENIED: return "ACCESS_DENIED"
        case .CRYPTOGRAPHIC_ERROR: return "CRYPTOGRAPHIC_ERROR"
        case .DEVICE_DISCONNECTED_DURING_OPERATION: return "DEVICE_DISCONNECTED_DURING_OPERATION"
        case .CREDENTIAL_EXCHANGE_BUSY: return "CREDENTIAL_EXCHANGE_BUSY"
        case .OUT_OF_SCHEDULE: return "OUT_OF_SCHEDULE"
        case .CREDENTIAL_NOT_FOUND: return "CREDENTIAL_NOT_FOUND"
        case .TIMEOUT: return "TIMEOUT"
        case .OTHER: return "OTHER"
        @unknown default: return "OTHER"
        }
    }

    private func emit(_ handler: ((NSDictionary) -> Void)?, _ body: [String: Any]) {
        let payload = body.mapValues { value -> Any in
            switch value {
            case let text as String:
                return text
            case let number as NSNumber:
                return number
            case let integer as Int:
                return NSNumber(value: integer)
            case let integer as Int32:
                return NSNumber(value: integer)
            case let flag as Bool:
                return NSNumber(value: flag)
            default:
                return String(describing: value)
            }
        } as NSDictionary
        let send = {
            handler?(payload)
            return ()
        }
        if Thread.isMainThread {
            send()
        } else {
            DispatchQueue.main.async(execute: send)
        }
    }
}

private struct LinkMobileError: LocalizedError {
    let message: String
    init(_ message: String) { self.message = message }
    var errorDescription: String? { message }
}

private func firmwareText(_ version: DeviceFirmwareVersion?) -> String {
    guard let version else { return "" }
    return "\(version.major).\(version.minor).\(version.revision)-\(version.build)"
}

private func kotlinBytes(_ data: Data) -> KotlinByteArray {
    let bytes = KotlinByteArray(size: Int32(data.count))
    for (index, byte) in data.enumerated() {
        bytes.set(index: Int32(index), value: Int8(bitPattern: byte))
    }
    return bytes
}

private enum OobPayloads {
    static func identify(deviceId: UInt32) -> KotlinByteArray {
        kotlinBytes(wrapper(operation(deviceId: deviceId, fieldNumber: 9, value: 1)))
    }

    static func lockEngaged(deviceId: UInt32, engaged: Bool) -> KotlinByteArray {
        kotlinBytes(wrapper(operation(deviceId: deviceId, fieldNumber: 11, value: engaged ? 1 : 2)))
    }

    static func installReboot(deviceId: UInt32) -> KotlinByteArray {
        var installMode = Data()
        writeKey(&installMode, fieldNumber: 2, wireType: 0)
        writeVarint(&installMode, 1)
        var operation = Data()
        writeKey(&operation, fieldNumber: 1, wireType: 0)
        writeVarint(&operation, UInt64(deviceId))
        writeBytesField(&operation, fieldNumber: 7, bytes: installMode)
        return kotlinBytes(wrapper(operation))
    }

    private static func operation(deviceId: UInt32, fieldNumber: Int, value: Int) -> Data {
        var data = Data()
        writeKey(&data, fieldNumber: 1, wireType: 0)
        writeVarint(&data, UInt64(deviceId))
        writeKey(&data, fieldNumber: fieldNumber, wireType: 0)
        writeVarint(&data, UInt64(value))
        return data
    }

    private static func wrapper(_ operation: Data) -> Data {
        var data = Data()
        writeBytesField(&data, fieldNumber: 1, bytes: operation)
        writeBytesField(&data, fieldNumber: 2, bytes: Data(repeating: 0xFF, count: 64))
        writeKey(&data, fieldNumber: 3, wireType: 0)
        writeVarint(&data, 1)
        return data
    }

    private static func writeBytesField(_ data: inout Data, fieldNumber: Int, bytes: Data) {
        writeKey(&data, fieldNumber: fieldNumber, wireType: 2)
        writeVarint(&data, UInt64(bytes.count))
        data.append(bytes)
    }

    private static func writeKey(_ data: inout Data, fieldNumber: Int, wireType: Int) {
        writeVarint(&data, UInt64((fieldNumber << 3) | wireType))
    }

    private static func writeVarint(_ data: inout Data, _ value: UInt64) {
        var remaining = value
        while remaining & ~0x7F != 0 {
            data.append(UInt8((remaining & 0x7F) | 0x80))
            remaining >>= 7
        }
        data.append(UInt8(remaining))
    }
}
