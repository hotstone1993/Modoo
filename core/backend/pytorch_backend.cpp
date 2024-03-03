#include "pytorch_backend.h"


modoo::backend::pytorch::PyTorchBackend::PyTorchBackend() {
}

modoo::backend::pytorch::PyTorchBackend::~PyTorchBackend() {
}


bool modoo::backend::pytorch::PyTorchBackend::loadModel(std::string_view path) {
    try
    {
        model = torch::jit::load(path.data());
    }
    catch (const c10::Error &e)
    {
        std::string error = "Failed to load PyTorch Module: ";
        throw std::runtime_error(error + e.msg());
    }
}


bool modoo::backend::pytorch::PyTorchBackend::inference(const data::ModooData& input, data::ModooData* output) {
    torch::jit::IValue modelInput;
    torch::jit::IValue modelOutputs;
}