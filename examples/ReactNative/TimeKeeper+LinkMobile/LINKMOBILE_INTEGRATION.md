# LinkMobile SDK Integration Guide

> **Important:**  
> Before integrating the LinkMobile SDK, ensure that you have **enrolled your app for attestation through Last Lock**. Attestation is required before devices can be discovered or connected through the SDK.

This document explains how the LinkMobile SDK was integrated into a React Native app using xcframeworks as an example.

## Overview

The LinkMobile SDK integration exposes device discovery and connection functionality through a React Native bridge. The implementation consists of several interconnected components that work together to provide seamless native-to-JavaScript communication.

**Key Components:**
- Native iOS Swift/Objective-C bridge module
- TypeScript interface layer
- React Native context providers
- Device discovery hooks
- UI integration components

## Architecture Overview

The integration follows a layered architecture:

```
┌─────────────────────────────────────┐
│           React Native UI           │
│        (index.tsx, components)      │
└─────────────────┬───────────────────┘
                  │
┌─────────────────▼───────────────────┐
│        Context Providers            │
│    (BridgeContext, ThemeContext)   │
└─────────────────┬───────────────────┘
                  │
┌─────────────────▼───────────────────┐
│      Custom Hooks Layer             │
│    (useDeviceDiscovery.ts)          │
└─────────────────┬───────────────────┘
                  │
┌─────────────────▼───────────────────┐
│     TypeScript Interface            │
│      (BridgeModule.ts)              │
└─────────────────┬───────────────────┘
                  │
┌─────────────────▼───────────────────┐
│    Native iOS Bridge Layer          │
│  (BridgeModule.swift, BridgeModule.m)│
└─────────────────┬───────────────────┘
                  │
┌─────────────────▼───────────────────┐
│        LinkMobile SDK               │
│        (xcframeworks)               │
└─────────────────────────────────────┘
```

## Pre-Integration Requirements

**1. App Enrollment:**  
Before writing any code, your app **must** be enrolled for attestation through Last Lock. Contact Last Lock and ensure enrollment is complete for your app's bundle ID.

**2. SDK Configuration:**  
When initializing the SDK, you **must use the proper server address and UUID**:
- Example server address: `api.test.example.com`
- Example UUID: `AAAA`

## Integration Components

### 1. Native iOS Bridge Layer

#### BridgeModule.swift
The Swift implementation provides the core functionality by wrapping the LinkMobile SDK:

```swift
import Foundation
import React
import LinkMobile

@objc(BridgeModule)
class BridgeModule: RCTEventEmitter {
    private var bridge: Bridge?
    
    @objc
    func initialize(_ serverAddress: String, uuid: String, resolver: @escaping RCTPromiseResolveBlock, rejecter: @escaping RCTPromiseRejectBlock) {
        // Initialize LinkMobile SDK with server address and UUID, then attach listeners
        bridge = Bridge(serverAddress: serverAddress, uuid: uuid)
        guard let blueLink = bridge?.getBlueLink() else {
            rejecter("ERROR", "Failed to get BlueLink from Bridge", nil)
            return
        }

        // Attach listener bridge so events stream to JS
        blueLink.addListener(listener: BlueLinkListenerBridge(eventEmitter: self), prependListener: false)
        resolver("Bridge initialized and listener attached")
    }
    
    @objc
    func start(_ uuid: String, resolver: @escaping RCTPromiseResolveBlock, rejecter: @escaping RCTPromiseRejectBlock) {
        // Start scanning with the provided UUID (events are emitted via the attached listener)
        guard let bridge = bridge else {
            rejecter("ERROR", "Bridge not initialized. Call initialize first.", nil)
            return
        }
        bridge.start(UUID: uuid)
        resolver("Bridge started successfully")
    }
}
```

**Supported native events:** `onDeviceDiscovered`, `onDeviceConnected`, `onDeviceDisconnected`, `onBLEStateChanged`

#### BridgeModule.m
The Objective-C bridge exposes the Swift module to React Native:

