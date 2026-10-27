package com.lastlock.linkmobile

import com.facebook.react.BaseReactPackage
import com.facebook.react.bridge.NativeModule
import com.facebook.react.bridge.ReactApplicationContext
import com.facebook.react.module.model.ReactModuleInfo
import com.facebook.react.module.model.ReactModuleInfoProvider

class LinkMobilePackage : BaseReactPackage() {
  override fun getModule(name: String, reactContext: ReactApplicationContext): NativeModule? {
    return if (name == LinkMobileModule.NAME) LinkMobileModule(reactContext) else null
  }

  override fun getReactModuleInfoProvider(): ReactModuleInfoProvider {
    return ReactModuleInfoProvider {
      mapOf(
        LinkMobileModule.NAME to
          ReactModuleInfo(
            LinkMobileModule.NAME,
            LinkMobileModule::class.java.name,
            false,
            false,
            false,
            true,
          ),
      )
    }
  }
}
