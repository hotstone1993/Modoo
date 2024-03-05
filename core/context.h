#ifndef MODOO_CORE_CONTEXT
#define MODOO_CORE_CONTEXT

#include "device.h"
#include "model_wrapper.h"

namespace modoo::core {

class BaseContext {
public:
    BaseContext();
    virtual ~BaseContext() = default;

    void setModel(std::shared_ptr<ModelWrapper<MODELS>> model) {
        this->model = model;
    }
    

private:
    std::vector<Device> deviceList;
    std::shared_ptr<ModelWrapper<MODELS>> model;
};

}

#endif // MODOO_CORE_CONTEXT