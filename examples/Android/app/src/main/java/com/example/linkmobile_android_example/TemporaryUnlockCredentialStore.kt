package com.example.linkmobile_android_example

import android.content.Context
import java.util.UUID

/** Persists the namespace that identifies the SDK-managed temporary credential. */
class TemporaryUnlockCredentialStore(context: Context) {
    private val preferences = context.applicationContext.getSharedPreferences(
        PREFERENCES_NAME,
        Context.MODE_PRIVATE,
    )

    fun existingNamespace(): String? = preferences.getString(NAMESPACE_KEY, null)

    fun getOrCreateNamespace(): String = existingNamespace() ?: UUID.randomUUID().toString().also {
        preferences.edit().putString(NAMESPACE_KEY, it).apply()
    }

    companion object {
        private const val PREFERENCES_NAME = "temporary_unlock_credential"
        private const val NAMESPACE_KEY = "namespace"
    }
}
