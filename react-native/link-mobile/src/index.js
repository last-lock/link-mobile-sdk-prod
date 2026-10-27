import {TurboModuleRegistry} from 'react-native';

function native() {
  const module = TurboModuleRegistry.get('LinkMobile');
  if (!module) {
    throw new Error(
      'LinkMobile native module is not available. Rebuild the app after installing @last-lock/link-mobile.',
    );
  }
  return module;
}

export function initialize(serverAddress = 'plane.lastlock.com') {
  return native().initialize(serverAddress);
}

export function start(uuid = 'FC5A') {
  return native().start(uuid);
}

export function startLimited(uuid = 'FC5A') {
  return native().startLimited(uuid);
}

export function identify(identifier) {
  return native().identify(identifier);
}

export function setLockEngagedState(identifier, engaged) {
  return native().setLockEngagedState(identifier, engaged);
}

export function sendOutOfBandPayload(identifier, payloadBase64) {
  return native().sendOutOfBandPayload(identifier, payloadBase64);
}

export function checkForDFU(identifier) {
  return native().checkForDFU(identifier);
}

export function startDFU(identifier) {
  return native().startDFU(identifier);
}

export function cancelDFU() {
  return native().cancelDFU();
}

export function waitForDeviceMode(identifier, dfuRequired) {
  return native().waitForDeviceMode(identifier, dfuRequired);
}

export function exitDFUInstallMode(identifier) {
  return native().exitDFUInstallMode(identifier);
}

export function fetchTokenUnlockPublicKey(namespace) {
  return native().fetchTokenUnlockPublicKey(namespace);
}

export function storeTokenUnlockPass(
  namespace,
  accessDocumentBase64,
  readerGroupIdBase64,
  issuerCaPublicKeyBase64,
  issuerCaCertificateBase64,
) {
  return native().storeTokenUnlockPass(
    namespace,
    accessDocumentBase64,
    readerGroupIdBase64,
    issuerCaPublicKeyBase64,
    issuerCaCertificateBase64,
  );
}

export function tokenUnlock(identifier, namespace) {
  return native().tokenUnlock(identifier, namespace);
}

export function onDeviceDiscovered(listener) {
  return native().onDeviceDiscovered(listener);
}

export function onDeviceConnected(listener) {
  return native().onDeviceConnected(listener);
}

export function onDeviceDisconnected(listener) {
  return native().onDeviceDisconnected(listener);
}

export function onBLEStateChanged(listener) {
  return native().onBLEStateChanged(listener);
}

export function onCredentialExchangeResult(listener) {
  return native().onCredentialExchangeResult(listener);
}

export function onDFUStateChanged(listener) {
  return native().onDFUStateChanged(listener);
}

export function onHeartbeat(listener) {
  return native().onHeartbeat(listener);
}

export function onProxyStreamStateChanged(listener) {
  return native().onProxyStreamStateChanged(listener);
}
