cmake_minimum_required(VERSION 3.12.4)
project(Pong)

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

if(UNIX AND APPLE)
    set(MACOS TRUE)
endif()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

#[[set(CMAKE_SYSTEM_NAME Windows)

set(triple x86_64-w64-windows-gnu)
set(CMAKE_LIBRARY_ARCHITECTURE ${triple})
set(CMAKE_C_COMPILER_TARGET ${triple})
set(CMAKE_CXX_COMPILER_TARGET ${triple})

set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")]]
set(CMAKE_PREFIX_PATH "include/discord-rpc/linux-dynamic/lib")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src/cmake/sdl2-cmake-modules)

set(CMAKE_CXX_STANDARD 20)

#set(SDL2_INCLUDE_DIR)
find_package(SDL2 REQUIRED)

add_subdirectory(src/include/random)

if (LINUX)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/include/discord-rpc/linux-dynamic/include)
    set(DISCORD_RPC ${CMAKE_CURRENT_SOURCE_DIR}/src/include/discord-rpc/linux-dynamic/lib/libdiscord-rpc.so)
endif(LINUX)

if (MACOS)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/include/discord-rpc/osx-dynamic/include)
    set(DISCORD_RPC ${CMAKE_CURRENT_SOURCE_DIR}/src/include/discord-rpc/osx-dynamic/lib/libdiscord-rpc.dylib)
endif(MACOS)

if (WIN32)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/include/discord-rpc/win32-dynamic/include)
    set(DISCORD_RPC ${CMAKE_CURRENT_SOURCE_DIR}/include/discord-rpc/win32-dynamic/lib/discord-rpc.lib)
endif(WIN32)

if (WIN64)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/include/discord-rpc/win64-dynamic/include)
    set(DISCORD_RPC ${CMAKE_CURRENT_SOURCE_DIR}/include/discord-rpc/win64-dynamic/lib/discord-rpc.lib)
endif(WIN64)

add_executable(Pong src/main.cpp src/Objects/Paddle.cpp src/Objects/Paddle.h src/Utils.cpp src/Utils.h src/Objects/Ball.cpp src/Objects/Ball.h src/PongRPC.cpp src/PongRPC.h src/MP.cpp src/MP.h)
target_link_libraries(${PROJECT_NAME} SDL2::Main effolkronium_random)
target_link_libraries(${PROJECT_NAME} ${DISCORD_RPC})
