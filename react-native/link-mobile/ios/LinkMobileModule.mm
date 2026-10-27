#import <LinkMobileSpec/LinkMobileSpec.h>

#import "LinkMobileController.h"

@interface LinkMobile : NativeLinkMobileSpecBase <NativeLinkMobileSpec>
@end

@implementation LinkMobile {
  LinkMobileController *_controller;
}

RCT_EXPORT_MODULE(LinkMobile)

+ (BOOL)requiresMainQueueSetup
{
  return YES;
}

- (instancetype)init
{
  if (self = [super init]) {
    _controller = [LinkMobileController new];
    __weak LinkMobile *weakSelf = self;
    _controller.onDeviceDiscovered = ^(NSDictionary *body) {
      [weakSelf emitDiscovered:body];
    };
    _controller.onDeviceConnected = ^(NSDictionary *body) {
      [weakSelf emitConnected:body];
    };
    _controller.onDeviceDisconnected = ^(NSDictionary *body) {
      [weakSelf emitDisconnected:body];
    };
    _controller.onBLEStateChanged = ^(NSDictionary *body) {
      [weakSelf emitBleState:body];
    };
    _controller.onCredentialExchangeResult = ^(NSDictionary *body) {
      [weakSelf emitCredentialResult:body];
    };
    _controller.onDFUStateChanged = ^(NSDictionary *body) {
      [weakSelf emitDfuState:body];
    };
    _controller.onHeartbeat = ^(NSDictionary *body) {
      [weakSelf emitHeartbeat:body];
    };
    _controller.onProxyStreamStateChanged = ^(NSDictionary *body) {
      [weakSelf emitProxyStream:body];
    };
  }
  return self;
}

- (void)initialize:(NSString *)serverAddress
          resolve:(RCTPromiseResolveBlock)resolve
           reject:(RCTPromiseRejectBlock)reject
{
  [_controller initialize:serverAddress resolve:resolve reject:reject];
}

- (void)start:(NSString *)uuid
     resolve:(RCTPromiseResolveBlock)resolve
      reject:(RCTPromiseRejectBlock)reject
{
  [_controller start:uuid resolve:resolve reject:reject];
}

- (void)startLimited:(NSString *)uuid
            resolve:(RCTPromiseResolveBlock)resolve
             reject:(RCTPromiseRejectBlock)reject
{
  [_controller start:uuid resolve:resolve reject:reject];
}

- (void)identify:(NSString *)identifier
        resolve:(RCTPromiseResolveBlock)resolve
         reject:(RCTPromiseRejectBlock)reject
{
  [_controller identify:identifier resolve:resolve reject:reject];
}

- (void)setLockEngagedState:(NSString *)identifier
                    engaged:(BOOL)engaged
                    resolve:(RCTPromiseResolveBlock)resolve
                     reject:(RCTPromiseRejectBlock)reject
{
  [_controller setLockEngagedState:identifier engaged:engaged resolve:resolve reject:reject];
}

- (void)sendOutOfBandPayload:(NSString *)identifier
               payloadBase64:(NSString *)payloadBase64
                     resolve:(RCTPromiseResolveBlock)resolve
                      reject:(RCTPromiseRejectBlock)reject
{
  [_controller sendOutOfBandPayload:identifier payloadBase64:payloadBase64 resolve:resolve reject:reject];
}

- (void)checkForDFU:(NSString *)identifier
           resolve:(RCTPromiseResolveBlock)resolve
            reject:(RCTPromiseRejectBlock)reject
{
  [_controller checkForDFU:identifier resolve:resolve reject:reject];
}

- (void)startDFU:(NSString *)identifier
        resolve:(RCTPromiseResolveBlock)resolve
         reject:(RCTPromiseRejectBlock)reject
{
  [_controller startDFU:identifier resolve:resolve reject:reject];
}

