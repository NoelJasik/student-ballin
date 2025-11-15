cmake_minimum_required(VERSION 4.0)
project(uniProject)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

set(SDL2_PATH ${CMAKE_SOURCE_DIR}/SDL2-2.32.10/x86_64-w64-mingw32)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(uniProject main.cpp)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})