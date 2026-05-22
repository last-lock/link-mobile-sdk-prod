package com.example.linkmobile_android_example

import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.PaddingValues
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.material3.AssistChip
import androidx.compose.material3.Button
import androidx.compose.material3.Card
import androidx.compose.material3.CardDefaults
import androidx.compose.material3.ExperimentalMaterial3Api
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.material3.TopAppBar
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp
import androidx.lifecycle.compose.collectAsStateWithLifecycle
import com.lastlock.bridge.bluelink.BluetoothDevice

// DevicesScreen.kt
@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun DeviceScreen(
    viewModel: ApplicationViewModel,
    onDeviceTap: (BluetoothDevice) -> Unit
) {
    val devices by viewModel.allDevices.collectAsStateWithLifecycle()

    Scaffold(
        topBar = { TopAppBar(title = { Text("Discovered Locks") }) },
        bottomBar = {
            Surface(shadowElevation = 6.dp) {
                Row(
                    modifier = Modifier
                        .fillMaxWidth()
                        .padding(12.dp),
                    horizontalArrangement = Arrangement.Center
                ) {
                    Button(
                        onClick = {
                            // Uncomment later once implemented in ApplicationViewModel
                             viewModel.createBLECred()
                        },
                        modifier = Modifier.fillMaxWidth()
                    ) {
                        Text("Create BLE Credential")
                    }
                }
            }
        }
    ) { padding ->
        DiscoveredDevicesList(
            devices = devices,
            onDeviceTap = onDeviceTap,
            modifier = Modifier.padding(padding)
        )
    }
}

@Composable
fun DiscoveredDevicesList(
    devices: List<BluetoothDevice>,
    onDeviceTap: (BluetoothDevice) -> Unit,
    modifier: Modifier = Modifier,
    emptyText: String = "No locks discovered yet…"
) {
    if (devices.isEmpty()) {
        Box(
            modifier = modifier.fillMaxSize(),
            contentAlignment = Alignment.Center
        ) {
            Text(emptyText, style = MaterialTheme.typography.bodyMedium)
        }
        return
    }

    LazyColumn(
        modifier = modifier.fillMaxSize(),
        contentPadding = PaddingValues(12.dp),
        verticalArrangement = Arrangement.spacedBy(10.dp)
    ) {
        items(
            items = devices,
            key = { it.deviceId.toString() } // stable for recomposition
        ) { device ->
            DeviceCard(
                device = device,
                onTap = { onDeviceTap(device) }
            )
        }
    }
}

@Composable
private fun DeviceCard(
    device: BluetoothDevice,
    onTap: () -> Unit,
    modifier: Modifier = Modifier
) {
    Card(
        modifier = modifier
            .fillMaxWidth()
            .clickable(onClick = onTap),
        shape = MaterialTheme.shapes.large,
        elevation = CardDefaults.cardElevation(defaultElevation = 2.dp),
    ) {
        Row(
            modifier = Modifier
                .fillMaxWidth()
                .padding(14.dp),
            verticalAlignment = Alignment.CenterVertically
        ) {
            Column(modifier = Modifier.weight(1f)) {
                Text(
                    text = "Device: ${device.deviceId}",
                    style = MaterialTheme.typography.titleMedium
                )
            }

            AssistChip(
                onClick = onTap,
                label = { Text("BLE Unlock") }
            )
        }
    }
}