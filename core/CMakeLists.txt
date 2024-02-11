cmake_minimum_required(VERSION 3.28)

project(core LANGUAGES CXX)

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