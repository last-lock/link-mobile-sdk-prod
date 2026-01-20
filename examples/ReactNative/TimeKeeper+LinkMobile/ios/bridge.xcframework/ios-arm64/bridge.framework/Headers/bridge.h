#import <Foundation/NSArray.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSError.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSString.h>
#import <Foundation/NSValue.h>

@class BridgeBLEErrorCodes, BridgeBLEProxy, BridgeBLEProxyCompanion, BridgeBLEStaticValues, BridgeBlueLink, BridgeBlueLinkActiveOperationType, BridgeBlueLinkCompanion, BridgeBlueLinkDeviceConnectionStatus, BridgeBlueLinkEventListener, BridgeBlueLinkOperation, BridgeBlueLinkOperationCompanion, BridgeBlueLinkOperationError, BridgeBlueLinkOperationType, BridgeBluetoothAdvertisement, BridgeBluetoothAdvertisementCompanion, BridgeBluetoothAdvertisementSignalingByte, BridgeBluetoothDevice, BridgeBluetoothGattCharacteristic, BridgeBridgeCache, BridgeBridgeCacheCompanion, BridgeCrashData, BridgeCrashDataCompanion, BridgeDFUDevice, BridgeDFUErrors, BridgeDFUResponse, BridgeDFUService, BridgeDFUServiceCompanion, BridgeDFUState, BridgeDeviceFirmwareVersion, BridgeDeviceFirmwareVersionCompanion, BridgeDeviceGeneratedPersistedPayload, BridgeDeviceGeneratedPersistedPayloadCompanion, BridgeDeviceOperation, BridgeDeviceTaskExecutor, BridgeFileEntry, BridgeFileEntryCompanion, BridgeFilePayload, BridgeFileUtils, BridgeFragmentedPayloadType, BridgeHeartbeatData, BridgeIsolatedKoinContext, BridgeKoin_coreBeanDefinition<T>, BridgeKoin_coreCallbacks<T>, BridgeKoin_coreExtensionManager, BridgeKoin_coreInstanceFactory<T>, BridgeKoin_coreInstanceFactoryCompanion, BridgeKoin_coreInstanceRegistry, BridgeKoin_coreKind, BridgeKoin_coreKoin, BridgeKoin_coreKoinApplication, BridgeKoin_coreKoinApplicationCompanion, BridgeKoin_coreKoinDefinition<R>, BridgeKoin_coreLevel, BridgeKoin_coreLockable, BridgeKoin_coreLogger, BridgeKoin_coreModule, BridgeKoin_coreParametersHolder, BridgeKoin_corePropertyRegistry, BridgeKoin_coreResolutionContext, BridgeKoin_coreScope, BridgeKoin_coreScopeDSL, BridgeKoin_coreScopeRegistry, BridgeKoin_coreScopeRegistryCompanion, BridgeKoin_coreSingleInstanceFactory<T>, BridgeKotlinArray<T>, BridgeKotlinByteArray, BridgeKotlinByteIterator, BridgeKotlinCancellationException, BridgeKotlinEnum<E>, BridgeKotlinEnumCompanion, BridgeKotlinException, BridgeKotlinIllegalStateException, BridgeKotlinLazyThreadSafetyMode, BridgeKotlinNothing, BridgeKotlinPair<__covariant A, __covariant B>, BridgeKotlinRuntimeException, BridgeKotlinThrowable, BridgeKotlinUnit, BridgeKotlinx_datetimeInstant, BridgeKotlinx_datetimeInstantCompanion, BridgeKotlinx_serialization_coreSerialKind, BridgeKotlinx_serialization_coreSerializersModule, BridgeLogger, BridgeManifest, BridgeManifestCompanion, BridgeNetworkConnectivityManagerModule, BridgeNetworkConnectivityMonitor, BridgeOperationState, BridgePacketVersion, BridgeParsedManifest, BridgePersistedLibraryCrashLog, BridgePersistedLibraryCrashLogCompanion, BridgePersistenceManager, BridgePersistenceManagerCompanion, BridgePlatform, BridgeProxyDevice, BridgeProxyDeviceCompanion, BridgeServerGeneratedPersistedPayload, BridgeServerGeneratedPersistedPayloadCompanion, BridgeServerResponse, BridgeServerResponseCompanion, BridgeServerResponseStateUpdate, BridgeServerResponseStateUpdateCompanion, BridgeSignalStrength, BridgeStates, BridgeStatesCompanion, BridgeStreamState, BridgeTaskElement, BridgeTaskElementCompanion, BridgeTaskElementState, BridgeTaskQueue, BridgeTaskQueueCompanion, BridgeUUID, BridgeUUIDCompanion, BridgeUUIDSerializer, BridgeUUIDUtils, CBCharacteristic, CBPeripheral, CBUUID;

@protocol BridgeBridgeTelemetryService, BridgeConnectivityListener, BridgeDFUDriverImplementation, BridgeDFUServiceListener, BridgeGRPCDFUImageManager, BridgeIHeartbeatParser, BridgeIOSMessageStreamManager, BridgeITrueTimeManager, BridgeKoin_coreKoinComponent, BridgeKoin_coreKoinExtension, BridgeKoin_coreKoinScopeComponent, BridgeKoin_coreQualifier, BridgeKoin_coreScopeCallback, BridgeKotlinAnnotation, BridgeKotlinAppendable, BridgeKotlinComparable, BridgeKotlinCoroutineContext, BridgeKotlinCoroutineContextElement, BridgeKotlinCoroutineContextKey, BridgeKotlinFunction, BridgeKotlinIterator, BridgeKotlinKAnnotatedElement, BridgeKotlinKClass, BridgeKotlinKClassifier, BridgeKotlinKDeclarationContainer, BridgeKotlinLazy, BridgeKotlinSequence, BridgeKotlinSuspendFunction0, BridgeKotlinx_coroutines_coreChildHandle, BridgeKotlinx_coroutines_coreChildJob, BridgeKotlinx_coroutines_coreCoroutineScope, BridgeKotlinx_coroutines_coreDisposableHandle, BridgeKotlinx_coroutines_coreFlow, BridgeKotlinx_coroutines_coreFlowCollector, BridgeKotlinx_coroutines_coreJob, BridgeKotlinx_coroutines_coreMutableSharedFlow, BridgeKotlinx_coroutines_coreMutableStateFlow, BridgeKotlinx_coroutines_coreMutex, BridgeKotlinx_coroutines_coreParentJob, BridgeKotlinx_coroutines_coreSelectClause, BridgeKotlinx_coroutines_coreSelectClause0, BridgeKotlinx_coroutines_coreSelectClause2, BridgeKotlinx_coroutines_coreSelectInstance, BridgeKotlinx_coroutines_coreSharedFlow, BridgeKotlinx_coroutines_coreStateFlow, BridgeKotlinx_datetimeDateTimeFormat, BridgeKotlinx_serialization_coreCompositeDecoder, BridgeKotlinx_serialization_coreCompositeEncoder, BridgeKotlinx_serialization_coreDecoder, BridgeKotlinx_serialization_coreDeserializationStrategy, BridgeKotlinx_serialization_coreEncoder, BridgeKotlinx_serialization_coreKSerializer, BridgeKotlinx_serialization_coreSerialDescriptor, BridgeKotlinx_serialization_coreSerializationStrategy, BridgeKotlinx_serialization_coreSerializersModuleCollector, BridgeMessageStreamManager, BridgeOOBWrapper, BridgeZipPackageInterface;

NS_ASSUME_NONNULL_BEGIN
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wincompatible-property-type"
#pragma clang diagnostic ignored "-Wnullability"

#pragma push_macro("_Nullable_result")
#if !__has_feature(nullability_nullable_result)
#undef _Nullable_result
#define _Nullable_result _Nullable
#endif

__attribute__((swift_name("KotlinBase")))
@interface BridgeBase : NSObject
- (instancetype)init __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (void)initialize __attribute__((objc_requires_super));
@end

@interface BridgeBase (BridgeBaseCopying) <NSCopying>
@end

__attribute__((swift_name("KotlinMutableSet")))
@interface BridgeMutableSet<ObjectType> : NSMutableSet<ObjectType>
@end

__attribute__((swift_name("KotlinMutableDictionary")))
@interface BridgeMutableDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>
@end

@interface NSError (NSErrorBridgeKotlinException)
@property (readonly) id _Nullable kotlinException;
@end

