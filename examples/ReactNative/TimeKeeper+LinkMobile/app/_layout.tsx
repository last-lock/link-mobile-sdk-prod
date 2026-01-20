import React, { useEffect, useMemo, useState } from "react";
import { withLayoutContext } from "expo-router";
import { StatusBar } from "react-native";
import { MD3LightTheme, MD3DarkTheme, PaperProvider } from "react-native-paper";
import { GestureHandlerRootView } from "react-native-gesture-handler";
import BridgeModule from '../modules/BridgeModule';
import { Alert } from "react-native";
import { ThemeProvider, useThemeContext } from "@/context/ThemeContext";
import {
  createStackNavigator,
  StackNavigationOptions,
  StackNavigationEventMap,
} from "@react-navigation/stack";
import { ParamListBase, NavigationState } from "@react-navigation/native";
import { CounterProvider } from "@/context/counterContext";
import { BridgeProvider, useBridgeContext } from "@/context/BridgeContext";

const { Navigator } = createStackNavigator();

// TODO: Replace with the correct server address / UUID
const BRIDGE_SERVER = "api.test.example.com";
const BRIDGE_UUID = "AAAA";

export const Stack = withLayoutContext<
  StackNavigationOptions,
  typeof Navigator,
  NavigationState<ParamListBase>,
  StackNavigationEventMap
>(Navigator);

const handleInitialize = async (setScanning: (value: boolean) => void) => {
  try {
    console.log('[Bridge] Initializing bridge...');
    const result = await BridgeModule.initialize(BRIDGE_SERVER, BRIDGE_UUID);
    console.log('[Bridge] Initialize result:', result);
    
    // Start scanning after a short delay to ensure initialization is complete
    setTimeout(async () => {
      try {
        console.log('[Bridge] Starting bridge...');
        const result2 = await BridgeModule.start(BRIDGE_UUID);
        console.log('[Bridge] Start result:', result2);
        console.log('[Bridge] Bridge is now scanning for devices');
        setScanning(true);
      } catch (startError: any) {
        console.error('[Bridge] Start error:', startError);
        // Don't show alert for start errors, just log them
      }
    }, 2000); // Reduced from 10 seconds to 2 seconds
  } catch (error: any) {
    console.error('[Bridge] Initialize error:', error);
    // Only show alert for critical initialization errors
    Alert.alert('Bridge Error', 'Failed to initialize device scanning. Some features may not work properly.');
  }
};

// Your custom interpolator for a popping effect
const forScale = ({ current }: { current: any }) => ({
  cardStyle: {
    opacity: current.progress, // Fade in the card
    transform: [
      {
        scale: current.progress.interpolate({
          inputRange: [0, 1],
          outputRange: [0.9, 1], // Start slightly smaller (0.9) and scale to full size (1)
          extrapolate: "clamp",
        }),
      },
    ],
  },
  overlayStyle: {
    // This creates a dimming effect behind the modal
    opacity: current.progress.interpolate({
      inputRange: [0, 1],
      outputRange: [0, 0.4], // Adjust dimming strength (0.4 for moderate dimming)
      extrapolate: "clamp",
    }),
  },
});

// This component directly contains the Stack Navigator
function RootContent() {
  const { isInitialized, setInitialized, setScanning } = useBridgeContext();
  
  useEffect(() => {
    if (!isInitialized) {
      handleInitialize(setScanning);
      setInitialized(true);
    }
  }, [isInitialized, setInitialized, setScanning]);
  
  const { themeMode } = useThemeContext();

  const theme = useMemo(() => {
    const baseTheme = themeMode === "dark" ? MD3DarkTheme : MD3LightTheme;
    const customColors =
      themeMode === "dark"
        ? { primary: "#85C1E9", secondary: "#424242" }
        : { primary: "#5DADE2", secondary: "lightgrey" };

    return {
      ...baseTheme,
      colors: {
        ...baseTheme.colors,
        ...customColors,
      },
    };
  }, [themeMode]);

  return (
    <PaperProvider theme={theme}>
      <StatusBar
        translucent={true}
        backgroundColor="transparent"
        barStyle={themeMode === "dark" ? "light-content" : "dark-content"}
      />
      <Stack>
        <Stack.Screen
          name="index"
          options={{
            headerShown: false,
          }}
        />
        <Stack.Screen
          name="details"
          options={{
            headerShown: false,
            // Use "transparentModal" to allow the overlayStyle to work
            presentation: "transparentModal",
            cardStyleInterpolator: forScale,
          }}
        />
        <Stack.Screen
          name="add.modal"
          options={{
            headerShown: false,
            cardStyleInterpolator: forScale,

            presentation: "transparentModal",
          }}
        />
      </Stack>
    </PaperProvider>
  );
}

// Default export is what Expo Router renders for this layout
export default function Layout() {
  return (
    <ThemeProvider>
      <BridgeProvider>
        <CounterProvider>
          <GestureHandlerRootView style={{ flex: 1 }}>
            <RootContent />
          </GestureHandlerRootView>
        </CounterProvider>
      </BridgeProvider>
    </ThemeProvider>
  );
}
