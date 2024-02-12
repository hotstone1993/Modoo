#pragma once

#include <concepts>
#include <type_traits>
#include <string_view>

#include "context.h"

namespace modoo::core::utils {

template <typename Backend>
concept CFoo = requires(Backend* backend, std::string_view path, modoo::core::BaseContext* context) {
	{ backend->loadModel(path, context) } -> std::same_as<bool>;
};

}