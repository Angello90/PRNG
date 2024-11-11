cmake_minimum_required(VERSION 3.5.0)
project(PRNG VERSION 0.1.0 LANGUAGES C CXX)

include_directories(${CMAKE_SOURCE_DIR}/includes)

add_executable(PRNG main.cpp src/prng.cpp src/Xorshift32.cpp)

