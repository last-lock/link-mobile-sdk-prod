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
            url: "https://api.github.com/repos/last-lock/link-mobile-sdk-prod/releases/assets/366266187.zip",
            checksum: "aa6708cf51e93ef9dfa74d982f7be7fd7f8f2e55f21920df393055151a90d922"
        ),
        .binaryTarget(
            name: "bridge",
            url: "https://api.github.com/repos/last-lock/link-mobile-sdk-prod/releases/assets/366266188.zip",
            checksum: "cd8954f1babc11112dfbaf0e9653579e58b08f4dfee60055f549564ff0376257"
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
