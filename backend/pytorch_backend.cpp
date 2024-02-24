#include <torch/script.h>
#include <memory>

#include "context.h"

class PyTorchBackend {

    ~PyTorchBackend() {
        torch_model_.reset();
    }
public:
    bool loadModel(std::string_view path, modoo::core::BaseContext* context) {
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

private:
    std::shared_ptr<torch::jit::script::Module> model;
};