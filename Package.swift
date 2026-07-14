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
            url: "https://api.github.com/repos/last-lock/link-mobile-sdk-prod/releases/assets/477232144.zip",
            checksum: "a58990df10fd50f2cb849f28c67c680190a8712517f6462b5cf810b16564ab6e"
        ),
        .binaryTarget(
            name: "bridge",
            url: "https://api.github.com/repos/last-lock/link-mobile-sdk-prod/releases/assets/477232143.zip",
            checksum: "0644cb410a10770cf196ebc93358744971ec149049443df6ef1226aedf2f2474"
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
