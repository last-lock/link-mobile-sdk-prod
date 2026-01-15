// swift-tools-version:6.0

import PackageDescription

let package = Package(
    name: "LinkMobile",
    platforms: [
        .iOS(.v13) // Or whatever your use
    ],
    products: [ // Example Product. Define your own
        .library(
            name: "LinkMobile",
            targets: ["iOSBridgeWrapper"]
        ),
    ],
    dependencies: [
        // Match versions you already use in the mono-repo
        .package(url: "https://github.com/grpc/grpc-swift.git", from: "1.24.2"),
        .package(url: "https://github.com/apple/swift-protobuf.git", from: "1.28.2"),
        .package(url: "https://github.com/NordicSemiconductor/IOS-nRF-Connect-Device-Manager.git", from: "1.9.2"),
        .package(url: "https://github.com/weichsel/ZIPFoundation.git", from: "0.9.19"),
        .package(url: "https://github.com/last-lock/TrueTime.git", from: "7.0.0")
    ],
    targets: [
        .binaryTarget(
            name: "LinkMobile",
            url: "https://api.github.com/repos/last-lock/link-mobile-sdk-prod/releases/assets/341010239.zip",
            checksum: "77323e1b6f6f0b53e2ab0e0a15c4fa7af1d1837d52f6c05a59c7a11bd984b809"
        ),
        .binaryTarget(
            name: "bridge",
            url: "https://api.github.com/repos/last-lock/link-mobile-sdk-prod/releases/assets/341010238.zip",
            checksum: "0ee2e97ad18ad9dd933b4cbb0686c2b272004281afb8845c475e6655e690800d"
        ),
        .target(
            name: "iOSBridgeWrapper",
            dependencies: [
                "LinkMobile",
                "bridge",
                .product(name: "GRPC", package: "grpc-swift"),
                .product(name: "SwiftProtobuf", package: "swift-protobuf"),
                .product(name: "iOSMcuManagerLibrary", package: "IOS-nRF-Connect-Device-Manager"),
                .product(name: "ZIPFoundation", package: "ZIPFoundation"),
                .product(name: "TrueTime", package: "TrueTime")
            ],
            path: "Sources/iOSBridgeWrapper"
        )
    ]
)
