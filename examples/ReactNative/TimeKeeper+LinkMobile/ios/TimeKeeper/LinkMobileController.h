#import <Foundation/Foundation.h>
#import <React/RCTBridgeModule.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^LinkMobileEventBlock)(NSDictionary *body);

@interface LinkMobileController : NSObject

@property (nonatomic, copy, nullable) LinkMobileEventBlock onDeviceDiscovered;
@property (nonatomic, copy, nullable) LinkMobileEventBlock onDeviceConnected;
@property (nonatomic, copy, nullable) LinkMobileEventBlock onDeviceDisconnected;
@property (nonatomic, copy, nullable) LinkMobileEventBlock onBLEStateChanged;
@property (nonatomic, copy, nullable) LinkMobileEventBlock onCredentialExchangeResult;
@property (nonatomic, copy, nullable) LinkMobileEventBlock onDFUStateChanged;
@property (nonatomic, copy, nullable) LinkMobileEventBlock onHeartbeat;
@property (nonatomic, copy, nullable) LinkMobileEventBlock onProxyStreamStateChanged;

- (void)initialize:(NSString *)serverAddress
          resolve:(RCTPromiseResolveBlock)resolve
           reject:(RCTPromiseRejectBlock)reject;

- (void)start:(NSString *)uuid
     resolve:(RCTPromiseResolveBlock)resolve
      reject:(RCTPromiseRejectBlock)reject;

- (void)identify:(NSString *)identifier
        resolve:(RCTPromiseResolveBlock)resolve
         reject:(RCTPromiseRejectBlock)reject;

- (void)setLockEngagedState:(NSString *)identifier
                    engaged:(BOOL)engaged
                    resolve:(RCTPromiseResolveBlock)resolve
                     reject:(RCTPromiseRejectBlock)reject;

- (void)sendOutOfBandPayload:(NSString *)identifier
               payloadBase64:(NSString *)payloadBase64
                     resolve:(RCTPromiseResolveBlock)resolve
                      reject:(RCTPromiseRejectBlock)reject;

- (void)checkForDFU:(NSString *)identifier
           resolve:(RCTPromiseResolveBlock)resolve
            reject:(RCTPromiseRejectBlock)reject;

- (void)startDFU:(NSString *)identifier
        resolve:(RCTPromiseResolveBlock)resolve
         reject:(RCTPromiseRejectBlock)reject;

- (void)cancelDFU:(RCTPromiseResolveBlock)resolve
          reject:(RCTPromiseRejectBlock)reject;

- (void)waitForDeviceMode:(NSString *)identifier
              dfuRequired:(BOOL)dfuRequired
                  resolve:(RCTPromiseResolveBlock)resolve
                   reject:(RCTPromiseRejectBlock)reject;

- (void)exitDFUInstallMode:(NSString *)identifier
                   resolve:(RCTPromiseResolveBlock)resolve
                    reject:(RCTPromiseRejectBlock)reject;

- (void)fetchTokenUnlockPublicKey:(NSString *)tokenNamespace
                          resolve:(RCTPromiseResolveBlock)resolve
                           reject:(RCTPromiseRejectBlock)reject;

- (void)storeTokenUnlockPass:(NSString *)tokenNamespace
        accessDocumentBase64:(NSString *)accessDocumentBase64
         readerGroupIdBase64:(NSString *)readerGroupIdBase64
     issuerCaPublicKeyBase64:(NSString *)issuerCaPublicKeyBase64
   issuerCaCertificateBase64:(NSString *)issuerCaCertificateBase64
                     resolve:(RCTPromiseResolveBlock)resolve
                      reject:(RCTPromiseRejectBlock)reject;

- (void)tokenUnlock:(NSString *)identifier
     tokenNamespace:(NSString *)tokenNamespace
            resolve:(RCTPromiseResolveBlock)resolve
             reject:(RCTPromiseRejectBlock)reject;

@end

NS_ASSUME_NONNULL_END
