cmake_minimum_required(VERSION 3.15)

project(modoo)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/core)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/engine)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)

add_dependencies(engine core)
add_dependencies(core-test core)