```objc
#import <React/RCTBridgeModule.h>
#import <React/RCTEventEmitter.h>

@interface RCT_EXTERN_MODULE(BridgeModule, RCTEventEmitter)

RCT_EXTERN_METHOD(initialize:(NSString *)serverAddress
                  uuid:(NSString *)uuid
                  resolver:(RCTPromiseResolveBlock)resolver
                  rejecter:(RCTPromiseRejectBlock)rejecter)

RCT_EXTERN_METHOD(start:(NSString *)uuid
                  resolver:(RCTPromiseResolveBlock)resolver
                  rejecter:(RCTPromiseRejectBlock)rejecter)

+ (BOOL)requiresMainQueueSetup
{
    return YES;
}

@end
```

### 2. TypeScript Interface Layer

#### BridgeModule.ts
```typescript
import { NativeModules } from 'react-native';

interface BridgeModuleInterface {
  initialize(serverAddress: string, uuid: string): Promise<string>;
  start(uuid: string): Promise<string>;
}

const { BridgeModule } = NativeModules;

if (!BridgeModule) {
  throw new Error(
    'BridgeModule native module is not available. Make sure you have run pod install and rebuilt the app.'
  );
}

export default BridgeModule as BridgeModuleInterface;
```

### 3. Context Provider Layer

#### BridgeContext.tsx
Manages global bridge state and provides it to components:

```typescript
import React, { createContext, useContext, useState, ReactNode } from 'react';

interface BridgeContextType {
  isInitialized: boolean;
  isScanning: boolean;
  setInitialized: (value: boolean) => void;
  setScanning: (value: boolean) => void;
}

const BridgeContext = createContext<BridgeContextType | undefined>(undefined);

export const BridgeProvider: React.FC<{ children: ReactNode }> = ({ children }) => {
  const [isInitialized, setIsInitialized] = useState(false);
  const [isScanning, setIsScanning] = useState(false);

  return (
    <BridgeContext.Provider value={{
      isInitialized,
      isScanning,
      setInitialized: setIsInitialized,
      setScanning: setIsScanning,
    }}>
      {children}
    </BridgeContext.Provider>
  );
};

export const useBridgeContext = () => {
  const context = useContext(BridgeContext);
  if (!context) {
    throw new Error('useBridgeContext must be used within BridgeProvider');
  }
  return context;
};
```

### 4. Custom Hooks Layer

#### useDeviceDiscovery.ts
Handles device discovery events and state management:

```typescript
import React from 'react';
import { NativeEventEmitter, NativeModules } from 'react-native';
import { Device } from './BridgeModule';

const { BridgeModule } = NativeModules;
const bridgeEmitter = new NativeEventEmitter(BridgeModule);

export function useDeviceDiscovery() {
  const [devices, setDevices] = React.useState<Device[]>([]);

  React.useEffect(() => {
    const discoveredListener = bridgeEmitter.addListener('onDeviceDiscovered', (event) => {
      setDevices((prev) => {
        const existingIndex = prev.findIndex((d) => d.identifier === event.identifier);
        if (existingIndex >= 0) {
          // Update existing device
          const updatedDevices = [...prev];
          updatedDevices[existingIndex] = event;
          return updatedDevices;
        } else {
          // Add new device
          return [...prev, event];
        }
      });
    });

    return () => {
      discoveredListener.remove();
    };
  }, []);

  return devices;
}
```

### 5. Application Integration

#### _layout.tsx
Initializes the bridge on app startup:

```typescript
import { BridgeProvider } from '@/context/BridgeContext';
import BridgeModule from '../modules/BridgeModule';

/**
 * NOTE:
 * It is important to use the correct values for serverAddress and UUID.
 * Example values for test environments:
 *   serverAddress: "api.test.example.com"
 *   uuid: "AAAA"
 */
const handleInitialize = async (setScanning: (value: boolean) => void) => {
  try {
    // Initialize with server address and UUID
    await BridgeModule.initialize("api.test.example.com", "AAAA");

    // Start scanning after initialization
    setTimeout(async () => {
      await BridgeModule.start("AAAA"); // 4-character UUID
      setScanning(true);
    }, 2000);
  } catch (error) {
    console.error('Bridge initialization failed:', error);
  }
};

export default function Layout() {
  return (
    <BridgeProvider>
      <RootContent />
    </BridgeProvider>
  );
}
```

