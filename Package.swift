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
            url: "https://api.github.com/repos/last-lock/link-mobile-sdk-prod/releases/assets/427241204.zip",
            checksum: "b844e34e186b37a7ff37dce108bb64f6a6d651a03d1379af5d9a79d280af693e"
        ),
        .binaryTarget(
            name: "bridge",
            url: "https://api.github.com/repos/last-lock/link-mobile-sdk-prod/releases/assets/427241203.zip",
            checksum: "1dc2d25622a6f7fb83113d9304bb0567d0de552546c11375ee318e03056cf6c5"
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
