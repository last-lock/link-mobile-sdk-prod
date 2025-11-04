//
//  ContentView.swift
//  LinkMobile-iOS-Example
//
//  Created by Nihir Singh on 10/27/25.
//

import SwiftUI
import CoreData
import LinkMobile

struct DeviceTile: View {
    var device: BluetoothDevice
    let onTap: () -> Void

    var body: some View {
        HStack {
            Text("DeviceId: \(device.deviceId)")
                .font(.headline)

            Spacer()

            Text("Tap to unlock")
                .font(.footnote)
        }
        .padding()
        .background(Color(.systemGray6))
        .cornerRadius(10)
        .padding()
        .onTapGesture { self.onTap() }
    }
}

struct ContentView: View {
    @StateObject var applicationController: ApplicationController = ApplicationController()

    var body: some View {
        NavigationView {
            VStack {
                Text("Link Mobile Integration")
                    .font(.title)
                    .padding()

                ForEach (applicationController.allDevices, id: \.deviceId) { device in
                    DeviceTile(device: device, onTap: { applicationController.performBLEUnlock(device: device) })
                }

                Spacer()

                Button(action: {
                    applicationController.createBLECredential()
                }, label: {
                    Text("Create PKOC credential")
                        .bold()
                })
                .foregroundStyle(.white)
                .padding()
                .background(Color(.systemBlue))
                .cornerRadius(10)

                Spacer()
                    .frame(height: 30)

                Text("Discovered Devices Count: \(applicationController.allDevices.count)")
            }
        }
    }
}
