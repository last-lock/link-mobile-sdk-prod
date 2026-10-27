//
//  ApplicationController.swift
//  LinkMobile-iOS-Example
//
//  Created by Nihir Singh on 10/27/25.

import CoreBluetooth
import Foundation
import LinkMobile

private struct IssueTokenUnlockPassRequest: Encodable {
    let credentialPublicKey: String
    let duration: Int

    enum CodingKeys: String, CodingKey {
        case credentialPublicKey = "credential_public_key"
        case duration
    }
}

private struct IssueTokenUnlockPassResponse: Decodable {
    let accessDocument: String
    let readerGroups: [ReaderGroup]

    enum CodingKeys: String, CodingKey {
        case accessDocument = "access_document"
        case readerGroups = "reader_groups"
    }

    struct ReaderGroup: Decodable {
        let readerGroupID: String
        let issuerCAPublicKey: String
        let issuerCACertificateDER: String

        enum CodingKeys: String, CodingKey {
            case readerGroupID = "reader_group_id"
            case issuerCAPublicKey = "issuer_ca_public_key"
            case issuerCACertificateDER = "issuer_ca_certificate_der"
        }
    }
}

private struct UnlockSampleError: LocalizedError {
    let message: String
    var errorDescription: String? { message }
}

/// Persists the namespace used to look up the SDK-managed temporary credential.
private enum TemporaryUnlockCredentialStore {
    private static let namespaceKey =
        "com.lastlock.linkmobile.example.temporary-unlock.namespace"
    private static let hasPassKey =
        "com.lastlock.linkmobile.example.temporary-unlock.has-pass"

    static func namespace() -> String {
        if let namespace = UserDefaults.standard.string(forKey: namespaceKey) {
            return namespace
        }

        let namespace = UUID().uuidString.lowercased()
        UserDefaults.standard.set(namespace, forKey: namespaceKey)
        return namespace
    }

    static var hasStoredPass: Bool {
        UserDefaults.standard.bool(forKey: hasPassKey)
    }

    static func markPassStored() {
        UserDefaults.standard.set(true, forKey: hasPassKey)
    }

    static func remove() {
        UserDefaults.standard.removeObject(forKey: namespaceKey)
        UserDefaults.standard.removeObject(forKey: hasPassKey)
    }
}

/// Controller for the entire app. Responsible for starting BLE Proxy
/// as well as implementing the various BlueLink delegates exposed by LinkMobile

class ApplicationController: BlueLinkEventListener, CredentialExchangeDelegate, ObservableObject {
    var bridge: Bridge
    var blueLink: BlueLink
    var credLinkManager: CredLinkManager

    // Configs
    let serverAddress: String = "external-plane.lastlock.com"
    // Set the below value to the host running token_unlock_server.py
    // A physical phone must use the host's LAN address, not localhost.
    let businessServerUrl = "http://<local_server_domain>:3006"
    let serviceUUID: CBUUID = CBUUID(string: "FC5A")

    @Published var allDevices: [BluetoothDevice] = []
    @Published private(set) var isBusy = false
    @Published private(set) var isIssuingPass = false
    @Published private(set) var temporaryCredentialReady =
        TemporaryUnlockCredentialStore.hasStoredPass
    @Published private(set) var unlockingDeviceID: String?
    @Published private(set) var status: String?

    @Published var isBleConnected: CBManagerState? {
        didSet {
            if isBleConnected == .poweredOn {
                print("starting scanning for devices")
                self.bridge.start()
            } else {
                self.bridge.getBlueLink().stopBLEScan()
            }
        }
    }

    // overriding and invoking super.init() to allow BlueLinkEventListener to get setup
    override init() {
        print(
            "Initializing ApplicationController and starting BLE Proxy with serverAdd: \(serverAddress) and UUID: \(serviceUUID.uuidString)"
        )
        self.bridge = Bridge(
            serverAddress: self.serverAddress,
            uuid: serviceUUID.uuidString
        )
        self.blueLink = bridge.getBlueLink()
        self.credLinkManager = bridge.getCredLink()
        super.init()

        // Registering ApplicationController to receive BlueLinkEventListener events
        self.blueLink.addListener(listener: self, prependListener: false)
        self.credLinkManager.credentialExchangeDelegate = self
    }

