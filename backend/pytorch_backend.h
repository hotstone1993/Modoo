#pragma once

#include <torch/script.h>
#include <memory>
#include "chunk.h"

namespace modoo::backend::pytorch {

class PyTorchBackend {

    PyTorchBackend();
    ~PyTorchBackend();
public:
    void loadModel(std::string_view path);
    void inference(Chunk* input, Chunk* output);

private:
    torch::jit::script::Module model;
};

}