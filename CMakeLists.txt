cmake_minimum_required(VERSION 3.15)
project(test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(fmt REQUIRED)

add_executable(test examples/test.cpp)

target_link_libraries(test PRIVATE fmt::fmt)

target_include_directories(test PRIVATE include)

# g++ -o build/test examples/test.cpp -Iinclude -lfmt -std=c++20 
