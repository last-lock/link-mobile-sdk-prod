package com.example.linkmobile_android_example

import android.app.Application
import com.lastlock.bridge.Bridge

class ExampleApplication: Application() {
    override fun onCreate() {
        super.onCreate()

       val serverAddress = "api.lastlock.seamless.lastlock.com"
        Bridge.init(this, serverAddress)
        Bridge.setLogsEnabled(true)
    }
}