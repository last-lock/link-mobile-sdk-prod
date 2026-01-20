#import <React/RCTBridgeModule.h>
#import <React/RCTEventEmitter.h>

@interface RCT_EXTERN_MODULE(BridgeModule, RCTEventEmitter)

RCT_EXTERN_METHOD(initialize:(NSString *)serverAddress
                  uuid:(NSString *)uuid
                  resolver:(RCTPromiseResolveBlock)resolver
                  rejecter:(RCTPromiseRejectBlock)rejecter)

RCT_EXTERN_METHOD(start:(NSString *)uuid
                  resolver:(RCTPromiseResolveBlock)resolver
                  rejecter:(RCTPromiseRejectBlock)rejecter)

+ (BOOL)requiresMainQueueSetup
{
  return YES;
}

@end