    override func onBLEStateChanged(newState: Bool) {
        print("BLE state changed to \(newState)")
        DispatchQueue.main.async {
            self.isBleConnected = newState ? .poweredOn : .poweredOff
        }
    }

    override func onDeviceDiscovered(
        device: BluetoothDevice,
        advertisementData: BluetoothAdvertisement,
        rssi: Int32,
        signalStrength: SignalStrength?,
        connectionStatus: BlueLinkDeviceConnectionStatus
    ) {
        DispatchQueue.main.async {
            print("Discovered device: \(device.deviceId)")
            if self.allDevices.contains(where: {
                $0.deviceId == device.deviceId
            }) {
                // Device already tracked in allDevices
                return
            } else {
                // Fresh Device discovered, tracking in allDevices
                self.allDevices.append(device)
            }
        }
    }

    /// Performs an unlock using a persisted temporary credential and pass.
    @MainActor
    func performTemporaryCredentialUnlock(device: BluetoothDevice) async {
        guard !isBusy else { return }
        guard TemporaryUnlockCredentialStore.hasStoredPass else {
            temporaryCredentialReady = false
            status = "Issue a 7 day unlock pass before unlocking."
            return
        }

        let deviceID = String(describing: device.deviceId)
        isBusy = true
        unlockingDeviceID = deviceID
        status = "Unlocking \(deviceID)…"

        do {
            try await credLinkManager.performCredLinkOperation(
                peripheral: device,
                operation: CredLinkOperationTokenUnlock(
                    namespace: TemporaryUnlockCredentialStore.namespace()
                )
            )
            print("Temporary unlock queued for \(device.deviceId)")
        } catch {
            guard unlockingDeviceID == deviceID else { return }
            unlockingDeviceID = nil
            isBusy = false
            status = "\(deviceID): \(error.localizedDescription)"
            print(
                "Temporary unlock failed with error: \(error.localizedDescription)"
            )
        }
    }

    func credExchangeCallback(
        for peripheral: BluetoothDevice,
        operationResult result: CredentialExchangeResult
    ) {
        let deviceID = String(describing: peripheral.deviceId)
        DispatchQueue.main.async {
            guard self.unlockingDeviceID == deviceID else { return }
            self.unlockingDeviceID = nil
            self.isBusy = false
            self.status = "\(deviceID): \(result)"
        }
    }

    /// Creates or retrieves a persisted temporary credential and stores its seven-day pass.
    @MainActor
    func createTemporaryUnlockCredential() async {
        guard !isBusy else { return }

        isBusy = true
        isIssuingPass = true
        status = "Issuing a 7 day unlock pass…"
        defer {
            isIssuingPass = false
            isBusy = false
        }

        let namespace = TemporaryUnlockCredentialStore.namespace()
        print("Creating and registering temporary Aliro BLE credential")

        do {
            // The SDK persists the private key under this namespace. Only the
            // matching public key is sent to the integrating server.
            let publicKey = try await credLinkManager
                .temporaryPassPublicCredential(namespace: namespace)
            let unlockPass = try await issueTemporaryUnlockPass(for: publicKey)

            guard try await credLinkManager.storeTemporaryPassAccessDocument(
                namespace: namespace,
                tokenUnlockPass: unlockPass
            ) else {
                throw UnlockSampleError(
                    message: "Error storing the temporary unlock pass"
                )
            }

            TemporaryUnlockCredentialStore.markPassStored()
            temporaryCredentialReady = true
            status = "Unlock pass is ready for seven days."
            print(
                "Successfully issued temporary unlock pass; tap a discovered lock to unlock"
            )
        } catch {
            status = "Unable to issue unlock pass: \(error.localizedDescription)"
            print(
                "Error creating temporary unlock pass: \(error.localizedDescription)"
            )
        }
    }

    /// Issues a seven-day pass for a persisted temporary credential public key.
    private func issueTemporaryUnlockPass(
        for publicKey: Data
    ) async throws -> TokenUnlockPass {
        try await issueUnlockPass(
            for: publicKey,
            duration: 7 * 24 * 60 * 60
        )
    }

