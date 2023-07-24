#ifndef MODOO_CORE_CONTEXT
#define MODOO_CORE_CONTEXT

#include "shape.h"
#include "device.h"

namespace modoo::core {
    class BaseContext {
    public:
        BaseContext();
        virtual ~BaseContext() = default;

    private:
        Device device;
        Shape shape;
    };
}

#endif // MODOO_CORE_CONTEXT