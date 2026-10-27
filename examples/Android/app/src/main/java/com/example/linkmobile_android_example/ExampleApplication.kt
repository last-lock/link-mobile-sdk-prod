package com.example.linkmobile_android_example

import android.app.Application
import com.lastlock.bridge.Bridge

class ExampleApplication: Application() {
    override fun onCreate() {
        super.onCreate()

       val linkAddress = "plane.lastlock.com"
        Bridge.init(this, linkAddress)
        Bridge.setLogsEnabled(true)
    }
}