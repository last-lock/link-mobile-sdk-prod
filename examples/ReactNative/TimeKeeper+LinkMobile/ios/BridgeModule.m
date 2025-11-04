#import <React/RCTBridgeModule.h>

@interface RCT_EXTERN_MODULE(BridgeModule, NSObject)

RCT_EXTERN_METHOD(initialize:(NSString *)serverAddress
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