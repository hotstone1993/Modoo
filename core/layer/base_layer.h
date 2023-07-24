#ifndef MODOO_CORE_LAYER_BASE
#define MODOO_CORE_LAYER_BASE

#include "base_operator.h"

namespace modoo::core::layer {
    class BaseLayer {
    public:
        BaseLayer() = default;
        virtual ~BaseLayer() = default;
        
        virtual bool process(const BaseContext* context, void* in, void* out) {
            return true;
        };
        virtual bool addOperator(std::shared_ptr<op::BaseOperator> op) {
            if (operators.size() > 1) {
                if (operators.back()->isPossibleNextOperator(op)) {
                    operators.push_back(op);
                } else {
                    return false;
                }
            } else {
                operators.push_back(op);
            }
            updateLayerShape();
            return true;
        }
        void setNextLayer(std::shared_ptr<BaseLayer> layer) {
            nextLayer = layer;
        }
    private:
        virtual bool updateLayerShape() {
        }

        Shape shape;
        std::vector<std::shared_ptr<op::BaseOperator>> operators;
        std::shared_ptr<BaseLayer> nextLayer;
    };
}

#endif // MODOO_CORE_LAYER_BASE