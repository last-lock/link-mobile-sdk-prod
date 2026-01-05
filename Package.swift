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
            url: "https://api.github.com/repos/last-lock/link-mobile-sdk-prod/releases/assets/336676844.zip",
            checksum: "f5829cab245d578cc6fa91a840bc859237ff409faa7b79d1af7f7e4098b4067d"
        ),
        .binaryTarget(
            name: "bridge",
            url: "https://api.github.com/repos/last-lock/link-mobile-sdk-prod/releases/assets/336676843.zip",
            checksum: "22d6b2ecb78605ec3994bae24e1dbe92954c306e9793cc64ecb1a530ebae0012"
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