#### index.tsx
Integrates device discovery into the main UI:

```typescript
import { DeviceDebugPanel } from '@/components/DeviceDebugPanel';
import { useDeviceDiscovery } from './useDeviceDiscovery';

export default function Index() {
  const devices = useDeviceDiscovery();
  
  return (
    <SafeAreaView>
      {/* Debug Panel for device discovery */}
      <DeviceDebugPanel />
      
      {/* Main app content */}
      {/* ... */}
    </SafeAreaView>
  );
}
```

## Android Integration

### 1. Add dependency
In `android/app/build.gradle`:
```gradle
dependencies {
  implementation "com.lastlock.prod:bridge-android:1.7.0"
}
```

### 1b. Add the GitHub Packages repository
In `android/build.gradle`, ensure the repository is added (and supply credentials via env or `gradle.properties`):
```gradle
allprojects {
  repositories {
    google()
    mavenCentral()
    maven { url 'https://www.jitpack.io' }
    maven {
      url "https://maven.pkg.github.com/last-lock/link-mobile-sdk-prod"
      credentials {
        username = System.getenv("GITHUB_ACTOR") ?: (findProperty("gpr.user") ?: "")
        password = System.getenv("GITHUB_TOKEN") ?: (findProperty("gpr.key") ?: "")
      }
    }
  }
}
```

Set credentials (one option):
```
export GITHUB_ACTOR=<your-gh-username>
export GITHUB_TOKEN=<a PAT with read:packages>
```
or in `android/gradle.properties`:
```
gpr.user=<your-gh-username>
gpr.key=<your-token>
```

### 1c. Compile SDK and AGP version
Update `android/build.gradle` to use:
```
compileSdkVersion = 36
classpath("com.android.tools.build:gradle:8.9.1")
```
This satisfies the `androidx.activity` / `androidx.core` requirements pulled in by the Android bridge.

### 1a. Android SDK location
Create/update `android/local.properties` so Gradle can find the SDK:
```
sdk.dir=/Users/<your-username>/Library/Android/sdk
```
Adjust the path if your SDK is elsewhere, or set `ANDROID_HOME` in your shell.

### 2. Add required permissions
In `android/app/src/main/AndroidManifest.xml` (add alongside existing permissions):
```xml
<uses-permission android:name="android.permission.BLUETOOTH"/>
<uses-permission android:name="android.permission.BLUETOOTH_ADMIN"/>
<uses-permission android:name="android.permission.BLUETOOTH_SCAN"/>
<uses-permission android:name="android.permission.BLUETOOTH_CONNECT"/>
<uses-permission android:name="android.permission.ACCESS_FINE_LOCATION"/>
<uses-permission android:name="android.permission.ACCESS_COARSE_LOCATION"/>
<uses-permission android:name="android.permission.ACCESS_BACKGROUND_LOCATION" android:maxSdkVersion="30"/>
<uses-permission android:name="android.permission.POST_NOTIFICATIONS"/>
<uses-permission android:name="android.permission.FOREGROUND_SERVICE"/>
```

### 3. Native module
Create `android/app/src/main/java/com/cody669/TimeKeeper/BridgeModule.kt`:
```kotlin
package com.cody669.TimeKeeper

import com.facebook.react.bridge.*
import com.lastlock.bridge.Bridge

class BridgeModule(ctx: ReactApplicationContext) : ReactContextBaseJavaModule(ctx) {
  override fun getName() = "BridgeModule"

  @ReactMethod
  fun initialize(serverAddress: String, uuid: String, promise: Promise) {
    try {
      Bridge.init(reactApplicationContext, serverAddress)
      Bridge.setLogsEnabled(true)
      promise.resolve("Bridge initialized")
    } catch (e: Exception) { promise.reject("INIT_ERROR", e) }
  }

  @ReactMethod
  fun start(uuid: String, promise: Promise) {
    try {
      Bridge.start(uuid)
      promise.resolve("Bridge started with UUID: $uuid")
    } catch (e: Exception) { promise.reject("START_ERROR", e) }
  }
}
```

