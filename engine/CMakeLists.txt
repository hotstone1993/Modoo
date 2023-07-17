cmake_minimum_required(VERSION 3.13)

project(engine LANGUAGES CXX)

# set(VCPKG_TARGET_ARCHITECTURE "x64")

# if(MSVC)
#   set(VCPKG_CMAKE_SYSTEM_NAME "")
#   set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
# else()
#   set(VCPKG_CMAKE_SYSTEM_NAME "Linux")
#   set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
#   set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
# endif()

# add_library(
# ${PROJECT_NAME} )

# set_target_properties(
# ${PROJECT_NAME}
# PROPERTIES CXX_STANDARD 20
#             CXX_STANDARD_REQUIRED ON)

# target_include_directories(
# ${PROJECT_NAME}
# PUBLIC )

# target_link_libraries(${PROJECT_NAME} PRIVATE )