__attribute__((swift_name("KotlinNumber")))
@interface BridgeNumber : NSNumber
- (instancetype)initWithChar:(char)value __attribute__((unavailable));
- (instancetype)initWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
- (instancetype)initWithShort:(short)value __attribute__((unavailable));
- (instancetype)initWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
- (instancetype)initWithInt:(int)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
- (instancetype)initWithLong:(long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
- (instancetype)initWithLongLong:(long long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
- (instancetype)initWithFloat:(float)value __attribute__((unavailable));
- (instancetype)initWithDouble:(double)value __attribute__((unavailable));
- (instancetype)initWithBool:(BOOL)value __attribute__((unavailable));
- (instancetype)initWithInteger:(NSInteger)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
+ (instancetype)numberWithChar:(char)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
+ (instancetype)numberWithShort:(short)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
+ (instancetype)numberWithInt:(int)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
+ (instancetype)numberWithLong:(long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
+ (instancetype)numberWithLongLong:(long long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
+ (instancetype)numberWithFloat:(float)value __attribute__((unavailable));
+ (instancetype)numberWithDouble:(double)value __attribute__((unavailable));
+ (instancetype)numberWithBool:(BOOL)value __attribute__((unavailable));
+ (instancetype)numberWithInteger:(NSInteger)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
@end

__attribute__((swift_name("KotlinByte")))
@interface BridgeByte : BridgeNumber
- (instancetype)initWithChar:(char)value;
+ (instancetype)numberWithChar:(char)value;
@end

__attribute__((swift_name("KotlinUByte")))
@interface BridgeUByte : BridgeNumber
- (instancetype)initWithUnsignedChar:(unsigned char)value;
+ (instancetype)numberWithUnsignedChar:(unsigned char)value;
@end

__attribute__((swift_name("KotlinShort")))
@interface BridgeShort : BridgeNumber
- (instancetype)initWithShort:(short)value;
+ (instancetype)numberWithShort:(short)value;
@end

__attribute__((swift_name("KotlinUShort")))
@interface BridgeUShort : BridgeNumber
- (instancetype)initWithUnsignedShort:(unsigned short)value;
+ (instancetype)numberWithUnsignedShort:(unsigned short)value;
@end

__attribute__((swift_name("KotlinInt")))
@interface BridgeInt : BridgeNumber
- (instancetype)initWithInt:(int)value;
+ (instancetype)numberWithInt:(int)value;
@end

__attribute__((swift_name("KotlinUInt")))
@interface BridgeUInt : BridgeNumber
- (instancetype)initWithUnsignedInt:(unsigned int)value;
+ (instancetype)numberWithUnsignedInt:(unsigned int)value;
@end

__attribute__((swift_name("KotlinLong")))
@interface BridgeLong : BridgeNumber
- (instancetype)initWithLongLong:(long long)value;
+ (instancetype)numberWithLongLong:(long long)value;
@end

__attribute__((swift_name("KotlinULong")))
@interface BridgeULong : BridgeNumber
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value;
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value;
@end

__attribute__((swift_name("KotlinFloat")))
@interface BridgeFloat : BridgeNumber
- (instancetype)initWithFloat:(float)value;
+ (instancetype)numberWithFloat:(float)value;
@end

__attribute__((swift_name("KotlinDouble")))
@interface BridgeDouble : BridgeNumber
- (instancetype)initWithDouble:(double)value;
+ (instancetype)numberWithDouble:(double)value;
@end

__attribute__((swift_name("KotlinBoolean")))
@interface BridgeBoolean : BridgeNumber
- (instancetype)initWithBool:(BOOL)value;
+ (instancetype)numberWithBool:(BOOL)value;
@end


/**
 * IBridge provides a unified interface for accessing core Bluetooth-related services
 * within the Bridge architecture. Implementations of this interface are responsible
 * for managing the lifecycle and providing access to BlueLink, BLEProxy, and DFUService instances.
 *
 * Note: PKOC services are not included in this interface due to differing types across platforms.
 *
 * Implementations are typically provided via a Koin isolated context to ensure proper dependency
 * management and lifecycle isolation for each bridge instance.
 */
__attribute__((swift_name("IBridge")))
@protocol BridgeIBridge
@required

/**
 * Returns the BLEProxy service instance.
 */
- (BridgeBLEProxy *)getBLEProxy __attribute__((swift_name("getBLEProxy()")));

/**
 * Returns the BlueLink service instance.
 */
- (BridgeBlueLink *)getBlueLink __attribute__((swift_name("getBlueLink()")));

/**
 * Returns the DFUService instance.
 */
- (BridgeDFUService *)getDFUService __attribute__((swift_name("getDFUService()")));

/**
 * Enable or disable library logs
 */
- (void)setLogsEnabledIsEnabled:(BOOL)isEnabled __attribute__((swift_name("setLogsEnabled(isEnabled:)")));
@end

__attribute__((swift_name("KotlinComparable")))
@protocol BridgeKotlinComparable
@required
- (int32_t)compareToOther:(id _Nullable)other __attribute__((swift_name("compareTo(other:)")));
@end

__attribute__((swift_name("KotlinEnum")))
@interface BridgeKotlinEnum<E> : BridgeBase <BridgeKotlinComparable>
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) BridgeKotlinEnumCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(E)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) int32_t ordinal __attribute__((swift_name("ordinal")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BLEErrorCodes")))
@interface BridgeBLEErrorCodes : BridgeKotlinEnum<BridgeBLEErrorCodes *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) BridgeBLEErrorCodes *bleErrorNoConnectableDevice __attribute__((swift_name("bleErrorNoConnectableDevice")));
@property (class, readonly) BridgeBLEErrorCodes *bleErrorProcedureInProgress __attribute__((swift_name("bleErrorProcedureInProgress")));
@property (class, readonly) BridgeBLEErrorCodes *bleErrorUnlikely __attribute__((swift_name("bleErrorUnlikely")));
@property (class, readonly) BridgeBLEErrorCodes *bleErrorInsufResource __attribute__((swift_name("bleErrorInsufResource")));
+ (BridgeKotlinArray<BridgeBLEErrorCodes *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<BridgeBLEErrorCodes *> *entries __attribute__((swift_name("entries")));
@property (readonly) int32_t value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BLEStaticValues")))
@interface BridgeBLEStaticValues : BridgeKotlinEnum<BridgeBLEStaticValues *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) BridgeBLEStaticValues *defaultMtuSize __attribute__((swift_name("defaultMtuSize")));
@property (class, readonly) BridgeBLEStaticValues *bleErrorDelayRetryMs __attribute__((swift_name("bleErrorDelayRetryMs")));
@property (class, readonly) BridgeBLEStaticValues *bleErrorInsufDelayRetryMs __attribute__((swift_name("bleErrorInsufDelayRetryMs")));
+ (BridgeKotlinArray<BridgeBLEStaticValues *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<BridgeBLEStaticValues *> *entries __attribute__((swift_name("entries")));
@property (readonly) int32_t value __attribute__((swift_name("value")));
@end


/**
 * BlueLink class - Acts as an interface between the BlueLink library and implementers.
 *
 * Handles device discovery, connection management, and BLE read/write operations,
 * abstracting the details of BLE communication and fragmentation.
 *
 * If a read or write operation is performed for a characteristic that is not present in the device,
 * an appropriate BlueLinkOpFailReason will be returned. Implementation on handling of these failed
 * scenarios is left up to the implementors. Once the implementor has handled the failing operation,
 * it must call completeOperation() to mark the failed operation as complete
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BlueLink")))
@interface BridgeBlueLink : BridgeBase
- (instancetype)initWithIOSIHeartbeatParser:(id<BridgeIHeartbeatParser> _Nullable)iOSIHeartbeatParser __attribute__((swift_name("init(iOSIHeartbeatParser:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) BridgeBlueLinkCompanion *companion __attribute__((swift_name("companion")));
- (void)addListenerListener:(BridgeBlueLinkEventListener *)listener prependListener:(BOOL)prependListener __attribute__((swift_name("addListener(listener:prependListener:)")));
- (void)completeActiveOperationDevice:(BridgeBluetoothDevice *)device __attribute__((swift_name("completeActiveOperation(device:)")));
- (void)connectToDeviceId:(uint32_t)deviceId persistConnection:(BOOL)persistConnection __attribute__((swift_name("connectTo(deviceId:persistConnection:)")));
- (void)disconnectPeripheral:(BridgeBluetoothDevice *)peripheral __attribute__((swift_name("disconnect(peripheral:)")));
- (BridgeDeviceFirmwareVersion * _Nullable)getFirmwareVersionDevice:(BridgeBluetoothDevice *)device __attribute__((swift_name("getFirmwareVersion(device:)")));
- (BridgeSignalStrength *)getSignalStrengthForDeviceDeviceId:(NSString *)deviceId __attribute__((swift_name("getSignalStrengthForDevice(deviceId:)")));
- (id _Nullable)getiOSCentralManager __attribute__((swift_name("getiOSCentralManager()")));
- (void)operationCompleteDevice:(BridgeBluetoothDevice *)device operation:(BridgeBlueLinkOperation *)operation __attribute__((swift_name("operationComplete(device:operation:)")));
- (void)queueOperationDevice:(BridgeBluetoothDevice *)device operation:(BridgeBlueLinkOperation *)operation __attribute__((swift_name("queueOperation(device:operation:)")));

/**
 * Reads data from a characteristic on the specified peripheral. Performs a BLE read operation
 * from the peripheral while also maintaining an active BLE Read operation. To be used in places
 * where multiple BLE reads are required for an operation to complete (eg: fragmented proxy
 * read)
 * @return BlueLinkOperationFailReason if the operation fails, otherwise null
 */
- (BridgeBlueLinkOperationError * _Nullable)readFromPeripheralAndAssignActiveOperationDevice:(BridgeBluetoothDevice *)device characteristicUUID:(BridgeUUID *)characteristicUUID fragmentation:(BOOL)fragmentation operationType:(BridgeBlueLinkOperationType *)operationType __attribute__((swift_name("readFromPeripheralAndAssignActiveOperation(device:characteristicUUID:fragmentation:operationType:)")));
- (void)removeListenerListener:(BridgeBlueLinkEventListener *)listener __attribute__((swift_name("removeListener(listener:)")));
- (void)removeOperationsDeviceId:(uint32_t)deviceId credentialExchangeOp:(BOOL)credentialExchangeOp proxyOp:(BOOL)proxyOp credLinkTimeSyncOp:(BridgeBoolean * _Nullable)credLinkTimeSyncOp __attribute__((swift_name("removeOperations(deviceId:credentialExchangeOp:proxyOp:credLinkTimeSyncOp:)")));

/**
 * Configures indications for a given characteristic.
 * @return BlueLinkOperationFailReason if the operation fails, otherwise null
 */
- (BridgeBlueLinkOperationError * _Nullable)setIndicationConfigDevice:(BridgeBluetoothDevice *)device characteristicUUID:(NSString *)characteristicUUID __attribute__((swift_name("setIndicationConfig(device:characteristicUUID:)")));

/**
 * Configures notifications for a given characteristic.
 * @return BlueLinkOperationFailReason if the operation fails
 */
- (BridgeBlueLinkOperationError * _Nullable)setNotificationConfigDevice:(BridgeBluetoothDevice *)device characteristicUUID:(NSString *)characteristicUUID __attribute__((swift_name("setNotificationConfig(device:characteristicUUID:)")));
- (void)setPersistConnectionDeviceId:(uint32_t)deviceId persistConnection:(BOOL)persistConnection __attribute__((swift_name("setPersistConnection(deviceId:persistConnection:)")));

/**
 * Writes data to a characteristic on the specified peripheral, provided characteristic exists
 * on peripheral to write
 * @return BlueLinkOperationFailReason if the operation fails, otherwise null
 */
- (BridgeBlueLinkOperationError * _Nullable)startActiveWriteOperationDevice:(BridgeBluetoothDevice *)device characteristicUUID:(BridgeUUID *)characteristicUUID payload:(BridgeKotlinByteArray *)payload fragmentation:(BOOL)fragmentation operationType:(BridgeBlueLinkOperationType *)operationType __attribute__((swift_name("startActiveWriteOperation(device:characteristicUUID:payload:fragmentation:operationType:)")));

/** Starts scanning for BLE peripherals. */
- (void)startBLEScanServiceUUIDs:(NSArray<BridgeUUID *> *)serviceUUIDs extraOptions:(NSDictionary<id, id> * _Nullable)extraOptions __attribute__((swift_name("startBLEScan(serviceUUIDs:extraOptions:)")));

/**
 * Actively begins the heartbeat procedure for all connected devices at an interval specified in BlueLink.
 *
 * Note: The role of this function is to ONLY queue Heartbeat operations in BlueLink. Execution
 * of the operations will be controlled by BlueLink and will happen over the course of its
 * operation
 */
- (void)startHeartbeatJob __attribute__((swift_name("startHeartbeatJob()")));

/** Stops scanning for BLE peripherals. */
- (void)stopBLEScan __attribute__((swift_name("stopBLEScan()")));

/**
 * To be invoked when all devices are disconnected from the bridge; stops any ongoing heartbeat job
 */
- (void)stopHeartbeatJob __attribute__((swift_name("stopHeartbeatJob()")));

/**
 * Purely writes the payloads to the provided device, provided that the characteristic to write
 * exists on the device. To be used or simple write operations (write single payload to char)
 * @return BlueLinkOperationFailReason if the operation fails, otherwise null
 */
- (BridgeBlueLinkOperationError * _Nullable)writeToPeripheralDevice:(BridgeBluetoothDevice *)device charUUID:(NSString *)charUUID payload:(BridgeKotlinByteArray *)payload operationType:(BridgeBlueLinkOperationType *)operationType __attribute__((swift_name("writeToPeripheral(device:charUUID:payload:operationType:)")));
@property id<BridgeKotlinx_coroutines_coreJob> _Nullable heartbeatJob __attribute__((swift_name("heartbeatJob")));
@property (readonly) id<BridgeIHeartbeatParser> heartbeatParser __attribute__((swift_name("heartbeatParser")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BlueLink.Companion")))
@interface BridgeBlueLinkCompanion : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeBlueLinkCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *TAG __attribute__((swift_name("TAG")));
@end


/** Enum to represent the connection status of a device. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BlueLinkDeviceConnectionStatus")))
@interface BridgeBlueLinkDeviceConnectionStatus : BridgeKotlinEnum<BridgeBlueLinkDeviceConnectionStatus *>
+ (instancetype)alloc __attribute__((unavailable));

/** Enum to represent the connection status of a device. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) BridgeBlueLinkDeviceConnectionStatus *connected __attribute__((swift_name("connected")));
@property (class, readonly) BridgeBlueLinkDeviceConnectionStatus *disconnected __attribute__((swift_name("disconnected")));
@property (class, readonly) BridgeBlueLinkDeviceConnectionStatus *connecting __attribute__((swift_name("connecting")));
@property (class, readonly) BridgeBlueLinkDeviceConnectionStatus *receivedAdv __attribute__((swift_name("receivedAdv")));
+ (BridgeKotlinArray<BridgeBlueLinkDeviceConnectionStatus *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<BridgeBlueLinkDeviceConnectionStatus *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BlueLinkOperationError")))
@interface BridgeBlueLinkOperationError : BridgeKotlinEnum<BridgeBlueLinkOperationError *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) BridgeBlueLinkOperationError *peripheralNotFound __attribute__((swift_name("peripheralNotFound")));
@property (class, readonly) BridgeBlueLinkOperationError *characteristicNotFound __attribute__((swift_name("characteristicNotFound")));
@property (class, readonly) BridgeBlueLinkOperationError *other __attribute__((swift_name("other")));
+ (BridgeKotlinArray<BridgeBlueLinkOperationError *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<BridgeBlueLinkOperationError *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((swift_name("Koin_coreKoinComponent")))
@protocol BridgeKoin_coreKoinComponent
@required
- (BridgeKoin_coreKoin *)getKoin __attribute__((swift_name("getKoin()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BlueLinkProvider")))
@interface BridgeBlueLinkProvider : BridgeBase <BridgeKoin_coreKoinComponent>
- (instancetype)initWithHeartbeatParser:(id<BridgeIHeartbeatParser> _Nullable)heartbeatParser __attribute__((swift_name("init(heartbeatParser:)"))) __attribute__((objc_designated_initializer));
@property (readonly) BridgeBlueLink *blueLink __attribute__((swift_name("blueLink")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BluetoothAdvertisement")))
@interface BridgeBluetoothAdvertisement : BridgeBase
- (instancetype)initWithUniqueIdentifier:(uint32_t)uniqueIdentifier deviceStateCounter:(uint16_t)deviceStateCounter serverStateCounter:(uint16_t)serverStateCounter signalingByte:(uint8_t)signalingByte firmwareVersion:(BridgeDeviceFirmwareVersion * _Nullable)firmwareVersion packetVersion:(BridgePacketVersion *)packetVersion __attribute__((swift_name("init(uniqueIdentifier:deviceStateCounter:serverStateCounter:signalingByte:firmwareVersion:packetVersion:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) BridgeBluetoothAdvertisementCompanion *companion __attribute__((swift_name("companion")));
- (BridgeBluetoothAdvertisement *)doCopyUniqueIdentifier:(uint32_t)uniqueIdentifier deviceStateCounter:(uint16_t)deviceStateCounter serverStateCounter:(uint16_t)serverStateCounter signalingByte:(uint8_t)signalingByte firmwareVersion:(BridgeDeviceFirmwareVersion * _Nullable)firmwareVersion packetVersion:(BridgePacketVersion *)packetVersion __attribute__((swift_name("doCopy(uniqueIdentifier:deviceStateCounter:serverStateCounter:signalingByte:firmwareVersion:packetVersion:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (BOOL)hasConnectionRequest __attribute__((swift_name("hasConnectionRequest()")));
- (BOOL)hasLowBatteryStatus __attribute__((swift_name("hasLowBatteryStatus()")));
- (BOOL)hasTimeSyncRequest __attribute__((swift_name("hasTimeSyncRequest()")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (BOOL)isBusy __attribute__((swift_name("isBusy()")));
- (BOOL)isInDFU __attribute__((swift_name("isInDFU()")));
- (BOOL)isInEmergencyState __attribute__((swift_name("isInEmergencyState()")));
- (BOOL)isInInstallMode __attribute__((swift_name("isInInstallMode()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) uint16_t deviceStateCounter __attribute__((swift_name("deviceStateCounter")));
@property (readonly) BridgeDeviceFirmwareVersion * _Nullable firmwareVersion __attribute__((swift_name("firmwareVersion")));
@property (readonly) BridgePacketVersion *packetVersion __attribute__((swift_name("packetVersion")));
@property (readonly) uint16_t serverStateCounter __attribute__((swift_name("serverStateCounter")));
@property (readonly) uint8_t signalingByte __attribute__((swift_name("signalingByte")));
@property (readonly) uint32_t uniqueIdentifier __attribute__((swift_name("uniqueIdentifier")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BluetoothAdvertisement.Companion")))
@interface BridgeBluetoothAdvertisementCompanion : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeBluetoothAdvertisementCompanion *shared __attribute__((swift_name("shared")));

/**
 * Detects packet version based on size and structure.
 * Heartbeat packets always use 1.4 format (16-bit counters).
 * Advertising packets use 1.5 format (4-bit counters) if they're 6 bytes.
 *
 * Version Detection Logic:
 * - Heartbeat packets: Always V1_4 (16-bit counters)
 * - 6-byte packets: V1_5 (4-bit counters in single byte)
 * - 9+ byte packets: V1_4 (16-bit counters)
 * - Default: V1_4 for backward compatibility
 */
- (BridgePacketVersion * _Nullable)detectPacketVersionBytes:(BridgeKotlinByteArray *)bytes isHeartbeat:(BOOL)isHeartbeat __attribute__((swift_name("detectPacketVersion(bytes:isHeartbeat:)")));
- (int32_t)extractValueBytes:(BridgeKotlinByteArray *)bytes start:(int32_t)start end:(int32_t)end __attribute__((swift_name("extractValue(bytes:start:end:)")));

/**
 * Parses advertising packet data into BluetoothAdvertisement.
 * Supports both V1_4 (16-bit counters) and V1_5 (4-bit counters) formats.
 *
 * Example V1_4 advertising format (9+ bytes):
 * [0-3]: deviceId (4 bytes, little-endian)
 * [4-5]: deviceStateCounter (2 bytes, little-endian)
 * [6-7]: serverStateCounter (2 bytes, little-endian)
 * [8]: signalingByte (1 byte)
 *
 * Example V1_5 advertising format (6 bytes):
 * [0-3]: deviceId (4 bytes, little-endian)
 * [4]: combinedStateCounter (1 byte: DSC[0-3], SSC[4-7])
 * [5]: signalingByte (1 byte)
 */
- (BridgeBluetoothAdvertisement * _Nullable)fromAdvPktBytes:(BridgeKotlinByteArray *)bytes __attribute__((swift_name("fromAdvPkt(bytes:)")));
- (BridgeBluetoothAdvertisement *)fromHeartbeatPayloadBytes:(BridgeKotlinByteArray *)bytes __attribute__((swift_name("fromHeartbeatPayload(bytes:)")));
- (BridgeKotlinByteArray *)toByteArrayAdvertisement:(BridgeBluetoothAdvertisement *)advertisement __attribute__((swift_name("toByteArray(advertisement:)")));
- (uint16_t)u16leB:(BridgeKotlinByteArray *)b off:(int32_t)off __attribute__((swift_name("u16le(b:off:)")));
- (uint32_t)u32leB:(BridgeKotlinByteArray *)b off:(int32_t)off __attribute__((swift_name("u32le(b:off:)")));
@property (readonly) int32_t MINIMUM_SIZE_V1_4 __attribute__((swift_name("MINIMUM_SIZE_V1_4")));
@property (readonly) int32_t MINIMUM_SIZE_V1_5 __attribute__((swift_name("MINIMUM_SIZE_V1_5")));
@property (readonly) int32_t PACKET_SIZE_V1_4 __attribute__((swift_name("PACKET_SIZE_V1_4")));
@property (readonly) int32_t PACKET_SIZE_V1_5 __attribute__((swift_name("PACKET_SIZE_V1_5")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BluetoothAdvertisement.SignalingByte")))
@interface BridgeBluetoothAdvertisementSignalingByte : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)signalingByte __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeBluetoothAdvertisementSignalingByte *shared __attribute__((swift_name("shared")));
- (NSArray<BridgeKotlinPair<NSString *, BridgeUByte *> *> *)getActiveFlagsByte:(uint8_t)byte __attribute__((swift_name("getActiveFlags(byte:)")));
- (BOOL)hasFlagByte:(uint8_t)byte flag:(uint8_t)flag __attribute__((swift_name("hasFlag(byte:flag:)")));
@property (readonly) uint8_t BLE_UNLOCK_UNAVAIL __attribute__((swift_name("BLE_UNLOCK_UNAVAIL")));
@property (readonly) uint8_t BUSY_FLAG __attribute__((swift_name("BUSY_FLAG")));
@property (readonly) uint8_t CONNECTION_REQUEST __attribute__((swift_name("CONNECTION_REQUEST")));
@property (readonly) uint8_t DFU_MODE __attribute__((swift_name("DFU_MODE")));
@property (readonly) uint8_t EMERGENCY_STATE __attribute__((swift_name("EMERGENCY_STATE")));
@property (readonly) uint8_t INSTALL_MODE __attribute__((swift_name("INSTALL_MODE")));
@property (readonly) uint8_t LOW_BATTERY __attribute__((swift_name("LOW_BATTERY")));
@property (readonly) uint8_t TIME_SYNC_REQUEST __attribute__((swift_name("TIME_SYNC_REQUEST")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BluetoothDevice")))
@interface BridgeBluetoothDevice : BridgeBase
- (instancetype)initWithPeripheral:(CBPeripheral *)peripheral _deviceId:(uint32_t)_deviceId __attribute__((swift_name("init(peripheral:_deviceId:)"))) __attribute__((objc_designated_initializer));
- (id)toNative __attribute__((swift_name("toNative()")));
@property (readonly) uint32_t deviceId __attribute__((swift_name("deviceId")));
@property (readonly) id<BridgeKotlinx_coroutines_coreMutex> mutex __attribute__((swift_name("mutex")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BluetoothGattCharacteristic")))
@interface BridgeBluetoothGattCharacteristic : BridgeBase
- (instancetype)initWithCharacteristic:(CBCharacteristic *)characteristic __attribute__((swift_name("init(characteristic:)"))) __attribute__((objc_designated_initializer));
- (id)toNative __attribute__((swift_name("toNative()")));
@property (readonly) NSString *uuid __attribute__((swift_name("uuid")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeviceFirmwareVersion")))
@interface BridgeDeviceFirmwareVersion : BridgeBase
- (instancetype)initWithMajor:(int32_t)major minor:(int32_t)minor revision:(int32_t)revision build:(int32_t)build __attribute__((swift_name("init(major:minor:revision:build:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) BridgeDeviceFirmwareVersionCompanion *companion __attribute__((swift_name("companion")));
- (BridgeDeviceFirmwareVersion *)doCopyMajor:(int32_t)major minor:(int32_t)minor revision:(int32_t)revision build:(int32_t)build __attribute__((swift_name("doCopy(major:minor:revision:build:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t build __attribute__((swift_name("build")));
@property (readonly) int32_t major __attribute__((swift_name("major")));
@property (readonly) int32_t minor __attribute__((swift_name("minor")));
@property (readonly) int32_t revision __attribute__((swift_name("revision")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeviceFirmwareVersion.Companion")))
@interface BridgeDeviceFirmwareVersionCompanion : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeDeviceFirmwareVersionCompanion *shared __attribute__((swift_name("shared")));

/**
 * Parse a firmware version string in the format "x.y.z-b" (e.g., "1.2.3-4").
 *
 * @param str The string to parse.
 * @return The DeviceFirmwareVersion object, or null if the string is invalid.
 */
- (BridgeDeviceFirmwareVersion * _Nullable)fromStringStr:(NSString *)str __attribute__((swift_name("fromString(str:)")));

/**
 * Returns true if [a] is less than [b] according to version precedence.
 *
 * @param a The first DeviceFirmwareVersion to compare.
 * @param b The second DeviceFirmwareVersion to compare.
 * @return Boolean result of the comparison.
 */
- (BOOL)isLessThanA:(BridgeDeviceFirmwareVersion *)a b:(BridgeDeviceFirmwareVersion *)b __attribute__((swift_name("isLessThan(a:b:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PacketVersion")))
@interface BridgePacketVersion : BridgeKotlinEnum<BridgePacketVersion *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) BridgePacketVersion *v14 __attribute__((swift_name("v14")));
@property (class, readonly) BridgePacketVersion *v15 __attribute__((swift_name("v15")));
+ (BridgeKotlinArray<BridgePacketVersion *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<BridgePacketVersion *> *entries __attribute__((swift_name("entries")));
@end


/**
 * Enum to represent the type of active operation.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BlueLinkActiveOperationType")))
@interface BridgeBlueLinkActiveOperationType : BridgeKotlinEnum<BridgeBlueLinkActiveOperationType *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Enum to represent the type of active operation.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) BridgeBlueLinkActiveOperationType *read __attribute__((swift_name("read")));
@property (class, readonly) BridgeBlueLinkActiveOperationType *write __attribute__((swift_name("write")));
+ (BridgeKotlinArray<BridgeBlueLinkActiveOperationType *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<BridgeBlueLinkActiveOperationType *> *entries __attribute__((swift_name("entries")));
@end


/** Represents an operation that can be performed on a BLE device. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BlueLinkOperation")))
@interface BridgeBlueLinkOperation : BridgeBase
- (instancetype)initWithId:(BridgeUUID *)id operationType:(BridgeBlueLinkOperationType *)operationType state:(BridgeOperationState *)state fragmentationRequired:(BOOL)fragmentationRequired whenServer:(BridgeLong * _Nullable)whenServer __attribute__((swift_name("init(id:operationType:state:fragmentationRequired:whenServer:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) BridgeBlueLinkOperationCompanion *companion __attribute__((swift_name("companion")));
- (BridgeBlueLinkOperation *)doCopyId:(BridgeUUID *)id operationType:(BridgeBlueLinkOperationType *)operationType state:(BridgeOperationState *)state fragmentationRequired:(BOOL)fragmentationRequired whenServer:(BridgeLong * _Nullable)whenServer __attribute__((swift_name("doCopy(id:operationType:state:fragmentationRequired:whenServer:)")));

/** Represents an operation that can be performed on a BLE device. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Represents an operation that can be performed on a BLE device. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BOOL fragmentationRequired __attribute__((swift_name("fragmentationRequired")));
@property (readonly) BridgeUUID *id __attribute__((swift_name("id")));
@property (readonly) BridgeBlueLinkOperationType *operationType __attribute__((swift_name("operationType")));
@property BridgeOperationState *state __attribute__((swift_name("state")));
@property (readonly) BridgeLong * _Nullable whenServer __attribute__((swift_name("whenServer")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BlueLinkOperation.Companion")))
@interface BridgeBlueLinkOperationCompanion : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeBlueLinkOperationCompanion *shared __attribute__((swift_name("shared")));
- (BridgeBlueLinkOperation *)createOperationType:(BridgeBlueLinkOperationType *)operationType state:(BridgeOperationState *)state fragmentationRequired:(BOOL)fragmentationRequired __attribute__((swift_name("create(operationType:state:fragmentationRequired:)")));
@end


/** Queue to manage BlueLinkOperations. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BlueLinkOperationQueue")))
@interface BridgeBlueLinkOperationQueue : BridgeBase

/** Queue to manage BlueLinkOperations. */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/** Queue to manage BlueLinkOperations. */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));

/** Clears all operations from the queue. */
- (void)clear __attribute__((swift_name("clear()")));

/** Removes and returns a specific operation from the queue. */
- (BridgeBlueLinkOperation * _Nullable)dequeueOperation:(BridgeBlueLinkOperation *)operation __attribute__((swift_name("dequeue(operation:)")));

/** Adds a single operation to the queue. */
- (void)enqueueOperation:(BridgeBlueLinkOperation *)operation __attribute__((swift_name("enqueue(operation:)")));

/** Returns the full queue as a list. */
- (NSArray<BridgeBlueLinkOperation *> *)fullQueue __attribute__((swift_name("fullQueue()")));
- (void)replaceWithNewQueue:(NSMutableArray<BridgeBlueLinkOperation *> *)newQueue __attribute__((swift_name("replaceWith(newQueue:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/** Represents the type of a BlueLinkOperation. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BlueLinkOperationType")))
@interface BridgeBlueLinkOperationType : BridgeKotlinEnum<BridgeBlueLinkOperationType *>
+ (instancetype)alloc __attribute__((unavailable));

/** Represents the type of a BlueLinkOperation. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) BridgeBlueLinkOperationType *deviceInformation __attribute__((swift_name("deviceInformation")));
@property (class, readonly) BridgeBlueLinkOperationType *credLinkTimeSync __attribute__((swift_name("credLinkTimeSync")));
@property (class, readonly) BridgeBlueLinkOperationType *serverTimeSync __attribute__((swift_name("serverTimeSync")));
@property (class, readonly) BridgeBlueLinkOperationType *credentialExchange __attribute__((swift_name("credentialExchange")));
@property (class, readonly) BridgeBlueLinkOperationType *proxyRead __attribute__((swift_name("proxyRead")));
@property (class, readonly) BridgeBlueLinkOperationType *proxyWrite __attribute__((swift_name("proxyWrite")));
@property (class, readonly) BridgeBlueLinkOperationType *dfu __attribute__((swift_name("dfu")));
@property (class, readonly) BridgeBlueLinkOperationType *resetOob __attribute__((swift_name("resetOob")));
@property (class, readonly) BridgeBlueLinkOperationType *installOob __attribute__((swift_name("installOob")));
@property (class, readonly) BridgeBlueLinkOperationType *unknownOob __attribute__((swift_name("unknownOob")));
@property (class, readonly) BridgeBlueLinkOperationType *identifyOob __attribute__((swift_name("identifyOob")));
@property (class, readonly) BridgeBlueLinkOperationType *recoveryOob __attribute__((swift_name("recoveryOob")));
@property (class, readonly) BridgeBlueLinkOperationType *error __attribute__((swift_name("error")));
+ (BridgeKotlinArray<BridgeBlueLinkOperationType *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<BridgeBlueLinkOperationType *> *entries __attribute__((swift_name("entries")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BOOL isCredentialExchange __attribute__((swift_name("isCredentialExchange")));
@property (readonly) BOOL isDFU __attribute__((swift_name("isDFU")));
@property (readonly) BOOL isProxy __attribute__((swift_name("isProxy")));
@end


/** Represents the state of a BlueLinkOperation. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OperationState")))
@interface BridgeOperationState : BridgeKotlinEnum<BridgeOperationState *>
+ (instancetype)alloc __attribute__((unavailable));

/** Represents the state of a BlueLinkOperation. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) BridgeOperationState *scheduled __attribute__((swift_name("scheduled")));
@property (class, readonly) BridgeOperationState *ongoing __attribute__((swift_name("ongoing")));
@property (class, readonly) BridgeOperationState *completed __attribute__((swift_name("completed")));
+ (BridgeKotlinArray<BridgeOperationState *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<BridgeOperationState *> *entries __attribute__((swift_name("entries")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * Listener for central-level BLE events.
 *
 * This interface provides callbacks for central BLE events,
 * such as state updates and device connection status changes.
 */
__attribute__((swift_name("BlueLinkCentralListener")))
@protocol BridgeBlueLinkCentralListener
@required
- (void)onBLEStateChangedIsBluetoothPoweredOn:(BOOL)isBluetoothPoweredOn __attribute__((swift_name("onBLEStateChanged(isBluetoothPoweredOn:)")));
- (void)onDeviceConnectedDevice:(BridgeBluetoothDevice *)device __attribute__((swift_name("onDeviceConnected(device:)")));
- (void)onDeviceConnectionFailedDevice:(BridgeBluetoothDevice *)device reason:(BridgeInt * _Nullable)reason __attribute__((swift_name("onDeviceConnectionFailed(device:reason:)")));
- (void)onDeviceDisconnectedDevice:(BridgeBluetoothDevice *)device reason:(BridgeInt * _Nullable)reason __attribute__((swift_name("onDeviceDisconnected(device:reason:)")));
- (void)onDeviceDiscoveredDevice:(BridgeBluetoothDevice *)device advertisementData:(BridgeBluetoothAdvertisement *)advertisementData rssi:(int32_t)rssi __attribute__((swift_name("onDeviceDiscovered(device:advertisementData:rssi:)")));
- (void)onLocationStateChangedIsLocationEnabled:(BOOL)isLocationEnabled __attribute__((swift_name("onLocationStateChanged(isLocationEnabled:)")));
@end


/**
 * Listener for general BLE events with optional callbacks.
 *
 * Default implementations are provided for all methods, allowing implementors
 * to override only the methods they need.
 */
__attribute__((swift_name("BlueLinkEventListener")))
@interface BridgeBlueLinkEventListener : BridgeBase

/**
 * Listener for general BLE events with optional callbacks.
 *
 * Default implementations are provided for all methods, allowing implementors
 * to override only the methods they need.
 */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/**
 * Listener for general BLE events with optional callbacks.
 *
 * Default implementations are provided for all methods, allowing implementors
 * to override only the methods they need.
 */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)onBLEStateChangedNewState:(BOOL)newState __attribute__((swift_name("onBLEStateChanged(newState:)")));

/**
 * Error if returned will correspond to the BLE GATT error thrown by the device
 */
- (void)onCharacteristicReadDevice:(BridgeBluetoothDevice *)device characteristic:(BridgeBluetoothGattCharacteristic *)characteristic payload:(BridgeKotlinByteArray *)payload error:(BridgeInt * _Nullable)error __attribute__((swift_name("onCharacteristicRead(device:characteristic:payload:error:)")));
- (void)onCharacteristicWriteDevice:(BridgeBluetoothDevice *)device characteristic:(BridgeBluetoothGattCharacteristic *)characteristic error:(BridgeBoolean * _Nullable)error operationType:(BridgeBlueLinkOperationType *)operationType __attribute__((swift_name("onCharacteristicWrite(device:characteristic:error:operationType:)")));
- (void)onDeviceConnectedDevice:(BridgeBluetoothDevice *)device __attribute__((swift_name("onDeviceConnected(device:)")));
- (void)onDeviceConnectionFailedDevice:(BridgeBluetoothDevice *)device reason:(BridgeInt * _Nullable)reason __attribute__((swift_name("onDeviceConnectionFailed(device:reason:)")));
- (void)onDeviceDisconnectedDevice:(BridgeBluetoothDevice *)device reason:(BridgeInt * _Nullable)reason __attribute__((swift_name("onDeviceDisconnected(device:reason:)")));
- (void)onDeviceDiscoveredDevice:(BridgeBluetoothDevice *)device advertisementData:(BridgeBluetoothAdvertisement *)advertisementData rssi:(int32_t)rssi signalStrength:(BridgeSignalStrength * _Nullable)signalStrength connectionStatus:(BridgeBlueLinkDeviceConnectionStatus *)connectionStatus __attribute__((swift_name("onDeviceDiscovered(device:advertisementData:rssi:signalStrength:connectionStatus:)")));
- (void)onHeartbeatDevice:(BridgeBluetoothDevice *)device heartbeatData:(BridgeKotlinByteArray *)heartbeatData __attribute__((swift_name("onHeartbeat(device:heartbeatData:)")));
- (void)onLocationStateUpdateNewState:(BOOL)newState __attribute__((swift_name("onLocationStateUpdate(newState:)")));
- (void)onNotificationReceivedDevice:(BridgeBluetoothDevice *)device characteristic:(BridgeBluetoothGattCharacteristic *)characteristic payload:(BridgeKotlinByteArray *)payload __attribute__((swift_name("onNotificationReceived(device:characteristic:payload:)")));
- (void)onNotificationStateChangedDevice:(BridgeBluetoothDevice *)device characteristic:(BridgeBluetoothGattCharacteristic *)characteristic __attribute__((swift_name("onNotificationStateChanged(device:characteristic:)")));
- (void)onOperationStartDevice:(BridgeBluetoothDevice *)device operation:(BridgeBlueLinkOperation *)operation __attribute__((swift_name("onOperationStart(device:operation:)")));
@end


/**
 * For accepting RSSI values for devices and computing hysteresis and maintaining normalized
 * values to minimize the spikes in the RSSI data set for a device. Maintains a sample size of 4
 * (number found through experimentation which yielded best results)
 *
 * Ensure unique RssiSignalManager instance is maintained per device
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RssiSignalManager")))
@interface BridgeRssiSignalManager : BridgeBase

/**
 * For accepting RSSI values for devices and computing hysteresis and maintaining normalized
 * values to minimize the spikes in the RSSI data set for a device. Maintains a sample size of 4
 * (number found through experimentation which yielded best results)
 *
 * Ensure unique RssiSignalManager instance is maintained per device
 */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/**
 * For accepting RSSI values for devices and computing hysteresis and maintaining normalized
 * values to minimize the spikes in the RSSI data set for a device. Maintains a sample size of 4
 * (number found through experimentation which yielded best results)
 *
 * Ensure unique RssiSignalManager instance is maintained per device
 */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (BridgeSignalStrength *)getSignalStrength __attribute__((swift_name("getSignalStrength()")));
- (void)updateRssiNewRssi:(int32_t)newRssi __attribute__((swift_name("updateRssi(newRssi:)")));
@end


/**
 * Signal Strength levels
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SignalStrength")))
@interface BridgeSignalStrength : BridgeKotlinEnum<BridgeSignalStrength *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Signal Strength levels
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) BridgeSignalStrength *excellent __attribute__((swift_name("excellent")));
@property (class, readonly) BridgeSignalStrength *good __attribute__((swift_name("good")));
@property (class, readonly) BridgeSignalStrength *okay __attribute__((swift_name("okay")));
@property (class, readonly) BridgeSignalStrength *weak __attribute__((swift_name("weak")));
+ (BridgeKotlinArray<BridgeSignalStrength *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<BridgeSignalStrength *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FragmentedPayloadType")))
@interface BridgeFragmentedPayloadType : BridgeKotlinEnum<BridgeFragmentedPayloadType *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) BridgeFragmentedPayloadType *read __attribute__((swift_name("read")));
@property (class, readonly) BridgeFragmentedPayloadType *write __attribute__((swift_name("write")));
+ (BridgeKotlinArray<BridgeFragmentedPayloadType *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<BridgeFragmentedPayloadType *> *entries __attribute__((swift_name("entries")));
@end


/**
 * Data class representing parsed heartbeat data with optional fields
 * This provides type safety and eliminates the need for string-based field access
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HeartbeatData")))
@interface BridgeHeartbeatData : BridgeBase
- (instancetype)initWithMfrId:(BridgeUInt * _Nullable)mfrId devId:(uint32_t)devId dsc:(uint32_t)dsc ssc:(uint32_t)ssc sigBmp:(uint32_t)sigBmp semVer:(BridgeDeviceFirmwareVersion *)semVer timestamp:(BridgeUInt * _Nullable)timestamp rssi:(BridgeInt * _Nullable)rssi lastOobServerTimestamp:(BridgeLong * _Nullable)lastOobServerTimestamp __attribute__((swift_name("init(mfrId:devId:dsc:ssc:sigBmp:semVer:timestamp:rssi:lastOobServerTimestamp:)"))) __attribute__((objc_designated_initializer));
- (BridgeHeartbeatData *)doCopyMfrId:(BridgeUInt * _Nullable)mfrId devId:(uint32_t)devId dsc:(uint32_t)dsc ssc:(uint32_t)ssc sigBmp:(uint32_t)sigBmp semVer:(BridgeDeviceFirmwareVersion *)semVer timestamp:(BridgeUInt * _Nullable)timestamp rssi:(BridgeInt * _Nullable)rssi lastOobServerTimestamp:(BridgeLong * _Nullable)lastOobServerTimestamp __attribute__((swift_name("doCopy(mfrId:devId:dsc:ssc:sigBmp:semVer:timestamp:rssi:lastOobServerTimestamp:)")));

/**
 * Data class representing parsed heartbeat data with optional fields
 * This provides type safety and eliminates the need for string-based field access
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Data class representing parsed heartbeat data with optional fields
 * This provides type safety and eliminates the need for string-based field access
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Data class representing parsed heartbeat data with optional fields
 * This provides type safety and eliminates the need for string-based field access
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) uint32_t devId __attribute__((swift_name("devId")));
@property (readonly) uint32_t dsc __attribute__((swift_name("dsc")));
@property (readonly) BridgeLong * _Nullable lastOobServerTimestamp __attribute__((swift_name("lastOobServerTimestamp")));
@property (readonly) BridgeUInt * _Nullable mfrId __attribute__((swift_name("mfrId")));
@property (readonly) BridgeInt * _Nullable rssi __attribute__((swift_name("rssi")));
@property (readonly) BridgeDeviceFirmwareVersion *semVer __attribute__((swift_name("semVer")));
@property (readonly) uint32_t sigBmp __attribute__((swift_name("sigBmp")));
@property (readonly) uint32_t ssc __attribute__((swift_name("ssc")));
@property (readonly) BridgeUInt * _Nullable timestamp __attribute__((swift_name("timestamp")));
@end


/**
 * Interface for parsing heartbeat protobuf messages in KMM
 * Bridges platform-specific protobuf implementations to common KMM code
 */
__attribute__((swift_name("IHeartbeatParser")))
@protocol BridgeIHeartbeatParser
@required

/**
 * Get the device ID from parsed heartbeat data
 */
- (uint32_t)getDevIdHeartbeatData:(BridgeHeartbeatData *)heartbeatData __attribute__((swift_name("getDevId(heartbeatData:)")));

/**
 * Get the firmware version from parsed heartbeat data
 */
- (BridgeDeviceFirmwareVersion *)getFirmwareVersionHeartbeatData:(BridgeHeartbeatData *)heartbeatData __attribute__((swift_name("getFirmwareVersion(heartbeatData:)")));

/**
 * Get the last OOB server timestamp
 */
- (BridgeLong * _Nullable)getLastOOBServerTimestampHeartbeatData:(BridgeHeartbeatData *)heartbeatData __attribute__((swift_name("getLastOOBServerTimestamp(heartbeatData:)")));

/**
 * Get the manufacturer ID from parsed heartbeat data
 */
- (BridgeUInt * _Nullable)getMfrIdHeartbeatData:(BridgeHeartbeatData *)heartbeatData __attribute__((swift_name("getMfrId(heartbeatData:)")));

/**
 * Get the RSSI value from parsed heartbeat data
 */
- (BridgeInt * _Nullable)getRssiHeartbeatData:(BridgeHeartbeatData *)heartbeatData __attribute__((swift_name("getRssi(heartbeatData:)")));

/**
 * Get the signal bitmap from parsed heartbeat data
 */
- (uint32_t)getSigBmpHeartbeatData:(BridgeHeartbeatData *)heartbeatData __attribute__((swift_name("getSigBmp(heartbeatData:)")));

/**
 * Get the timestamp from parsed heartbeat data
 */
- (BridgeUInt * _Nullable)getTimestampHeartbeatData:(BridgeHeartbeatData *)heartbeatData __attribute__((swift_name("getTimestamp(heartbeatData:)")));

/**
 * Parse heartbeat data from byte array
 * @param data Raw heartbeat protobuf bytes
 * @return Parsed heartbeat data as a structured data class
 */
- (BridgeHeartbeatData *)parseHeartbeatData:(BridgeKotlinByteArray *)data __attribute__((swift_name("parseHeartbeat(data:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ThreadSafeMap")))
@interface BridgeThreadSafeMap<K, V> : BridgeBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)clear __attribute__((swift_name("clear()")));
- (V _Nullable)findFirstPredicate:(BridgeBoolean *(^)(V _Nullable))predicate __attribute__((swift_name("findFirst(predicate:)")));
- (V _Nullable)getKey:(K _Nullable)key __attribute__((swift_name("get(key:)")));
- (id)getAll __attribute__((swift_name("getAll()")));
- (void)putKey:(K _Nullable)key value:(V _Nullable)value __attribute__((swift_name("put(key:value:)")));
- (void)removeKey:(K _Nullable)key __attribute__((swift_name("remove(key:)")));
@end


/** Data structure for crash information sent to Link via BridgeTelemetry
 *
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CrashData")))
@interface BridgeCrashData : BridgeBase
- (instancetype)initWithTimestamp:(int64_t)timestamp library:(NSString *)library context:(NSString *)context message:(NSString *)message stackTrace:(NSString *)stackTrace platform:(BridgePlatform *)platform version:(NSString *)version __attribute__((swift_name("init(timestamp:library:context:message:stackTrace:platform:version:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) BridgeCrashDataCompanion *companion __attribute__((swift_name("companion")));
- (BridgeCrashData *)doCopyTimestamp:(int64_t)timestamp library:(NSString *)library context:(NSString *)context message:(NSString *)message stackTrace:(NSString *)stackTrace platform:(BridgePlatform *)platform version:(NSString *)version __attribute__((swift_name("doCopy(timestamp:library:context:message:stackTrace:platform:version:)")));

/** Data structure for crash information sent to Link via BridgeTelemetry */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Data structure for crash information sent to Link via BridgeTelemetry */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Data structure for crash information sent to Link via BridgeTelemetry */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *context __attribute__((swift_name("context")));
@property (readonly) NSString *library __attribute__((swift_name("library")));
@property (readonly) NSString *message __attribute__((swift_name("message")));
@property (readonly) BridgePlatform *platform __attribute__((swift_name("platform")));
@property (readonly) NSString *stackTrace __attribute__((swift_name("stackTrace")));
@property (readonly) int64_t timestamp __attribute__((swift_name("timestamp")));
@property (readonly) NSString *version __attribute__((swift_name("version")));
@end


/** Data structure for crash information sent to Link via BridgeTelemetry */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CrashData.Companion")))
@interface BridgeCrashDataCompanion : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));

/** Data structure for crash information sent to Link via BridgeTelemetry */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeCrashDataCompanion *shared __attribute__((swift_name("shared")));

/** Data structure for crash information sent to Link via BridgeTelemetry */
- (id<BridgeKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * Interface for handling crashes from internal libraries Sends crash data to Link via
 * BridgeTelemetry
 */
__attribute__((swift_name("LibraryCrashHandler")))
@protocol BridgeLibraryCrashHandler
@required

/**
 * Get the telemetry service used by this crash handler
 * @return The telemetry service instance
 */
- (id<BridgeBridgeTelemetryService> _Nullable)getTelemetryService __attribute__((swift_name("getTelemetryService()")));

/**
 * Handle a crash from an internal library
 * @param message The message of the crash
 * @param stackTrace The stack trace of the crash
 * @param library The name of the library where the crash occurred
 * @param context Additional context about the crash
 */
- (void)handleCrashMessage:(NSString *)message stackTrace:(NSString *)stackTrace library:(NSString *)library context:(NSString *)context __attribute__((swift_name("handleCrash(message:stackTrace:library:context:)")));

/** Initialize the crash handler (for iOS where telemetry service is set up separately) */
- (void)initialize __attribute__((swift_name("initialize()")));

/**
 * Initialize the crash handler with telemetry service
 * @param telemetryService The service to use for sending crash data
 */
- (void)initializeTelemetryService:(id<BridgeBridgeTelemetryService>)telemetryService __attribute__((swift_name("initialize(telemetryService:)")));

/** Shutdown the crash handler and cleanup resources */
- (void)shutdown __attribute__((swift_name("shutdown()")));
@end


/**
 * Service for persisting and sending library crash logs Follows the same pattern as the main
 * LoggingService
 */
__attribute__((swift_name("LibraryCrashPersistenceService")))
@protocol BridgeLibraryCrashPersistenceService
@required

/** Clear all persisted crash logs (for testing or cleanup) */
- (void)clearPersistedCrashLogs __attribute__((swift_name("clearPersistedCrashLogs()")));

/** Get count of persisted crash logs */
- (int32_t)getPersistedCrashLogCount __attribute__((swift_name("getPersistedCrashLogCount()")));

/** Persist a crash log to file system for later retry */
- (void)persistCrashLogCrashData:(BridgeCrashData *)crashData __attribute__((swift_name("persistCrashLog(crashData:)")));

/** Send all persisted crash logs to Link
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)sendPersistedCrashLogsWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("sendPersistedCrashLogs(completionHandler:)")));
@end


/** Data class for persisted library crash logs
 *
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PersistedLibraryCrashLog")))
@interface BridgePersistedLibraryCrashLog : BridgeBase
- (instancetype)initWithCrashData:(BridgeCrashData *)crashData timestamp:(BridgeKotlinx_datetimeInstant *)timestamp __attribute__((swift_name("init(crashData:timestamp:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) BridgePersistedLibraryCrashLogCompanion *companion __attribute__((swift_name("companion")));
- (BridgePersistedLibraryCrashLog *)doCopyCrashData:(BridgeCrashData *)crashData timestamp:(BridgeKotlinx_datetimeInstant *)timestamp __attribute__((swift_name("doCopy(crashData:timestamp:)")));

/** Data class for persisted library crash logs */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Data class for persisted library crash logs */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Data class for persisted library crash logs */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BridgeCrashData *crashData __attribute__((swift_name("crashData")));
@property (readonly) BridgeKotlinx_datetimeInstant *timestamp __attribute__((swift_name("timestamp")));
@end


/** Data class for persisted library crash logs */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PersistedLibraryCrashLog.Companion")))
@interface BridgePersistedLibraryCrashLogCompanion : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));

/** Data class for persisted library crash logs */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgePersistedLibraryCrashLogCompanion *shared __attribute__((swift_name("shared")));

/** Data class for persisted library crash logs */
- (id<BridgeKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Platform")))
@interface BridgePlatform : BridgeKotlinEnum<BridgePlatform *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) BridgePlatform *platformIos __attribute__((swift_name("platformIos")));
@property (class, readonly) BridgePlatform *platformAndroid __attribute__((swift_name("platformAndroid")));
+ (BridgeKotlinArray<BridgePlatform *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<BridgePlatform *> *entries __attribute__((swift_name("entries")));
@property (readonly) NSString *stringValue __attribute__((swift_name("stringValue")));
@end

__attribute__((swift_name("ConnectivityListener")))
@protocol BridgeConnectivityListener
@required
- (void)didChangeConnectivityIsConnected:(BOOL)isConnected __attribute__((swift_name("didChangeConnectivity(isConnected:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NetworkConnectivityManagerModule")))
@interface BridgeNetworkConnectivityManagerModule : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)networkConnectivityManagerModule __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeNetworkConnectivityManagerModule *shared __attribute__((swift_name("shared")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (BridgeKoin_coreModule *)networkConnectivityManagerModule __attribute__((swift_name("networkConnectivityManagerModule()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NetworkConnectivityMonitor")))
@interface BridgeNetworkConnectivityMonitor : BridgeBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)addListenerListener:(id<BridgeConnectivityListener>)listener __attribute__((swift_name("addListener(listener:)")));
- (void)removeListenerListener:(id<BridgeConnectivityListener>)listener __attribute__((swift_name("removeListener(listener:)")));
- (void)startMonitoring __attribute__((swift_name("startMonitoring()")));
- (void)stopMonitoring __attribute__((swift_name("stopMonitoring()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NetworkConnectivityMonitorProvider")))
@interface BridgeNetworkConnectivityMonitorProvider : BridgeBase <BridgeKoin_coreKoinComponent>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (readonly) BridgeNetworkConnectivityMonitor *networkConnectivityMonitor __attribute__((swift_name("networkConnectivityMonitor")));
@end

__attribute__((swift_name("PlaneStreamManagerInterface")))
@protocol BridgePlaneStreamManagerInterface
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)attachDeviceToPlaneStreamDeviceId:(id)deviceId completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("attachDeviceToPlaneStream(deviceId:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)cancelStreamWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("cancelStream(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)clearStreamWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("clearStream(completionHandler:)")));
- (NSArray<BridgeUInt *> *)getActiveDevices __attribute__((swift_name("getActiveDevices()")));
- (BridgeStreamState *)getStreamState __attribute__((swift_name("getStreamState()")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)pushMessagesToStreamPayload:(id)payload completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("pushMessagesToStream(payload:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)removeDeviceFromPlaneStreamDeviceId:(id)deviceId completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("removeDeviceFromPlaneStream(deviceId:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)startStreamWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("startStream(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)subscribeToStreamHandler:(id)handler completionHandler:(void (^)(BridgeUUID * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("subscribeToStream(handler:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("StreamState")))
@interface BridgeStreamState : BridgeKotlinEnum<BridgeStreamState *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) BridgeStreamState *disconnected __attribute__((swift_name("disconnected")));
@property (class, readonly) BridgeStreamState *connecting __attribute__((swift_name("connecting")));
@property (class, readonly) BridgeStreamState *connected __attribute__((swift_name("connected")));
@property (class, readonly) BridgeStreamState *error __attribute__((swift_name("error")));
+ (BridgeKotlinArray<BridgeStreamState *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<BridgeStreamState *> *entries __attribute__((swift_name("entries")));
@end


/**
 * Service for sending telemetry data to Link via BridgeTelemetryRequest Used for sending crash logs
 * from internal libraries
 */
__attribute__((swift_name("BridgeTelemetryService")))
@protocol BridgeBridgeTelemetryService
@required

/**
 * Send telemetry data synchronously
 * @param data The telemetry data to send
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)sendTelemetryData:(BridgeKotlinByteArray *)data completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("sendTelemetry(data:completionHandler:)")));
@end

__attribute__((swift_name("ITrueTimeManager")))
@protocol BridgeITrueTimeManager
@required
- (int64_t)getCurrentTimeSeconds __attribute__((swift_name("getCurrentTimeSeconds()")));
- (BOOL)initializeTrueTime __attribute__((swift_name("initializeTrueTime()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("IsolatedKoinContext")))
@interface BridgeIsolatedKoinContext : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)isolatedKoinContext __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeIsolatedKoinContext *shared __attribute__((swift_name("shared")));
- (BridgeKoin_coreKoin *)koin __attribute__((swift_name("koin()")));
- (void)registerContextContext:(id)context __attribute__((swift_name("registerContext(context:)")));
@property (readonly, getter=koin_) BridgeKoin_coreKoin *koin __attribute__((swift_name("koin")));
@property (readonly) BridgeKoin_coreKoinApplication *koinApp __attribute__((swift_name("koinApp")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Logger")))
@interface BridgeLogger : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)logger __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeLogger *shared __attribute__((swift_name("shared")));
- (void)dTag:(NSString *)tag message:(NSString *)message __attribute__((swift_name("d(tag:message:)")));
- (void)eTag:(NSString *)tag message:(NSString *)message __attribute__((swift_name("e(tag:message:)")));
- (void)iTag:(NSString *)tag message:(NSString *)message __attribute__((swift_name("i(tag:message:)")));
- (void)setLoggerEnabledEnabled:(BOOL)enabled __attribute__((swift_name("setLoggerEnabled(enabled:)")));
- (void)wTag:(NSString *)tag message:(NSString *)message __attribute__((swift_name("w(tag:message:)")));
@property BOOL isEnabled __attribute__((swift_name("isEnabled")));
@end


/**
 * Allows multiple listeners to respond to BLE events.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MulticastListener")))
@interface BridgeMulticastListener<T> : BridgeBase

/**
 * Allows multiple listeners to respond to BLE events.
 */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/**
 * Allows multiple listeners to respond to BLE events.
 */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));

/**
 * Adds a listener to the list.
 */
- (void)addListenerListener:(T)listener prependListener:(BOOL)prependListener __attribute__((swift_name("addListener(listener:prependListener:)")));

/**
 * Invokes a method on all active listeners.
 */
- (void)invokeListenersAction:(void (^)(T))action __attribute__((swift_name("invokeListeners(action:)")));

/**
 * Removes a listener from the list.
 */
- (void)removeListenerListener:(T)listener __attribute__((swift_name("removeListener(listener:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UUID")))
@interface BridgeUUID : BridgeBase
@property (class, readonly, getter=companion) BridgeUUIDCompanion *companion __attribute__((swift_name("companion")));
- (CBUUID *)toCBUUID __attribute__((swift_name("toCBUUID()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UUID.Companion")))
@interface BridgeUUIDCompanion : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeUUIDCompanion *shared __attribute__((swift_name("shared")));
- (BridgeUUID *)fromStringUuid:(NSString *)uuid __attribute__((swift_name("fromString(uuid:)")));
- (BridgeUUID *)randomUUID __attribute__((swift_name("randomUUID()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UUIDUtils")))
@interface BridgeUUIDUtils : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)uUIDUtils __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeUUIDUtils *shared __attribute__((swift_name("shared")));

/**
 * Converts a short-form UUID (16-bit or 32-bit) into a full 128-bit UUID.
 * If already a full UUID, it simply parses and returns it.
 *
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (BridgeUUID *)toFullUUIDShortUUID:(NSString *)shortUUID __attribute__((swift_name("toFullUUID(shortUUID:)")));
@property (readonly) BridgeUUID *CRED_LINK_READ_UUID __attribute__((swift_name("CRED_LINK_READ_UUID")));
@property (readonly) BridgeUUID *CRED_LINK_WRITE_UUID __attribute__((swift_name("CRED_LINK_WRITE_UUID")));
@property (readonly) BridgeUUID *DFU_SERVICE_UUID __attribute__((swift_name("DFU_SERVICE_UUID")));
@property (readonly) BridgeKotlinByteArray *DeviceBusyCharacteristic __attribute__((swift_name("DeviceBusyCharacteristic")));
@property (readonly) BridgeKotlinByteArray *DevicePayloadCharacteristic __attribute__((swift_name("DevicePayloadCharacteristic")));
@property (readonly) BridgeUUID *HeartbeatCharUUID __attribute__((swift_name("HeartbeatCharUUID")));
@property (readonly) int32_t MANUFACTURER_ID __attribute__((swift_name("MANUFACTURER_ID")));
@property (readonly) BridgeUUID *OOBCharUUID __attribute__((swift_name("OOBCharUUID")));
@property (readonly) BridgeUUID *PayloadCharUUID __attribute__((swift_name("PayloadCharUUID")));
@property (readonly) NSString *heartbeatCharUUIDString __attribute__((swift_name("heartbeatCharUUIDString")));
@property (readonly) NSString *oobCharUUIDString __attribute__((swift_name("oobCharUUIDString")));
@property (readonly) NSString *payloadCharUUIDString __attribute__((swift_name("payloadCharUUIDString")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("WeakRef")))
@interface BridgeWeakRef<T> : BridgeBase
- (instancetype)initWithValue:(T)value __attribute__((swift_name("init(value:)"))) __attribute__((objc_designated_initializer));
- (T _Nullable)get __attribute__((swift_name("get()")));
@end


/**
 * Device object pertaining to DFU library. Stores device information along with an optional
 * parsed binary file representation used for performing DFU
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DFUDevice")))
@interface BridgeDFUDevice : BridgeBase
- (instancetype)initWithDeviceId:(uint32_t)deviceId peripheral:(BridgeBluetoothDevice *)peripheral parsedManifest:(BridgeParsedManifest * _Nullable)parsedManifest oobRequestPayload:(BridgeKotlinByteArray * _Nullable)oobRequestPayload __attribute__((swift_name("init(deviceId:peripheral:parsedManifest:oobRequestPayload:)"))) __attribute__((objc_designated_initializer));
- (BridgeDFUDevice *)doCopyDeviceId:(uint32_t)deviceId peripheral:(BridgeBluetoothDevice *)peripheral parsedManifest:(BridgeParsedManifest * _Nullable)parsedManifest oobRequestPayload:(BridgeKotlinByteArray * _Nullable)oobRequestPayload __attribute__((swift_name("doCopy(deviceId:peripheral:parsedManifest:oobRequestPayload:)")));

/**
 * Device object pertaining to DFU library. Stores device information along with an optional
 * parsed binary file representation used for performing DFU
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Device object pertaining to DFU library. Stores device information along with an optional
 * parsed binary file representation used for performing DFU
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Device object pertaining to DFU library. Stores device information along with an optional
 * parsed binary file representation used for performing DFU
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) uint32_t deviceId __attribute__((swift_name("deviceId")));
@property BridgeKotlinByteArray * _Nullable oobRequestPayload __attribute__((swift_name("oobRequestPayload")));
@property BridgeParsedManifest * _Nullable parsedManifest __attribute__((swift_name("parsedManifest")));
@property BridgeBluetoothDevice *peripheral __attribute__((swift_name("peripheral")));
@end


/**
 * Defines the interface that implementors implementing DFUDriver for their respective
 * bridgeOS need to implement
 *
 * Implementors also need to define their respective ZipPackage definitions in order
 * to extract the DFU image files from the Link provided zip
 */
__attribute__((swift_name("DFUDriverImplementation")))
@protocol BridgeDFUDriverImplementation
@required

/**
 * Sends an SMP identify command to group 64 (custom group) for devices in DFU mode
 * @param device The Bluetooth device to send the command to
 * @param payload Optional payload data (can be empty for identify command)
 * @return true if command was sent successfully, false otherwise
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)sendSMPIdentifyDevice:(BridgeBluetoothDevice *)device payload:(BridgeKotlinByteArray *)payload completionHandler:(void (^)(BridgeBoolean * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("sendSMPIdentify(device:payload:completionHandler:)")));

/**
 * Sends an SMP reboot command to group 1 (OS management group) to exit install mode
 * @param device The Bluetooth device to send the command to
 * @return true if command was sent successfully, false otherwise
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)sendSMPRebootDevice:(BridgeBluetoothDevice *)device completionHandler:(void (^)(BridgeBoolean * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("sendSMPReboot(device:completionHandler:)")));
- (void)startDfuDfuDevice:(BridgeDFUDevice *)dfuDevice parsedManifest:(BridgeParsedManifest *)parsedManifest onUpgradeStarted:(void (^)(void))onUpgradeStarted progress:(void (^)(BridgeFloat *))progress completion:(void (^)(BridgeBoolean *))completion __attribute__((swift_name("startDfu(dfuDevice:parsedManifest:onUpgradeStarted:progress:completion:)")));
@end

__attribute__((swift_name("KotlinThrowable")))
@interface BridgeKotlinThrowable : BridgeBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(BridgeKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(BridgeKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));

/**
 * @note annotations
 *   kotlin.experimental.ExperimentalNativeApi
*/
- (BridgeKotlinArray<NSString *> *)getStackTrace __attribute__((swift_name("getStackTrace()")));
- (void)printStackTrace __attribute__((swift_name("printStackTrace()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BridgeKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) NSString * _Nullable message __attribute__((swift_name("message")));
- (NSError *)asError __attribute__((swift_name("asError()")));
@end

__attribute__((swift_name("KotlinException")))
@interface BridgeKotlinException : BridgeKotlinThrowable
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(BridgeKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(BridgeKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DFUError")))
@interface BridgeDFUError : BridgeKotlinException
- (instancetype)initWithMessage:(NSString *)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithCause:(BridgeKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(BridgeKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DFUErrors")))
@interface BridgeDFUErrors : BridgeKotlinEnum<BridgeDFUErrors *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) BridgeDFUErrors *noImageFromServer __attribute__((swift_name("noImageFromServer")));
@property (class, readonly) BridgeDFUErrors *ongoingDfu __attribute__((swift_name("ongoingDfu")));
@property (class, readonly) BridgeDFUErrors *emptyDfuStream __attribute__((swift_name("emptyDfuStream")));
@property (class, readonly) BridgeDFUErrors *invalidDevice __attribute__((swift_name("invalidDevice")));
@property (class, readonly) BridgeDFUErrors *unknownError __attribute__((swift_name("unknownError")));
+ (BridgeKotlinArray<BridgeDFUErrors *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<BridgeDFUErrors *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DFUProvider")))
@interface BridgeDFUProvider : BridgeBase <BridgeKoin_coreKoinComponent>
- (instancetype)initWithDfuDriverIOS:(id<BridgeDFUDriverImplementation>)dfuDriverIOS __attribute__((swift_name("init(dfuDriverIOS:)"))) __attribute__((objc_designated_initializer));
@property (readonly) BridgeDFUService *dfuModule __attribute__((swift_name("dfuModule")));
@end


/**
 * Matches the DFU object from link.proto
 *
 * Copy has to be created since protos cannot be used in commonMain declarations since protos aren't
 * present natively in iOSMain side of KMM. Hopefully by end of Summer 2025, update is released to resolve
 * this issue
 *
 * Reference DFU proto:
 * message DFU {
 * 	optional uint32 device_id = 1;
 * 	optional string firmware_name = 2;
 * 	optional bytes firmware = 3;
 * }
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DFUResponse")))
@interface BridgeDFUResponse : BridgeBase
- (instancetype)initWithDeviceId:(uint32_t)deviceId dfuVersion:(NSString *)dfuVersion dfuImage:(BridgeKotlinByteArray *)dfuImage oobRequest:(BridgeKotlinByteArray *)oobRequest __attribute__((swift_name("init(deviceId:dfuVersion:dfuImage:oobRequest:)"))) __attribute__((objc_designated_initializer));
- (BridgeDFUResponse *)doCopyDeviceId:(uint32_t)deviceId dfuVersion:(NSString *)dfuVersion dfuImage:(BridgeKotlinByteArray *)dfuImage oobRequest:(BridgeKotlinByteArray *)oobRequest __attribute__((swift_name("doCopy(deviceId:dfuVersion:dfuImage:oobRequest:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Matches the DFU object from link.proto
 *
 * Copy has to be created since protos cannot be used in commonMain declarations since protos aren't
 * present natively in iOSMain side of KMM. Hopefully by end of Summer 2025, update is released to resolve
 * this issue
 *
 * Reference DFU proto:
 * message DFU {
 * 	optional uint32 device_id = 1;
 * 	optional string firmware_name = 2;
 * 	optional bytes firmware = 3;
 * }
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property uint32_t deviceId __attribute__((swift_name("deviceId")));
@property BridgeKotlinByteArray *dfuImage __attribute__((swift_name("dfuImage")));
@property NSString *dfuVersion __attribute__((swift_name("dfuVersion")));
@property BridgeKotlinByteArray *oobRequest __attribute__((swift_name("oobRequest")));
@end


/**
 * Exposes performing functionality for Device Firmware Upgrades on supported Last Lock BLE devices
 * Class handles the entire bridge - device DFU process including DFU image fetching and validation,
 * and conducting the firmware upgrade.
 *
 * Validate and fetch
 *
 * Assumption: As of internal-libs v1.2, only multi-image DFUs are supported. A .zip file is expected
 * that contains the individual DFU images (application_core and network_core) along with a manifest.json.
 * Failure to include manifest.json will result in the entire process getting aborted.
 *
 * Note: To avoid deadlocking Last Lock device in DFU mode, enable DFU mode only if the DFU images pass
 * the validation checks
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DFUService")))
@interface BridgeDFUService : BridgeBlueLinkEventListener
- (instancetype)initWithIOSDFUDriver:(id<BridgeDFUDriverImplementation> _Nullable)iOSDFUDriver iOSDFUImageManager:(id<BridgeGRPCDFUImageManager> _Nullable)iOSDFUImageManager iOSZipProvider:(id<BridgeZipPackageInterface> _Nullable)iOSZipProvider blueLink:(BridgeBlueLink *)blueLink proxy:(BridgeBLEProxy *)proxy __attribute__((swift_name("init(iOSDFUDriver:iOSDFUImageManager:iOSZipProvider:blueLink:proxy:)"))) __attribute__((objc_designated_initializer));

/**
 * Listener for general BLE events with optional callbacks.
 *
 * Default implementations are provided for all methods, allowing implementors
 * to override only the methods they need.
 */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
@property (class, readonly, getter=companion) BridgeDFUServiceCompanion *companion __attribute__((swift_name("companion")));

/**
 * Exits install mode by sending a reboot command.
 * If device has DFU service available, uses SMP group 1 (reboot).
 * Otherwise, this method should not be called (device is not in install mode).
 *
 * @param deviceId The device ID to reboot
 * @return true if command was sent successfully
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)exitInstallModeDevice:(BridgeBluetoothDevice *)device completionHandler:(void (^)(BridgeBoolean * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("exitInstallMode(device:completionHandler:)")));

/**
 * Fetches firmware image for the provided device and assigns it to the internal states of that DFU Device.
 * On successful retrieval of the image, true is returned and on absence of any image or error in
 * fetching the image, false is the return value.
 *
 * Under the hood this function also persists the DFU Image to be used for initiating DFU as well as performs
 * validation checks against the image to ensure healthy DFU
 *
 * @return DFUResponse for device or null if no updates avail from Link
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)fetchFirmwareUpdateImageDevice:(BridgeBluetoothDevice *)device completionHandler:(void (^)(BridgeDFUResponse * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("fetchFirmwareUpdateImage(device:completionHandler:)")));
- (BridgeDeviceFirmwareVersion * _Nullable)getFirmwareVersionDevice:(BridgeBluetoothDevice *)device __attribute__((swift_name("getFirmwareVersion(device:)")));

/**
 * Sends an identify command to the device.
 * If device has DFU service available, uses SMP group 64.
 * Otherwise, uses OOB characteristic.
 *
 * @param deviceId The device ID to identify
 * @param oobPayload The OOB payload to send if DFU service is not available
 * @return true if command was sent successfully
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)identifyDeviceDevice:(BridgeBluetoothDevice *)device oobPayload:(BridgeKotlinByteArray *)oobPayload completionHandler:(void (^)(BridgeBoolean * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("identifyDevice(device:oobPayload:completionHandler:)")));

/**
 * Starts the DFU process for the provided Device. This is called when the device is already in DFU mode.
 * It sets states and allows for DFU to begin.
 *
 * Precursor: DFUService.fetchFirmwareUpdateImage() has been called successfully before running this fn
 *
 * @return DFUResult or null if no errors
 */
- (BridgeDFUErrors * _Nullable)initiateDFUDevice:(BridgeBluetoothDevice *)device __attribute__((swift_name("initiateDFU(device:)")));

/**
 * Resets all internal states, to be called after DFU completion or abort
 */
- (void)resetDFUStates __attribute__((swift_name("resetDFUStates()")));
@property id<BridgeDFUServiceListener> _Nullable dfuListener __attribute__((swift_name("dfuListener")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DFUService.Companion")))
@interface BridgeDFUServiceCompanion : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeDFUServiceCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *TAG __attribute__((swift_name("TAG")));
@end

__attribute__((swift_name("DFUServiceListener")))
@protocol BridgeDFUServiceListener
@required
- (void)onProgressChangedPct:(float)pct __attribute__((swift_name("onProgressChanged(pct:)")));
- (void)onStateChangedState:(BridgeDFUState *)state __attribute__((swift_name("onStateChanged(state:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DFUState")))
@interface BridgeDFUState : BridgeKotlinEnum<BridgeDFUState *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) BridgeDFUState *sleep __attribute__((swift_name("sleep")));
@property (class, readonly) BridgeDFUState *dfuOperationQueued __attribute__((swift_name("dfuOperationQueued")));
@property (class, readonly) BridgeDFUState *dfuInProgress __attribute__((swift_name("dfuInProgress")));
@property (class, readonly) BridgeDFUState *completed __attribute__((swift_name("completed")));
@property (class, readonly) BridgeDFUState *failed __attribute__((swift_name("failed")));
+ (BridgeKotlinArray<BridgeDFUState *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<BridgeDFUState *> *entries __attribute__((swift_name("entries")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FileEntry")))
@interface BridgeFileEntry : BridgeBase
- (instancetype)initWithImageIndex:(NSString *)imageIndex fileName:(NSString *)fileName firmwareVersion:(NSString * _Nullable)firmwareVersion size:(int32_t)size __attribute__((swift_name("init(imageIndex:fileName:firmwareVersion:size:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) BridgeFileEntryCompanion *companion __attribute__((swift_name("companion")));
- (BridgeFileEntry *)doCopyImageIndex:(NSString *)imageIndex fileName:(NSString *)fileName firmwareVersion:(NSString * _Nullable)firmwareVersion size:(int32_t)size __attribute__((swift_name("doCopy(imageIndex:fileName:firmwareVersion:size:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="file")
*/
@property (readonly) NSString *fileName __attribute__((swift_name("fileName")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="version_MCUBOOT")
*/
@property (readonly) NSString * _Nullable firmwareVersion __attribute__((swift_name("firmwareVersion")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="image_index")
*/
@property (readonly) NSString *imageIndex __attribute__((swift_name("imageIndex")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="size")
*/
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FileEntry.Companion")))
@interface BridgeFileEntryCompanion : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeFileEntryCompanion *shared __attribute__((swift_name("shared")));
- (id<BridgeKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FilePayload")))
@interface BridgeFilePayload : BridgeBase
- (instancetype)initWithFileName:(NSString *)fileName rawBytes:(BridgeKotlinByteArray *)rawBytes __attribute__((swift_name("init(fileName:rawBytes:)"))) __attribute__((objc_designated_initializer));
- (BridgeFilePayload *)doCopyFileName:(NSString *)fileName rawBytes:(BridgeKotlinByteArray *)rawBytes __attribute__((swift_name("doCopy(fileName:rawBytes:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *fileName __attribute__((swift_name("fileName")));
@property (readonly) BridgeKotlinByteArray *rawBytes __attribute__((swift_name("rawBytes")));
@end

__attribute__((swift_name("GRPCDFUImageManager")))
@protocol BridgeGRPCDFUImageManager
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getDFUResponseDeviceId:(uint32_t)deviceId currentFirmwareVersion:(BridgeDeviceFirmwareVersion * _Nullable)currentFirmwareVersion completionHandler:(void (^)(BridgeDFUResponse * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("getDFUResponse(deviceId:currentFirmwareVersion:completionHandler:)")));
@end


/**
 * Manifest FileEntry definitions used for parsing through manifest.json in the DFU zip files
 *
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Manifest")))
@interface BridgeManifest : BridgeBase
- (instancetype)initWithFormatVersion:(int32_t)formatVersion files:(NSArray<BridgeFileEntry *> *)files __attribute__((swift_name("init(formatVersion:files:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) BridgeManifestCompanion *companion __attribute__((swift_name("companion")));
- (BridgeManifest *)doCopyFormatVersion:(int32_t)formatVersion files:(NSArray<BridgeFileEntry *> *)files __attribute__((swift_name("doCopy(formatVersion:files:)")));

/**
 * Manifest FileEntry definitions used for parsing through manifest.json in the DFU zip files
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Manifest FileEntry definitions used for parsing through manifest.json in the DFU zip files
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Manifest FileEntry definitions used for parsing through manifest.json in the DFU zip files
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSArray<BridgeFileEntry *> *files __attribute__((swift_name("files")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="format-version")
*/
@property (readonly) int32_t formatVersion __attribute__((swift_name("formatVersion")));
@end


/**
 * Manifest FileEntry definitions used for parsing through manifest.json in the DFU zip files
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Manifest.Companion")))
@interface BridgeManifestCompanion : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Manifest FileEntry definitions used for parsing through manifest.json in the DFU zip files
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeManifestCompanion *shared __attribute__((swift_name("shared")));

/**
 * Manifest FileEntry definitions used for parsing through manifest.json in the DFU zip files
 */
- (id<BridgeKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * Used for storing DFU image parsed in a usable format. FileEntries are listed out by each file
 * where each entry is a Pair with the key being the imageIndex of that DFU image and value being the raw bytes.
 * Firmware version parsed from manifest.json is also included here as well
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ParsedManifest")))
@interface BridgeParsedManifest : BridgeBase
- (instancetype)initWithFileEntries:(NSArray<BridgeKotlinPair<BridgeInt *, BridgeFilePayload *> *> *)fileEntries firmwareVersion:(NSString *)firmwareVersion __attribute__((swift_name("init(fileEntries:firmwareVersion:)"))) __attribute__((objc_designated_initializer));
- (BridgeParsedManifest *)doCopyFileEntries:(NSArray<BridgeKotlinPair<BridgeInt *, BridgeFilePayload *> *> *)fileEntries firmwareVersion:(NSString *)firmwareVersion __attribute__((swift_name("doCopy(fileEntries:firmwareVersion:)")));

/**
 * Used for storing DFU image parsed in a usable format. FileEntries are listed out by each file
 * where each entry is a Pair with the key being the imageIndex of that DFU image and value being the raw bytes.
 * Firmware version parsed from manifest.json is also included here as well
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Used for storing DFU image parsed in a usable format. FileEntries are listed out by each file
 * where each entry is a Pair with the key being the imageIndex of that DFU image and value being the raw bytes.
 * Firmware version parsed from manifest.json is also included here as well
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Used for storing DFU image parsed in a usable format. FileEntries are listed out by each file
 * where each entry is a Pair with the key being the imageIndex of that DFU image and value being the raw bytes.
 * Firmware version parsed from manifest.json is also included here as well
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSArray<BridgeKotlinPair<BridgeInt *, BridgeFilePayload *> *> *fileEntries __attribute__((swift_name("fileEntries")));
@property (readonly) NSString *firmwareVersion __attribute__((swift_name("firmwareVersion")));
@end

__attribute__((swift_name("ZipPackageInterface")))
@protocol BridgeZipPackageInterface
@required
- (NSDictionary<NSString *, BridgeKotlinByteArray *> *)extractFiles __attribute__((swift_name("extractFiles()")));
- (NSDictionary<NSString *, BridgeKotlinByteArray *> *)getBinaries __attribute__((swift_name("getBinaries()")));
- (BridgeKotlinByteArray * _Nullable)getManifest __attribute__((swift_name("getManifest()")));
- (void)readZipZipData:(BridgeKotlinByteArray *)zipData __attribute__((swift_name("readZip(zipData:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BLEProxy")))
@interface BridgeBLEProxy : BridgeBase <BridgeConnectivityListener>
- (instancetype)initWithMessageStreamManager:(id<BridgeIOSMessageStreamManager> _Nullable)messageStreamManager blueLink:(BridgeBlueLink *)blueLink networkConnectivityMonitor:(BridgeNetworkConnectivityMonitor *)networkConnectivityMonitor persistenceManager:(BridgePersistenceManager *)persistenceManager iOSTrueTimeManager:(id<BridgeITrueTimeManager> _Nullable)iOSTrueTimeManager __attribute__((swift_name("init(messageStreamManager:blueLink:networkConnectivityMonitor:persistenceManager:iOSTrueTimeManager:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) BridgeBLEProxyCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)checkDeviceBatteryStatusLowDeviceId:(uint32_t)deviceId __attribute__((swift_name("checkDeviceBatteryStatusLow(deviceId:)")));
- (BOOL)checkDeviceIsBlacklistedDeviceId:(uint32_t)deviceId __attribute__((swift_name("checkDeviceIsBlacklisted(deviceId:)")));
- (BridgeDeviceFirmwareVersion * _Nullable)checkDeviceOutstandingInstallDFUDeviceId:(uint32_t)deviceId __attribute__((swift_name("checkDeviceOutstandingInstallDFU(deviceId:)")));
- (void)collectOOBPayloads __attribute__((swift_name("collectOOBPayloads()")));
- (void)didChangeConnectivityIsConnected:(BOOL)isConnected __attribute__((swift_name("didChangeConnectivity(isConnected:)")));
- (BridgeProxyDevice *)fetchOrCreateDeviceDevice:(BridgeBluetoothDevice *)device accessId:(uint32_t)accessId __attribute__((swift_name("fetchOrCreateDevice(device:accessId:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getDevicesOnStreamWithCompletionHandler:(void (^)(NSArray<BridgeUInt *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getDevicesOnStream(completionHandler:)")));
- (BridgeServerResponseStateUpdate * _Nullable)getHighestServerPayloadDeviceId:(uint32_t)deviceId __attribute__((swift_name("getHighestServerPayload(deviceId:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)isStreamAliveWithCompletionHandler:(void (^)(BridgeBoolean * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("isStreamAlive(completionHandler:)")));
- (BOOL)purgePersistedPayloadsDeviceId:(uint32_t)deviceId __attribute__((swift_name("purgePersistedPayloads(deviceId:)")));
- (void)sendIdentifyOOBDeviceId:(uint32_t)deviceId payload:(BridgeKotlinByteArray *)payload __attribute__((swift_name("sendIdentifyOOB(deviceId:payload:)")));

/**
 * Allows implementors to write payloads to the OOB Characteristic bypassing Link
 * Note: This feature is to be used with utmost care as wrong / malformed operations could
 * negatively impact the device
 */
- (void)sendOOBToDeviceDeviceId:(uint32_t)deviceId payload:(BridgeKotlinByteArray *)payload __attribute__((swift_name("sendOOBToDevice(deviceId:payload:)")));
- (void)setProxyPausedIsPaused:(BOOL)isPaused __attribute__((swift_name("setProxyPaused(isPaused:)")));
- (void)startStreaming __attribute__((swift_name("startStreaming()")));
- (void)stopStreamingAndClearDevices __attribute__((swift_name("stopStreamingAndClearDevices()")));
@property (readonly) BridgeBlueLink *blueLink __attribute__((swift_name("blueLink")));
@property (readonly) id<BridgeKotlinx_coroutines_coreCoroutineScope> coroutineScope __attribute__((swift_name("coroutineScope")));
@property (readonly) id<BridgeKotlinx_coroutines_coreStateFlow> networkAvailable __attribute__((swift_name("networkAvailable")));
@property id<BridgeKotlinx_coroutines_coreMutableStateFlow> proxyPaused __attribute__((swift_name("proxyPaused")));
@property (readonly) id<BridgeITrueTimeManager> trueTimeManager __attribute__((swift_name("trueTimeManager")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BLEProxy.Companion")))
@interface BridgeBLEProxyCompanion : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeBLEProxyCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *TAG __attribute__((swift_name("TAG")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeviceTaskExecutor")))
@interface BridgeDeviceTaskExecutor : BridgeBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)executeDeviceId:(uint32_t)deviceId task:(id<BridgeKotlinSuspendFunction0>)task __attribute__((swift_name("execute(deviceId:task:)")));
- (void)shutdown __attribute__((swift_name("shutdown()")));
@end

__attribute__((swift_name("IOSMessageStreamManager")))
@protocol BridgeIOSMessageStreamManager
@required
- (void)addDeviceToStreamDeviceId:(uint32_t)deviceId __attribute__((swift_name("addDeviceToStream(deviceId:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getActiveDevicesWithCompletionHandler:(void (^)(NSArray<BridgeUInt *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getActiveDevices(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)isStreamActiveWithCompletionHandler:(void (^)(BridgeBoolean * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("isStreamActive(completionHandler:)")));
- (void)processStreamResponseResponse:(id)response __attribute__((swift_name("processStreamResponse(response:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)pushEncryptedMessagesDeviceId:(uint32_t)deviceId payloads:(NSArray<BridgeKotlinByteArray *> *)payloads isHeartbeat:(BOOL)isHeartbeat completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("pushEncryptedMessages(deviceId:payloads:isHeartbeat:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)removeDeviceFromStreamDeviceId:(uint32_t)deviceId completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("removeDeviceFromStream(deviceId:completionHandler:)")));
- (void)setOOBHandlerHandleOOBResponse:(void (^)(id<BridgeOOBWrapper> _Nullable))handleOOBResponse __attribute__((swift_name("setOOBHandler(handleOOBResponse:)")));
- (void)shutdown __attribute__((swift_name("shutdown()")));
- (void)streamMessagesFromServerPersistenceManager:(BridgePersistenceManager *)persistenceManager __attribute__((swift_name("streamMessagesFromServer(persistenceManager:)")));
@property NSString *serverAddress __attribute__((swift_name("serverAddress")));
@end

__attribute__((swift_name("MessageStreamManager")))
@protocol BridgeMessageStreamManager
@required
- (void)addDeviceToStreamDeviceId:(uint32_t)deviceId __attribute__((swift_name("addDeviceToStream(deviceId:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getActiveDevicesWithCompletionHandler:(void (^)(NSArray<BridgeUInt *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getActiveDevices(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)isStreamActiveWithCompletionHandler:(void (^)(BridgeBoolean * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("isStreamActive(completionHandler:)")));
- (void)processStreamResponseResponse:(id)response __attribute__((swift_name("processStreamResponse(response:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)pushEncryptedMessagesDeviceId:(uint32_t)deviceId payloads:(NSArray<BridgeKotlinByteArray *> *)payloads isHeartbeat:(BOOL)isHeartbeat completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("pushEncryptedMessages(deviceId:payloads:isHeartbeat:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)removeDeviceFromStreamDeviceId:(uint32_t)deviceId completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("removeDeviceFromStream(deviceId:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)shutdownWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("shutdown(completionHandler:)")));
- (void)streamMessagesFromServer __attribute__((swift_name("streamMessagesFromServer()")));
@property (readonly) id<BridgeKotlinx_coroutines_coreMutableSharedFlow> oobStateFlow __attribute__((swift_name("oobStateFlow")));
@property (readonly) BridgePersistenceManager *persistenceManager __attribute__((swift_name("persistenceManager")));
@end

__attribute__((swift_name("OOBWrapper")))
@protocol BridgeOOBWrapper
@required
@property (readonly) BridgeKotlinByteArray *bytes __attribute__((swift_name("bytes")));
@property (readonly) uint32_t deviceId __attribute__((swift_name("deviceId")));
@property (readonly) BridgeDeviceFirmwareVersion * _Nullable dfuVersion __attribute__((swift_name("dfuVersion")));
@property (readonly) BridgeLong * _Nullable timestamp __attribute__((swift_name("timestamp")));
@property (readonly) BridgeDeviceOperation *type __attribute__((swift_name("type")));
@end


/** Represents a BLE Device and its associated properties and operations. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ProxyDevice")))
@interface BridgeProxyDevice : BridgeBase
- (instancetype)initWithPeripheral:(BridgeBluetoothDevice * _Nullable)peripheral deviceId:(uint32_t)deviceId proxyTaskQueue:(BridgeTaskQueue *)proxyTaskQueue internalCache:(BridgeBridgeCache *)internalCache taskExecutor:(BridgeDeviceTaskExecutor *)taskExecutor batteryStatusLow:(BOOL)batteryStatusLow cachedDevicePayloads:(NSMutableArray<BridgeKotlinByteArray *> *)cachedDevicePayloads lastInstallOOBTimestamp:(BridgeLong * _Nullable)lastInstallOOBTimestamp lastTimeSyncOOBTimestamp:(BridgeLong * _Nullable)lastTimeSyncOOBTimestamp lastResetOOBTimestamp:(BridgeLong * _Nullable)lastResetOOBTimestamp lastUnknownOOBTimestamp:(BridgeLong * _Nullable)lastUnknownOOBTimestamp lastIdentifyOOBTimestamp:(BridgeLong * _Nullable)lastIdentifyOOBTimestamp outstandingInstallDFU:(BridgeDeviceFirmwareVersion * _Nullable)outstandingInstallDFU lastRecoveryOOBTimestamp:(BridgeLong * _Nullable)lastRecoveryOOBTimestamp __attribute__((swift_name("init(peripheral:deviceId:proxyTaskQueue:internalCache:taskExecutor:batteryStatusLow:cachedDevicePayloads:lastInstallOOBTimestamp:lastTimeSyncOOBTimestamp:lastResetOOBTimestamp:lastUnknownOOBTimestamp:lastIdentifyOOBTimestamp:outstandingInstallDFU:lastRecoveryOOBTimestamp:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) BridgeProxyDeviceCompanion *companion __attribute__((swift_name("companion")));
- (void)addCachedPayloadPayload:(BridgeKotlinByteArray *)payload __attribute__((swift_name("addCachedPayload(payload:)")));

/** Adds an event to the device's task queue */
- (BOOL)addProxyQueueEventEvent:(BridgeTaskElement *)event __attribute__((swift_name("addProxyQueueEvent(event:)")));

/**
 * Clears accepted payloads from the map based on their type:
 * - ACKs are cleared when DSC <= currentDSC
 * - Writes are cleared when PSC <= currentSSC
 * This matches the logic in PersistenceManager.removeStaleServerStateUpdatesForDevice
 */
- (void)clearAcceptedPayloadsCurrentDSC:(int32_t)currentDSC currentSSC:(int32_t)currentSSC __attribute__((swift_name("clearAcceptedPayloads(currentDSC:currentSSC:)")));
- (void)clearCachedPayloads __attribute__((swift_name("clearCachedPayloads()")));

/** Removes all events of specific operation types */
- (void)clearEventsByTypesOperations:(NSArray<BridgeDeviceOperation *> *)operations __attribute__((swift_name("clearEventsByTypes(operations:)")));

/** Deletes a specific event from the task queue. */
- (BOOL)deleteEventFromProxyQueueEvent:(BridgeTaskElement *)event __attribute__((swift_name("deleteEventFromProxyQueue(event:)")));
- (NSArray<BridgeKotlinByteArray *> *)fetchCachedPayloads __attribute__((swift_name("fetchCachedPayloads()")));

/** Helper function to fetch the corresponding event from the proxy queue */
- (BridgeTaskElement * _Nullable)fetchCurrentEventFromQueueOperation:(BridgeBlueLinkOperation *)operation __attribute__((swift_name("fetchCurrentEventFromQueue(operation:)")));

/** Fetches events from the task queue based on their state and operation type. */
- (NSArray<BridgeTaskElement *> *)getQueueEventsOperation:(BridgeDeviceOperation * _Nullable)operation state:(BridgeTaskElementState * _Nullable)state __attribute__((swift_name("getQueueEvents(operation:state:)")));
- (BOOL)hasScheduledOOB __attribute__((swift_name("hasScheduledOOB()")));

/**
 * Increments a payload count.
 * If the payload isn't yet tracked, it logs a warning and returns 0 (this is an error)
 * If already tracked, increments the count.
 *
 * @param payload The payload to increment
 * @return The count after incrementing (if already tracked), or 0 (if not found)
 */
- (int32_t)incrementPayloadCountPayload:(BridgeKotlinByteArray *)payload __attribute__((swift_name("incrementPayloadCount(payload:)")));

/** Logs out the current state of the device, including its task queue and properties. */
- (NSString *)toLog __attribute__((swift_name("toLog()")));

/**
 * Tracks a payload count.
 * If the payload isn't yet tracked, adds it at 0 (does NOT increment it), else does nothing.
 *
 * @param payload The payload to track/increment
 * @param isAck Whether this is an ACK payload (only used if payload doesn't exist yet)
 * @param dsc Device state counter (for ACKs, null for writes, only used if payload doesn't exist yet)
 * @param psc Payload state counter (for writes, or for ACKs that have PSC, only used if payload doesn't exist yet)
 */
- (void)trackPayloadPayload:(BridgeKotlinByteArray *)payload isAck:(BOOL)isAck dsc:(BridgeInt * _Nullable)dsc psc:(int32_t)psc __attribute__((swift_name("trackPayload(payload:isAck:dsc:psc:)")));
@property BOOL batteryStatusLow __attribute__((swift_name("batteryStatusLow")));
@property NSMutableArray<BridgeKotlinByteArray *> *cachedDevicePayloads __attribute__((swift_name("cachedDevicePayloads")));
@property uint32_t deviceId __attribute__((swift_name("deviceId")));
@property BridgeBridgeCache *internalCache __attribute__((swift_name("internalCache")));
@property BOOL isBlacklisted __attribute__((swift_name("isBlacklisted")));
@property BridgeKotlinx_datetimeInstant * _Nullable lastDiscoveryTime __attribute__((swift_name("lastDiscoveryTime")));
@property BridgeLong * _Nullable lastIdentifyOOBTimestamp __attribute__((swift_name("lastIdentifyOOBTimestamp")));
@property BridgeLong * _Nullable lastInstallOOBTimestamp __attribute__((swift_name("lastInstallOOBTimestamp")));
@property BridgeLong * _Nullable lastRecoveryOOBTimestamp __attribute__((swift_name("lastRecoveryOOBTimestamp")));
@property BridgeLong * _Nullable lastResetOOBTimestamp __attribute__((swift_name("lastResetOOBTimestamp")));
@property BridgeLong * _Nullable lastTimeSyncOOBTimestamp __attribute__((swift_name("lastTimeSyncOOBTimestamp")));
@property BridgeLong * _Nullable lastUnknownOOBTimestamp __attribute__((swift_name("lastUnknownOOBTimestamp")));
@property BridgeDeviceFirmwareVersion * _Nullable outstandingInstallDFU __attribute__((swift_name("outstandingInstallDFU")));
@property BOOL performingProxyOperation __attribute__((swift_name("performingProxyOperation")));
@property BridgeBluetoothDevice * _Nullable peripheral __attribute__((swift_name("peripheral")));
@property BridgeTaskQueue *proxyTaskQueue __attribute__((swift_name("proxyTaskQueue")));
@property (readonly) BridgeDeviceTaskExecutor *taskExecutor __attribute__((swift_name("taskExecutor")));
@property int32_t timeSyncFailureCount __attribute__((swift_name("timeSyncFailureCount")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ProxyDevice.Companion")))
@interface BridgeProxyDeviceCompanion : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeProxyDeviceCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ProxyProvider")))
@interface BridgeProxyProvider : BridgeBase <BridgeKoin_coreKoinComponent>
- (instancetype)initWithMessageStreamManager:(id<BridgeIOSMessageStreamManager> _Nullable)messageStreamManager heartbeatParser:(id<BridgeIHeartbeatParser> _Nullable)heartbeatParser iOSTrueTimeManager:(id<BridgeITrueTimeManager> _Nullable)iOSTrueTimeManager __attribute__((swift_name("init(messageStreamManager:heartbeatParser:iOSTrueTimeManager:)"))) __attribute__((objc_designated_initializer));
@property (readonly) BridgeBLEProxy *proxy __attribute__((swift_name("proxy")));
@end


/** Represents the full server response.
 *
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ServerResponse")))
@interface BridgeServerResponse : BridgeBase
- (instancetype)initWithStateUpdates:(NSMutableArray<BridgeServerResponseStateUpdate *> *)stateUpdates __attribute__((swift_name("init(stateUpdates:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) BridgeServerResponseCompanion *companion __attribute__((swift_name("companion")));
- (BridgeServerResponse *)doCopyStateUpdates:(NSMutableArray<BridgeServerResponseStateUpdate *> *)stateUpdates __attribute__((swift_name("doCopy(stateUpdates:)")));

/** Represents the full server response. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Represents the full server response. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Represents the full server response. */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSMutableArray<BridgeServerResponseStateUpdate *> *stateUpdates __attribute__((swift_name("stateUpdates")));
@end


/** Represents the full server response. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ServerResponse.Companion")))
@interface BridgeServerResponseCompanion : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));

/** Represents the full server response. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeServerResponseCompanion *shared __attribute__((swift_name("shared")));

/** Represents the full server response. */
- (id<BridgeKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/** Represents an update within the server response.
 *
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ServerResponseStateUpdate")))
@interface BridgeServerResponseStateUpdate : BridgeBase
- (instancetype)initWithPsc:(int32_t)psc payload:(BridgeKotlinByteArray *)payload dsc:(BridgeInt * _Nullable)dsc isAck:(BOOL)isAck __attribute__((swift_name("init(psc:payload:dsc:isAck:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) BridgeServerResponseStateUpdateCompanion *companion __attribute__((swift_name("companion")));
- (BridgeServerResponseStateUpdate *)doCopyPsc:(int32_t)psc payload:(BridgeKotlinByteArray *)payload dsc:(BridgeInt * _Nullable)dsc isAck:(BOOL)isAck __attribute__((swift_name("doCopy(psc:payload:dsc:isAck:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Represents an update within the server response. */
- (NSString *)description __attribute__((swift_name("description()")));
@property BridgeInt * _Nullable dsc __attribute__((swift_name("dsc")));
@property BOOL isAck __attribute__((swift_name("isAck")));
@property (readonly) BridgeKotlinByteArray *payload __attribute__((swift_name("payload")));
@property (readonly) int32_t psc __attribute__((swift_name("psc")));
@end


/** Represents an update within the server response. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ServerResponseStateUpdate.Companion")))
@interface BridgeServerResponseStateUpdateCompanion : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));

/** Represents an update within the server response. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeServerResponseStateUpdateCompanion *shared __attribute__((swift_name("shared")));

/** Represents an update within the server response. */
- (id<BridgeKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * Defines the list of operations that can be performed by the library with the device.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeviceOperation")))
@interface BridgeDeviceOperation : BridgeKotlinEnum<BridgeDeviceOperation *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Defines the list of operations that can be performed by the library with the device.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) BridgeDeviceOperation *deviceRead __attribute__((swift_name("deviceRead")));
@property (class, readonly) BridgeDeviceOperation *deviceWrite __attribute__((swift_name("deviceWrite")));
@property (class, readonly) BridgeDeviceOperation *error __attribute__((swift_name("error")));
@property (class, readonly) BridgeDeviceOperation *timeSync __attribute__((swift_name("timeSync")));
@property (class, readonly) BridgeDeviceOperation *installOob __attribute__((swift_name("installOob")));
@property (class, readonly) BridgeDeviceOperation *resetOob __attribute__((swift_name("resetOob")));
@property (class, readonly) BridgeDeviceOperation *unknownOob __attribute__((swift_name("unknownOob")));
@property (class, readonly) BridgeDeviceOperation *recoveryOob __attribute__((swift_name("recoveryOob")));
@property (class, readonly) BridgeDeviceOperation *identifyOob __attribute__((swift_name("identifyOob")));
+ (BridgeKotlinArray<BridgeDeviceOperation *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<BridgeDeviceOperation *> *entries __attribute__((swift_name("entries")));
- (BridgeBlueLinkOperationType *)blueLinkOperationType __attribute__((swift_name("blueLinkOperationType()")));
- (BOOL)isOOBOperation __attribute__((swift_name("isOOBOperation()")));

/**
 * Provides a string representation of the operation.
 */
- (NSString *)description __attribute__((swift_name("description()")));
@end


/** Data classes for persisted payloads.
 *
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeviceGeneratedPersistedPayload")))
@interface BridgeDeviceGeneratedPersistedPayload : BridgeBase
- (instancetype)initWithDeviceId:(uint32_t)deviceId payload:(NSArray<BridgeKotlinByteArray *> *)payload creationTimestamp:(BridgeKotlinx_datetimeInstant *)creationTimestamp __attribute__((swift_name("init(deviceId:payload:creationTimestamp:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) BridgeDeviceGeneratedPersistedPayloadCompanion *companion __attribute__((swift_name("companion")));
- (BridgeDeviceGeneratedPersistedPayload *)doCopyDeviceId:(uint32_t)deviceId payload:(NSArray<BridgeKotlinByteArray *> *)payload creationTimestamp:(BridgeKotlinx_datetimeInstant *)creationTimestamp __attribute__((swift_name("doCopy(deviceId:payload:creationTimestamp:)")));

/** Data classes for persisted payloads. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Data classes for persisted payloads. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Data classes for persisted payloads. */
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
@property (readonly) BridgeKotlinx_datetimeInstant *creationTimestamp __attribute__((swift_name("creationTimestamp")));
@property (readonly) uint32_t deviceId __attribute__((swift_name("deviceId")));
@property (readonly) NSArray<BridgeKotlinByteArray *> *payload __attribute__((swift_name("payload")));
@end


/** Data classes for persisted payloads. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeviceGeneratedPersistedPayload.Companion")))
@interface BridgeDeviceGeneratedPersistedPayloadCompanion : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));

/** Data classes for persisted payloads. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeDeviceGeneratedPersistedPayloadCompanion *shared __attribute__((swift_name("shared")));

/** Data classes for persisted payloads. */
- (id<BridgeKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/** Singleton persistence manager for managing persisted payloads. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PersistenceManager")))
@interface BridgePersistenceManager : BridgeBase

/** Singleton persistence manager for managing persisted payloads. */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/** Singleton persistence manager for managing persisted payloads. */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (class, readonly, getter=companion) BridgePersistenceManagerCompanion *companion __attribute__((swift_name("companion")));

/** Delete the persisted payload from the device for a specific device ID. */
- (BOOL)deleteAllPersistedPayloadFromDeviceDeviceId:(NSString *)deviceId __attribute__((swift_name("deleteAllPersistedPayloadFromDevice(deviceId:)")));

/** Delete the persisted payload from the server for a specific device ID. */
- (BOOL)deletePersistedPayloadFromServerDeviceId:(NSString *)deviceId __attribute__((swift_name("deletePersistedPayloadFromServer(deviceId:)")));

/** Fetch all device-generated persisted payloads. */
- (NSArray<BridgeDeviceGeneratedPersistedPayload *> *)fetchAllDeviceGeneratedPersistedPayload __attribute__((swift_name("fetchAllDeviceGeneratedPersistedPayload()")));

/** Fetch all persisted server-issued payloads. */
- (NSArray<BridgeServerGeneratedPersistedPayload *> *)fetchAllServerIssuedPayloads __attribute__((swift_name("fetchAllServerIssuedPayloads()")));

/** Fetch persisted payloads from the server for a specific device ID. */
- (BridgeServerGeneratedPersistedPayload * _Nullable)fetchPersistedPayloadsFromServerDeviceId:(NSString *)deviceId __attribute__((swift_name("fetchPersistedPayloadsFromServer(deviceId:)")));

/** Persist payloads sent from the device for a specific device ID. */
- (BOOL)persistPayloadFromDeviceDeviceId:(uint32_t)deviceId payload:(NSArray<BridgeKotlinByteArray *> *)payload __attribute__((swift_name("persistPayloadFromDevice(deviceId:payload:)")));

/** Persist payloads sent from the server for a specific device ID. */
- (BOOL)persistPayloadFromServerDeviceId:(uint32_t)deviceId payload:(BridgeServerResponse *)payload __attribute__((swift_name("persistPayloadFromServer(deviceId:payload:)")));

/**
 * Removes stale server state updates for a device, based on its current DSC and SSC.
 *
 * Returns the updated persisted payload if changes were made, null if:
 *  - no payload file exists,
 *  - no updates were removed,
 *  - or an error occurred during decode/encode.
 *
 * If all updates are stale, the file is deleted and null is returned.
 */
- (BridgeServerGeneratedPersistedPayload * _Nullable)removeStaleServerStateUpdatesForDeviceDeviceId:(uint32_t)deviceId deviceDSC:(int32_t)deviceDSC deviceSSC:(int32_t)deviceSSC __attribute__((swift_name("removeStaleServerStateUpdatesForDevice(deviceId:deviceDSC:deviceSSC:)")));

/** Reset all persisted data by deleting the directory contents. */
- (void)resetPersistedData __attribute__((swift_name("resetPersistedData()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PersistenceManager.Companion")))
@interface BridgePersistenceManagerCompanion : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgePersistenceManagerCompanion *shared __attribute__((swift_name("shared")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ServerGeneratedPersistedPayload")))
@interface BridgeServerGeneratedPersistedPayload : BridgeBase
- (instancetype)initWithDeviceId:(uint32_t)deviceId payload:(BridgeServerResponse *)payload creationTimestamp:(BridgeKotlinx_datetimeInstant *)creationTimestamp __attribute__((swift_name("init(deviceId:payload:creationTimestamp:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) BridgeServerGeneratedPersistedPayloadCompanion *companion __attribute__((swift_name("companion")));
- (BridgeServerGeneratedPersistedPayload *)doCopyDeviceId:(uint32_t)deviceId payload:(BridgeServerResponse *)payload creationTimestamp:(BridgeKotlinx_datetimeInstant *)creationTimestamp __attribute__((swift_name("doCopy(deviceId:payload:creationTimestamp:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
@property (readonly) BridgeKotlinx_datetimeInstant *creationTimestamp __attribute__((swift_name("creationTimestamp")));
@property (readonly) uint32_t deviceId __attribute__((swift_name("deviceId")));
@property (readonly) BridgeServerResponse *payload __attribute__((swift_name("payload")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ServerGeneratedPersistedPayload.Companion")))
@interface BridgeServerGeneratedPersistedPayloadCompanion : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeServerGeneratedPersistedPayloadCompanion *shared __attribute__((swift_name("shared")));
- (id<BridgeKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BridgeCache")))
@interface BridgeBridgeCache : BridgeBase
- (instancetype)initWithAdvertisedDeviceState:(BridgeStates *)advertisedDeviceState fullDeviceState:(BridgeStates *)fullDeviceState __attribute__((swift_name("init(advertisedDeviceState:fullDeviceState:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) BridgeBridgeCacheCompanion *companion __attribute__((swift_name("companion")));
- (NSString *)description __attribute__((swift_name("description()")));
- (void)updateAdvStateCtrsDeviceStateCounter:(BridgeInt * _Nullable)deviceStateCounter serverStateCounter:(BridgeInt * _Nullable)serverStateCounter __attribute__((swift_name("updateAdvStateCtrs(deviceStateCounter:serverStateCounter:)")));
- (void)updateFullStateCtrsFullDeviceStateCounter:(BridgeInt * _Nullable)fullDeviceStateCounter fullServerStateCounter:(BridgeInt * _Nullable)fullServerStateCounter __attribute__((swift_name("updateFullStateCtrs(fullDeviceStateCounter:fullServerStateCounter:)")));
@property BridgeStates *advertisedDeviceState __attribute__((swift_name("advertisedDeviceState")));
@property BridgeStates *fullDeviceState __attribute__((swift_name("fullDeviceState")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BridgeCache.Companion")))
@interface BridgeBridgeCacheCompanion : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeBridgeCacheCompanion *shared __attribute__((swift_name("shared")));
- (id<BridgeKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("States")))
@interface BridgeStates : BridgeBase
- (instancetype)initWithDsc:(int32_t)dsc ssc:(int32_t)ssc __attribute__((swift_name("init(dsc:ssc:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) BridgeStatesCompanion *companion __attribute__((swift_name("companion")));
- (void)reset __attribute__((swift_name("reset()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property int32_t dsc __attribute__((swift_name("dsc")));
@property int32_t ssc __attribute__((swift_name("ssc")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("States.Companion")))
@interface BridgeStatesCompanion : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeStatesCompanion *shared __attribute__((swift_name("shared")));
- (id<BridgeKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * TaskElement - Defines an interface for actions performed on a Device including Writing and Reading data.
 *
 * Handles failures during payload transfer between the Device and the Bridge.
 *
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TaskElement")))
@interface BridgeTaskElement : BridgeBase
- (instancetype)initWithOperation:(BridgeDeviceOperation *)operation payload:(BridgeKotlinByteArray * _Nullable)payload timestamp:(BridgeKotlinx_datetimeInstant *)timestamp __attribute__((swift_name("init(operation:payload:timestamp:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithId:(BridgeUUID *)id operation:(BridgeDeviceOperation *)operation payload:(BridgeKotlinByteArray * _Nullable)payload timestamp:(BridgeKotlinx_datetimeInstant *)timestamp state:(BridgeTaskElementState *)state oobWrapper:(id<BridgeOOBWrapper> _Nullable)oobWrapper psc:(BridgeInt * _Nullable)psc __attribute__((swift_name("init(id:operation:payload:timestamp:state:oobWrapper:psc:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) BridgeTaskElementCompanion *companion __attribute__((swift_name("companion")));
- (BridgeTaskElement *)doCopyId:(BridgeUUID *)id operation:(BridgeDeviceOperation *)operation payload:(BridgeKotlinByteArray * _Nullable)payload timestamp:(BridgeKotlinx_datetimeInstant *)timestamp state:(BridgeTaskElementState *)state oobWrapper:(id<BridgeOOBWrapper> _Nullable)oobWrapper psc:(BridgeInt * _Nullable)psc __attribute__((swift_name("doCopy(id:operation:payload:timestamp:state:oobWrapper:psc:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=com/lastlock/bridge/proxy/proxyOperationQueue/UUIDSerializer))
*/
@property (readonly) BridgeUUID *id __attribute__((swift_name("id")));
@property id<BridgeOOBWrapper> _Nullable oobWrapper __attribute__((swift_name("oobWrapper")));
@property BridgeDeviceOperation *operation __attribute__((swift_name("operation")));
@property BridgeKotlinByteArray * _Nullable payload __attribute__((swift_name("payload")));
@property BridgeInt * _Nullable psc __attribute__((swift_name("psc")));
@property BridgeTaskElementState *state __attribute__((swift_name("state")));
@property BridgeKotlinx_datetimeInstant *timestamp __attribute__((swift_name("timestamp")));
@end


/**
 * TaskElement - Defines an interface for actions performed on a Device including Writing and Reading data.
 *
 * Handles failures during payload transfer between the Device and the Bridge.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TaskElement.Companion")))
@interface BridgeTaskElementCompanion : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));

/**
 * TaskElement - Defines an interface for actions performed on a Device including Writing and Reading data.
 *
 * Handles failures during payload transfer between the Device and the Bridge.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeTaskElementCompanion *shared __attribute__((swift_name("shared")));

/**
 * TaskElement - Defines an interface for actions performed on a Device including Writing and Reading data.
 *
 * Handles failures during payload transfer between the Device and the Bridge.
 */
- (id<BridgeKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * To track the state of the TaskElement event as it propagates through the pipeline system.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TaskElementState")))
@interface BridgeTaskElementState : BridgeKotlinEnum<BridgeTaskElementState *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * To track the state of the TaskElement event as it propagates through the pipeline system.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) BridgeTaskElementState *scheduled __attribute__((swift_name("scheduled")));
@property (class, readonly) BridgeTaskElementState *ongoing __attribute__((swift_name("ongoing")));
+ (BridgeKotlinArray<BridgeTaskElementState *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<BridgeTaskElementState *> *entries __attribute__((swift_name("entries")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * TaskQueue - A queue implementation for managing TaskElement instances.
 *
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TaskQueue")))
@interface BridgeTaskQueue : BridgeBase

/**
 * TaskQueue - A queue implementation for managing TaskElement instances.
 */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/**
 * TaskQueue - A queue implementation for managing TaskElement instances.
 */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (class, readonly, getter=companion) BridgeTaskQueueCompanion *companion __attribute__((swift_name("companion")));

/**
 * Removes and returns the specified TaskElement from the queue.
 * If the element is not found, logs a warning and returns null.
 */
- (BridgeTaskElement * _Nullable)dequeueElement:(BridgeTaskElement *)element __attribute__((swift_name("dequeue(element:)")));

/**
 * Adds a TaskElement to the queue.
 */
- (void)enqueueElement:(BridgeTaskElement *)element __attribute__((swift_name("enqueue(element:)")));

/**
 * Returns a copy of the full queue.
 */
- (NSArray<BridgeTaskElement *> *)fullQueue __attribute__((swift_name("fullQueue()")));
@end


/**
 * TaskQueue - A queue implementation for managing TaskElement instances.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TaskQueue.Companion")))
@interface BridgeTaskQueueCompanion : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));

/**
 * TaskQueue - A queue implementation for managing TaskElement instances.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeTaskQueueCompanion *shared __attribute__((swift_name("shared")));

/**
 * TaskQueue - A queue implementation for managing TaskElement instances.
 */
- (id<BridgeKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerializationStrategy")))
@protocol BridgeKotlinx_serialization_coreSerializationStrategy
@required
- (void)serializeEncoder:(id<BridgeKotlinx_serialization_coreEncoder>)encoder value:(id _Nullable)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<BridgeKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreDeserializationStrategy")))
@protocol BridgeKotlinx_serialization_coreDeserializationStrategy
@required
- (id _Nullable)deserializeDecoder:(id<BridgeKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
@property (readonly) id<BridgeKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreKSerializer")))
@protocol BridgeKotlinx_serialization_coreKSerializer <BridgeKotlinx_serialization_coreSerializationStrategy, BridgeKotlinx_serialization_coreDeserializationStrategy>
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UUIDSerializer")))
@interface BridgeUUIDSerializer : BridgeBase <BridgeKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)uUIDSerializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeUUIDSerializer *shared __attribute__((swift_name("shared")));
- (BridgeUUID *)deserializeDecoder:(id<BridgeKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<BridgeKotlinx_serialization_coreEncoder>)encoder value:(BridgeUUID *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<BridgeKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FileUtils")))
@interface BridgeFileUtils : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)fileUtils __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeFileUtils *shared __attribute__((swift_name("shared")));
- (void)clearDirectorySource:(NSString *)source __attribute__((swift_name("clearDirectory(source:)")));
- (BOOL)deleteFileFileName:(NSString *)fileName source:(NSString *)source __attribute__((swift_name("deleteFile(fileName:source:)")));
- (void)doInitContext:(id _Nullable)context __attribute__((swift_name("doInit(context:)")));
- (NSArray<NSString *> *)listFilesSource:(NSString *)source __attribute__((swift_name("listFiles(source:)")));
- (NSString * _Nullable)readFileFileName:(NSString *)fileName source:(NSString *)source __attribute__((swift_name("readFile(fileName:source:)")));
- (BOOL)writeFileFileName:(NSString *)fileName data:(NSString *)data source:(NSString *)source __attribute__((swift_name("writeFile(fileName:data:source:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinByteArray")))
@interface BridgeKotlinByteArray : BridgeBase
+ (instancetype)arrayWithSize:(int32_t)size __attribute__((swift_name("init(size:)")));
+ (instancetype)arrayWithSize:(int32_t)size init:(BridgeByte *(^)(BridgeInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (int8_t)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (BridgeKotlinByteIterator *)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(int8_t)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

@interface BridgeKotlinByteArray (Extensions)
- (NSString *)toHexString __attribute__((swift_name("toHexString()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BlueLinkModuleKt")))
@interface BridgeBlueLinkModuleKt : BridgeBase
+ (BridgeKoin_coreModule *)blueLinkModule __attribute__((swift_name("blueLinkModule()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DFUModuleKt")))
@interface BridgeDFUModuleKt : BridgeBase
@property (class, readonly) BridgeKoin_coreModule *dfuModule __attribute__((swift_name("dfuModule")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DataManipulationKt")))
@interface BridgeDataManipulationKt : BridgeBase

/**
 * Converts any compatible data type to a `ByteArray` in Little-Endian format.
 */
+ (BridgeKotlinByteArray * _Nullable)convertAnyToUInt8ArrayInput:(id _Nullable)input __attribute__((swift_name("convertAnyToUInt8Array(input:)")));
+ (BridgeKotlinByteArray * _Nullable)convertIntToUInt8Value:(int32_t)value byteCount:(int32_t)byteCount __attribute__((swift_name("convertIntToUInt8(value:byteCount:)")));
+ (int32_t)convertUInt8ArrayToIntValue:(BridgeKotlinByteArray *)value __attribute__((swift_name("convertUInt8ArrayToInt(value:)")));
+ (uint32_t)convertUInt8ArrayToUIntValue:(BridgeKotlinByteArray *)value __attribute__((swift_name("convertUInt8ArrayToUInt(value:)")));

/**
 * Converts an `Int` to a 4-byte Little-Endian `ByteArray`.
 */
+ (BridgeKotlinByteArray *)intToByteArrayValue:(int32_t)value __attribute__((swift_name("intToByteArray(value:)")));

/**
 * Converts a `Long` to an 8-byte Little-Endian `ByteArray`.
 */
+ (BridgeKotlinByteArray *)longToByteArrayValue:(int64_t)value __attribute__((swift_name("longToByteArray(value:)")));

/**
 * Converts a `Short` to a 2-byte Little-Endian `ByteArray`.
 */
+ (BridgeKotlinByteArray *)shortToByteArrayValue:(int16_t)value __attribute__((swift_name("shortToByteArray(value:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("IOSHeartbeatParserKt")))
@interface BridgeIOSHeartbeatParserKt : BridgeBase

/**
 * Factory function to create heartbeat parser for iOS
 */
+ (id<BridgeIHeartbeatParser>)provideHeartbeatParserHeartbeatParser:(id<BridgeIHeartbeatParser> _Nullable)heartbeatParser __attribute__((swift_name("provideHeartbeatParser(heartbeatParser:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KMMCrashHandlerKt")))
@interface BridgeKMMCrashHandlerKt : BridgeBase
+ (void)initializeKotlinCrashHandlerTelemetry:(id<BridgeBridgeTelemetryService>)telemetry onCrash:(void (^)(NSString *, NSString *, NSString *))onCrash __attribute__((swift_name("initializeKotlinCrashHandler(telemetry:onCrash:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KoinHelperKt")))
@interface BridgeKoinHelperKt : BridgeBase
+ (void)loadModules __attribute__((swift_name("loadModules()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MessageStreamManagerKt")))
@interface BridgeMessageStreamManagerKt : BridgeBase
+ (id<BridgeMessageStreamManager>)provideMessageStreamManagerPersistenceManager:(BridgePersistenceManager *)persistenceManager messageStreamManager:(id<BridgeIOSMessageStreamManager> _Nullable)messageStreamManager oobStateFlow:(id<BridgeKotlinx_coroutines_coreMutableSharedFlow>)oobStateFlow __attribute__((swift_name("provideMessageStreamManager(persistenceManager:messageStreamManager:oobStateFlow:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PersistenceManagerKt")))
@interface BridgePersistenceManagerKt : BridgeBase
@property (class, readonly) BridgeKoin_coreModule *persistenceModule __attribute__((swift_name("persistenceModule")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PlaneStreamConfigsKt")))
@interface BridgePlaneStreamConfigsKt : BridgeBase
@property (class, readonly) int64_t planeStreamRetryTimeoutMilliSeconds __attribute__((swift_name("planeStreamRetryTimeoutMilliSeconds")));
@property (class, readonly) int64_t planeStreamSendRetryTimeoutMilliSeconds __attribute__((swift_name("planeStreamSendRetryTimeoutMilliSeconds")));
@property (class, readonly) int64_t planeStreamTimeoutSeconds __attribute__((swift_name("planeStreamTimeoutSeconds")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ProxyModuleKt")))
@interface BridgeProxyModuleKt : BridgeBase
@property (class, readonly) BridgeKoin_coreModule *proxyModule __attribute__((swift_name("proxyModule")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TrueTimeManagerProviderKt")))
@interface BridgeTrueTimeManagerProviderKt : BridgeBase
+ (id<BridgeITrueTimeManager>)provideTrueTimeManagerTrueTimeManager:(id<BridgeITrueTimeManager> _Nullable)trueTimeManager __attribute__((swift_name("provideTrueTimeManager(trueTimeManager:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GRPCClient_iosKt")))
@interface BridgeGRPCClient_iosKt : BridgeBase
+ (id<BridgeGRPCDFUImageManager>)provideGRPCDFUManagerIOSDFUImageManager:(id<BridgeGRPCDFUImageManager> _Nullable)iOSDFUImageManager __attribute__((swift_name("provideGRPCDFUManager(iOSDFUImageManager:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UnusedDFUDriverKt")))
@interface BridgeUnusedDFUDriverKt : BridgeBase
+ (id<BridgeDFUDriverImplementation> _Nullable)createDfuDriver __attribute__((swift_name("createDfuDriver()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinEnumCompanion")))
@interface BridgeKotlinEnumCompanion : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeKotlinEnumCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinArray")))
@interface BridgeKotlinArray<T> : BridgeBase
+ (instancetype)arrayWithSize:(int32_t)size init:(T _Nullable (^)(BridgeInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (T _Nullable)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (id<BridgeKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(T _Nullable)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinCoroutineContext")))
@protocol BridgeKotlinCoroutineContext
@required
- (id _Nullable)foldInitial:(id _Nullable)initial operation:(id _Nullable (^)(id _Nullable, id<BridgeKotlinCoroutineContextElement>))operation __attribute__((swift_name("fold(initial:operation:)")));
- (id<BridgeKotlinCoroutineContextElement> _Nullable)getKey:(id<BridgeKotlinCoroutineContextKey>)key __attribute__((swift_name("get(key:)")));
- (id<BridgeKotlinCoroutineContext>)minusKeyKey:(id<BridgeKotlinCoroutineContextKey>)key __attribute__((swift_name("minusKey(key:)")));
- (id<BridgeKotlinCoroutineContext>)plusContext:(id<BridgeKotlinCoroutineContext>)context __attribute__((swift_name("plus(context:)")));
@end

__attribute__((swift_name("KotlinCoroutineContextElement")))
@protocol BridgeKotlinCoroutineContextElement <BridgeKotlinCoroutineContext>
@required
@property (readonly) id<BridgeKotlinCoroutineContextKey> key __attribute__((swift_name("key")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreJob")))
@protocol BridgeKotlinx_coroutines_coreJob <BridgeKotlinCoroutineContextElement>
@required

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (id<BridgeKotlinx_coroutines_coreChildHandle>)attachChildChild:(id<BridgeKotlinx_coroutines_coreChildJob>)child __attribute__((swift_name("attachChild(child:)")));
- (void)cancelCause:(BridgeKotlinCancellationException * _Nullable)cause __attribute__((swift_name("cancel(cause:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (BridgeKotlinCancellationException *)getCancellationException __attribute__((swift_name("getCancellationException()")));
- (id<BridgeKotlinx_coroutines_coreDisposableHandle>)invokeOnCompletionHandler:(void (^)(BridgeKotlinThrowable * _Nullable))handler __attribute__((swift_name("invokeOnCompletion(handler:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (id<BridgeKotlinx_coroutines_coreDisposableHandle>)invokeOnCompletionOnCancelling:(BOOL)onCancelling invokeImmediately:(BOOL)invokeImmediately handler:(void (^)(BridgeKotlinThrowable * _Nullable))handler __attribute__((swift_name("invokeOnCompletion(onCancelling:invokeImmediately:handler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)joinWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("join(completionHandler:)")));
- (id<BridgeKotlinx_coroutines_coreJob>)plusOther:(id<BridgeKotlinx_coroutines_coreJob>)other __attribute__((swift_name("plus(other:)"))) __attribute__((unavailable("Operator '+' on two Job objects is meaningless. Job is a coroutine context element and `+` is a set-sum operator for coroutine contexts. The job to the right of `+` just replaces the job the left of `+`.")));
- (BOOL)start __attribute__((swift_name("start()")));
@property (readonly) id<BridgeKotlinSequence> children __attribute__((swift_name("children")));
@property (readonly) BOOL isActive __attribute__((swift_name("isActive")));
@property (readonly) BOOL isCancelled __attribute__((swift_name("isCancelled")));
@property (readonly) BOOL isCompleted __attribute__((swift_name("isCompleted")));
@property (readonly) id<BridgeKotlinx_coroutines_coreSelectClause0> onJoin __attribute__((swift_name("onJoin")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
@property (readonly) id<BridgeKotlinx_coroutines_coreJob> _Nullable parent __attribute__((swift_name("parent")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Koin_coreKoin")))
@interface BridgeKoin_coreKoin : BridgeBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)close __attribute__((swift_name("close()")));
- (void)createEagerInstances __attribute__((swift_name("createEagerInstances()")));
- (BridgeKoin_coreScope *)createScopeT:(id<BridgeKoin_coreKoinScopeComponent>)t __attribute__((swift_name("createScope(t:)")));
- (BridgeKoin_coreScope *)createScopeScopeId:(NSString *)scopeId __attribute__((swift_name("createScope(scopeId:)")));
- (BridgeKoin_coreScope *)createScopeScopeId:(NSString *)scopeId source:(id _Nullable)source __attribute__((swift_name("createScope(scopeId:source:)")));
- (BridgeKoin_coreScope *)createScopeScopeId:(NSString *)scopeId qualifier:(id<BridgeKoin_coreQualifier>)qualifier source:(id _Nullable)source __attribute__((swift_name("createScope(scopeId:qualifier:source:)")));
- (void)declareInstance:(id _Nullable)instance qualifier:(id<BridgeKoin_coreQualifier> _Nullable)qualifier secondaryTypes:(NSArray<id<BridgeKotlinKClass>> *)secondaryTypes allowOverride:(BOOL)allowOverride __attribute__((swift_name("declare(instance:qualifier:secondaryTypes:allowOverride:)")));
- (void)deletePropertyKey:(NSString *)key __attribute__((swift_name("deleteProperty(key:)")));
- (void)deleteScopeScopeId:(NSString *)scopeId __attribute__((swift_name("deleteScope(scopeId:)")));
- (id)getQualifier:(id<BridgeKoin_coreQualifier> _Nullable)qualifier parameters:(BridgeKoin_coreParametersHolder *(^ _Nullable)(void))parameters __attribute__((swift_name("get(qualifier:parameters:)")));
- (id _Nullable)getClazz:(id<BridgeKotlinKClass>)clazz qualifier:(id<BridgeKoin_coreQualifier> _Nullable)qualifier parameters:(BridgeKoin_coreParametersHolder *(^ _Nullable)(void))parameters __attribute__((swift_name("get(clazz:qualifier:parameters:)")));
- (NSArray<id> *)getAll __attribute__((swift_name("getAll()")));
- (BridgeKoin_coreScope *)getOrCreateScopeScopeId:(NSString *)scopeId __attribute__((swift_name("getOrCreateScope(scopeId:)")));
- (BridgeKoin_coreScope *)getOrCreateScopeScopeId:(NSString *)scopeId qualifier:(id<BridgeKoin_coreQualifier>)qualifier source:(id _Nullable)source __attribute__((swift_name("getOrCreateScope(scopeId:qualifier:source:)")));
- (id _Nullable)getOrNullQualifier:(id<BridgeKoin_coreQualifier> _Nullable)qualifier parameters:(BridgeKoin_coreParametersHolder *(^ _Nullable)(void))parameters __attribute__((swift_name("getOrNull(qualifier:parameters:)")));
- (id _Nullable)getOrNullClazz:(id<BridgeKotlinKClass>)clazz qualifier:(id<BridgeKoin_coreQualifier> _Nullable)qualifier parameters:(BridgeKoin_coreParametersHolder *(^ _Nullable)(void))parameters __attribute__((swift_name("getOrNull(clazz:qualifier:parameters:)")));
- (id _Nullable)getPropertyKey:(NSString *)key __attribute__((swift_name("getProperty(key:)")));
- (id)getPropertyKey:(NSString *)key defaultValue:(id)defaultValue __attribute__((swift_name("getProperty(key:defaultValue:)")));
- (BridgeKoin_coreScope *)getScopeScopeId:(NSString *)scopeId __attribute__((swift_name("getScope(scopeId:)")));
- (BridgeKoin_coreScope * _Nullable)getScopeOrNullScopeId:(NSString *)scopeId __attribute__((swift_name("getScopeOrNull(scopeId:)")));
- (id<BridgeKotlinLazy>)injectQualifier:(id<BridgeKoin_coreQualifier> _Nullable)qualifier mode:(BridgeKotlinLazyThreadSafetyMode *)mode parameters:(BridgeKoin_coreParametersHolder *(^ _Nullable)(void))parameters __attribute__((swift_name("inject(qualifier:mode:parameters:)")));
- (id<BridgeKotlinLazy>)injectOrNullQualifier:(id<BridgeKoin_coreQualifier> _Nullable)qualifier mode:(BridgeKotlinLazyThreadSafetyMode *)mode parameters:(BridgeKoin_coreParametersHolder *(^ _Nullable)(void))parameters __attribute__((swift_name("injectOrNull(qualifier:mode:parameters:)")));
- (void)loadModulesModules:(NSArray<BridgeKoin_coreModule *> *)modules allowOverride:(BOOL)allowOverride createEagerInstances:(BOOL)createEagerInstances __attribute__((swift_name("loadModules(modules:allowOverride:createEagerInstances:)")));
- (void)setPropertyKey:(NSString *)key value:(id)value __attribute__((swift_name("setProperty(key:value:)")));
- (void)setupLoggerLogger:(BridgeKoin_coreLogger *)logger __attribute__((swift_name("setupLogger(logger:)")));
- (void)unloadModulesModules:(NSArray<BridgeKoin_coreModule *> *)modules __attribute__((swift_name("unloadModules(modules:)")));
@property (readonly) BridgeKoin_coreExtensionManager *extensionManager __attribute__((swift_name("extensionManager")));
@property (readonly) BridgeKoin_coreInstanceRegistry *instanceRegistry __attribute__((swift_name("instanceRegistry")));
@property (readonly) BridgeKoin_coreLogger *logger __attribute__((swift_name("logger")));
@property (readonly) BridgeKoin_corePropertyRegistry *propertyRegistry __attribute__((swift_name("propertyRegistry")));
@property (readonly) BridgeKoin_coreScopeRegistry *scopeRegistry __attribute__((swift_name("scopeRegistry")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinPair")))
@interface BridgeKotlinPair<__covariant A, __covariant B> : BridgeBase
- (instancetype)initWithFirst:(A _Nullable)first second:(B _Nullable)second __attribute__((swift_name("init(first:second:)"))) __attribute__((objc_designated_initializer));
- (BridgeKotlinPair<A, B> *)doCopyFirst:(A _Nullable)first second:(B _Nullable)second __attribute__((swift_name("doCopy(first:second:)")));
- (BOOL)equalsOther:(id _Nullable)other __attribute__((swift_name("equals(other:)")));
- (int32_t)hashCode __attribute__((swift_name("hashCode()")));
- (NSString *)toString __attribute__((swift_name("toString()")));
@property (readonly) A _Nullable first __attribute__((swift_name("first")));
@property (readonly) B _Nullable second __attribute__((swift_name("second")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreMutex")))
@protocol BridgeKotlinx_coroutines_coreMutex
@required
- (BOOL)holdsLockOwner:(id)owner __attribute__((swift_name("holdsLock(owner:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)lockOwner:(id _Nullable)owner completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("lock(owner:completionHandler:)")));
- (BOOL)tryLockOwner:(id _Nullable)owner __attribute__((swift_name("tryLock(owner:)")));
- (void)unlockOwner:(id _Nullable)owner __attribute__((swift_name("unlock(owner:)")));
@property (readonly) BOOL isLocked __attribute__((swift_name("isLocked")));
@property (readonly) id<BridgeKotlinx_coroutines_coreSelectClause2> onLock __attribute__((swift_name("onLock"))) __attribute__((deprecated("Mutex.onLock deprecated without replacement. For additional details please refer to #2794")));
@end

__attribute__((swift_name("KotlinRuntimeException")))
@interface BridgeKotlinRuntimeException : BridgeKotlinException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(BridgeKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(BridgeKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("KotlinIllegalStateException")))
@interface BridgeKotlinIllegalStateException : BridgeKotlinRuntimeException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(BridgeKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(BridgeKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
__attribute__((swift_name("KotlinCancellationException")))
@interface BridgeKotlinCancellationException : BridgeKotlinIllegalStateException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(BridgeKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(BridgeKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=kotlinx/datetime/serializers/InstantIso8601Serializer))
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_datetimeInstant")))
@interface BridgeKotlinx_datetimeInstant : BridgeBase <BridgeKotlinComparable>
@property (class, readonly, getter=companion) BridgeKotlinx_datetimeInstantCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(BridgeKotlinx_datetimeInstant *)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (BridgeKotlinx_datetimeInstant *)minusDuration:(int64_t)duration __attribute__((swift_name("minus(duration:)")));
- (int64_t)minusOther:(BridgeKotlinx_datetimeInstant *)other __attribute__((swift_name("minus(other:)")));
- (BridgeKotlinx_datetimeInstant *)plusDuration:(int64_t)duration __attribute__((swift_name("plus(duration:)")));
- (int64_t)toEpochMilliseconds __attribute__((swift_name("toEpochMilliseconds()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int64_t epochSeconds __attribute__((swift_name("epochSeconds")));
@property (readonly) int32_t nanosecondsOfSecond __attribute__((swift_name("nanosecondsOfSecond")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Koin_coreModule")))
@interface BridgeKoin_coreModule : BridgeBase
- (instancetype)initWith_createdAtStart:(BOOL)_createdAtStart __attribute__((swift_name("init(_createdAtStart:)"))) __attribute__((objc_designated_initializer));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (BridgeKoin_coreKoinDefinition<id> *)factoryQualifier:(id<BridgeKoin_coreQualifier> _Nullable)qualifier definition:(id _Nullable (^)(BridgeKoin_coreScope *, BridgeKoin_coreParametersHolder *))definition __attribute__((swift_name("factory(qualifier:definition:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (void)includesModule:(BridgeKotlinArray<BridgeKoin_coreModule *> *)module __attribute__((swift_name("includes(module:)")));
- (void)includesModule_:(id)module __attribute__((swift_name("includes(module_:)")));
- (void)indexPrimaryTypeInstanceFactory:(BridgeKoin_coreInstanceFactory<id> *)instanceFactory __attribute__((swift_name("indexPrimaryType(instanceFactory:)")));
- (void)indexSecondaryTypesInstanceFactory:(BridgeKoin_coreInstanceFactory<id> *)instanceFactory __attribute__((swift_name("indexSecondaryTypes(instanceFactory:)")));
- (NSArray<BridgeKoin_coreModule *> *)plusModules:(NSArray<BridgeKoin_coreModule *> *)modules __attribute__((swift_name("plus(modules:)")));
- (NSArray<BridgeKoin_coreModule *> *)plusModule:(BridgeKoin_coreModule *)module __attribute__((swift_name("plus(module:)")));
- (void)prepareForCreationAtStartInstanceFactory:(BridgeKoin_coreSingleInstanceFactory<id> *)instanceFactory __attribute__((swift_name("prepareForCreationAtStart(instanceFactory:)")));
- (void)scopeScopeSet:(void (^)(BridgeKoin_coreScopeDSL *))scopeSet __attribute__((swift_name("scope(scopeSet:)")));
- (void)scopeQualifier:(id<BridgeKoin_coreQualifier>)qualifier scopeSet:(void (^)(BridgeKoin_coreScopeDSL *))scopeSet __attribute__((swift_name("scope(qualifier:scopeSet:)")));
- (BridgeKoin_coreKoinDefinition<id> *)singleQualifier:(id<BridgeKoin_coreQualifier> _Nullable)qualifier createdAtStart:(BOOL)createdAtStart definition:(id _Nullable (^)(BridgeKoin_coreScope *, BridgeKoin_coreParametersHolder *))definition __attribute__((swift_name("single(qualifier:createdAtStart:definition:)")));
@property (readonly) BridgeMutableSet<BridgeKoin_coreSingleInstanceFactory<id> *> *eagerInstances __attribute__((swift_name("eagerInstances")));
@property (readonly) NSString *id __attribute__((swift_name("id")));
@property (readonly) NSMutableArray<BridgeKoin_coreModule *> *includedModules __attribute__((swift_name("includedModules")));
@property (readonly) BOOL isLoaded __attribute__((swift_name("isLoaded")));
@property (readonly) BridgeMutableDictionary<NSString *, BridgeKoin_coreInstanceFactory<id> *> *mappings __attribute__((swift_name("mappings")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Koin_coreKoinApplication")))
@interface BridgeKoin_coreKoinApplication : BridgeBase
@property (class, readonly, getter=companion) BridgeKoin_coreKoinApplicationCompanion *companion __attribute__((swift_name("companion")));
- (void)allowOverrideOverride:(BOOL)override __attribute__((swift_name("allowOverride(override:)")));
- (void)close __attribute__((swift_name("close()")));
- (void)createEagerInstances __attribute__((swift_name("createEagerInstances()")));
- (BridgeKoin_coreKoinApplication *)loggerLogger:(BridgeKoin_coreLogger *)logger __attribute__((swift_name("logger(logger:)")));
- (BridgeKoin_coreKoinApplication *)modulesModules:(BridgeKotlinArray<BridgeKoin_coreModule *> *)modules __attribute__((swift_name("modules(modules:)")));
- (BridgeKoin_coreKoinApplication *)modulesModules_:(NSArray<BridgeKoin_coreModule *> *)modules __attribute__((swift_name("modules(modules_:)")));
- (BridgeKoin_coreKoinApplication *)modulesModules__:(BridgeKoin_coreModule *)modules __attribute__((swift_name("modules(modules__:)")));
- (BridgeKoin_coreKoinApplication *)printLoggerLevel:(BridgeKoin_coreLevel *)level __attribute__((swift_name("printLogger(level:)")));
- (BridgeKoin_coreKoinApplication *)propertiesValues:(NSDictionary<NSString *, id> *)values __attribute__((swift_name("properties(values:)")));
@property (readonly) BridgeKoin_coreKoin *koin __attribute__((swift_name("koin")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreCoroutineScope")))
@protocol BridgeKotlinx_coroutines_coreCoroutineScope
@required
@property (readonly) id<BridgeKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreFlow")))
@protocol BridgeKotlinx_coroutines_coreFlow
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<BridgeKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreSharedFlow")))
@protocol BridgeKotlinx_coroutines_coreSharedFlow <BridgeKotlinx_coroutines_coreFlow>
@required
@property (readonly) NSArray<id> *replayCache __attribute__((swift_name("replayCache")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreStateFlow")))
@protocol BridgeKotlinx_coroutines_coreStateFlow <BridgeKotlinx_coroutines_coreSharedFlow>
@required
@property (readonly) id _Nullable value_ __attribute__((swift_name("value_")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreFlowCollector")))
@protocol BridgeKotlinx_coroutines_coreFlowCollector
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)emitValue:(id _Nullable)value completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("emit(value:completionHandler:)")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreMutableSharedFlow")))
@protocol BridgeKotlinx_coroutines_coreMutableSharedFlow <BridgeKotlinx_coroutines_coreSharedFlow, BridgeKotlinx_coroutines_coreFlowCollector>
@required

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
- (void)resetReplayCache __attribute__((swift_name("resetReplayCache()")));
- (BOOL)tryEmitValue:(id _Nullable)value __attribute__((swift_name("tryEmit(value:)")));
@property (readonly) id<BridgeKotlinx_coroutines_coreStateFlow> subscriptionCount __attribute__((swift_name("subscriptionCount")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreMutableStateFlow")))
@protocol BridgeKotlinx_coroutines_coreMutableStateFlow <BridgeKotlinx_coroutines_coreStateFlow, BridgeKotlinx_coroutines_coreMutableSharedFlow>
@required
- (void)setValue:(id _Nullable)value __attribute__((swift_name("setValue(_:)")));
- (BOOL)compareAndSetExpect:(id _Nullable)expect update:(id _Nullable)update __attribute__((swift_name("compareAndSet(expect:update:)")));
@end

__attribute__((swift_name("KotlinFunction")))
@protocol BridgeKotlinFunction
@required
@end

__attribute__((swift_name("KotlinSuspendFunction0")))
@protocol BridgeKotlinSuspendFunction0 <BridgeKotlinFunction>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)invokeWithCompletionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("invoke(completionHandler:)")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreEncoder")))
@protocol BridgeKotlinx_serialization_coreEncoder
@required
- (id<BridgeKotlinx_serialization_coreCompositeEncoder>)beginCollectionDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor collectionSize:(int32_t)collectionSize __attribute__((swift_name("beginCollection(descriptor:collectionSize:)")));
- (id<BridgeKotlinx_serialization_coreCompositeEncoder>)beginStructureDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("beginStructure(descriptor:)")));
- (void)encodeBooleanValue:(BOOL)value __attribute__((swift_name("encodeBoolean(value:)")));
- (void)encodeByteValue:(int8_t)value __attribute__((swift_name("encodeByte(value:)")));
- (void)encodeCharValue:(unichar)value __attribute__((swift_name("encodeChar(value:)")));
- (void)encodeDoubleValue:(double)value __attribute__((swift_name("encodeDouble(value:)")));
- (void)encodeEnumEnumDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)enumDescriptor index:(int32_t)index __attribute__((swift_name("encodeEnum(enumDescriptor:index:)")));
- (void)encodeFloatValue:(float)value __attribute__((swift_name("encodeFloat(value:)")));
- (id<BridgeKotlinx_serialization_coreEncoder>)encodeInlineDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("encodeInline(descriptor:)")));
- (void)encodeIntValue:(int32_t)value __attribute__((swift_name("encodeInt(value:)")));
- (void)encodeLongValue:(int64_t)value __attribute__((swift_name("encodeLong(value:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNotNullMark __attribute__((swift_name("encodeNotNullMark()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNull __attribute__((swift_name("encodeNull()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNullableSerializableValueSerializer:(id<BridgeKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeNullableSerializableValue(serializer:value:)")));
- (void)encodeSerializableValueSerializer:(id<BridgeKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeSerializableValue(serializer:value:)")));
- (void)encodeShortValue:(int16_t)value __attribute__((swift_name("encodeShort(value:)")));
- (void)encodeStringValue:(NSString *)value __attribute__((swift_name("encodeString(value:)")));
@property (readonly) BridgeKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerialDescriptor")))
@protocol BridgeKotlinx_serialization_coreSerialDescriptor
@required
- (NSArray<id<BridgeKotlinAnnotation>> *)getElementAnnotationsIndex:(int32_t)index __attribute__((swift_name("getElementAnnotations(index:)")));
- (id<BridgeKotlinx_serialization_coreSerialDescriptor>)getElementDescriptorIndex:(int32_t)index __attribute__((swift_name("getElementDescriptor(index:)")));
- (int32_t)getElementIndexName:(NSString *)name __attribute__((swift_name("getElementIndex(name:)")));
- (NSString *)getElementNameIndex:(int32_t)index __attribute__((swift_name("getElementName(index:)")));
- (BOOL)isElementOptionalIndex:(int32_t)index __attribute__((swift_name("isElementOptional(index:)")));
@property (readonly) NSArray<id<BridgeKotlinAnnotation>> *annotations __attribute__((swift_name("annotations")));
@property (readonly) int32_t elementsCount __attribute__((swift_name("elementsCount")));
@property (readonly) BOOL isInline __attribute__((swift_name("isInline")));
@property (readonly) BOOL isNullable __attribute__((swift_name("isNullable")));
@property (readonly) BridgeKotlinx_serialization_coreSerialKind *kind __attribute__((swift_name("kind")));
@property (readonly) NSString *serialName __attribute__((swift_name("serialName")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreDecoder")))
@protocol BridgeKotlinx_serialization_coreDecoder
@required
- (id<BridgeKotlinx_serialization_coreCompositeDecoder>)beginStructureDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("beginStructure(descriptor:)")));
- (BOOL)decodeBoolean __attribute__((swift_name("decodeBoolean()")));
- (int8_t)decodeByte __attribute__((swift_name("decodeByte()")));
- (unichar)decodeChar __attribute__((swift_name("decodeChar()")));
- (double)decodeDouble __attribute__((swift_name("decodeDouble()")));
- (int32_t)decodeEnumEnumDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)enumDescriptor __attribute__((swift_name("decodeEnum(enumDescriptor:)")));
- (float)decodeFloat __attribute__((swift_name("decodeFloat()")));
- (id<BridgeKotlinx_serialization_coreDecoder>)decodeInlineDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeInline(descriptor:)")));
- (int32_t)decodeInt __attribute__((swift_name("decodeInt()")));
- (int64_t)decodeLong __attribute__((swift_name("decodeLong()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)decodeNotNullMark __attribute__((swift_name("decodeNotNullMark()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BridgeKotlinNothing * _Nullable)decodeNull __attribute__((swift_name("decodeNull()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id _Nullable)decodeNullableSerializableValueDeserializer:(id<BridgeKotlinx_serialization_coreDeserializationStrategy>)deserializer __attribute__((swift_name("decodeNullableSerializableValue(deserializer:)")));
- (id _Nullable)decodeSerializableValueDeserializer:(id<BridgeKotlinx_serialization_coreDeserializationStrategy>)deserializer __attribute__((swift_name("decodeSerializableValue(deserializer:)")));
- (int16_t)decodeShort __attribute__((swift_name("decodeShort()")));
- (NSString *)decodeString __attribute__((swift_name("decodeString()")));
@property (readonly) BridgeKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("KotlinIterator")))
@protocol BridgeKotlinIterator
@required
- (BOOL)hasNext __attribute__((swift_name("hasNext()")));
- (id _Nullable)next __attribute__((swift_name("next()")));
@end

__attribute__((swift_name("KotlinByteIterator")))
@interface BridgeKotlinByteIterator : BridgeBase <BridgeKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (BridgeByte *)next __attribute__((swift_name("next()")));
- (int8_t)nextByte __attribute__((swift_name("nextByte()")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreDisposableHandle")))
@protocol BridgeKotlinx_coroutines_coreDisposableHandle
@required
- (void)dispose __attribute__((swift_name("dispose()")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("Kotlinx_coroutines_coreChildHandle")))
@protocol BridgeKotlinx_coroutines_coreChildHandle <BridgeKotlinx_coroutines_coreDisposableHandle>
@required

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (BOOL)childCancelledCause:(BridgeKotlinThrowable *)cause __attribute__((swift_name("childCancelled(cause:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
@property (readonly) id<BridgeKotlinx_coroutines_coreJob> _Nullable parent __attribute__((swift_name("parent")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("Kotlinx_coroutines_coreChildJob")))
@protocol BridgeKotlinx_coroutines_coreChildJob <BridgeKotlinx_coroutines_coreJob>
@required

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (void)parentCancelledParentJob:(id<BridgeKotlinx_coroutines_coreParentJob>)parentJob __attribute__((swift_name("parentCancelled(parentJob:)")));
@end

__attribute__((swift_name("KotlinSequence")))
@protocol BridgeKotlinSequence
@required
- (id<BridgeKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("Kotlinx_coroutines_coreSelectClause")))
@protocol BridgeKotlinx_coroutines_coreSelectClause
@required
@property (readonly) id clauseObject __attribute__((swift_name("clauseObject")));
@property (readonly) BridgeKotlinUnit *(^(^ _Nullable onCancellationConstructor)(id<BridgeKotlinx_coroutines_coreSelectInstance>, id _Nullable, id _Nullable))(BridgeKotlinThrowable *, id _Nullable, id<BridgeKotlinCoroutineContext>) __attribute__((swift_name("onCancellationConstructor")));
@property (readonly) id _Nullable (^processResFunc)(id, id _Nullable, id _Nullable) __attribute__((swift_name("processResFunc")));
@property (readonly) void (^regFunc)(id, id<BridgeKotlinx_coroutines_coreSelectInstance>, id _Nullable) __attribute__((swift_name("regFunc")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreSelectClause0")))
@protocol BridgeKotlinx_coroutines_coreSelectClause0 <BridgeKotlinx_coroutines_coreSelectClause>
@required
@end

__attribute__((swift_name("KotlinCoroutineContextKey")))
@protocol BridgeKotlinCoroutineContextKey
@required
@end

__attribute__((swift_name("Koin_coreLockable")))
@interface BridgeKoin_coreLockable : BridgeBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Koin_coreScope")))
@interface BridgeKoin_coreScope : BridgeKoin_coreLockable
- (instancetype)initWithScopeQualifier:(id<BridgeKoin_coreQualifier>)scopeQualifier id:(NSString *)id isRoot:(BOOL)isRoot _koin:(BridgeKoin_coreKoin *)_koin __attribute__((swift_name("init(scopeQualifier:id:isRoot:_koin:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (void)close __attribute__((swift_name("close()")));
- (void)declareInstance:(id _Nullable)instance qualifier:(id<BridgeKoin_coreQualifier> _Nullable)qualifier secondaryTypes:(NSArray<id<BridgeKotlinKClass>> *)secondaryTypes allowOverride:(BOOL)allowOverride __attribute__((swift_name("declare(instance:qualifier:secondaryTypes:allowOverride:)")));
- (id)getQualifier:(id<BridgeKoin_coreQualifier> _Nullable)qualifier parameters:(BridgeKoin_coreParametersHolder *(^ _Nullable)(void))parameters __attribute__((swift_name("get(qualifier:parameters:)")));
- (id _Nullable)getClazz:(id<BridgeKotlinKClass>)clazz qualifier:(id<BridgeKoin_coreQualifier> _Nullable)qualifier parameters:(BridgeKoin_coreParametersHolder *(^ _Nullable)(void))parameters __attribute__((swift_name("get(clazz:qualifier:parameters:)")));
- (NSArray<id> *)getAll __attribute__((swift_name("getAll()")));
- (NSArray<id> *)getAllClazz:(id<BridgeKotlinKClass>)clazz __attribute__((swift_name("getAll(clazz:)")));
- (BridgeKoin_coreKoin *)getKoin __attribute__((swift_name("getKoin()")));
- (id _Nullable)getOrNullQualifier:(id<BridgeKoin_coreQualifier> _Nullable)qualifier parameters:(BridgeKoin_coreParametersHolder *(^ _Nullable)(void))parameters __attribute__((swift_name("getOrNull(qualifier:parameters:)")));
- (id _Nullable)getOrNullClazz:(id<BridgeKotlinKClass>)clazz qualifier:(id<BridgeKoin_coreQualifier> _Nullable)qualifier parameters:(BridgeKoin_coreParametersHolder *(^ _Nullable)(void))parameters __attribute__((swift_name("getOrNull(clazz:qualifier:parameters:)")));
- (id)getPropertyKey:(NSString *)key __attribute__((swift_name("getProperty(key:)")));
- (id)getPropertyKey:(NSString *)key defaultValue:(id)defaultValue __attribute__((swift_name("getProperty(key:defaultValue:)")));
- (id _Nullable)getPropertyOrNullKey:(NSString *)key __attribute__((swift_name("getPropertyOrNull(key:)")));
- (BridgeKoin_coreScope *)getScopeScopeID:(NSString *)scopeID __attribute__((swift_name("getScope(scopeID:)")));
- (id _Nullable)getSource __attribute__((swift_name("getSource()")));
- (id _Nullable)getWithParametersClazz:(id<BridgeKotlinKClass>)clazz qualifier:(id<BridgeKoin_coreQualifier> _Nullable)qualifier parameters:(BridgeKoin_coreParametersHolder * _Nullable)parameters __attribute__((swift_name("getWithParameters(clazz:qualifier:parameters:)")));
- (id<BridgeKotlinLazy>)injectQualifier:(id<BridgeKoin_coreQualifier> _Nullable)qualifier mode:(BridgeKotlinLazyThreadSafetyMode *)mode parameters:(BridgeKoin_coreParametersHolder *(^ _Nullable)(void))parameters __attribute__((swift_name("inject(qualifier:mode:parameters:)")));
- (id<BridgeKotlinLazy>)injectOrNullQualifier:(id<BridgeKoin_coreQualifier> _Nullable)qualifier mode:(BridgeKotlinLazyThreadSafetyMode *)mode parameters:(BridgeKoin_coreParametersHolder *(^ _Nullable)(void))parameters __attribute__((swift_name("injectOrNull(qualifier:mode:parameters:)")));
- (BOOL)isNotClosed __attribute__((swift_name("isNotClosed()")));
- (void)linkToScopes:(BridgeKotlinArray<BridgeKoin_coreScope *> *)scopes __attribute__((swift_name("linkTo(scopes:)")));
- (void)registerCallbackCallback:(id<BridgeKoin_coreScopeCallback>)callback __attribute__((swift_name("registerCallback(callback:)")));
- (NSString *)description __attribute__((swift_name("description()")));
- (void)unlinkScopes:(BridgeKotlinArray<BridgeKoin_coreScope *> *)scopes __attribute__((swift_name("unlink(scopes:)")));
@property (readonly) BOOL closed __attribute__((swift_name("closed")));
@property (readonly) NSString *id __attribute__((swift_name("id")));
@property (readonly) BOOL isRoot __attribute__((swift_name("isRoot")));
@property (readonly) BridgeKoin_coreLogger *logger __attribute__((swift_name("logger")));
@property (readonly) id<BridgeKoin_coreQualifier> scopeQualifier __attribute__((swift_name("scopeQualifier")));
@property id _Nullable sourceValue __attribute__((swift_name("sourceValue")));
@end

__attribute__((swift_name("Koin_coreKoinScopeComponent")))
@protocol BridgeKoin_coreKoinScopeComponent <BridgeKoin_coreKoinComponent>
@required
@property (readonly) BridgeKoin_coreScope *scope __attribute__((swift_name("scope")));
@end

__attribute__((swift_name("Koin_coreQualifier")))
@protocol BridgeKoin_coreQualifier
@required
@property (readonly) NSString *value_ __attribute__((swift_name("value_")));
@end

__attribute__((swift_name("KotlinKDeclarationContainer")))
@protocol BridgeKotlinKDeclarationContainer
@required
@end

__attribute__((swift_name("KotlinKAnnotatedElement")))
@protocol BridgeKotlinKAnnotatedElement
@required
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
__attribute__((swift_name("KotlinKClassifier")))
@protocol BridgeKotlinKClassifier
@required
@end

__attribute__((swift_name("KotlinKClass")))
@protocol BridgeKotlinKClass <BridgeKotlinKDeclarationContainer, BridgeKotlinKAnnotatedElement, BridgeKotlinKClassifier>
@required

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
- (BOOL)isInstanceValue:(id _Nullable)value __attribute__((swift_name("isInstance(value:)")));
@property (readonly) NSString * _Nullable qualifiedName __attribute__((swift_name("qualifiedName")));
@property (readonly) NSString * _Nullable simpleName __attribute__((swift_name("simpleName")));
@end

__attribute__((swift_name("Koin_coreParametersHolder")))
@interface BridgeKoin_coreParametersHolder : BridgeBase
- (instancetype)initWith_values:(NSMutableArray<id> *)_values useIndexedValues:(BridgeBoolean * _Nullable)useIndexedValues __attribute__((swift_name("init(_values:useIndexedValues:)"))) __attribute__((objc_designated_initializer));
- (BridgeKoin_coreParametersHolder *)addValue:(id)value __attribute__((swift_name("add(value:)")));
- (id _Nullable)component1 __attribute__((swift_name("component1()")));
- (id _Nullable)component2 __attribute__((swift_name("component2()")));
- (id _Nullable)component3 __attribute__((swift_name("component3()")));
- (id _Nullable)component4 __attribute__((swift_name("component4()")));
- (id _Nullable)component5 __attribute__((swift_name("component5()")));
- (id _Nullable)elementAtI:(int32_t)i clazz:(id<BridgeKotlinKClass>)clazz __attribute__((swift_name("elementAt(i:clazz:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (id)get __attribute__((swift_name("get()")));
- (id _Nullable)getI:(int32_t)i __attribute__((swift_name("get(i:)")));
- (id _Nullable)getOrNull __attribute__((swift_name("getOrNull()")));
- (id _Nullable)getOrNullClazz:(id<BridgeKotlinKClass>)clazz __attribute__((swift_name("getOrNull(clazz:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (BridgeKoin_coreParametersHolder *)insertIndex:(int32_t)index value:(id)value __attribute__((swift_name("insert(index:value:)")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()")));
- (BOOL)isNotEmpty __attribute__((swift_name("isNotEmpty()")));
- (void)setI:(int32_t)i t:(id _Nullable)t __attribute__((swift_name("set(i:t:)")));
- (int32_t)size __attribute__((swift_name("size()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property int32_t index __attribute__((swift_name("index")));
@property (readonly) BridgeBoolean * _Nullable useIndexedValues __attribute__((swift_name("useIndexedValues")));
@property (readonly) NSArray<id> *values __attribute__((swift_name("values")));
@end

__attribute__((swift_name("KotlinLazy")))
@protocol BridgeKotlinLazy
@required
- (BOOL)isInitialized __attribute__((swift_name("isInitialized()")));
@property (readonly) id _Nullable value_ __attribute__((swift_name("value_")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinLazyThreadSafetyMode")))
@interface BridgeKotlinLazyThreadSafetyMode : BridgeKotlinEnum<BridgeKotlinLazyThreadSafetyMode *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) BridgeKotlinLazyThreadSafetyMode *synchronized __attribute__((swift_name("synchronized")));
@property (class, readonly) BridgeKotlinLazyThreadSafetyMode *publication __attribute__((swift_name("publication")));
@property (class, readonly) BridgeKotlinLazyThreadSafetyMode *none __attribute__((swift_name("none")));
+ (BridgeKotlinArray<BridgeKotlinLazyThreadSafetyMode *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<BridgeKotlinLazyThreadSafetyMode *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((swift_name("Koin_coreLogger")))
@interface BridgeKoin_coreLogger : BridgeBase
- (instancetype)initWithLevel:(BridgeKoin_coreLevel *)level __attribute__((swift_name("init(level:)"))) __attribute__((objc_designated_initializer));
- (void)debugMsg:(NSString *)msg __attribute__((swift_name("debug(msg:)")));
- (void)displayLevel:(BridgeKoin_coreLevel *)level msg:(NSString *)msg __attribute__((swift_name("display(level:msg:)")));
- (void)errorMsg:(NSString *)msg __attribute__((swift_name("error(msg:)")));
- (void)infoMsg:(NSString *)msg __attribute__((swift_name("info(msg:)")));
- (BOOL)isAtLvl:(BridgeKoin_coreLevel *)lvl __attribute__((swift_name("isAt(lvl:)")));
- (void)logLvl:(BridgeKoin_coreLevel *)lvl msg:(NSString *(^)(void))msg __attribute__((swift_name("log(lvl:msg:)")));
- (void)logLvl:(BridgeKoin_coreLevel *)lvl msg_:(NSString *)msg __attribute__((swift_name("log(lvl:msg_:)")));
- (void)warnMsg:(NSString *)msg __attribute__((swift_name("warn(msg:)")));
@property BridgeKoin_coreLevel *level __attribute__((swift_name("level")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Koin_coreExtensionManager")))
@interface BridgeKoin_coreExtensionManager : BridgeBase
- (instancetype)initWith_koin:(BridgeKoin_coreKoin *)_koin __attribute__((swift_name("init(_koin:)"))) __attribute__((objc_designated_initializer));
- (void)close __attribute__((swift_name("close()")));
- (id<BridgeKoin_coreKoinExtension>)getExtensionId:(NSString *)id __attribute__((swift_name("getExtension(id:)")));
- (id<BridgeKoin_coreKoinExtension> _Nullable)getExtensionOrNullId:(NSString *)id __attribute__((swift_name("getExtensionOrNull(id:)")));
- (void)registerExtensionId:(NSString *)id extension:(id<BridgeKoin_coreKoinExtension>)extension __attribute__((swift_name("registerExtension(id:extension:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Koin_coreInstanceRegistry")))
@interface BridgeKoin_coreInstanceRegistry : BridgeBase
- (instancetype)initWith_koin:(BridgeKoin_coreKoin *)_koin __attribute__((swift_name("init(_koin:)"))) __attribute__((objc_designated_initializer));
- (void)saveMappingAllowOverride:(BOOL)allowOverride mapping:(NSString *)mapping factory:(BridgeKoin_coreInstanceFactory<id> *)factory logWarning:(BOOL)logWarning __attribute__((swift_name("saveMapping(allowOverride:mapping:factory:logWarning:)")));
- (int32_t)size __attribute__((swift_name("size()")));
@property (readonly) BridgeKoin_coreKoin *_koin __attribute__((swift_name("_koin")));
@property (readonly) NSDictionary<NSString *, BridgeKoin_coreInstanceFactory<id> *> *instances __attribute__((swift_name("instances")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Koin_corePropertyRegistry")))
@interface BridgeKoin_corePropertyRegistry : BridgeBase
- (instancetype)initWith_koin:(BridgeKoin_coreKoin *)_koin __attribute__((swift_name("init(_koin:)"))) __attribute__((objc_designated_initializer));
- (void)close __attribute__((swift_name("close()")));
- (void)deletePropertyKey:(NSString *)key __attribute__((swift_name("deleteProperty(key:)")));
- (id _Nullable)getPropertyKey:(NSString *)key __attribute__((swift_name("getProperty(key:)")));
- (void)savePropertiesProperties:(NSDictionary<NSString *, id> *)properties __attribute__((swift_name("saveProperties(properties:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Koin_coreScopeRegistry")))
@interface BridgeKoin_coreScopeRegistry : BridgeBase
- (instancetype)initWith_koin:(BridgeKoin_coreKoin *)_koin __attribute__((swift_name("init(_koin:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) BridgeKoin_coreScopeRegistryCompanion *companion __attribute__((swift_name("companion")));
- (void)loadScopesModules:(NSSet<BridgeKoin_coreModule *> *)modules __attribute__((swift_name("loadScopes(modules:)")));
@property (readonly) BridgeKoin_coreScope *rootScope __attribute__((swift_name("rootScope")));
@property (readonly) NSSet<id<BridgeKoin_coreQualifier>> *scopeDefinitions __attribute__((swift_name("scopeDefinitions")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreSelectClause2")))
@protocol BridgeKotlinx_coroutines_coreSelectClause2 <BridgeKotlinx_coroutines_coreSelectClause>
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_datetimeInstant.Companion")))
@interface BridgeKotlinx_datetimeInstantCompanion : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeKotlinx_datetimeInstantCompanion *shared __attribute__((swift_name("shared")));
- (BridgeKotlinx_datetimeInstant *)fromEpochMillisecondsEpochMilliseconds:(int64_t)epochMilliseconds __attribute__((swift_name("fromEpochMilliseconds(epochMilliseconds:)")));
- (BridgeKotlinx_datetimeInstant *)fromEpochSecondsEpochSeconds:(int64_t)epochSeconds nanosecondAdjustment:(int32_t)nanosecondAdjustment __attribute__((swift_name("fromEpochSeconds(epochSeconds:nanosecondAdjustment:)")));
- (BridgeKotlinx_datetimeInstant *)fromEpochSecondsEpochSeconds:(int64_t)epochSeconds nanosecondAdjustment_:(int64_t)nanosecondAdjustment __attribute__((swift_name("fromEpochSeconds(epochSeconds:nanosecondAdjustment_:)")));
- (BridgeKotlinx_datetimeInstant *)now __attribute__((swift_name("now()"))) __attribute__((unavailable("Use Clock.System.now() instead")));
- (BridgeKotlinx_datetimeInstant *)parseInput:(id)input format:(id<BridgeKotlinx_datetimeDateTimeFormat>)format __attribute__((swift_name("parse(input:format:)")));
- (id<BridgeKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@property (readonly) BridgeKotlinx_datetimeInstant *DISTANT_FUTURE __attribute__((swift_name("DISTANT_FUTURE")));
@property (readonly) BridgeKotlinx_datetimeInstant *DISTANT_PAST __attribute__((swift_name("DISTANT_PAST")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Koin_coreKoinDefinition")))
@interface BridgeKoin_coreKoinDefinition<R> : BridgeBase
- (instancetype)initWithModule:(BridgeKoin_coreModule *)module factory:(BridgeKoin_coreInstanceFactory<R> *)factory __attribute__((swift_name("init(module:factory:)"))) __attribute__((objc_designated_initializer));
- (BridgeKoin_coreKoinDefinition<R> *)doCopyModule:(BridgeKoin_coreModule *)module factory:(BridgeKoin_coreInstanceFactory<R> *)factory __attribute__((swift_name("doCopy(module:factory:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BridgeKoin_coreInstanceFactory<R> *factory __attribute__((swift_name("factory")));
@property (readonly) BridgeKoin_coreModule *module __attribute__((swift_name("module")));
@end

__attribute__((swift_name("Koin_coreInstanceFactory")))
@interface BridgeKoin_coreInstanceFactory<T> : BridgeKoin_coreLockable
- (instancetype)initWithBeanDefinition:(BridgeKoin_coreBeanDefinition<T> *)beanDefinition __attribute__((swift_name("init(beanDefinition:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
@property (class, readonly, getter=companion) BridgeKoin_coreInstanceFactoryCompanion *companion __attribute__((swift_name("companion")));
- (T _Nullable)createContext:(BridgeKoin_coreResolutionContext *)context __attribute__((swift_name("create(context:)")));
- (void)dropScope:(BridgeKoin_coreScope * _Nullable)scope __attribute__((swift_name("drop(scope:)")));
- (void)dropAll __attribute__((swift_name("dropAll()")));
- (T _Nullable)getContext:(BridgeKoin_coreResolutionContext *)context __attribute__((swift_name("get(context:)")));
- (BOOL)isCreatedContext:(BridgeKoin_coreResolutionContext * _Nullable)context __attribute__((swift_name("isCreated(context:)")));
@property (readonly) BridgeKoin_coreBeanDefinition<T> *beanDefinition __attribute__((swift_name("beanDefinition")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Koin_coreSingleInstanceFactory")))
@interface BridgeKoin_coreSingleInstanceFactory<T> : BridgeKoin_coreInstanceFactory<T>
- (instancetype)initWithBeanDefinition:(BridgeKoin_coreBeanDefinition<T> *)beanDefinition __attribute__((swift_name("init(beanDefinition:)"))) __attribute__((objc_designated_initializer));
- (T _Nullable)createContext:(BridgeKoin_coreResolutionContext *)context __attribute__((swift_name("create(context:)")));
- (void)dropScope:(BridgeKoin_coreScope * _Nullable)scope __attribute__((swift_name("drop(scope:)")));
- (void)dropAll __attribute__((swift_name("dropAll()")));
- (T _Nullable)getContext:(BridgeKoin_coreResolutionContext *)context __attribute__((swift_name("get(context:)")));
- (BOOL)isCreatedContext:(BridgeKoin_coreResolutionContext * _Nullable)context __attribute__((swift_name("isCreated(context:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Koin_coreScopeDSL")))
@interface BridgeKoin_coreScopeDSL : BridgeBase
- (instancetype)initWithScopeQualifier:(id<BridgeKoin_coreQualifier>)scopeQualifier module:(BridgeKoin_coreModule *)module __attribute__((swift_name("init(scopeQualifier:module:)"))) __attribute__((objc_designated_initializer));
- (BridgeKoin_coreKoinDefinition<id> *)factoryQualifier:(id<BridgeKoin_coreQualifier> _Nullable)qualifier definition:(id _Nullable (^)(BridgeKoin_coreScope *, BridgeKoin_coreParametersHolder *))definition __attribute__((swift_name("factory(qualifier:definition:)")));
- (BridgeKoin_coreKoinDefinition<id> *)scopedQualifier:(id<BridgeKoin_coreQualifier> _Nullable)qualifier definition:(id _Nullable (^)(BridgeKoin_coreScope *, BridgeKoin_coreParametersHolder *))definition __attribute__((swift_name("scoped(qualifier:definition:)")));
@property (readonly) BridgeKoin_coreModule *module __attribute__((swift_name("module")));
@property (readonly) id<BridgeKoin_coreQualifier> scopeQualifier __attribute__((swift_name("scopeQualifier")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Koin_coreKoinApplication.Companion")))
@interface BridgeKoin_coreKoinApplicationCompanion : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeKoin_coreKoinApplicationCompanion *shared __attribute__((swift_name("shared")));
- (BridgeKoin_coreKoinApplication *)doInit __attribute__((swift_name("doInit()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Koin_coreLevel")))
@interface BridgeKoin_coreLevel : BridgeKotlinEnum<BridgeKoin_coreLevel *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) BridgeKoin_coreLevel *debug __attribute__((swift_name("debug")));
@property (class, readonly) BridgeKoin_coreLevel *info __attribute__((swift_name("info")));
@property (class, readonly) BridgeKoin_coreLevel *warning __attribute__((swift_name("warning")));
@property (class, readonly) BridgeKoin_coreLevel *error __attribute__((swift_name("error")));
@property (class, readonly) BridgeKoin_coreLevel *none __attribute__((swift_name("none")));
+ (BridgeKotlinArray<BridgeKoin_coreLevel *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<BridgeKoin_coreLevel *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreCompositeEncoder")))
@protocol BridgeKotlinx_serialization_coreCompositeEncoder
@required
- (void)encodeBooleanElementDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(BOOL)value __attribute__((swift_name("encodeBooleanElement(descriptor:index:value:)")));
- (void)encodeByteElementDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int8_t)value __attribute__((swift_name("encodeByteElement(descriptor:index:value:)")));
- (void)encodeCharElementDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(unichar)value __attribute__((swift_name("encodeCharElement(descriptor:index:value:)")));
- (void)encodeDoubleElementDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(double)value __attribute__((swift_name("encodeDoubleElement(descriptor:index:value:)")));
- (void)encodeFloatElementDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(float)value __attribute__((swift_name("encodeFloatElement(descriptor:index:value:)")));
- (id<BridgeKotlinx_serialization_coreEncoder>)encodeInlineElementDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("encodeInlineElement(descriptor:index:)")));
- (void)encodeIntElementDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int32_t)value __attribute__((swift_name("encodeIntElement(descriptor:index:value:)")));
- (void)encodeLongElementDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int64_t)value __attribute__((swift_name("encodeLongElement(descriptor:index:value:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNullableSerializableElementDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index serializer:(id<BridgeKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeNullableSerializableElement(descriptor:index:serializer:value:)")));
- (void)encodeSerializableElementDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index serializer:(id<BridgeKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeSerializableElement(descriptor:index:serializer:value:)")));
- (void)encodeShortElementDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int16_t)value __attribute__((swift_name("encodeShortElement(descriptor:index:value:)")));
- (void)encodeStringElementDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(NSString *)value __attribute__((swift_name("encodeStringElement(descriptor:index:value:)")));
- (void)endStructureDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("endStructure(descriptor:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)shouldEncodeElementDefaultDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("shouldEncodeElementDefault(descriptor:index:)")));
@property (readonly) BridgeKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerializersModule")))
@interface BridgeKotlinx_serialization_coreSerializersModule : BridgeBase

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)dumpToCollector:(id<BridgeKotlinx_serialization_coreSerializersModuleCollector>)collector __attribute__((swift_name("dumpTo(collector:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<BridgeKotlinx_serialization_coreKSerializer> _Nullable)getContextualKClass:(id<BridgeKotlinKClass>)kClass typeArgumentsSerializers:(NSArray<id<BridgeKotlinx_serialization_coreKSerializer>> *)typeArgumentsSerializers __attribute__((swift_name("getContextual(kClass:typeArgumentsSerializers:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<BridgeKotlinx_serialization_coreSerializationStrategy> _Nullable)getPolymorphicBaseClass:(id<BridgeKotlinKClass>)baseClass value:(id)value __attribute__((swift_name("getPolymorphic(baseClass:value:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<BridgeKotlinx_serialization_coreDeserializationStrategy> _Nullable)getPolymorphicBaseClass:(id<BridgeKotlinKClass>)baseClass serializedClassName:(NSString * _Nullable)serializedClassName __attribute__((swift_name("getPolymorphic(baseClass:serializedClassName:)")));
@end

__attribute__((swift_name("KotlinAnnotation")))
@protocol BridgeKotlinAnnotation
@required
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerialKind")))
@interface BridgeKotlinx_serialization_coreSerialKind : BridgeBase
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreCompositeDecoder")))
@protocol BridgeKotlinx_serialization_coreCompositeDecoder
@required
- (BOOL)decodeBooleanElementDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeBooleanElement(descriptor:index:)")));
- (int8_t)decodeByteElementDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeByteElement(descriptor:index:)")));
- (unichar)decodeCharElementDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeCharElement(descriptor:index:)")));
- (int32_t)decodeCollectionSizeDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeCollectionSize(descriptor:)")));
- (double)decodeDoubleElementDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeDoubleElement(descriptor:index:)")));
- (int32_t)decodeElementIndexDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeElementIndex(descriptor:)")));
- (float)decodeFloatElementDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeFloatElement(descriptor:index:)")));
- (id<BridgeKotlinx_serialization_coreDecoder>)decodeInlineElementDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeInlineElement(descriptor:index:)")));
- (int32_t)decodeIntElementDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeIntElement(descriptor:index:)")));
- (int64_t)decodeLongElementDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeLongElement(descriptor:index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id _Nullable)decodeNullableSerializableElementDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index deserializer:(id<BridgeKotlinx_serialization_coreDeserializationStrategy>)deserializer previousValue:(id _Nullable)previousValue __attribute__((swift_name("decodeNullableSerializableElement(descriptor:index:deserializer:previousValue:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)decodeSequentially __attribute__((swift_name("decodeSequentially()")));
- (id _Nullable)decodeSerializableElementDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index deserializer:(id<BridgeKotlinx_serialization_coreDeserializationStrategy>)deserializer previousValue:(id _Nullable)previousValue __attribute__((swift_name("decodeSerializableElement(descriptor:index:deserializer:previousValue:)")));
- (int16_t)decodeShortElementDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeShortElement(descriptor:index:)")));
- (NSString *)decodeStringElementDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeStringElement(descriptor:index:)")));
- (void)endStructureDescriptor:(id<BridgeKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("endStructure(descriptor:)")));
@property (readonly) BridgeKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinNothing")))
@interface BridgeKotlinNothing : BridgeBase
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("Kotlinx_coroutines_coreParentJob")))
@protocol BridgeKotlinx_coroutines_coreParentJob <BridgeKotlinx_coroutines_coreJob>
@required

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (BridgeKotlinCancellationException *)getChildJobCancellationCause __attribute__((swift_name("getChildJobCancellationCause()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinUnit")))
@interface BridgeKotlinUnit : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)unit __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeKotlinUnit *shared __attribute__((swift_name("shared")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("Kotlinx_coroutines_coreSelectInstance")))
@protocol BridgeKotlinx_coroutines_coreSelectInstance
@required
- (void)disposeOnCompletionDisposableHandle:(id<BridgeKotlinx_coroutines_coreDisposableHandle>)disposableHandle __attribute__((swift_name("disposeOnCompletion(disposableHandle:)")));
- (void)selectInRegistrationPhaseInternalResult:(id _Nullable)internalResult __attribute__((swift_name("selectInRegistrationPhase(internalResult:)")));
- (BOOL)trySelectClauseObject:(id)clauseObject result:(id _Nullable)result __attribute__((swift_name("trySelect(clauseObject:result:)")));
@property (readonly) id<BridgeKotlinCoroutineContext> context __attribute__((swift_name("context")));
@end

__attribute__((swift_name("Koin_coreScopeCallback")))
@protocol BridgeKoin_coreScopeCallback
@required
- (void)onScopeCloseScope:(BridgeKoin_coreScope *)scope __attribute__((swift_name("onScopeClose(scope:)")));
@end

__attribute__((swift_name("Koin_coreKoinExtension")))
@protocol BridgeKoin_coreKoinExtension
@required
- (void)onClose __attribute__((swift_name("onClose()")));
- (void)onRegisterKoin:(BridgeKoin_coreKoin *)koin __attribute__((swift_name("onRegister(koin:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Koin_coreScopeRegistry.Companion")))
@interface BridgeKoin_coreScopeRegistryCompanion : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeKoin_coreScopeRegistryCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("Kotlinx_datetimeDateTimeFormat")))
@protocol BridgeKotlinx_datetimeDateTimeFormat
@required
- (NSString *)formatValue:(id _Nullable)value __attribute__((swift_name("format(value:)")));
- (id<BridgeKotlinAppendable>)formatToAppendable:(id<BridgeKotlinAppendable>)appendable value:(id _Nullable)value __attribute__((swift_name("formatTo(appendable:value:)")));
- (id _Nullable)parseInput:(id)input __attribute__((swift_name("parse(input:)")));
- (id _Nullable)parseOrNullInput:(id)input __attribute__((swift_name("parseOrNull(input:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Koin_coreBeanDefinition")))
@interface BridgeKoin_coreBeanDefinition<T> : BridgeBase
- (instancetype)initWithScopeQualifier:(id<BridgeKoin_coreQualifier>)scopeQualifier primaryType:(id<BridgeKotlinKClass>)primaryType qualifier:(id<BridgeKoin_coreQualifier> _Nullable)qualifier definition:(T _Nullable (^)(BridgeKoin_coreScope *, BridgeKoin_coreParametersHolder *))definition kind:(BridgeKoin_coreKind *)kind secondaryTypes:(NSArray<id<BridgeKotlinKClass>> *)secondaryTypes __attribute__((swift_name("init(scopeQualifier:primaryType:qualifier:definition:kind:secondaryTypes:)"))) __attribute__((objc_designated_initializer));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (BOOL)hasTypeClazz:(id<BridgeKotlinKClass>)clazz __attribute__((swift_name("hasType(clazz:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (BOOL)isClazz:(id<BridgeKotlinKClass>)clazz qualifier:(id<BridgeKoin_coreQualifier> _Nullable)qualifier scopeDefinition:(id<BridgeKoin_coreQualifier>)scopeDefinition __attribute__((swift_name("is(clazz:qualifier:scopeDefinition:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@property BridgeKoin_coreCallbacks<T> *callbacks __attribute__((swift_name("callbacks")));
@property (readonly) T _Nullable (^definition)(BridgeKoin_coreScope *, BridgeKoin_coreParametersHolder *) __attribute__((swift_name("definition")));
@property (readonly) BridgeKoin_coreKind *kind __attribute__((swift_name("kind")));
@property (readonly) id<BridgeKotlinKClass> primaryType __attribute__((swift_name("primaryType")));
@property id<BridgeKoin_coreQualifier> _Nullable qualifier __attribute__((swift_name("qualifier")));
@property (readonly) id<BridgeKoin_coreQualifier> scopeQualifier __attribute__((swift_name("scopeQualifier")));
@property NSArray<id<BridgeKotlinKClass>> *secondaryTypes __attribute__((swift_name("secondaryTypes")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Koin_coreInstanceFactoryCompanion")))
@interface BridgeKoin_coreInstanceFactoryCompanion : BridgeBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) BridgeKoin_coreInstanceFactoryCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *ERROR_SEPARATOR __attribute__((swift_name("ERROR_SEPARATOR")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Koin_coreResolutionContext")))
@interface BridgeKoin_coreResolutionContext : BridgeBase
- (instancetype)initWithLogger:(BridgeKoin_coreLogger *)logger scope:(BridgeKoin_coreScope *)scope clazz:(id<BridgeKotlinKClass>)clazz qualifier:(id<BridgeKoin_coreQualifier> _Nullable)qualifier parameters:(BridgeKoin_coreParametersHolder * _Nullable)parameters __attribute__((swift_name("init(logger:scope:clazz:qualifier:parameters:)"))) __attribute__((objc_designated_initializer));
@property (readonly) id<BridgeKotlinKClass> clazz __attribute__((swift_name("clazz")));
@property (readonly) NSString *debugTag __attribute__((swift_name("debugTag")));
@property (readonly) BridgeKoin_coreLogger *logger __attribute__((swift_name("logger")));
@property (readonly) BridgeKoin_coreParametersHolder * _Nullable parameters __attribute__((swift_name("parameters")));
@property (readonly) id<BridgeKoin_coreQualifier> _Nullable qualifier __attribute__((swift_name("qualifier")));
@property (readonly) BridgeKoin_coreScope *scope __attribute__((swift_name("scope")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
__attribute__((swift_name("Kotlinx_serialization_coreSerializersModuleCollector")))
@protocol BridgeKotlinx_serialization_coreSerializersModuleCollector
@required
- (void)contextualKClass:(id<BridgeKotlinKClass>)kClass provider:(id<BridgeKotlinx_serialization_coreKSerializer> (^)(NSArray<id<BridgeKotlinx_serialization_coreKSerializer>> *))provider __attribute__((swift_name("contextual(kClass:provider:)")));
- (void)contextualKClass:(id<BridgeKotlinKClass>)kClass serializer:(id<BridgeKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("contextual(kClass:serializer:)")));
- (void)polymorphicBaseClass:(id<BridgeKotlinKClass>)baseClass actualClass:(id<BridgeKotlinKClass>)actualClass actualSerializer:(id<BridgeKotlinx_serialization_coreKSerializer>)actualSerializer __attribute__((swift_name("polymorphic(baseClass:actualClass:actualSerializer:)")));
- (void)polymorphicDefaultBaseClass:(id<BridgeKotlinKClass>)baseClass defaultDeserializerProvider:(id<BridgeKotlinx_serialization_coreDeserializationStrategy> _Nullable (^)(NSString * _Nullable))defaultDeserializerProvider __attribute__((swift_name("polymorphicDefault(baseClass:defaultDeserializerProvider:)"))) __attribute__((deprecated("Deprecated in favor of function with more precise name: polymorphicDefaultDeserializer")));
- (void)polymorphicDefaultDeserializerBaseClass:(id<BridgeKotlinKClass>)baseClass defaultDeserializerProvider:(id<BridgeKotlinx_serialization_coreDeserializationStrategy> _Nullable (^)(NSString * _Nullable))defaultDeserializerProvider __attribute__((swift_name("polymorphicDefaultDeserializer(baseClass:defaultDeserializerProvider:)")));
- (void)polymorphicDefaultSerializerBaseClass:(id<BridgeKotlinKClass>)baseClass defaultSerializerProvider:(id<BridgeKotlinx_serialization_coreSerializationStrategy> _Nullable (^)(id))defaultSerializerProvider __attribute__((swift_name("polymorphicDefaultSerializer(baseClass:defaultSerializerProvider:)")));
@end

__attribute__((swift_name("KotlinAppendable")))
@protocol BridgeKotlinAppendable
@required
- (id<BridgeKotlinAppendable>)appendValue:(unichar)value __attribute__((swift_name("append(value:)")));
- (id<BridgeKotlinAppendable>)appendValue_:(id _Nullable)value __attribute__((swift_name("append(value_:)")));
- (id<BridgeKotlinAppendable>)appendValue:(id _Nullable)value startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("append(value:startIndex:endIndex:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Koin_coreKind")))
@interface BridgeKoin_coreKind : BridgeKotlinEnum<BridgeKoin_coreKind *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) BridgeKoin_coreKind *singleton __attribute__((swift_name("singleton")));
@property (class, readonly) BridgeKoin_coreKind *factory __attribute__((swift_name("factory")));
@property (class, readonly) BridgeKoin_coreKind *scoped __attribute__((swift_name("scoped")));
+ (BridgeKotlinArray<BridgeKoin_coreKind *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<BridgeKoin_coreKind *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Koin_coreCallbacks")))
@interface BridgeKoin_coreCallbacks<T> : BridgeBase
- (instancetype)initWithOnClose:(void (^ _Nullable)(T _Nullable))onClose __attribute__((swift_name("init(onClose:)"))) __attribute__((objc_designated_initializer));
- (BridgeKoin_coreCallbacks<T> *)doCopyOnClose:(void (^ _Nullable)(T _Nullable))onClose __attribute__((swift_name("doCopy(onClose:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) void (^ _Nullable onClose)(T _Nullable) __attribute__((swift_name("onClose")));
@end

#pragma pop_macro("_Nullable_result")
#pragma clang diagnostic pop
NS_ASSUME_NONNULL_END
