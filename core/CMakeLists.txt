cmake_minimum_required(VERSION 3.28)

project(core LANGUAGES CXX)

if(MSVC)
  set(VCPKG_CMAKE_SYSTEM_NAME "")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
else()
  set(VCPKG_CMAKE_SYSTEM_NAME "Linux")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
endif()

set(UTILS_CPP ${CMAKE_CURRENT_SOURCE_DIR}/utils/id_generator.cpp)

add_library(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/context.cpp
                                ${UTILS_CPP})

set_target_properties(
${PROJECT_NAME}
PROPERTIES CXX_STANDARD 20
            CXX_STANDARD_REQUIRED ON)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                                                    ${CMAKE_CURRENT_SOURCE_DIR}/utils)

target_link_libraries(${PROJECT_NAME} PRIVATE ${TORCH_LIBRARIES})