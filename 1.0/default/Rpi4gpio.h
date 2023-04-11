// FIXME: your file license if you have one

#pragma once

#include <vendor/demo/rpi4gpio/1.0/IRpi4gpio.h>
#include <vendor/demo/rpi4gpio/1.0/IRpi4gpioCallback.h>
#include <android/hardware/automotive/vehicle/2.0/IVehicle.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <log/log.h>

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "TEST_Rpi4GPIO_HAL_20"
#define UEVENT_MSG_LEN 2048
namespace vendor::demo::rpi4gpio::implementation {

    using ::android::hardware::hidl_array;
    using ::android::hardware::hidl_memory;
    using ::android::hardware::hidl_string;
    using ::android::hardware::hidl_vec;
    using ::android::hardware::Return;
    using ::android::hardware::Void;
    using ::android::sp;
    using vendor::demo::rpi4gpio::V1_0::IRpi4gpioCallback;
    using vendor::demo::rpi4gpio::V1_0::LedStatus;
    using android::hardware::automotive::vehicle::V2_0::IVehicle;

    struct Rpi4gpio : public V1_0::IRpi4gpio {
        Rpi4gpio();  // Add manually
        ~Rpi4gpio();  // Add manually
        // Methods from ::vendor::demo::rpi4gpio::V1_0::IRpi4gpio follow.
        Return<::vendor::demo::rpi4gpio::V1_0::LedStatus> get() override;

        Return<int32_t> set(::vendor::demo::rpi4gpio::V1_0::LedStatus val) override;

        Return<void> on() override;

        Return<void> off() override;

        Return<void>
        registerCallback(const sp<::vendor::demo::rpi4gpio::V1_0::IRpi4gpioCallback> &cb) override;

        sp<IRpi4gpioCallback> mCallback;
        pthread_mutex_t mutexSW = PTHREAD_MUTEX_INITIALIZER;
        pthread_cond_t conditionSW;
        // Methods from ::android::hidl::base::V1_0::IBase follow.
        sp<IVehicle> iVehicleService;
    private:
        LedStatus state;
        int valid;

        pthread_t mPoll;
        pthread_mutex_t mLock = PTHREAD_MUTEX_INITIALIZER;

        //Return<void> setVhal(int value);

    };

// FIXME: most likely delete, this is only for passthrough implementations
// extern "C" IRpi4gpio* HIDL_FETCH_IRpi4gpio(const char* name);

}  // namespace vendor::demo::rpi4gpio::implementation
