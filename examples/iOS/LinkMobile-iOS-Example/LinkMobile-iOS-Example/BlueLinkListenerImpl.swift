//
//  BlueLinkListenerImpl.swift
//  LinkMobile-iOS-Example
//
//  Created by Nihir Singh on 10/27/25.
//
//import LinkMobile
//
//class BlueLinkListenerImpl: BlueLinkEventListener {
//    private weak var applicationController: ApplicationController?
//
//    init(applicationController: ApplicationController) {
//        self.applicationController = applicationController
//        super.init()
//    }
//
//    // delegate invoked on BLE state change
//    override func onBLEStateChanged(newState: Bool) {
//        print("BlueLinkListenerImpl: BLE enabled: \(newState)")
//        DispatchQueue.main.async {
//            self.applicationController?.isBleConnected = newState ? .poweredOn : .poweredOff
//        }
//    }
//}
