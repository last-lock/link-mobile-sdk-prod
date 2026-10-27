/** Configures Link; defaults to the production hostname plane.lastlock.com. */
export function initialize(serverAddress?: string): Promise<string>;
/** Starts BLE and Proxy; defaults to service UUID FC5A. */
export function start(uuid?: string): Promise<string>;
/** Uses foreground-only service operation on Android and regular start on iOS; defaults to FC5A. */
export function startLimited(uuid?: string): Promise<string>;
export function identify(identifier: string): Promise<boolean>;
export function setLockEngagedState(identifier: string, engaged: boolean): Promise<boolean>;
export function sendOutOfBandPayload(identifier: string, payloadBase64: string): Promise<string>;
export function checkForDFU(identifier: string): Promise<DFUCheck>;
export function startDFU(identifier: string): Promise<string>;
export function cancelDFU(): Promise<string>;
export function waitForDeviceMode(identifier: string, dfuRequired: boolean): Promise<string>;
export function exitDFUInstallMode(identifier: string): Promise<string>;
export function fetchTokenUnlockPublicKey(namespace: string): Promise<string>;
export function storeTokenUnlockPass(
  namespace: string,
  accessDocumentBase64: string,
  readerGroupIdBase64: string,
  issuerCaPublicKeyBase64: string,
  issuerCaCertificateBase64: string,
): Promise<boolean>;
export function tokenUnlock(identifier: string, namespace: string): Promise<string>;

export function onDeviceDiscovered(
  listener: (device: DiscoveredDevice) => void,
): LinkMobileSubscription;
export function onDeviceConnected(
  listener: (device: DeviceEvent) => void,
): LinkMobileSubscription;
export function onDeviceDisconnected(
  listener: (device: DeviceEvent) => void,
): LinkMobileSubscription;
export function onBLEStateChanged(
  listener: (event: BLEState) => void,
): LinkMobileSubscription;
export function onCredentialExchangeResult(
  listener: (event: CredentialResult) => void,
): LinkMobileSubscription;
export function onDFUStateChanged(
  listener: (event: DFUState) => void,
): LinkMobileSubscription;
export function onHeartbeat(
  listener: (event: Heartbeat) => void,
): LinkMobileSubscription;
export function onProxyStreamStateChanged(
  listener: (event: ProxyStreamState) => void,
): LinkMobileSubscription;

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

export type Heartbeat = {
  identifier: string;
  oobTimestamp: number;
};

export type ProxyStreamState = {
  state: string;
};

export type DeviceEvent = {
  identifier: string;
  name: string;
};

export type BLEState = {
  state: boolean;
};

export type CredentialResult = {
  identifier: string;
  name: string;
  result: string;
  message: string;
};

export type DFUCheck = {
  status: string;
  firmwareVersion: string;
  availableVersion: string;
};

export type DFUState = {
  flowState: string;
  installProgress: number;
  postInstallProgress: number;
  dfuAvailable: boolean;
  dfuImageLoading: boolean;
  availableVersion: string;
};

export type LinkMobileSubscription = {
  remove(): void;
};
