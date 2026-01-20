package com.lastlock.sampleapp1

import com.facebook.react.bridge.Promise
import com.facebook.react.bridge.ReactApplicationContext
import com.facebook.react.bridge.ReactContextBaseJavaModule
import com.facebook.react.bridge.ReactMethod
import com.lastlock.bridge.Bridge

class BridgeModule(reactContext: ReactApplicationContext) :
        ReactContextBaseJavaModule(reactContext) {

  override fun getName() = "BridgeModule"

  @ReactMethod
  fun initialize(serverAddress: String, uuid: String, promise: Promise) {
    try {
      Bridge.init(reactApplicationContext, serverAddress)
      Bridge.setLogsEnabled(true)
      promise.resolve("Bridge initialized")
    } catch (e: Exception) {
      promise.reject("INIT_ERROR", e)
    }
  }

  @ReactMethod
  fun start(uuid: String, promise: Promise) {
    try {
      Bridge.start(uuid)
      promise.resolve("Bridge started with UUID: $uuid")
    } catch (e: Exception) {
      promise.reject("START_ERROR", e)
    }
  }
}
