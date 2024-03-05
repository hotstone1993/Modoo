#include "pytorch_backend.h"


modoo::backend::pytorch::PyTorchBackend::PyTorchBackend() {
}

modoo::backend::pytorch::PyTorchBackend::~PyTorchBackend() {
}


bool modoo::backend::pytorch::PyTorchBackend::loadModel(std::string_view path) {
    torch::InferenceMode inferenceMode{true};

    try
    {
        model = torch::jit::load(path.data());
    }
    catch (const c10::Error &e)
    {
        std::string error = "Failed to load PyTorch Module: ";
        throw std::runtime_error(error + e.msg());
    }
    return true;
}


bool modoo::backend::pytorch::PyTorchBackend::inference(const data::ModooData& input, data::ModooData* output) {
    torch::jit::IValue modelInput;
    torch::jit::IValue modelOutputs;

    torch::jit::setGraphExecutorOptimize(true);
    // this mode gets better performance by disabling autograd
    torch::InferenceMode inferenceGuard{true};

    torch::jit::getProfilingMode() = false;
    torch::jit::getExecutorMode() = false; 
    torch::jit::setTensorExprFuserEnabled(false);

    torch::NoGradGuard noGrad;

    // excute

    return true;
}

bool modoo::backend::pytorch::PyTorchBackend::validateInput() {
    const torch::jit::Method& method = model.get_method("forward");
    const auto& schema = method.function().getSchema();
    const std::vector<c10::Argument>& arguments = schema.arguments();

    return true;
}