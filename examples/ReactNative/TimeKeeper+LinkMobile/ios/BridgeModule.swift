import Foundation
import LinkMobile
import React

@objc(BridgeModule)
class BridgeModule: RCTEventEmitter {
    private var seamlessBridge: Bridge?
    private var blueLinkListener: BlueLinkListenerBridge?

    override static func requiresMainQueueSetup() -> Bool {
        return true
    }

    override func supportedEvents() -> [String]! {
        // List of all possible event names that JS can listen to
        return [
            "onDeviceDiscovered",
            "onDeviceConnected",
            "onDeviceDisconnected",
            "onBLEStateChanged",
        ]
    }

    @objc
    func initialize(
        _ serverAddress: String,
        uuid: String,
        resolver: @escaping RCTPromiseResolveBlock,
        rejecter: @escaping RCTPromiseRejectBlock
    ) {
        DispatchQueue.main.async {
            self.seamlessBridge = Bridge(serverAddress: serverAddress, uuid: uuid)
            self.seamlessBridge?.setLogsEnabled(isEnabled: true)
            guard let blueLink = self.seamlessBridge?.getBlueLink() else {
                rejecter("ERROR", "Failed to get BlueLink from Bridge", nil)
                return
            }

            // Attach listener bridge
            self.blueLinkListener = BlueLinkListenerBridge(eventEmitter: self)
            blueLink.addListener(listener: self.blueLinkListener!, prependListener: false)

            resolver("Bridge initialized and listener attached")
        }
    }

    @objc
    func start(
        _ uuid: String,
        resolver: @escaping RCTPromiseResolveBlock,
        rejecter: @escaping RCTPromiseRejectBlock
    ) {
        guard let seamlessBridge = self.seamlessBridge else {
            rejecter("ERROR", "Bridge not initialized. Call initialize first.", nil)
            return
        }

        DispatchQueue.global(qos: .userInitiated).async {
            seamlessBridge.start(UUID: uuid)
            DispatchQueue.main.async {
                resolver("Bridge started with UUID: \(uuid)")
            }
        }
    }

    // Required to avoid warnings
    override func startObserving() {}
    override func stopObserving() {}
}

class BlueLinkListenerBridge: BlueLinkEventListener {
    weak var eventEmitter: RCTEventEmitter?

    init(eventEmitter: RCTEventEmitter) {
        self.eventEmitter = eventEmitter
        super.init()
    }

    override func onBLEStateChanged(newState: Bool) {
        eventEmitter?.sendEvent(
            withName: "onBLEStateChanged",
            body: [
                "state": newState
            ])
    }

    override func onDeviceDiscovered(
        device: BluetoothDevice,
        advertisementData: BluetoothAdvertisement,
        rssi: Int32,
        signalStrength: SignalStrength?,
        connectionStatus: BlueLinkDeviceConnectionStatus
    ) {
        print("[BlueLinkListenerBridge] onDeviceDiscovered called")

        // Send simple serializable info to JS
        eventEmitter?.sendEvent(
            withName: "onDeviceDiscovered",
            body: [
                "name": device.name ?? "Unknown",
                "identifier": device.deviceId,
                "rssi": rssi,
                "connectionStatus": connectionStatus.name,
                "signalStrength": signalStrength?.description ?? "unknown",
            ])
    }

    override func onDeviceConnected(device: BluetoothDevice) {
        eventEmitter?.sendEvent(
            withName: "onDeviceConnected",
            body: [
                "name": device.name ?? "Unknown",
                "identifier": device.deviceId,
            ])
    }

    override func onDeviceDisconnected(device: BluetoothDevice, reason _: KotlinInt?) {
        eventEmitter?.sendEvent(
            withName: "onDeviceDisconnected",
            body: [
                "name": device.name ?? "Unknown",
                "identifier": device.deviceId,
            ])
    }
}