Create `BridgePackage.kt`:
```kotlin
package com.cody669.TimeKeeper

import com.facebook.react.*
import com.facebook.react.bridge.ReactApplicationContext
import com.facebook.react.uimanager.ViewManager

class BridgePackage : ReactPackage {
  override fun createNativeModules(ctx: ReactApplicationContext) = listOf(BridgeModule(ctx))
  override fun createViewManagers(ctx: ReactApplicationContext): List<ViewManager<*, *>> = emptyList()
}
```

### 4. Register the package
In `MainApplication.kt`, add the package inside `getPackages()`:
```kotlin
val packages = PackageList(this).packages
packages.add(BridgePackage())
return packages
```

### 5. JS usage (same as iOS)
Call from JS with both params:
```ts
await BridgeModule.initialize("api.test.example.com", "AAAA");
await BridgeModule.start("AAAA");
```

### 6. Runtime permissions
Before calling `start`, request the BLE/location/notification permissions appropriate for the device SDK level (e.g., with `react-native-permissions`). Only start scanning after the user grants them.

## Key Integration Patterns

### 1. Event-Driven Architecture
The integration uses React Native's event emitter system to handle real-time device discovery:
- Native events are emitted from Swift/Objective-C
- JavaScript listeners update React state
- UI automatically re-renders with new device data
- Supported native events: `onDeviceDiscovered`, `onDeviceConnected`, `onDeviceDisconnected`, `onBLEStateChanged`

### 2. Promise-Based API
All native method calls return promises for proper error handling:
```typescript
try {
  // Use the correct server address and UUID here (see example above)
  await BridgeModule.initialize("api.test.example.com", "AAAA");
  await BridgeModule.start("AAAA");
} catch (error) {
  // Handle errors gracefully
}
```

### 3. Context-Based State Management
Global bridge state is managed through React Context:
- Prevents prop drilling
- Centralizes state management
- Provides consistent state across components

### 4. Custom Hooks for Logic Separation
Device discovery logic is encapsulated in custom hooks:
- Reusable across components
- Separates concerns from UI logic
- Easier to test and maintain

## xcframework Integration Notes

This implementation uses xcframeworks as an example rather than Swift Package Manager (SPM) for several reasons:

1. **Legacy Support**: xcframeworks provide better compatibility with older Xcode versions
2. **Distribution**: Easier to distribute pre-compiled frameworks
3. **Dependencies**: Avoids potential dependency conflicts with SPM
4. **Control**: More control over framework linking and embedding

### Adding xcframeworks to Xcode Project:
1. Drag the `.xcframework` file into Xcode
2. Add to "Frameworks, Libraries, and Embedded Content"
3. Update the bridging header to import the framework
4. Ensure proper code signing and deployment targets

## Setup Instructions

### 1. Install Dependencies
```bash
cd ios
npm install
pod install
cd ..
```

### 2. Build and Run
```bash
npx expo run:ios --device "example device name"
```

### 3. Verify Integration
- Check console logs for bridge initialization
- Verify device discovery events are received
- Test UI updates with discovered devices

## Troubleshooting

### Common Issues:
1. **Module not found**: Ensure `pod install` was run and app was rebuilt
2. **Linker errors**: Verify xcframework is properly embedded in Xcode project
3. **Event not received**: Check event listener setup and native event emission
4. **TypeScript errors**: Ensure proper type definitions in BridgeModule.ts

This integration provides a complete reference for integrating native iOS SDKs into React Native applications using xcframeworks and demonstrates best practices for maintaining clean, maintainable code architecture.

