package com.cody669.TimeKeeper

import com.facebook.react.bridge.Arguments
import com.facebook.react.bridge.Promise
import com.facebook.react.bridge.ReactApplicationContext
import com.facebook.react.bridge.ReactContextBaseJavaModule
import com.facebook.react.bridge.ReactMethod
import com.facebook.react.bridge.WritableMap
import com.facebook.react.modules.core.DeviceEventManagerModule
import com.lastlock.bridge.Bridge
import android.util.Log
import com.lastlock.bridge.bluelink.BluetoothAdvertisement
import com.lastlock.bridge.bluelink.BluetoothDevice
import com.lastlock.bridge.bluelink.BlueLinkDeviceConnectionStatus
import com.lastlock.bridge.bluelink.interfaces.BlueLinkEventListener
import com.lastlock.bridge.bluelink.interfaces.SignalStrength

class BridgeModule(reactContext: ReactApplicationContext) :
        ReactContextBaseJavaModule(reactContext) {

  override fun getName() = "BridgeModule"

  private fun sendEvent(eventName: String, params: WritableMap?) {
    reactApplicationContext
      .getJSModule(DeviceEventManagerModule.RCTDeviceEventEmitter::class.java)
      .emit(eventName, params)
  }

  @ReactMethod
  fun initialize(serverAddress: String, uuid: String, promise: Promise) {
    try {
      Bridge.init(reactApplicationContext, serverAddress)
      Bridge.setLogsEnabled(true)

      // Attach listener to receive device discovery events
      val blueLink = Bridge.getBlueLink()
      blueLink?.addListener(object : BlueLinkEventListener() {
        override fun onDeviceDiscovered(
          device: BluetoothDevice,
          advertisementData: BluetoothAdvertisement,
          rssi: Int,
          signalStrength: SignalStrength,
          connectionStatus: BlueLinkDeviceConnectionStatus
        ) {
          Log.d("BridgeModule", "onDeviceDiscovered called! deviceId=${device.deviceId.toString()}")

          val params = Arguments.createMap().apply {
            putString("name", device.name ?: "Unknown")
            putString("identifier", device.deviceId.toString())
            putInt("rssi", rssi)
            putString("connectionStatus", connectionStatus.name)
            putString("signalStrength", signalStrength.toString() ?: "unknown")
          }
          sendEvent("onDeviceDiscovered", params)
        }

        override fun onDeviceConnected(device: BluetoothDevice) {
          val params = Arguments.createMap().apply {
            putString("name", device.name ?: "Unknown")
            putString("identifier", device.deviceId.toString())
          }
          sendEvent("onDeviceConnected", params)
        }

        override fun onDeviceDisconnected(device: BluetoothDevice, reason: Int?) {
          val params = Arguments.createMap().apply {
            putString("name", device.name ?: "Unknown")
            putString("identifier", device.deviceId.toString())
          }
          sendEvent("onDeviceDisconnected", params)
        }

        override fun onBLEStateChanged(newState: Boolean) {
          val params = Arguments.createMap().apply {
            putBoolean("state", newState)
          }
          sendEvent("onBLEStateChanged", params)
        }
      }, false)

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

  // Required for NativeEventEmitter
  @ReactMethod
  fun addListener(eventName: String) {
    // Keep: Required for RN built-in Event Emitter Calls
  }

  @ReactMethod
  fun removeListeners(count: Int) {
    // Keep: Required for RN built-in Event Emitter Calls
  }
}