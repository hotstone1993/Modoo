cmake_minimum_required(VERSION 3.13)

project(core-test LANGUAGES CXX CUDA)

find_package(Catch2 3 REQUIRED)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/UnitTest.cpp)

set_target_properties(
${PROJECT_NAME}
PROPERTIES CXX_STANDARD 20
            CXX_STANDARD_REQUIRED ON
            CUDA_STANDARD 17
            CUDA_ARCHITECTURES 75
            CUDA_SEPARABLE_COMPILATION ON)

target_link_libraries(${PROJECT_NAME} PRIVATE core
                                            ${CUDART_LIBRARY}
                                            Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(core-test)