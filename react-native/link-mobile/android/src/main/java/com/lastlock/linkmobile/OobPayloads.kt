package com.lastlock.linkmobile

import java.io.ByteArrayOutputStream

/**
 * Builds the same unsigned out-of-band wrapper the Seamless app sends for identify and
 * lock-engaged commands. The signature is 64 0xFF bytes and the bridge timestamp is 1.
 */
internal object OobPayloads {
  fun identify(deviceId: UInt): ByteArray {
    return wrapper(operation(deviceId, fieldNumber = 9, value = 1))
  }

  fun lockEngaged(deviceId: UInt, engaged: Boolean): ByteArray {
    return wrapper(operation(deviceId, fieldNumber = 11, value = if (engaged) 1 else 2))
  }

  /** InstallMode.reboot, the command that reboots a lock out of DFU. */
  fun installReboot(deviceId: UInt): ByteArray {
    val installMode = ByteArrayOutputStream()
    writeKey(installMode, 2, 0)
    writeVarint(installMode, 1)
    val operation = ByteArrayOutputStream()
    writeKey(operation, 1, 0)
    writeVarint(operation, deviceId.toLong())
    writeBytesField(operation, 7, installMode.toByteArray())
    return wrapper(operation.toByteArray())
  }

  private fun operation(deviceId: UInt, fieldNumber: Int, value: Int): ByteArray {
    val out = ByteArrayOutputStream()
    writeKey(out, 1, 0)
    writeVarint(out, deviceId.toLong())
    writeKey(out, fieldNumber, 0)
    writeVarint(out, value.toLong())
    return out.toByteArray()
  }

  private fun wrapper(operation: ByteArray): ByteArray {
    val out = ByteArrayOutputStream()
    writeBytesField(out, 1, operation)
    writeBytesField(out, 2, ByteArray(64) { 0xFF.toByte() })
    writeKey(out, 3, 0)
    writeVarint(out, 1)
    return out.toByteArray()
  }

  private fun writeBytesField(out: ByteArrayOutputStream, fieldNumber: Int, bytes: ByteArray) {
    writeKey(out, fieldNumber, 2)
    writeVarint(out, bytes.size.toLong())
    out.write(bytes)
  }

  private fun writeKey(out: ByteArrayOutputStream, fieldNumber: Int, wireType: Int) {
    writeVarint(out, ((fieldNumber shl 3) or wireType).toLong())
  }

  private fun writeVarint(out: ByteArrayOutputStream, value: Long) {
    var remaining = value
    while (remaining and 0x7FL.inv() != 0L) {
      out.write(((remaining and 0x7F) or 0x80).toInt())
      remaining = remaining ushr 7
    }
    out.write(remaining.toInt())
  }
}
