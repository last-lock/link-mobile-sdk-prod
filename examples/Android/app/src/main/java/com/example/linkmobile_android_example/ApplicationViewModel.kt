package com.example.linkmobile_android_example

import android.util.Log
import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import com.lastlock.bridge.Bridge
import com.lastlock.bridge.bluelink.BlueLink
import com.lastlock.bridge.bluelink.BlueLinkDeviceConnectionStatus
import com.lastlock.bridge.bluelink.BluetoothAdvertisement
import com.lastlock.bridge.bluelink.BluetoothDevice
import com.lastlock.bridge.bluelink.interfaces.BlueLinkEventListener
import com.lastlock.bridge.bluelink.interfaces.SignalStrength
import com.lastlock.bridge.credlink.CredLink
import com.lastlock.bridge.credlink.enums.CredentialExchangeResult
import com.lastlock.bridge.credlink.enums.ValidatePhoneKeysResult
import com.lastlock.bridge.credlink.interfaces.CredentialExchangeListener
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.flow.update
import kotlinx.coroutines.launch
import kotlinx.coroutines.withContext
import org.json.JSONObject
import java.net.HttpURLConnection
import java.net.URL
import java.time.Instant.*

class ApplicationViewModel(
    private val businessServerUrl: String
): ViewModel(), CredentialExchangeListener {
    // BLE Layer
    private val blueLink: BlueLink = Bridge.getBlueLink()
    private val credLink: CredLink = Bridge.getCredLink()
    private val TAG = "ApplicationViewModel"

    // Internal var to track changes
    private val _allDevices = MutableStateFlow<List<BluetoothDevice>>(emptyList())

    // Publicly accessible var for UI to use
    val allDevices = _allDevices.asStateFlow()

    private val blueLinkEventListener = object : BlueLinkEventListener() {
        override fun onDeviceDiscovered(
            device: BluetoothDevice,
            advertisementData: BluetoothAdvertisement,
            rssi: Int,
            signalStrength: SignalStrength,
            connectionStatus: BlueLinkDeviceConnectionStatus
        ) {
            viewModelScope.launch(Dispatchers.IO) {
                if (_allDevices.value.find { it.deviceId == device.deviceId } == null) {
                    _allDevices.update { it + device }
                }
            }
        }
    }

    override fun onCredentialExchangeResult(
        device: android.bluetooth.BluetoothDevice,
        result: CredentialExchangeResult
    ) {
        TODO("Not yet implemented")
    }

    fun createBLECred() {
        viewModelScope.launch(Dispatchers.IO) {
            credLink.validatePhoneKeys("${now()}", "http://localhost:3005") { result ->
                if (result.isFailure) {
                    Log.w(TAG, "Error creating BLE Credentials: ${result.exceptionOrNull()?.localizedMessage}")
                } else {
                    Log.d(TAG, "Successfully created BLE Credential")
                    when (val data = result.getOrNull()) {
                        is ValidatePhoneKeysResult.PublicKey -> {
                            Log.i(TAG, "Keys created, sending to business logic server")
                            viewModelScope.launch {
                                enrollCredentialToAllDevices(data.key.toHexString())
                            }
                        }

                        is ValidatePhoneKeysResult.Error -> {
                            Log.w(TAG, "Error during validation: ${data.error.localizedMessage}")
                        }

                        null -> {
                            Log.e(TAG, "Error response in validating BLE keys")
                        }
                    }
                }
            }
        }
    }

    /**
     * Demo Server. Use your custom integration / business logic server here for anything more than initial testing
     */
    suspend fun enrollCredentialToAllDevices(publicKeyHex: String) {
        _allDevices.value.forEach { d ->
            val body = JSONObject(mapOf("device_id" to d.deviceId.toInt(), "pkoc" to publicKeyHex)).toString()
            println("Enroll ${d.deviceId}: ${postJson("$businessServerUrl/add", body)}")
        }
    }

    fun performCredExchange(device: BluetoothDevice) {
        viewModelScope.launch {
            credLink.performCredLinkOperation(device)
        }
    }

    private suspend fun postJson(url: String, body: String) = withContext(Dispatchers.IO) {
        (URL(url).openConnection() as HttpURLConnection).run {
            requestMethod = "POST"
            setRequestProperty("Content-Type", "application/json")
            doOutput = true
            connectTimeout = 5_000; readTimeout = 5_000
            try {
                outputStream.use { it.write(body.toByteArray()) }
                val stream = if (responseCode in 200..299) inputStream else errorStream
                stream?.bufferedReader()?.readText() ?: "No data"
            } catch (e: Exception) {
                "Error: ${e.localizedMessage}"
            } finally {
                disconnect()
            }
        }
    }

    init {
        blueLink.addListener(blueLinkEventListener)
    }
}