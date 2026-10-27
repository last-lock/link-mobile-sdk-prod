package com.example.linkmobile_android_example

import android.Manifest.permission.ACCESS_BACKGROUND_LOCATION
import android.Manifest.permission.ACCESS_FINE_LOCATION
import android.Manifest.permission.BLUETOOTH
import android.Manifest.permission.BLUETOOTH_ADMIN
import android.Manifest.permission.BLUETOOTH_CONNECT
import android.Manifest.permission.BLUETOOTH_SCAN
import android.Manifest.permission.POST_NOTIFICATIONS
import org.junit.Assert.assertEquals
import org.junit.Test

class LinkPermissionsTest {
    @Test
    fun android12And12LRequestNearbyDevicesInsteadOfLegacyLocation() {
        for (sdkInt in 31..32) {
            assertEquals(
                setOf(BLUETOOTH_SCAN, BLUETOOTH_CONNECT),
                requiredLinkPermissions(sdkInt).toSet(),
            )
        }
    }

    @Test
    fun android13AndLaterPreserveNotificationRequest() {
        for (sdkInt in 33..36) {
            assertEquals(
                setOf(BLUETOOTH_SCAN, BLUETOOTH_CONNECT, POST_NOTIFICATIONS),
                requiredLinkPermissions(sdkInt).toSet(),
            )
        }
    }

    @Test
    fun android10And11NeedBackgroundLocationForFullStartup() {
        for (sdkInt in 29..30) {
            assertEquals(
                setOf(BLUETOOTH, BLUETOOTH_ADMIN, ACCESS_FINE_LOCATION, ACCESS_BACKGROUND_LOCATION),
                requiredLinkPermissions(sdkInt).toSet(),
            )
        }
    }

    @Test
    fun olderAndroidDoesNotRequestBackgroundLocation() {
        for (sdkInt in 26..28) {
            assertEquals(
                setOf(BLUETOOTH, BLUETOOTH_ADMIN, ACCESS_FINE_LOCATION),
                requiredLinkPermissions(sdkInt).toSet(),
            )
        }
    }

    @Test
    fun firstRequestNeverCombinesForegroundAndBackgroundLocation() {
        for (sdkInt in 29..30) {
            assertEquals(
                setOf(BLUETOOTH, BLUETOOTH_ADMIN, ACCESS_FINE_LOCATION),
                nextLinkPermissionRequest(requiredLinkPermissions(sdkInt)).toSet(),
            )
        }
    }

    @Test
    fun afterForegroundGrantsOnlyBackgroundLocationRemains() {
        assertEquals(
            listOf(ACCESS_BACKGROUND_LOCATION),
            nextLinkPermissionRequest(listOf(ACCESS_BACKGROUND_LOCATION)),
        )
    }
}
