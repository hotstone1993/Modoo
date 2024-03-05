#pragma once

#include <variant>

#include "backend_utils.h"
#include "shape.h"

// Backend Header
#include "pytorch_backend.h"

#define MODELS modoo::backend::pytorch::PyTorchBackend

namespace modoo::core {

template <utils::CBackend... TBackend>
class ModelWrapper {
public:
    ModelWrapper(utils::BackendType type): type(type) {}

    void loadModel(std::string_view path) {
        std::visit([=](auto& obj) -> auto { return obj.loadModel(path); }, backend);
    }
    void inference(const data::ModooData& input, data::ModooData* output) {
        std::visit([&](auto& obj) -> auto { return obj.inference(input, output); }, backend);
    }
private:
    Shape shape;
	std::variant<TBackend...> backend{};
    utils::BackendType type;
};

}