package com.example.linkmobile_android_example

import android.content.pm.PackageManager
import android.os.Build
import android.os.Bundle
import android.util.Log
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.activity.result.contract.ActivityResultContracts
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.mutableStateOf
import androidx.compose.ui.Modifier
import androidx.compose.ui.tooling.preview.Preview
import androidx.core.content.ContextCompat
import com.example.linkmobile_android_example.ui.theme.LinkMobileAndroidExampleTheme
import com.lastlock.bridge.Bridge

class MainActivity : ComponentActivity() {
    private var businessServerUrl: String = "http://100.64.62.54:3005"
    private var applicationViewModel: ApplicationViewModel = ApplicationViewModel(businessServerUrl)
    private var permissionsGranted = mutableStateOf(false)
    private val permissions = if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.TIRAMISU) {
        arrayOf(
            android.Manifest.permission.BLUETOOTH_SCAN,
            android.Manifest.permission.BLUETOOTH_CONNECT,
            android.Manifest.permission.POST_NOTIFICATIONS // POST_NOTIFICATIONS introduced in api 33
        )
    } else {
        arrayOf(
            android.Manifest.permission.BLUETOOTH_ADMIN, android.Manifest.permission.BLUETOOTH, android.Manifest.permission.ACCESS_FINE_LOCATION
        )
    }

    private val requestPermissionLauncher = registerForActivityResult(ActivityResultContracts.RequestMultiplePermissions()) { permissions ->
        // Check if all permissions were granted
        val allGranted = permissions.all { it.value }
        if (allGranted) {
            Log.d("MainActivity", "Permissions granted!")
            startLinkMobile()
            permissionsGranted.value = true
        } else {
            Log.w("MainActivity", "Missing permissions")
        }
    }

    private fun checkAndRequestPermissions() {
        val missingPermissions = permissions.filter {
            ContextCompat.checkSelfPermission(this, it) != PackageManager.PERMISSION_GRANTED
        }

        if (missingPermissions.isNotEmpty()) {
            requestPermissionLauncher.launch(missingPermissions.toTypedArray())
        } else {
            startLinkMobile()
            permissionsGranted.value = true
        }
    }

    private fun startLinkMobile() {
        val serviceUUID = "4000"
        Bridge.start(serviceUUID)
    }


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        checkAndRequestPermissions()

        enableEdgeToEdge()

        setContent {
            LinkMobileAndroidExampleTheme {
                val vm = applicationViewModel
                Text("Link SDK Companion")
                DeviceScreen(
                    viewModel = vm,
                    onDeviceTap = { device ->
                        vm.performCredExchange(device)
                    }
                )
            }
        }
    }
}

@Composable
fun Greeting(name: String, modifier: Modifier = Modifier) {
    Text(
        text = "Hello $name!",
        modifier = modifier
    )
}

@Preview(showBackground = true)
@Composable
fun GreetingPreview() {
    LinkMobileAndroidExampleTheme {
        Greeting("Android")
    }
}