    /// Requests a pass from the example backend and converts its response for CredLink.
    private func issueUnlockPass(
        for publicKey: Data,
        duration: Int
    ) async throws -> TokenUnlockPass {
        let baseURL =
            businessServerUrl.hasSuffix("/")
            ? String(businessServerUrl.dropLast())
            : businessServerUrl
        guard let url = URL(string: "\(baseURL)/v1/issue-unlock-pass")
        else {
            throw UnlockSampleError(
                message:
                    "Set businessServerUrl to the token-unlock sample backend URL"
            )
        }

        let requestBody = IssueTokenUnlockPassRequest(
            credentialPublicKey: publicKey.base64EncodedString(),
            duration: duration
        )
        var request = URLRequest(url: url)
        request.httpMethod = "POST"
        request.setValue("application/json", forHTTPHeaderField: "Content-Type")
        request.httpBody = try JSONEncoder().encode(requestBody)

        let (data, response) = try await URLSession.shared.data(for: request)
        guard let httpResponse = response as? HTTPURLResponse else {
            throw UnlockSampleError(
                message: "Example server returned an invalid response"
            )
        }
        guard (200...299).contains(httpResponse.statusCode) else {
            let message =
                String(data: data, encoding: .utf8) ?? "No response body"
            throw UnlockSampleError(
                message:
                    "Token-unlock pass request failed (HTTP \(httpResponse.statusCode)): \(message)"
            )
        }

        // Parse the response object and fetch the readerGroupId and issuerCA values
        // and create a TokenUnlockPass object
        let responseBody = try JSONDecoder().decode(
            IssueTokenUnlockPassResponse.self,
            from: data
        )
        guard
            let accessDocument = Data(
                base64Encoded: responseBody.accessDocument
            )
        else {
            throw UnlockSampleError(
                message:
                    "The token-unlock backend returned an invalid access document"
            )
        }

        // For every received reader group received, create the ReaderGroupTrust object
        let readerGroups = try responseBody.readerGroups.map { group in
            guard
                let readerGroupID = Data(base64Encoded: group.readerGroupID),
                let issuerCAPublicKey = Data(
                    base64Encoded: group.issuerCAPublicKey
                ),
                let issuerCACertificateDER = Data(
                    base64Encoded: group.issuerCACertificateDER
                )
            else {
                throw UnlockSampleError(
                    message: "Invalid reader trust material received"
                )
            }
            return ReaderGroupTrust(
                readerGroupIdentifier: readerGroupID.toKotlinByteArray(),
                issuerCAPublicKey: issuerCAPublicKey.toKotlinByteArray(),
                issuerCACertificateDer:
                    issuerCACertificateDER.toKotlinByteArray()
            )
        }

        // Token Unlock Pass object
        return TokenUnlockPass(
            accessDocument: accessDocument.toKotlinByteArray(),
            readerGroups: readerGroups
        )
    }

    /// Deletes the persisted temporary credential and its access document.
    func removeTemporaryUnlockCredential() async {
        let namespace = TemporaryUnlockCredentialStore.namespace()

        do {
            guard try await credLinkManager.deleteTemporaryUnlockPass(
                namespace: namespace
            ) else {
                throw UnlockSampleError(
                    message: "Error removing the temporary unlock pass"
                )
            }
            TemporaryUnlockCredentialStore.remove()
            print("Removed temporary unlock credential")
        } catch {
            print(
                "Error removing temporary unlock pass: \(error.localizedDescription)"
            )
        }
    }

    /// Calls the example server's health check endpoint
    func serverHealthCheck() async {
        let baseURL =
            businessServerUrl.hasSuffix("/")
            ? String(businessServerUrl.dropLast())
            : businessServerUrl

        guard let url = URL(string: "\(baseURL)/healthz") else {
            print("HealthCheck URL invalid")
            return
        }

        var request = URLRequest(url: url)
        request.httpMethod = "GET"
        do {
            let (data, response) = try await URLSession.shared.data(
                for: request
            )
        } catch {
            print("Error checking server health: \(error.localizedDescription)")
            return
        }
    }

}
