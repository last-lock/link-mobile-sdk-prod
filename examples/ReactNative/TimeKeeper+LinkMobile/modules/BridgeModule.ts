import { NativeModules } from 'react-native';

interface BridgeModuleInterface {
  initialize(serverAddress: string, uuid: string): Promise<string>;
  start(uuid: string): Promise<string>;
}

const { BridgeModule } = NativeModules;

if (!BridgeModule) {
  throw new Error(
    'BridgeModule native module is not available. Make sure you have run pod install and rebuilt the app.'
  );
}

export default BridgeModule as BridgeModuleInterface;

