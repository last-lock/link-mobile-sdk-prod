import React from 'react';
import { NativeEventEmitter, NativeModules } from 'react-native';

const { BridgeModule } = NativeModules;
const bridgeEmitter = new NativeEventEmitter(BridgeModule);

interface Device {
  identifier: string;
  name?: string;
  rssi?: number;
  connectionStatus?: string;
  signalStrength?: string;
  [key: string]: any;
}

export function useDeviceDiscovery() {
  const [devices, setDevices] = React.useState<Device[]>([]);

  React.useEffect(() => {
    const discoveredListener = bridgeEmitter.addListener('onDeviceDiscovered', (event) => {
      console.log('Device discovered:', event);
      setDevices((prev) => {
        const existingIndex = prev.findIndex((d) => d.identifier === event.identifier);
        if (existingIndex >= 0) {
          // Update existing device with new properties
          console.log('Updating existing device at index:', existingIndex);
          const updatedDevices = [...prev];
          updatedDevices[existingIndex] = event;
          console.log('Updated devices array:', updatedDevices);
          return updatedDevices;
        } else {
          // Add new device
          console.log('Adding new device');
          const newDevices = [...prev, event];
          console.log('New devices array:', newDevices);
          return newDevices;
        }
      });
    });

    const connectedListener = bridgeEmitter.addListener('onDeviceConnected', (event) => {
      console.log('Device connected:', event);
    });

    const disconnectedListener = bridgeEmitter.addListener('onDeviceDisconnected', (event) => {
      console.log('Device disconnected:', event);
    });

    return () => {
      discoveredListener.remove();
      connectedListener.remove();
      disconnectedListener.remove();
    };
  }, []);

  return devices;
}
