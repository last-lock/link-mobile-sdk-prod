import type {CodegenTypes, TurboModule} from 'react-native';
import {TurboModuleRegistry} from 'react-native';

/**
 * A lock seen in a BLE advertisement. `identifier` is the device id from the
 * advertising packet, not the Bluetooth address. The boolean flags and state
 * counters are parsed from that advertisement. `oobTimestamp` is the last
 * out-of-band server timestamp observed for this lock, or 0.
 * Delivered by `onDeviceDiscovered`.
 */
export type DiscoveredDevice = {
  identifier: string;
  name: string;
  rssi: number;
  connectionStatus: string;
  signalStrength: string;
  installMode: boolean;
  dfuMode: boolean;
  hibernate: boolean;
  serviceMode: boolean;
  lowBattery: boolean;
  criticalBattery: boolean;
  cooldown: boolean;
  emergency: boolean;
  busy: boolean;
  timeSyncRequest: boolean;
  overridingMode: string;
  deviceStateCounter: number;
  serverStateCounter: number;
  oobTimestamp: number;
};

/**
 * A heartbeat from a connected lock. `oobTimestamp` is the lock's last
 * out-of-band server timestamp. Delivered by `onHeartbeat`.
 */
export type Heartbeat = {
  identifier: string;
  oobTimestamp: number;
};

/**
 * Plane proxy stream liveness. `state` is `connected` or `disconnected`.
 * Delivered by `onProxyStreamStateChanged`.
 */
export type ProxyStreamState = {
  state: string;
};

/**
 * A lock that connected or disconnected. Delivered by `onDeviceConnected`
 * and `onDeviceDisconnected`.
 */
export type DeviceEvent = {
  identifier: string;
  name: string;
};

/**
 * Bluetooth radio state. `state` is true when the radio is on.
 * Delivered by `onBLEStateChanged`.
 */
export type BLEState = {
  state: boolean;
};

/**
 * Outcome of a token unlock. `result` is the SDK credential-exchange result
 * name, such as `ACCESS_GRANTED` or `TIMEOUT`. `message` is the same result
 * rendered as text. Delivered by `onCredentialExchangeResult`.
 */
export type CredentialResult = {
  identifier: string;
  name: string;
  result: string;
  message: string;
};

/**
 * Result of `checkForDFU`. `status` is `update_available`, `up_to_date`, or
 * `timeout`. Version strings are empty when the check times out.
 */
export type DFUCheck = {
  status: string;
  firmwareVersion: string;
  availableVersion: string;
};

/**
 * Firmware update progress. `flowState` is the SDK DFU flow name.
 * Progress values run from 0 to 1. Delivered by `onDFUStateChanged`.
 */
export type DFUState = {
  flowState: string;
  installProgress: number;
  postInstallProgress: number;
  dfuAvailable: boolean;
  dfuImageLoading: boolean;
  availableVersion: string;
};

export interface Spec extends TurboModule {
  /** Stores the plane host. Does not start scanning. */
  initialize(serverAddress: string): Promise<string>;
  /** Starts, or restarts, a BLE scan for a 4-character service UUID. */
  start(uuid: string): Promise<string>;
  /** Uses foreground-only service operation on Android and regular start on iOS. */
  startLimited(uuid: string): Promise<string>;
  /** Queues an identify payload for a discovered lock. */
  identify(identifier: string): Promise<boolean>;
  /** Queues a lock-engaged or lock-disengaged payload. */
  setLockEngagedState(identifier: string, engaged: boolean): Promise<boolean>;
  /** Queues a caller-supplied out-of-band payload. `payloadBase64` is standard base64. */
  sendOutOfBandPayload(identifier: string, payloadBase64: string): Promise<string>;
  /** Asks the plane whether a firmware image is available for this lock. */
  checkForDFU(identifier: string): Promise<DFUCheck>;
  /** Starts DFU after `checkForDFU` reported `update_available` for this lock. */
  startDFU(identifier: string): Promise<string>;
  /** Cancels an in-progress firmware update. */
  cancelDFU(): Promise<string>;
  /** Waits until the lock advertisement shows install mode, or DFU mode when `dfuRequired` is true. */
  waitForDeviceMode(identifier: string, dfuRequired: boolean): Promise<string>;
  /** Sends the DFU reboot and waits for the lock to leave install mode. */
  exitDFUInstallMode(identifier: string): Promise<string>;
  /** Returns the token-unlock public key for `tokenNamespace`, as base64. */
  fetchTokenUnlockPublicKey(tokenNamespace: string): Promise<string>;
  /** Stores a token-unlock pass. Every material argument is base64. */
  storeTokenUnlockPass(
    tokenNamespace: string,
    accessDocumentBase64: string,
    readerGroupIdBase64: string,
    issuerCaPublicKeyBase64: string,
    issuerCaCertificateBase64: string,
  ): Promise<boolean>;
  /** Presents the stored pass for `tokenNamespace` to a discovered lock. */
  tokenUnlock(identifier: string, tokenNamespace: string): Promise<string>;
  readonly onDeviceDiscovered: CodegenTypes.EventEmitter<DiscoveredDevice>;
  readonly onDeviceConnected: CodegenTypes.EventEmitter<DeviceEvent>;
  readonly onDeviceDisconnected: CodegenTypes.EventEmitter<DeviceEvent>;
  readonly onBLEStateChanged: CodegenTypes.EventEmitter<BLEState>;
  readonly onCredentialExchangeResult: CodegenTypes.EventEmitter<CredentialResult>;
  readonly onDFUStateChanged: CodegenTypes.EventEmitter<DFUState>;
  readonly onHeartbeat: CodegenTypes.EventEmitter<Heartbeat>;
  readonly onProxyStreamStateChanged: CodegenTypes.EventEmitter<ProxyStreamState>;
}

export default TurboModuleRegistry.getEnforcing<Spec>('LinkMobile');
