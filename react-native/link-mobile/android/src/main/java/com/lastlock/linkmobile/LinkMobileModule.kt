package com.lastlock.linkmobile

import android.Manifest
import android.content.pm.PackageManager
import android.os.Build
import android.os.Handler
import android.os.Looper
import android.util.Log
import androidx.core.content.ContextCompat
import com.facebook.react.bridge.Arguments
import com.facebook.react.bridge.Promise
import com.facebook.react.bridge.ReactApplicationContext
import com.facebook.react.bridge.WritableMap
import com.facebook.react.common.LifecycleState
import com.facebook.react.modules.core.PermissionAwareActivity
import com.facebook.react.modules.core.PermissionListener
import android.util.Base64
import com.lastlock.bridge.Bridge
import com.lastlock.bridge.bluelink.BlueLink
import com.lastlock.bridge.bluelink.BluetoothDevice
import com.lastlock.bridge.bluelink.interfaces.BlueLinkEventListener
import com.lastlock.bridge.bluelink.BluetoothAdvertisement
import com.lastlock.bridge.credlink.config.CredLinkOperation
import com.lastlock.bridge.credlink.enums.CredentialExchangeResult
import com.lastlock.bridge.credlink.interfaces.CredentialExchangeListener
import com.lastlock.bridge.credlink.interfaces.ReaderGroupTrust
import com.lastlock.bridge.credlink.interfaces.TokenUnlockPass
import com.lastlock.bridge.dfu.CheckDFUResult
import com.lastlock.bridge.dfu.DFUUiState
import com.lastlock.bridge.proxy.InstallOOBResult
import io.ktor.utils.io.core.Closeable
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.SupervisorJob
import kotlinx.coroutines.delay
import kotlinx.coroutines.isActive
import kotlinx.coroutines.launch
import kotlinx.coroutines.withContext
import java.util.concurrent.ConcurrentHashMap
import java.util.concurrent.atomic.AtomicBoolean

