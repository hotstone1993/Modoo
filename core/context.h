#ifndef MODOO_CORE_CONTEXT
#define MODOO_CORE_CONTEXT

#include "shape.h"
#include "device.h"
#include "framework.h"

namespace modoo::core {
    class BaseContext {
    public:
        BaseContext();
        virtual ~BaseContext() = default;

    private:
        Device device;
        Shape shape;
        FrameworkType frameworkType;
    };
}

#endif // MODOO_CORE_CONTEXT