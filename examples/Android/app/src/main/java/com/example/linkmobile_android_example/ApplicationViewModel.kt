package com.example.linkmobile_android_example

import android.content.Context
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
import com.lastlock.bridge.credlink.config.CredLinkOperation
import com.lastlock.bridge.credlink.enums.CredentialExchangeResult
import com.lastlock.bridge.credlink.interfaces.CredentialExchangeListener
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.flow.update
import kotlinx.coroutines.launch

data class TokenUnlockUiState(
    val isBusy: Boolean = false,
    val temporaryCredentialReady: Boolean = false,
    val status: String? = null,
)

class ApplicationViewModel(
    context: Context,
    businessServerUrl: String,
) : ViewModel(), CredentialExchangeListener {
    private val blueLink: BlueLink = Bridge.getBlueLink()
    private val credLink: CredLink = Bridge.getCredLink()
    private val tokenUnlockClient = TokenUnlockClient(businessServerUrl)
    private val temporaryCredentialStore = TemporaryUnlockCredentialStore(context)

    private val _allDevices = MutableStateFlow<List<BluetoothDevice>>(emptyList())
    val allDevices = _allDevices.asStateFlow()

    private val _tokenUnlockUiState = MutableStateFlow(TokenUnlockUiState())
    val tokenUnlockUiState = _tokenUnlockUiState.asStateFlow()

    private val blueLinkEventListener = object : BlueLinkEventListener() {
        override fun onDeviceDiscovered(
            device: BluetoothDevice,
            advertisementData: BluetoothAdvertisement,
            rssi: Int,
            signalStrength: SignalStrength,
            connectionStatus: BlueLinkDeviceConnectionStatus,
        ) {
            viewModelScope.launch(Dispatchers.Main) {
                if (_allDevices.value.none { it.deviceId == device.deviceId }) {
                    _allDevices.update { it + device }
                }
            }
        }
    }

    init {
        blueLink.addListener(blueLinkEventListener)
        credLink.credentialExchangeListener = this
        refreshTemporaryCredentialState()
    }

    /** Creates or reuses the persisted credential and stores its seven-day unlock pass. */
    fun createTemporaryUnlockCredential() {
        viewModelScope.launch {
            setBusy("Creating temporary BLE credential…")

            try {
                val namespace = temporaryCredentialStore.getOrCreateNamespace()
                val publicKey = credLink.fetchPublicCredential(namespace)
                val pass = tokenUnlockClient.issueTemporaryUnlockPass(publicKey)

                check(credLink.storeTokenUnlockPass(namespace, pass)) {
                    "Unable to store the temporary unlock pass"
                }
                _tokenUnlockUiState.update {
                    it.copy(
                        isBusy = false,
                        temporaryCredentialReady = true,
                        status = "Temporary unlock pass is ready for seven days.",
                    )
                }
            } catch (error: Exception) {
                _tokenUnlockUiState.update {
                    it.copy(isBusy = false, temporaryCredentialReady = false, status = error.userMessage())
                }
                Log.e(TAG, "Unable to create temporary unlock credential", error)
            }
        }
    }

    /** Queues a BLE unlock using the persisted temporary credential. */
    fun performTemporaryUnlock(device: BluetoothDevice) {
        viewModelScope.launch {
            val namespace = temporaryCredentialStore.existingNamespace() ?: run {
                setStatus("Create a temporary unlock pass before unlocking.")
                return@launch
            }

            if (credLink.getTokenUnlockPass(namespace) == null) {
                refreshTemporaryCredentialState()
                setStatus("Create a temporary unlock pass before unlocking.")
                return@launch
            }

            setBusy("Unlocking ${device.deviceId} with the temporary credential…")
            try {
                credLink.performCredLinkOperation(
                    peripheral = device,
                    operation = CredLinkOperation.TokenUnlock(namespace = namespace),
                )
            } catch (error: Exception) {
                _tokenUnlockUiState.update {
                    it.copy(isBusy = false, status = error.userMessage())
                }
                Log.e(TAG, "Unable to queue temporary unlock", error)
            }
        }
    }

    override fun onCredentialExchangeResult(
        device: BluetoothDevice,
        result: CredentialExchangeResult,
    ) {
        _tokenUnlockUiState.update {
            it.copy(isBusy = false, status = "${device.deviceId}: $result")
        }
    }

    override fun onCleared() {
        blueLink.removeListener(blueLinkEventListener)
        if (credLink.credentialExchangeListener === this) {
            credLink.credentialExchangeListener = null
        }
        super.onCleared()
    }

    private fun refreshTemporaryCredentialState() {
        viewModelScope.launch {
            val namespace = temporaryCredentialStore.existingNamespace()
            val hasPass = namespace != null && credLink.getTokenUnlockPass(namespace) != null
            _tokenUnlockUiState.update { it.copy(temporaryCredentialReady = hasPass) }
        }
    }

    private fun setBusy(status: String) {
        _tokenUnlockUiState.update { it.copy(isBusy = true, status = status) }
    }

    private fun setStatus(status: String) {
        _tokenUnlockUiState.update { it.copy(status = status) }
    }

    private fun Exception.userMessage(): String = message ?: "An unexpected error occurred."

    private companion object {
        const val TAG = "LinkMobileExample"
    }
}
