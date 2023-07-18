#ifndef MODOO_CORE_DEVICE_TYPE
#define MODOO_CORE_CONTEXT

#include "id_generator.h"

namespace modoo::core {
    enum class DeviceType {
        CPU, CUDA
    };

    class Device {
    public:
        Device(DeviceType t = DeviceType::CPU): id (utils::IdGenerator::getInstance().createId()), type(t) {};
        ~Device() = default;

        bool operator=(const Device& other) {
            return (id == other.id && type == other.type);
        }

    private:
        int id;
        DeviceType type;
    };

    inline void findAvailableDevice() {
        
    }
}


#endif // MODOO_CORE_DEVICE_TYPE