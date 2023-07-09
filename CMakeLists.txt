cmake_minimum_required(VERSION 3.13)

project(modoo)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/core)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/engine)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)

add_dependencies(engine core)
add_dependencies(test core)