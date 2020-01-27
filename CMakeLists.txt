cmake_minimum_required(VERSION 3.13.4)
project(Pong)
#[[set(CMAKE_SYSTEM_NAME Windows)

set(triple x86_64-w64-windows-gnu)
set(CMAKE_LIBRARY_ARCHITECTURE ${triple})
set(CMAKE_C_COMPILER_TARGET ${triple})
set(CMAKE_CXX_COMPILER_TARGET ${triple})

set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")]]

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src/cmake/sdl2-cmake-modules)

set(CMAKE_CXX_STANDARD 20)

set(SDL2_INCLUDE_DIR)
find_package(SDL2 REQUIRED)
find_package(SDL2_gfx REQUIRED)

add_subdirectory(src/include/random)

add_executable(Pong src/main.cpp src/Objects/Paddle.cpp src/Objects/Paddle.h src/Utils.cpp src/Utils.h src/Objects/Ball.cpp src/Objects/Ball.h)
target_link_libraries(${PROJECT_NAME} SDL2::Main SDL2::GFX effolkronium_random)
