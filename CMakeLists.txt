cmake_minimum_required(VERSION 3.13.4)
project(Pong)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
find_package(SDL2_gfx REQUIRED)

add_executable(Pong main.cpp Paddle.cpp Paddle.h Utils.cpp Utils.h)
target_link_libraries(${PROJECT_NAME} SDL2::Main SDL2::GFX)