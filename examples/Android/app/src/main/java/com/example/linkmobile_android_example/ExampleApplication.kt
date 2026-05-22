package com.example.linkmobile_android_example

import android.app.Activity
import android.app.Application
import com.lastlock.bridge.Bridge
import org.koin.android.ext.koin.androidContext
import org.koin.core.context.startKoin

class ExampleApplication: Application() {
    override fun onCreate() {
        super.onCreate()

       val serverAddress = "api.lastlock.seamless.lastlock.com"

        startKoin {
            androidContext(this@ExampleApplication)
        }

        Bridge.init(this, serverAddress)
        Bridge.setLogsEnabled(true)
    }
}