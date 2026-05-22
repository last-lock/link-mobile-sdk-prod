//
//  ApplicationController.swift
//  LinkMobile-iOS-Example
//
//  Created by Nihir Singh on 10/27/25.

import LinkMobile
import CoreBluetooth

/// Controller for the entire app. Responsible for starting BLE Proxy
/// as well as implementing the various BlueLink delegates exposed by LinkMobile

class ApplicationController: BlueLinkEventListener, ObservableObject {
    var bridge: Bridge
    var blueLink: BlueLink
    var credLinkManager: CredLinkManager

    let userId: String = "test-user"        // userId required to categorize BLE credentials by user

    // Configs
    let serverAddress: String = "enter_server_url"
    let businessServerUrl: String = "enter_business_server_url"
    let serviceUUID: CBUUID = CBUUID(string: "BF01")

    @Published var allDevices: [BluetoothDevice] = []

    @Published var isBleConnected: CBManagerState? {
        didSet {
            if isBleConnected == .poweredOn {
                print("starting scanning for devices")
                self.bridge.start(UUID: serviceUUID.uuidString)
            } else {
                self.bridge.getBlueLink().stopBLEScan()
            }
        }
    }

    func performBLEUnlock(device: BluetoothDevice) {
        print("Performing BLE Unlock for \(device.deviceId)")
        self.credLinkManager.performCredLinkOperation(for: device)
    }

    // overriding and invoking super.init() to allow BlueLinkEventListener to get setup
    override init() {
        print("Initializing ApplicationController and starting BLE Proxy with serverAdd: \(serverAddress) and UUID: \(serviceUUID.uuidString)")
        self.bridge = Bridge(serverAddress: self.serverAddress, uuid: serviceUUID.uuidString)
        self.blueLink = bridge.getBlueLink()
        self.credLinkManager = bridge.getCredLink()
        super.init()

        self.credLinkManager.credentialExchangeDelegate = self
        // Registering ApplicationController to receive BlueLinkEventListener events
        self.blueLink.addListener(listener: self, prependListener: false)
    }

    override func onBLEStateChanged(newState: Bool) {
        print("BLE state changed to \(newState)")
        DispatchQueue.main.async {
            self.isBleConnected = newState ? .poweredOn : .poweredOff
        }
    }

    override func onDeviceDiscovered(device: BluetoothDevice, advertisementData: BluetoothAdvertisement, rssi: Int32, signalStrength: SignalStrength?, connectionStatus: BlueLinkDeviceConnectionStatus) {
        DispatchQueue.main.async {
            print("Discovered device: \(device.deviceId)")
            if self.allDevices.contains(where: { $0.deviceId == device.deviceId }) {
                // Device already tracked in allDevices
                return
            } else {
                // Fresh Device discovered, tracking in allDevices
                self.allDevices.append(device)
            }
        }
    }

    func createBLECredential() {
        print("Creating BLE Credential and adding to all discovered devices")
        credLinkManager.validatePhoneKeys(
            userId: self.userId,    // as dictated by the business server logic
            serverAddress: self.serverAddress,  // business server url
            completionHandler: { [weak self] result in
                guard let self = self else {
                    print("error setting up validate phone keys completion handler")
                    return
                }

                if case .failure = result {
                    print("error validating BLE credential keys")
                } else {
                    // BLE Credential successfully created or fetched from persistent storage
                    print("successfully validated BLE credential")
                    // will now  fetch the public key from the created BLE credential and enroll it to the device via Link
                    do {
                        let validationResult = try result.get()
                        switch validationResult {
                        case let .error(error):
                            print("error during validation of BLE Credential key: \(error.localizedDescription)")
                            return
                        case .publicKey(let publicKey):
                            let publicKeyHexString = publicKey.map { String(format: "%02x", $0) }.joined()
                            print("public key fetched, verifying existence / assigning it via Link, \(publicKeyHexString)")
                            self.enrollCredentialToAllDevice(bytes: publicKeyHexString)
                        }
                    } catch {
                        print("error getting result: \(error.localizedDescription)")
                        return
                    }
                }
            }
        )
    }

    /// Enrolls provided credential to all discovered devices
    func enrollCredentialToAllDevice(bytes: String) {
        self.allDevices.forEach { device in
            print("enrolling credential to device: \(device.deviceId)")
            let url = URL(string: "\(self.businessServerUrl)/add")!
            var request = URLRequest(url: url)
            request.httpMethod = "POST"
            request.setValue("application/json", forHTTPHeaderField: "Content-Type")

            // Request Body
            let body: [String: String] = [
                "device_id": String(device.deviceId),
                "pkoc": bytes
            ]
            request.httpBody =  try? JSONSerialization.data(withJSONObject: body)

            let task = URLSession.shared.dataTask(with: request) { data, response, error in
                if let error = error {
                    print("Error: \(error.localizedDescription)")
                    return
                }

                guard let httpResponse = response as? HTTPURLResponse,
                      (200...299).contains(httpResponse.statusCode) else {
                    print("Invalid response")
                    return
                }

                if let data = data {
                    let responseString = String(data: data, encoding: .utf8)
                    print("Response: \(responseString ?? "No readable data")")
                }
            }

            task.resume()
        }
    }
}

extension ApplicationController: CredentialExchangeDelegate {
    func credExchangeCallback(for peripheral: BluetoothDevice, operationResult result: LinkMobile.CredentialExchangeResult) {
        print("Credential Exchange callback received on \(peripheral.deviceId), result: \(result)")
    }
}