class LinkMobileModule(reactContext: ReactApplicationContext) :
  NativeLinkMobileSpec(reactContext) {
  private val scope = CoroutineScope(SupervisorJob() + Dispatchers.Main.immediate)
  private val devices = ConcurrentHashMap<String, BluetoothDevice>()
  private val oobTimestamps = ConcurrentHashMap<String, Double>()
  private val scanStarted = AtomicBoolean(false)
  private val streamWatchStarted = AtomicBoolean(false)
  private val permissionRequestInFlight = AtomicBoolean(false)
  private var serverAddress: String? = null
  private var eventListener: Events? = null
  private var attachedBlueLink: BlueLink? = null
  private var dfuWatch: Closeable? = null

  override fun initialize(serverAddress: String, promise: Promise) {
    this.serverAddress = serverAddress
    scope.launch {
      try {
        // Bridge.init reloads Koin and replaces the proxy. The process can
        // outlive an app restart, and BluetoothService keeps the first instances.
        // Stop the BlueLink already attached so that instance does not keep
        // scanning after init replaces it, or after a later initialize.
        if (bridgeReady.compareAndSet(false, true)) {
          try {
            stopAttachedScan()
            Bridge.init(reactApplicationContext.applicationContext, serverAddress)
            Bridge.setLogsEnabled(true)
          } catch (error: Exception) {
            bridgeReady.set(false)
            throw error
          }
        } else {
          stopAttachedScan()
          Bridge.setServerAddress(serverAddress)
          activeModule?.takeIf { it !== this@LinkMobileModule }?.detachListeners()
        }
        activeModule = this@LinkMobileModule
        attachListeners()
        promise.resolve("Bridge ready for $serverAddress")
      } catch (error: Exception) {
        promise.reject("ERROR", error.message, error)
      }
    }
  }

  override fun start(uuid: String, promise: Promise) {
    startWithPermissions(uuid, promise, limited = false)
  }

  override fun startLimited(uuid: String, promise: Promise) {
    startWithPermissions(uuid, promise, limited = true)
  }

  private fun startWithPermissions(uuid: String, promise: Promise, limited: Boolean) {
    if (serverAddress == null) {
      promise.reject("ERROR", "Bridge not initialized. Call initialize first.")
      return
    }
    if (limited && reactApplicationContext.lifecycleState != LifecycleState.RESUMED) {
      promise.reject("ERROR", "Call startLimited while the app is in the foreground.")
      return
    }
    val missing = requiredPermissions(limited).filterNot(::hasPermission)
    if (missing.isEmpty()) {
      startScan(uuid, promise, limited)
      return
    }
    if (!permissionRequestInFlight.compareAndSet(false, true)) {
      promise.reject("ERROR", "A permission request is already in progress.")
      return
    }
    // Android 10/11 requires foreground location to be granted first.
    // Android 11 handles the separate background grant in system Settings.
    val background = Manifest.permission.ACCESS_BACKGROUND_LOCATION
    val foreground = missing.filterNot { it == background }
    val firstStage = if (foreground.isNotEmpty()) foreground else missing
    val listener =
      PermissionRequestListener(PERMISSION_REQUEST, firstStage, ::hasPermission) { granted ->
        if (!granted) {
          permissionRequestInFlight.set(false)
          promise.reject("ERROR", "Bluetooth permissions were denied.")
        } else if (background in missing && background !in firstStage) {
          // Never request background and foreground location in the same dialog.
          val backgroundListener =
            PermissionRequestListener(PERMISSION_REQUEST, listOf(background), ::hasPermission) { backgroundGranted ->
              permissionRequestInFlight.set(false)
              if (backgroundGranted) {
                startScan(uuid, promise, limited)
              } else {
                promise.reject("ERROR", "Background location is required for full scanning. Enable Allow all the time in Settings.")
              }
            }
          // ReactActivity clears the completed listener after this callback returns.
          // Register the next listener afterwards so it is not cleared as well.
          Handler(Looper.getMainLooper()).post {
            requestPermissions(listOf(background), backgroundListener, promise)
          }
        } else {
          permissionRequestInFlight.set(false)
          startScan(uuid, promise, limited)
        }
      }
    requestPermissions(firstStage, listener, promise)
  }

  private fun requestPermissions(permissions: List<String>, listener: PermissionListener, promise: Promise) {
    requestPermissionsSafely(
      permissions,
      PERMISSION_REQUEST,
      listener,
      currentActivity = {
        reactApplicationContext.currentActivity
          ?.takeUnless { it.isFinishing || it.isDestroyed } as? PermissionAwareActivity
      },
      onFailure = { error ->
        permissionRequestInFlight.set(false)
        promise.reject("ERROR", error.message, error)
      },
    )
  }

  override fun identify(identifier: String, promise: Promise) {
    val device = requireDevice(identifier, promise) ?: return
    scope.launch {
      try {
        val queued =
          withContext(Dispatchers.IO) {
            Bridge.getBLEProxy().identifyDevice(device.deviceId, OobPayloads.identify(device.deviceId))
          }
        if (!queued) {
          promise.reject("ERROR", "Device $identifier is not tracked by the proxy.")
          return@launch
        }
        promise.resolve(true)
      } catch (error: Exception) {
        promise.reject("ERROR", error.message, error)
      }
    }
  }

  override fun setLockEngagedState(identifier: String, engaged: Boolean, promise: Promise) {
    val device = requireDevice(identifier, promise) ?: return
    scope.launch {
      try {
        val queued =
          withContext(Dispatchers.IO) {
            Bridge.getBLEProxy()
              .setLockEngagedState(device.deviceId, OobPayloads.lockEngaged(device.deviceId, engaged))
          }
        if (!queued) {
          promise.reject("ERROR", "Device $identifier is not tracked by the proxy.")
          return@launch
        }
        promise.resolve(true)
      } catch (error: Exception) {
        promise.reject("ERROR", error.message, error)
      }
    }
  }

  override fun sendOutOfBandPayload(identifier: String, payloadBase64: String, promise: Promise) {
    val device = requireDevice(identifier, promise) ?: return
    val payload =
      try {
        Base64.decode(payloadBase64, Base64.DEFAULT)
      } catch (error: IllegalArgumentException) {
        promise.reject("ERROR", "Out-of-band payload is not valid base64.")
        return
      }
    try {
      Bridge.getBLEProxy().sendOOBToDevice(device.deviceId, payload)
      promise.resolve("Out-of-band payload queued for $identifier")
    } catch (error: Exception) {
      promise.reject("ERROR", error.message, error)
    }
  }

  override fun checkForDFU(identifier: String, promise: Promise) {
    val device = requireDevice(identifier, promise) ?: return
    scope.launch {
      try {
        val result =
          withContext(Dispatchers.IO) {
            Bridge.getDFUService().checkForDFU(device, 15_000L)
          }
        val body = Arguments.createMap()
        when (result) {
          is CheckDFUResult.Timeout -> {
            body.putString("status", "timeout")
            body.putString("firmwareVersion", "")
            body.putString("availableVersion", "")
          }
          is CheckDFUResult.Success -> {
            val state = Bridge.getDFUService().uiState.value
            body.putString("status", if (state.dfuAvailable) "update_available" else "up_to_date")
            body.putString("firmwareVersion", result.firmwareVersion?.toString() ?: "")
            body.putString("availableVersion", state.dfuImage?.dfuVersion ?: "")
          }
        }
        promise.resolve(body)
      } catch (error: Exception) {
        promise.reject("ERROR", error.message, error)
      }
    }
  }

  override fun startDFU(identifier: String, promise: Promise) {
    val device = requireDevice(identifier, promise) ?: return
    val state = Bridge.getDFUService().uiState.value
    val image = state.dfuImage
    if (!state.dfuAvailable || image == null || image.deviceId.toString() != identifier) {
      promise.reject("ERROR", "Check for a firmware update before starting DFU.")
      return
    }
    waitForMode(device, dfuRequired = true, promise, "DFU started for $identifier")
  }

  override fun waitForDeviceMode(identifier: String, dfuRequired: Boolean, promise: Promise) {
    val device = requireDevice(identifier, promise) ?: return
    val message = if (dfuRequired) "Device $identifier entered DFU mode." else "Device $identifier entered install mode."
    waitForMode(device, dfuRequired, promise, message)
  }

  override fun exitDFUInstallMode(identifier: String, promise: Promise) {
    val device = requireDevice(identifier, promise) ?: return
    scope.launch {
      try {
        val sent =
          withContext(Dispatchers.IO) {
            Bridge.getDFUService().exitInstallMode(device, OobPayloads.installReboot(device.deviceId))
          }
        if (!sent) {
          promise.reject("ERROR", "Failed to send the DFU reboot.")
          return@launch
        }
        val result =
          withContext(Dispatchers.IO) {
            Bridge.getBLEProxy().waitForInstallModeExit(device.deviceId)
          }
        if (result is InstallOOBResult.Timeout) {
          promise.reject("ERROR", "Timed out waiting for the lock to leave DFU.")
          return@launch
        }
        promise.resolve("Device $identifier left install mode.")
      } catch (error: Exception) {
        promise.reject("ERROR", error.message, error)
      }
    }
  }

  override fun fetchTokenUnlockPublicKey(tokenNamespace: String, promise: Promise) {
    if (tokenNamespace.isBlank()) {
      promise.reject("ERROR", "Token unlock namespace is required.")
      return
    }
    scope.launch {
      try {
        val publicKey =
          withContext(Dispatchers.IO) {
            Bridge.getCredLink().fetchPublicCredential(tokenNamespace)
          }
        if (publicKey.isEmpty()) {
          promise.reject("ERROR", "Token unlock public key is empty.")
          return@launch
        }
        promise.resolve(Base64.encodeToString(publicKey, Base64.NO_WRAP))
      } catch (error: Exception) {
        promise.reject("ERROR", error.message, error)
      }
    }
  }

  override fun storeTokenUnlockPass(
    tokenNamespace: String,
    accessDocumentBase64: String,
    readerGroupIdBase64: String,
    issuerCaPublicKeyBase64: String,
    issuerCaCertificateBase64: String,
    promise: Promise,
  ) {
    val accessDocument = decodeBase64(accessDocumentBase64, promise) ?: return
    val readerGroupId = decodeBase64(readerGroupIdBase64, promise) ?: return
    val issuerCaPublicKey = decodeBase64(issuerCaPublicKeyBase64, promise) ?: return
    val certificate = decodeBase64(issuerCaCertificateBase64, promise) ?: return
    scope.launch {
      try {
        val stored =
          withContext(Dispatchers.IO) {
            Bridge.getCredLink().storeTokenUnlockPass(
              tokenNamespace,
              TokenUnlockPass(
                accessDocument = accessDocument,
                readerGroups = listOf(
                  ReaderGroupTrust(
                    readerGroupIdentifier = readerGroupId,
                    issuerCAPublicKey = issuerCaPublicKey,
                    issuerCACertificateDer = certificate,
                  ),
                ),
              ),
            )
          }
        if (!stored) {
          promise.reject("ERROR", "Unable to store the token unlock pass.")
          return@launch
        }
        promise.resolve(true)
      } catch (error: Exception) {
        promise.reject("ERROR", error.message, error)
      }
    }
  }

  override fun tokenUnlock(identifier: String, tokenNamespace: String, promise: Promise) {
    val device = requireDevice(identifier, promise) ?: return
    if (tokenNamespace.isBlank()) {
      promise.reject("ERROR", "Token unlock namespace is required.")
      return
    }
    scope.launch {
      try {
        withContext(Dispatchers.IO) {
          Bridge.getCredLink().performCredLinkOperation(device, CredLinkOperation.TokenUnlock(tokenNamespace))
        }
        promise.resolve("Token unlock started for $identifier")
      } catch (error: Exception) {
        promise.reject("ERROR", error.message, error)
      }
    }
  }

  private fun waitForMode(
    device: BluetoothDevice,
    dfuRequired: Boolean,
    promise: Promise,
    success: String,
  ) {
    scope.launch {
      try {
        val result =
          withContext(Dispatchers.IO) {
            Bridge.getBLEProxy().deliverInstallOOBAndWaitForMode(device.deviceId, dfuRequired, 20_000L)
          }
        if (result is InstallOOBResult.Timeout) {
          val mode = if (dfuRequired) "DFU" else "install"
          promise.reject("ERROR", "Timed out waiting for the lock to enter $mode mode.")
          return@launch
        }
        promise.resolve(success)
      } catch (error: Exception) {
        promise.reject("ERROR", error.message, error)
      }
    }
  }

  private fun decodeBase64(value: String, promise: Promise): ByteArray? {
    return try {
      Base64.decode(value, Base64.DEFAULT)
    } catch (error: IllegalArgumentException) {
      promise.reject("ERROR", "Token unlock material is not valid base64.")
      null
    }
  }

  override fun cancelDFU(promise: Promise) {
    try {
      Bridge.getDFUService().cancelDFU()
      promise.resolve("DFU cancelled")
    } catch (error: Exception) {
      promise.reject("ERROR", error.message, error)
    }
  }

  private fun requireDevice(identifier: String, promise: Promise): BluetoothDevice? {
    if (serverAddress == null) {
      promise.reject("ERROR", "Bridge not initialized. Call initialize first.")
      return null
    }
    val device = devices[identifier]
    if (device == null) {
      promise.reject("ERROR", "Device $identifier has not been discovered.")
      return null
    }
    return device
  }

  private fun stopAttachedScan() {
    val links = LinkedHashSet<BlueLink>()
    attachedBlueLink?.let { links.add(it) }
    activeModule?.attachedBlueLink?.let { links.add(it) }
    for (link in links) {
      try {
        link.stopBLEScan()
      } catch (error: Exception) {
        Log.w(NAME, "Failed to stop the previous BLE scan", error)
      }
    }
  }

  private fun startScan(uuid: String, promise: Promise, limited: Boolean) {
    scope.launch {
      try {
        // Recheck at the point of use, including the path that skips the dialog.
        // A service lifecycle exception is asynchronous and cannot be caught here.
        val missing = missingStartupPermissions(
          Build.VERSION.SDK_INT, limited, requiredPermissions(limited).toList(), ::hasPermission,
        )
        if (missing.isNotEmpty()) {
          promise.reject("ERROR", "Permissions are required before scanning: ${missing.joinToString()}")
          return@launch
        }
        val address = serverAddress
        if (limited) {
          attachListeners()
          Bridge.startLimited(uuid)
          scanStarted.set(true)
          promise.resolve("Bridge started in limited mode with UUID: $uuid")
        } else if (address != null && scanStarted.get()) {
          Bridge.restart(address, uuid)
          attachListeners()
          // Ensure a limited session is promoted to a foreground service, or
          // recreate the service if Android stopped it while the app was hidden.
          Bridge.start(uuid)
          promise.resolve("Bridge restarted for $address UUID: $uuid")
        } else {
          attachListeners()
          Bridge.start(uuid)
          scanStarted.set(true)
          promise.resolve("Bridge started with UUID: $uuid")
        }
        watchProxyStream()
      } catch (error: Exception) {
        promise.reject("ERROR", error.message, error)
      }
    }
  }

  private fun detachListeners() {
    val events = eventListener ?: return
    attachedBlueLink?.removeListener(events)
    if (Bridge.getCredLink().credentialExchangeListener === events) {
      Bridge.getCredLink().credentialExchangeListener = null
    }
    dfuWatch?.close()
    dfuWatch = null
    attachedBlueLink = null
  }

  private fun attachListeners() {
    val blueLink = Bridge.getBlueLink()
    if (blueLink === attachedBlueLink && eventListener != null) {
      return
    }
    val events = eventListener ?: Events().also { eventListener = it }
    attachedBlueLink?.removeListener(events)
    blueLink.addListener(events, false)
    attachedBlueLink = blueLink
    Bridge.getCredLink().credentialExchangeListener = events
    dfuWatch?.close()
    dfuWatch =
      Bridge.getDFUService().watchUiState { state ->
        emitDfuState(state.toMap())
      }
    Log.i(NAME, "Attached bridge listeners")
  }

  private fun hasPermission(permission: String): Boolean =
    ContextCompat.checkSelfPermission(reactApplicationContext, permission) ==
      PackageManager.PERMISSION_GRANTED

  private fun requiredPermissions(limited: Boolean): Array<String> {
    return if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.TIRAMISU) {
      arrayOf(
        Manifest.permission.BLUETOOTH_SCAN,
        Manifest.permission.BLUETOOTH_CONNECT,
      ) + if (limited) emptyArray<String>() else arrayOf(Manifest.permission.POST_NOTIFICATIONS)
    } else if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.S) {
      arrayOf(Manifest.permission.BLUETOOTH_SCAN, Manifest.permission.BLUETOOTH_CONNECT)
    } else if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.Q) {
      arrayOf(
        Manifest.permission.BLUETOOTH_ADMIN,
        Manifest.permission.BLUETOOTH,
        Manifest.permission.ACCESS_FINE_LOCATION,
      ) + if (limited) emptyArray<String>() else arrayOf(Manifest.permission.ACCESS_BACKGROUND_LOCATION)
    } else {
      arrayOf(
        Manifest.permission.BLUETOOTH_ADMIN,
        Manifest.permission.BLUETOOTH,
        Manifest.permission.ACCESS_FINE_LOCATION,
      )
    }
  }

  private fun emitDiscovered(body: WritableMap) {
    if (mEventEmitterCallback != null) {
      emitOnDeviceDiscovered(body)
    }
  }

  private fun emitConnected(body: WritableMap) {
    if (mEventEmitterCallback != null) {
      emitOnDeviceConnected(body)
    }
  }

  private fun emitDisconnected(body: WritableMap) {
    if (mEventEmitterCallback != null) {
      emitOnDeviceDisconnected(body)
    }
  }

  private fun emitBleState(body: WritableMap) {
    if (mEventEmitterCallback != null) {
      emitOnBLEStateChanged(body)
    }
  }

  private fun emitCredentialResult(body: WritableMap) {
    if (mEventEmitterCallback != null) {
      emitOnCredentialExchangeResult(body)
    }
  }

  private fun emitDfuState(body: WritableMap) {
    if (mEventEmitterCallback != null) {
      emitOnDFUStateChanged(body)
    }
  }

  private fun emitHeartbeat(body: WritableMap) {
    if (mEventEmitterCallback != null) {
      emitOnHeartbeat(body)
    }
  }

  private fun emitProxyStream(body: WritableMap) {
    if (mEventEmitterCallback != null) {
      emitOnProxyStreamStateChanged(body)
    }
  }

  private fun watchProxyStream() {
    if (!streamWatchStarted.compareAndSet(false, true)) {
      return
    }
    scope.launch {
      var last: String? = null
      while (isActive) {
        val alive =
          withContext(Dispatchers.IO) {
            runCatching { Bridge.getBLEProxy().isStreamAlive() }.getOrDefault(false)
          }
        val state = if (alive) "connected" else "disconnected"
        if (state != last) {
          last = state
          val body = Arguments.createMap()
          body.putString("state", state)
          emitProxyStream(body)
        }
        delay(3_000)
      }
    }
  }

  private fun deviceName(device: BluetoothDevice): String {
    val identifier = device.deviceId.toString()
    return try {
      device.name ?: identifier
    } catch (error: SecurityException) {
      identifier
    }
  }

  private fun remember(
    device: BluetoothDevice,
    advertisement: BluetoothAdvertisement,
    rssi: Int,
    connectionStatus: String,
    signalStrength: String,
  ): Snapshot {
    val identifier = device.deviceId.toString()
    val name = deviceName(device)
    devices[identifier] = device
    val snapshot =
      Snapshot(
        name = name,
        identifier = identifier,
        rssi = rssi,
        connectionStatus = connectionStatus,
        signalStrength = signalStrength,
        advertisement = advertisement,
        oobTimestamp = oobTimestamps[identifier] ?: 0.0,
      )
    Log.i(NAME, "Discovered $identifier rssi=$rssi")
    return snapshot
  }

  private inner class Events :
    BlueLinkEventListener(),
    CredentialExchangeListener {
    override fun onBLEStateChanged(newState: Boolean) {
      val body = Arguments.createMap()
      body.putBoolean("state", newState)
      emitBleState(body)
    }

    override fun onDeviceDiscovered(
      device: BluetoothDevice,
      advertisementData: com.lastlock.bridge.bluelink.BluetoothAdvertisement,
      rssi: Int,
      signalStrength: com.lastlock.bridge.bluelink.interfaces.SignalStrength,
      connectionStatus: com.lastlock.bridge.bluelink.BlueLinkDeviceConnectionStatus,
    ) {
      val snapshot = remember(device, advertisementData, rssi, connectionStatus.name, signalStrength.name)
      emitDiscovered(snapshot.toMap())
    }

    override fun onHeartbeat(device: BluetoothDevice, heartbeatData: ByteArray) {
      val parsed = Bridge.getBlueLink().heartbeatParser.parseHeartbeat(heartbeatData) ?: return
      val timestamp = parsed.lastOobServerTimestamp ?: return
      val identifier = device.deviceId.toString()
      oobTimestamps[identifier] = timestamp.toDouble()
      val body = Arguments.createMap()
      body.putString("identifier", identifier)
      body.putDouble("oobTimestamp", timestamp.toDouble())
      emitHeartbeat(body)
    }

    override fun onDeviceConnected(device: BluetoothDevice) {
      val identifier = device.deviceId.toString()
      devices[identifier] = device
      val body = Arguments.createMap()
      body.putString("name", deviceName(device))
      body.putString("identifier", identifier)
      emitConnected(body)
    }

    override fun onDeviceDisconnected(device: BluetoothDevice, reason: Int?) {
      val body = Arguments.createMap()
      body.putString("name", deviceName(device))
      body.putString("identifier", device.deviceId.toString())
      emitDisconnected(body)
    }

    override fun onCredentialExchangeResult(
      device: BluetoothDevice,
      result: CredentialExchangeResult,
    ) {
      val body = Arguments.createMap()
      body.putString("name", deviceName(device))
      body.putString("identifier", device.deviceId.toString())
      body.putString("result", result.name)
      body.putString("message", result.toString())
      emitCredentialResult(body)
    }
  }

  private data class Snapshot(
    val name: String,
    val identifier: String,
    val rssi: Int,
    val connectionStatus: String,
    val signalStrength: String,
    val advertisement: BluetoothAdvertisement,
    val oobTimestamp: Double,
  ) {
    fun toMap(): WritableMap {
      val body = Arguments.createMap()
      body.putString("name", name)
      body.putString("identifier", identifier)
      body.putInt("rssi", rssi)
      body.putString("connectionStatus", connectionStatus)
      body.putString("signalStrength", signalStrength)
      body.putBoolean("installMode", advertisement.isInInstallMode())
      body.putBoolean("dfuMode", advertisement.isInDFU())
      body.putBoolean("hibernate", advertisement.isHibernating())
      body.putBoolean("serviceMode", advertisement.isInServiceMode())
      body.putBoolean("lowBattery", advertisement.hasLowBatteryStatus())
      body.putBoolean("criticalBattery", advertisement.hasCriticalBattery())
      body.putBoolean("cooldown", advertisement.isInCooldown())
      body.putBoolean("emergency", advertisement.isInEmergencyState())
      body.putBoolean("busy", advertisement.isBusy())
      body.putBoolean("timeSyncRequest", advertisement.hasTimeSyncRequest())
      body.putString("overridingMode", advertisement.overridingMode().name)
      body.putInt("deviceStateCounter", advertisement.deviceStateCounter.toInt())
      body.putInt("serverStateCounter", advertisement.serverStateCounter.toInt())
      body.putDouble("oobTimestamp", oobTimestamp)
      return body
    }
  }

  private fun DFUUiState.toMap(): WritableMap {
    val body = Arguments.createMap()
    body.putString("flowState", flowState.name)
    body.putDouble("installProgress", installProgress.toDouble())
    body.putDouble("postInstallProgress", postInstallProgress.toDouble())
    body.putBoolean("dfuAvailable", dfuAvailable)
    body.putBoolean("dfuImageLoading", dfuImageLoading)
    body.putString("availableVersion", dfuImage?.dfuVersion ?: "")
    return body
  }

  companion object {
    const val NAME = "LinkMobile"
    private const val PERMISSION_REQUEST = 4401
    private val bridgeReady = AtomicBoolean(false)
    private var activeModule: LinkMobileModule? = null
  }
}
