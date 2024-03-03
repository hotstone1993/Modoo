#pragma once

#include <variant>

#include "backend_utils.h"

// Backend Header
#include "pytorch_backend.h"

namespace modoo::core {

template <utils::CBackend... TBackend>
class ModelWrapper {
public:
    void loadModel(std::string_view path) {
        std::visit([=](auto& obj) -> auto { return obj.loadModel(path); }, backend);
    }
    void inference(const data::ModooData& input, data::ModooData* output) {
        std::visit([&](auto& obj) -> auto { return obj.inference(input, output); }, backend);
    }
private:
	std::variant<TBackend...> backend{};
    utils::BackendType type;
};

}