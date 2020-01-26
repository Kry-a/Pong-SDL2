cmake_minimum_required(VERSION 3.13.4)
project(Pong)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
find_package(SDL2_gfx REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(Pong main.cpp Paddle.cpp Paddle.h Utils.cpp Utils.h)
target_link_libraries(Pong ${SDL2_LIBRARIES})