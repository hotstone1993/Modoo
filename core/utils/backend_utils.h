#pragma once

#include <concepts>
#include <type_traits>
#include <string_view>

#include "context.h"
#include "modoo_data.h"

namespace modoo::core::utils {

template <typename T>
concept CBackend = requires(T* backend, std::string_view path, const data::ModooData& input, data::ModooData* output) {
	{ backend->loadModel(path) } -> std::same_as<bool>;
	{ backend->inference(input, output) } -> std::same_as<bool>;
};

enum class BackendType {
	PyTorch, TensorFlow
};

}