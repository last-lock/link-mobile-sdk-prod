// swift-tools-version: 5.9
import PackageDescription

let package = Package(
    name: "LinkMobileiOS",
    platforms: [
        .iOS(.v16)
    ],
    products: [
        .library(
            name: "LinkMobile",
            targets: ["LinkMobile", "LinkMobileTypes", "bridge"]
        ),
        .library(
            name: "LinkMobileTypes",
            targets: ["LinkMobileTypes"]
        )
    ],
    dependencies: [
        .package(url: "https://github.com/grpc/grpc-swift.git", from: "1.24.2"),
        .package(url: "https://github.com/apple/swift-protobuf", from: "1.28.2"),
        .package(url: "https://github.com/apple/swift-nio.git", from: "2.60.0"),
        .package(url: "https://github.com/apple/swift-nio-http2.git", from: "1.27.0"),
        .package(url: "https://github.com/apple/swift-atomics.git", from: "1.0.0")
    ],
    targets: [
        .binaryTarget(
            name: "LinkMobile",
            url: "https://api.github.com/repos/last-lock/link-mobile-sdk-prod/releases/assets/505711200.zip",
            checksum: "ac99bdee0bfa8f6ba2af773436c59d14cdfac08347b54b52d91adfa56702f1b5"
        ),
        .binaryTarget(
            name: "bridge",
            url: "https://api.github.com/repos/last-lock/link-mobile-sdk-prod/releases/assets/505711199.zip",
            checksum: "6b61c9f6ca674b922894df7f22348a072f908af057be829040ca4d40daa83781"
        ),
        .target(
            name: "LinkMobileTypes",
            dependencies: [
                .product(name: "GRPC", package: "grpc-swift"),
                .product(name: "SwiftProtobuf", package: "swift-protobuf"),
                .product(name: "NIO", package: "swift-nio"),
                .product(name: "NIOCore", package: "swift-nio"),
                .product(name: "NIOConcurrencyHelpers", package: "swift-nio"),
                .product(name: "NIOHTTP2", package: "swift-nio-http2"),
                .product(name: "Atomics", package: "swift-atomics")
            ],
            path: "Sources/LinkMobileTypes"
        )
    ]
)
