#ifndef MODOO_CORE_CONTEXT
#define MODOO_CORE_CONTEXT

#include "shape.h"
#include "device.h"
#include "model_wrapper.h"

namespace modoo::core {

class BaseContext {
public:
    BaseContext();
    virtual ~BaseContext() = default;

    void setModel(std::shared_ptr<ModelWrapper> model) {
        this->model = model;
    }

private:
    Device device;
    Shape shape;
    std::shared_ptr<ModelWrapper> model;
};

}

#endif // MODOO_CORE_CONTEXT