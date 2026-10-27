import React from 'react';
import {
  onBLEStateChanged,
  onDeviceConnected,
  onDeviceDisconnected,
  onDeviceDiscovered,
  onHeartbeat,
} from '@last-lock/link-mobile';

interface Device {
  identifier: string;
  name?: string;
  rssi?: number;
  connectionStatus?: string;
  signalStrength?: string;
}

export function useDeviceDiscovery() {
  const [devices, setDevices] = React.useState<Device[]>([]);

  React.useEffect(() => {
    const bleStateListener = onBLEStateChanged((event) => {
      console.log('BLE state:', event?.state);
    });

    const discoveredListener = onDeviceDiscovered((event) => {
      console.log('Device discovered:', event);
      setDevices((prev) => {
        const existingIndex = prev.findIndex((device) => device.identifier === event.identifier);
        if (existingIndex >= 0) {
          const updatedDevices = [...prev];
          updatedDevices[existingIndex] = event;
          return updatedDevices;
        }
        return [...prev, event];
      });
    });

    const connectedListener = onDeviceConnected((event) => {
      console.log('Device connected:', event);
    });

    const disconnectedListener = onDeviceDisconnected((event) => {
      console.log('Device disconnected:', event);
    });

    const heartbeatListener = onHeartbeat((event) => {
      setDevices((prev) =>
        prev.map((device) =>
          device.identifier === event.identifier ? {...device, oobTimestamp: event.oobTimestamp} : device,
        ),
      );
    });

    return () => {
      bleStateListener.remove();
      discoveredListener.remove();
      connectedListener.remove();
      disconnectedListener.remove();
      heartbeatListener.remove();
    };
  }, []);

  return devices;
}
