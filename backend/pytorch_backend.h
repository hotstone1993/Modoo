#pragma once

#include <torch/script.h>
#include <memory>

namespace modoo::backend::pytorch {

class PyTorchBackend {

    PyTorchBackend();
    ~PyTorchBackend();
public:
    void loadModel(std::string_view path);

private:
    torch::jit::script::Module model;
};

}