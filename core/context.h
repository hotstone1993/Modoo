#ifndef MODOO_CORE_CONTEXT
#define MODOO_CORE_CONTEXT

#include "device.h"
#include "framework.h"

namespace modoo::core {
    class BaseContext {
    public:
        BaseContext();
        virtual ~BaseContext() = default;

        Device device;
        FrameworkType frameworkType;
    private:
    };
}

#endif // MODOO_CORE_CONTEXT