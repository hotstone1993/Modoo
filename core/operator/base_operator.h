#ifndef MODOO_CORE_OPERATOR_BASE
#define MODOO_CORE_OPERATOR_BASE

#include "context.h"
#include <memory>
#include <vector>

namespace modoo::core::op {
    class BaseOperator {
    public:
        BaseOperator();
        virtual ~BaseOperator() = default;
        
        virtual bool isPossibleNextOperator(std::shared_ptr<op::BaseOperator> op) {
            return true;
        };
    private:
        Shape in;
        Shape out;
    };
}

#endif // MODOO_CORE_OPERATOR_BASE