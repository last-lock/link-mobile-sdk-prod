import React from 'react';
import { View, StyleSheet, ScrollView } from 'react-native';
import { Text, Card, Title, Paragraph, Chip, Divider, useTheme } from 'react-native-paper';
import { LinearGradient } from 'expo-linear-gradient';
import { useDeviceDiscovery } from '../hooks/useDeviceDiscovery';
import { useBridgeContext } from '../context/BridgeContext';

interface Device {
  identifier: string;
  name?: string;
  rssi?: number;
  connectionStatus?: string;
  signalStrength?: string;
  [key: string]: any;
}

export function DeviceDebugPanel() {
  const devices = useDeviceDiscovery();
  const { isInitialized, isScanning } = useBridgeContext();
  const theme = useTheme();

  console.log('[DeviceDebugPanel] Rendering with devices:', devices);

  const containerStyle = [
    styles.container,
    { backgroundColor: theme.colors.surface, borderColor: theme.colors.outline }
  ];

  const titleStyle = [styles.title, { color: theme.colors.onSurface }];
  const subtitleStyle = [styles.subtitle, { color: theme.colors.onSurfaceVariant }];

  return (
    <Card style={containerStyle} contentStyle={styles.cardContent} mode="outlined">
      <Card.Content style={styles.cardBody}>
        <Title style={titleStyle}>🔍 Device Discovery Debug</Title>
        <View style={styles.statusContainer}>
          <Chip 
            mode="outlined" 
            style={[
              styles.statusChip, 
              { 
                backgroundColor: isInitialized ? theme.colors.primaryContainer : theme.colors.surfaceVariant,
                borderColor: isInitialized ? theme.colors.primary : theme.colors.outline
              }
            ]}
            textStyle={{ color: isInitialized ? theme.colors.onPrimaryContainer : theme.colors.onSurfaceVariant }}
          >
            Bridge: {isInitialized ? 'Initialized' : 'Initializing...'}
          </Chip>
          <Chip 
            mode="outlined" 
            style={[
              styles.statusChip, 
              { 
                backgroundColor: isScanning ? theme.colors.primaryContainer : theme.colors.surfaceVariant,
                borderColor: isScanning ? theme.colors.primary : theme.colors.outline
              }
            ]}
            textStyle={{ color: isScanning ? theme.colors.onPrimaryContainer : theme.colors.onSurfaceVariant }}
          >
            Scanning: {isScanning ? 'Active' : 'Inactive'}
          </Chip>
        </View>
        <Paragraph style={subtitleStyle}>
          Found {devices.length} device{devices.length !== 1 ? 's' : ''}
        </Paragraph>
        
        <Divider style={styles.divider} />
        
        {devices.length === 0 ? (
          <View style={styles.emptyState}>
            <Text style={[styles.emptyText, { color: theme.colors.onSurfaceVariant }]}>
              No devices discovered yet...
            </Text>
            <Text style={[styles.emptySubtext, { color: theme.colors.outline }]}>
              Make sure your bridge is running and devices are discoverable
            </Text>
          </View>
        ) : (
          <View style={styles.deviceListContainer}>
            <ScrollView 
              style={styles.deviceList} 
              contentContainerStyle={styles.deviceListContent}
              showsVerticalScrollIndicator={false}
            >
              {devices.map((device: Device, index: number) => (
                <Card 
                  key={device.identifier || index} 
                  style={[
                    styles.deviceCard,
                    { 
                      backgroundColor: 'transparent',
                      borderColor: theme.colors.outline,
                    }
                  ]}
                  mode="outlined"
                >
                  <LinearGradient
                    colors={[
                      theme.colors.surfaceVariant,
                      theme.colors.surfaceVariant + '80'
                    ]}
                    start={{ x: 0, y: 0 }}
                    end={{ x: 1, y: 1 }}
                    style={styles.gradientBackground}
                  >
                    <Card.Content>
                      <View style={styles.deviceHeader}>
                        <Text style={[styles.deviceName, { color: theme.colors.onSurfaceVariant }]}>
                          {"Device ID: " + device.identifier || 'Unknown Device'}
                        </Text>
                      </View>
                      
                      <View style={styles.propertiesContainer}>
                        <Text style={[styles.propertiesTitle, { color: theme.colors.onSurfaceVariant }]}>
                          Properties:
                        </Text>
                        {Object.entries(device).sort((a, b) => a[0].localeCompare(b[0])).map(([key, value]) => (
                          <View key={key} style={styles.propertyRow}>
                            <Text style={[styles.propertyKey, { color: theme.colors.primary }]}>
                              {key}:
                            </Text>
                            <Text style={[styles.propertyValue, { color: theme.colors.onSurfaceVariant }]}>
                              {typeof value === 'object' 
                                ? JSON.stringify(value, null, 2)
                                : String(value)
                              }
                            </Text>
                          </View>
                        ))}
                      </View>
                    </Card.Content>
                  </LinearGradient>
                </Card>
              ))}
            </ScrollView>
          </View>
        )}
      </Card.Content>
    </Card>
  );
}

const styles = StyleSheet.create({
  container: {
    margin: 16,
    maxHeight: 400,
    overflow: 'hidden',
    elevation: 2,
    shadowColor: '#000',
    shadowOffset: { width: 0, height: 2 },
    shadowOpacity: 0.1,
    shadowRadius: 4,
  },
  cardContent: {
    paddingBottom: 12,
  },
  cardBody: {
    flexGrow: 1,
  },
  title: {
    fontSize: 18,
    fontWeight: 'bold',
    marginBottom: 4,
  },
  subtitle: {
    fontSize: 14,
    marginBottom: 8,
  },
  divider: {
    marginVertical: 12,
  },
  deviceListContainer: {
    maxHeight: 300,
    overflow: 'hidden',
    flexShrink: 1,
  },
  statusContainer: {
    flexDirection: 'row',
    gap: 8,
    marginBottom: 8,
  },
  statusChip: {
    marginRight: 4,
  },
  emptyState: {
    alignItems: 'center',
    paddingVertical: 20,
  },
  emptyText: {
    fontSize: 16,
    marginBottom: 4,
    textAlign: 'center',
  },
  emptySubtext: {
    fontSize: 12,
    textAlign: 'center',
    lineHeight: 16,
  },
  deviceList: {
    flexGrow: 0,
  },
  deviceListContent: {
    paddingBottom: 40,
  },
  deviceCard: {
    marginBottom: 8,
    elevation: 1,
    shadowColor: '#000',
    shadowOffset: { width: 0, height: 1 },
    shadowOpacity: 0.05,
    shadowRadius: 2,
    overflow: 'hidden',
  },
  gradientBackground: {
    borderRadius: 8,
    padding: 10,
  },
  deviceHeader: {
    flexDirection: 'row',
    justifyContent: 'space-between',
    alignItems: 'center',
    marginBottom: 8,
  },
  deviceName: {
    fontSize: 16,
    fontWeight: 'bold',
    flex: 1,
    marginRight: 8,
  },
  identifierChip: {
    // Theme colors applied dynamically
  },
  propertiesContainer: {
    marginTop: 8,
  },
  propertiesTitle: {
    fontSize: 14,
    fontWeight: 'bold',
    marginBottom: 6,
  },
  propertyRow: {
    flexDirection: 'row',
    marginBottom: 4,
    flexWrap: 'wrap',
  },
  propertyKey: {
    fontSize: 12,
    fontWeight: 'bold',
    minWidth: 80,
    marginRight: 8,
  },
  propertyValue: {
    fontSize: 12,
    flex: 1,
    fontFamily: 'monospace',
    lineHeight: 16,
  },
});
