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
            url: "https://api.github.com/repos/last-lock/link-mobile-sdk-prod/releases/assets/341021115.zip",
            checksum: "aaa9a2dad0ec9b5c1031819b9006ff82a70d7114d5d9128496179d24067be626"
        ),
        .binaryTarget(
            name: "bridge",
            url: "https://api.github.com/repos/last-lock/link-mobile-sdk-prod/releases/assets/341021113.zip",
            checksum: "f098051e0984abec83e75921d37663011df7ea9995e906c12fa8a82f5058f070"
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
