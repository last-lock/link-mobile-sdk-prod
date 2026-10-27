Pod::Spec.new do |s|
  s.name         = "LinkMobileRN"
  s.version      = "2.7.3"
  s.summary      = "Codegen anchor for the Link Mobile React Native bridge"
  s.homepage     = "https://github.com/last-lock/link-mobile-sdk-prod"
  s.license      = { :type => "Proprietary" }
  s.authors      = "Last Lock"
  s.platforms    = { :ios => "17.0" }
  s.source       = { :git => "https://github.com/last-lock/link-mobile-sdk-prod.git", :tag => "react-native-2.7.3" }
  s.source_files = "ios/LinkMobilePod.m"
  s.dependency "React-Core"
end
