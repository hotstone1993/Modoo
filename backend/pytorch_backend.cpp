#include "pytorch_backend.h"


modoo::backend::pytorch::PyTorchBackend::PyTorchBackend() {
}

modoo::backend::pytorch::PyTorchBackend::~PyTorchBackend() {
}


void modoo::backend::pytorch::PyTorchBackend::loadModel(std::string_view path) {
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