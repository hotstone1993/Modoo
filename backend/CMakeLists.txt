cmake_minimum_required(VERSION 3.28)

project(pytorch_backend LANGUAGES CXX)

find_package(Torch REQUIRED)

add_library(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/pytorch_backend.cpp
                                ${UTILS_CPP})

set_target_properties(
${PROJECT_NAME} SHARED
PROPERTIES CXX_STANDARD 20
            CXX_STANDARD_REQUIRED ON)

target_include_directories(
    ${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../core
)

target_link_libraries(${PROJECT_NAME} PRIVATE ${TORCH_LIBRARIES})