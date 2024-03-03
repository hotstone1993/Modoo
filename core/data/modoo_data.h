#pragma once

#include <memory>

#include "type.h"

namespace modoo::data {

class ModooData {
public:
    ModooData(): data(nullptr), type(DataType::FLOAT_32) {}
    virtual ~ModooData() {}

    void* getRawData() {
        return data;
    }

    DataType getType() {
        return type;
    }

private:
    void* data;
    DataType type;
};

}