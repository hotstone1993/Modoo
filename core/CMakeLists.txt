cmake_minimum_required(VERSION 3.28)

project(core LANGUAGES CXX)

find_package(Torch REQUIRED)

set(UTILS_CPP ${CMAKE_CURRENT_SOURCE_DIR}/utils/id_generator.cpp)

add_library(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/context.cpp
                                ${UTILS_CPP})

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/backend)

set_target_properties(
${PROJECT_NAME}
PROPERTIES CXX_STANDARD 20
            CXX_STANDARD_REQUIRED ON)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                                                    ${CMAKE_CURRENT_SOURCE_DIR}/utils
                                                    ${CMAKE_CURRENT_SOURCE_DIR}/backend
                                                    ${CMAKE_CURRENT_SOURCE_DIR}/data
                                                    ${TORCH_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} PRIVATE pytorch_backend)