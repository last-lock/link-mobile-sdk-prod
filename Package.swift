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
            url: "https://api.github.com/repos/last-lock/link-mobile-sdk-prod/releases/assets/346884047.zip",
            checksum: "db06924e6123cbbfbadb8d5eb0b4de1db05737d3fcffa83f6cd3f91800732a27"
        ),
        .binaryTarget(
            name: "bridge",
            url: "https://api.github.com/repos/last-lock/link-mobile-sdk-prod/releases/assets/346884048.zip",
            checksum: "329cdc7c2929f60531797f8f238ad619a8fb2324646a86b9306344528c759d37"
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
