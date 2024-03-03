#pragma once

#include <torch/script.h>
#include <memory>

#include "modoo_data.h"

namespace modoo::backend::pytorch {

class PyTorchBackend {

    PyTorchBackend();
    ~PyTorchBackend();
public:
    bool loadModel(std::string_view path);
    bool inference(const data::ModooData& input, data::ModooData* output);

private:
    torch::jit::script::Module model;
};

}