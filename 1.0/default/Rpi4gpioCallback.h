// FIXME: your file license if you have one

#pragma once

#include <vendor/demo/rpi4gpio/1.0/IRpi4gpioCallback.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

namespace vendor::demo::rpi4gpio::implementation {

using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;

struct Rpi4gpioCallback : public V1_0::IRpi4gpioCallback {
    // Methods from ::vendor::demo::rpi4gpio::V1_0::IRpi4gpioCallback follow.
    Return<void> sendEvent(uint32_t event_id) override;
    Return<void> sendData(const hidl_vec<uint8_t>& data) override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.

};

// FIXME: most likely delete, this is only for passthrough implementations
// extern "C" IRpi4gpioCallback* HIDL_FETCH_IRpi4gpioCallback(const char* name);

}  // namespace vendor::demo::rpi4gpio::implementation
