#ifndef MODOO_CORE_LAYER_BASE
#define MODOO_CORE_LAYER_BASE

#include "context.h"
#include <memory>

namespace modoo::core::layer {
    class BaseLayer {
    public:
        BaseLayer();
        virtual ~BaseLayer() = default;
        
        virtual bool process(const BaseContext* context, void* in, void* out) = 0;
        void setNextLayer(std::shared_ptr<BaseLayer> layer) {
            next = layer;
        }
    private:
        std::shared_ptr<BaseLayer> next;
    };
}

#endif // MODOO_CORE_LAYER_BASE