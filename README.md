# Link Mobile SDK v1.7.1
The Link Mobile SDK provides a bridge between Last Lock's hardware ecosystem and mobile applications wanting to communicate. It enables integrators to quickly integrate BLE device discovery, perform connections and trigger actions with the lock without explicitly implementing a bluetooth controller. The SDK also establishes a background proxy connection allowing the Last Lock hardware to communicate securely with the cloud.

By integrating this SDK, developers can:
- Seamlessly discover and establish connectivity with Last Lock devices over BLE.
- Perform secure credential exchange with supported locks.
- Focus on application logic instead of protocol and connectivity details.

For more detailed documentation and public API, visit: 
- iOS: https://developer.lastlock.com/docs/api/link-mobile-sdk-iOS
- android: https://developer.lastlock.com/docs/api/link-mobile-sdk-android

## Prerequisites
- Read Access to the Link Mobile SDK private Github repository
- Personal Access Token (PAT) with `repo` and `read:packages` permissions
- Xcode 15+, Swift 5.9+, iOS 16.0+

### Note: For React Native projects, use versions 1.7.2 of the Android and iOS Link Mobile SDK dependencies. That specific release has dependencies compatible with Expo and React Native.

## Setup Instructions iOS
### Private Github Access
The SDK lives inside a private Github repository. Fetch a PAT created from an account that has permissions to access the private repo and include it in the .netrc file stored in the home location:
```shell
// ~/.netrc
// for accessing private repository
machine github.com
    login user_name
    password access_token

// for downloading assets
machine api.github.com
    login user_name
    password access_token

```
If this is the first time setting up .netrc, run `chmod 600 ~/.netrc`. This allows Keychain credential helper to utilize the PAT and authenticate HTTP downloads when needed.

### Import SDK
#### Option A - Add via Xcode (GUI)
For setting up the SDK natively in an Xcode project or workspace:
- Navigate to File -> Add Package Dependencies
- In the Search box enter the SDK's repository url, https://github.com/last-lock/link-mobile-sdk.....
- Enter the next major version or exact version of the SDK to download
- After Xcode completes downloading the SDK, select the `iOSBridge` Package Product to add to the app's target
- Select Add Package
- The Link Mobile iOS SDK should be downloading and getting set up for the workspace under Package Dependencies. When the installation is complete, ensure that the SDK version matches the desired version
- You have successfully imported the SDK to your project via Xcode!

#### Option B - Add via Xcodegen
If the project is configured via [Xcodegen](https://github.com/yonaskolb/XcodeGen):
- In the project.yml configuration file, add LinkMobile SDK as a package to the project
- Make sure to include the url as well as the next major version or exact version
- Add Link Mobile SDK as a dependency to the target that requires the SDK. This would require specifying the package and the product (details showed below)
- Save the project.yml config file and setup the project with this update
- Link Mobile package should be resolved and installing into the workspace
- Make sure to verify that the installed version of the SDK is the desired version
- You have successfully imported the SDK to your project via Xcodegen!
```shell
// project.yml
...
packages:
    LinkMobile:
        url: https://github.com/last-lock/link-mobile-sdk......
        exactVersion: VERSION

targets:
    IntegratorApp:
        .....
        dependencies:
          - package: LinkMobile
            product: iOSBridge
...
```

If everything gets resolved and setup correctly, LinkMobile iOS SDK can be imported via the following command:
```swift
// example showing how to start a ble proxy session
import LinkMobile

// ensure all required permissions and capabilities listed below are enabled
var seamlessBridge: Bridge = Bridge(serverAddress: "SERVER_ADDRESS")
seamlessBridge.start(UUID: "ABDC")
```

Note: In order to successfully connect to Link server and enable a communication medium, please provide Last Lock with the TeamID and the Bundle Identifier for the app:
- TeamID: this can be found at Apple Developer Portal -> Membership Details (ex: ABCDE12345)
- Bundle Identifier: found in Xcode project settings -> General Tab -> Bundle Identifier field
Only those apps whose bundle identifiers are white listed by Link will be allowed to connect to Link

### Permissions and Capabilities
- Privacy : Bluetooth Always Usage Description (NSBluetoothAlwaysUsageDescription): required to use the phone's bluetooth module
- UIBackgroundMode - bluetooth-central: for scanning, connecting, and communicating with devices in teh background

## Troubleshooting
- Run app on a real device
  - simulators cannot simulate BLE
- If package resolution fails:
 - check github tokens stored in ~/.netrc
 - clean and rebuild Xcode project
- If app keeps crashing on scanning for devices or if scanning for devices silently fails:
 - ensure the permissions listed in Permissions and Capabilities are added to the app's Info.plist
- Unable to connect to Link (connectivity errors):
 - ensure TeamID and Bundle Identifier for the app are provided to Last Lock
