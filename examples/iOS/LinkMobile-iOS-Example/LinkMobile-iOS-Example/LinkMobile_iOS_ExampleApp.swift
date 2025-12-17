//
//  LinkMobile_iOS_ExampleApp.swift
//  LinkMobile-iOS-Example
//
//  Created by Nihir Singh on 10/27/25.
//

import SwiftUI

@main
struct LinkMobile_iOS_ExampleApp: App {
    let persistenceController = PersistenceController.shared

    var body: some Scene {
        WindowGroup {
            ContentView()
                .environment(\.managedObjectContext, persistenceController.container.viewContext)
        }
    }
}
