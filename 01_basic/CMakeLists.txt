cmake_minimum_required(VERSION 3.20)

project(
    ShaderBasic
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SFML_BUILD_AUDIO OFF)
set(SFML_BUILD_NETWORK OFF)

add_subdirectory(../external/SFML ${CMAKE_BINARY_DIR}/SFML)

add_executable(
    ShaderBasic
    src/main.cpp
)

target_link_libraries(
    ShaderBasic
    PRIVATE
        SFML::Graphics
)