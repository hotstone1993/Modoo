#ifndef MODOO_CORE_LAYER_BASE
#define MODOO_CORE_LAYER_BASE

#include "context.h"
#include <memory>
#include <vector>

namespace modoo::core::layer {
    class BaseLayer {
    public:
        BaseLayer();
        virtual ~BaseLayer() = default;
        
        virtual bool process(const BaseContext* context, void* in, void* out) = 0;
        void setNextLayer(std::shared_ptr<BaseLayer> layer) {
            next.push_back(layer);
        }
    private:
        Shape shape;
        std::vector<std::shared_ptr<BaseLayer>> nextLayers;
    };
}

#endif // MODOO_CORE_LAYER_BASE