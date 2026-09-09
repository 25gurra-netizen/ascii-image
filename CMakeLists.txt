cmake_minimum_required(VERSION 3.16)

project(ascii-image VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(ascii-image
    src/main.cpp
)

target_include_directories(ascii-image PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(ascii-image PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()