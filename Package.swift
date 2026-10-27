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
            url: "https://api.github.com/repos/last-lock/link-mobile-sdk-prod/releases/assets/680564571.zip",
            checksum: "1d60f61bbecd5f7d32128d75666394dea8ea9a1a1ce160100a19aef6994709ac"
        ),
        .binaryTarget(
            name: "bridge",
            url: "https://api.github.com/repos/last-lock/link-mobile-sdk-prod/releases/assets/680564569.zip",
            checksum: "0797b39f3aa48a9bdd98cc41fac33ee3d6c8db712b0ab3203fdaee76883b10e0"
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
