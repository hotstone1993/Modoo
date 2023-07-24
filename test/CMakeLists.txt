cmake_minimum_required(VERSION 3.13)

project(core-test LANGUAGES CXX)

find_package(Catch2 3 REQUIRED)

set(MAIN_TEST ${CMAKE_CURRENT_SOURCE_DIR}/test_context.cpp)
set(UTILS_TEST ${CMAKE_CURRENT_SOURCE_DIR}/utils/test_id_generator.cpp)

add_executable(${PROJECT_NAME} ${MAIN_TEST}
                                ${UTILS_TEST})

set_target_properties(
${PROJECT_NAME}
PROPERTIES CXX_STANDARD 20
            CXX_STANDARD_REQUIRED ON)

target_link_libraries(${PROJECT_NAME} PRIVATE core
                                            Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(core-test)