- (void)cancelDFU:(RCTPromiseResolveBlock)resolve
          reject:(RCTPromiseRejectBlock)reject
{
  [_controller cancelDFU:resolve reject:reject];
}

- (void)waitForDeviceMode:(NSString *)identifier
              dfuRequired:(BOOL)dfuRequired
                  resolve:(RCTPromiseResolveBlock)resolve
                   reject:(RCTPromiseRejectBlock)reject
{
  [_controller waitForDeviceMode:identifier dfuRequired:dfuRequired resolve:resolve reject:reject];
}

- (void)exitDFUInstallMode:(NSString *)identifier
                   resolve:(RCTPromiseResolveBlock)resolve
                    reject:(RCTPromiseRejectBlock)reject
{
  [_controller exitDFUInstallMode:identifier resolve:resolve reject:reject];
}

- (void)fetchTokenUnlockPublicKey:(NSString *)tokenNamespace
                          resolve:(RCTPromiseResolveBlock)resolve
                           reject:(RCTPromiseRejectBlock)reject
{
  [_controller fetchTokenUnlockPublicKey:tokenNamespace resolve:resolve reject:reject];
}

- (void)storeTokenUnlockPass:(NSString *)tokenNamespace
        accessDocumentBase64:(NSString *)accessDocumentBase64
         readerGroupIdBase64:(NSString *)readerGroupIdBase64
     issuerCaPublicKeyBase64:(NSString *)issuerCaPublicKeyBase64
   issuerCaCertificateBase64:(NSString *)issuerCaCertificateBase64
                     resolve:(RCTPromiseResolveBlock)resolve
                      reject:(RCTPromiseRejectBlock)reject
{
  [_controller storeTokenUnlockPass:tokenNamespace
              accessDocumentBase64:accessDocumentBase64
               readerGroupIdBase64:readerGroupIdBase64
           issuerCaPublicKeyBase64:issuerCaPublicKeyBase64
         issuerCaCertificateBase64:issuerCaCertificateBase64
                           resolve:resolve
                            reject:reject];
}

- (void)tokenUnlock:(NSString *)identifier
     tokenNamespace:(NSString *)tokenNamespace
            resolve:(RCTPromiseResolveBlock)resolve
             reject:(RCTPromiseRejectBlock)reject
{
  [_controller tokenUnlock:identifier tokenNamespace:tokenNamespace resolve:resolve reject:reject];
}

- (std::shared_ptr<facebook::react::TurboModule>)getTurboModule:
    (const facebook::react::ObjCTurboModule::InitParams &)params
{
  return std::make_shared<facebook::react::NativeLinkMobileSpecJSI>(params);
}

- (void)emitDiscovered:(NSDictionary *)body
{
  if (_eventEmitterCallback) {
    [self emitOnDeviceDiscovered:body];
  }
}

- (void)emitConnected:(NSDictionary *)body
{
  if (_eventEmitterCallback) {
    [self emitOnDeviceConnected:body];
  }
}

- (void)emitDisconnected:(NSDictionary *)body
{
  if (_eventEmitterCallback) {
    [self emitOnDeviceDisconnected:body];
  }
}

- (void)emitBleState:(NSDictionary *)body
{
  if (_eventEmitterCallback) {
    [self emitOnBLEStateChanged:body];
  }
}

- (void)emitCredentialResult:(NSDictionary *)body
{
  if (_eventEmitterCallback) {
    [self emitOnCredentialExchangeResult:body];
  }
}

- (void)emitDfuState:(NSDictionary *)body
{
  if (_eventEmitterCallback) {
    [self emitOnDFUStateChanged:body];
  }
}

- (void)emitHeartbeat:(NSDictionary *)body
{
  if (_eventEmitterCallback) {
    [self emitOnHeartbeat:body];
  }
}

- (void)emitProxyStream:(NSDictionary *)body
{
  if (_eventEmitterCallback) {
    [self emitOnProxyStreamStateChanged:body];
  }
}

@end
