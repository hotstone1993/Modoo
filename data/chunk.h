#pragma once

#include <memory>

#include "type"

namespace modoo::data {

class Chunk {
public:
    Chunk(): type(DataType::FLOAT_32) {}
    virtual ~Chunk() {}

    void* getRawData() {
        return data->data();
    }

    DataType getType() {
        return type;
    }

private:
    std::unique_ptr<void*> data;
    DataType type;
};

}