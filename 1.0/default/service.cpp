#define LOG_TAG "vendor.demo.rpi4gpio@1.0-service"
 
#include <vendor/demo/rpi4gpio/1.0/IRpi4gpio.h>
#include <hidl/LegacySupport.h>
#include "Rpi4gpio.h"
using vendor::demo::rpi4gpio::V1_0::IRpi4gpio;
using vendor::demo::rpi4gpio::implementation::Rpi4gpio;
using android::hardware::defaultPassthroughServiceImplementation;
using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;
using android::sp;
 
 
int main() {
// Binder approach
  sp<IRpi4gpio> service = new Rpi4gpio();
  configureRpcThreadpool(3, true /*callerWillJoin*/);
    if(android::OK !=  service->registerAsService())
      return 1; 
    joinRpcThreadpool();
}
