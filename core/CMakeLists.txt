cmake_minimum_required(VERSION 3.13)

project(core LANGUAGES CXX CUDA)

set(VCPKG_TARGET_ARCHITECTURE "x64")
set(CMAKE_CUDA_FLAGS_DEBUG "${CMAKE_CUDA_FLAGS_DEBUG} -G -src-in-ptx")

if(MSVC)
  set(VCPKG_CMAKE_SYSTEM_NAME "")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
else()
  set(VCPKG_CMAKE_SYSTEM_NAME "Linux")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
endif()

find_package(CUDA REQUIRED)

set(UTILS_CPP ${CMAKE_CURRENT_SOURCE_DIR}/utils/id_generator.cpp)

add_library(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/context.cpp
                                ${UTILS_CPP})

set_target_properties(
${PROJECT_NAME}
PROPERTIES CXX_STANDARD 17
            CUDA_STANDARD 17
            CXX_STANDARD_REQUIRED ON
            CUDA_ARCHITECTURES 75
            CUDA_SEPARABLE_COMPILATION ON
            CUDA_RESOLVE_DEVICE_SYMBOLS ON)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                                                    ${CMAKE_CURRENT_SOURCE_DIR}/utils
                                                    ${CMAKE_CURRENT_SOURCE_DIR}/layer)

target_link_libraries(${PROJECT_NAME} PRIVATE ${TORCH_LIBRARIES}
                                            ${CUDART_LIBRARY})