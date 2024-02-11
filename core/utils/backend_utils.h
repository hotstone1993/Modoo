#pragma once

#include <concepts>
#include <type_traits>
#include <string_view>

#include "device.h"

namespace modoo::core::utils {

template <typename Backend>
concept CFoo = requires(Backend* backend, std::string_view path, core::Device device) {
	{ backend->loadModel() } -> std::same_as<bool>;
};


}