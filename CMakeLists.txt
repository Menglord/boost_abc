cmake_minimum_required(VERSION 2.8)
project(boost_abc)

add_compile_options(-std=c++11)
find_package(Boost REQUIRED COMPONENTS system thread program_options)
message("${Boost_INCLUDE_DIR}")
set(BINARY_DIR ${PROJECT_SOURCE_DIR}/devel)

include_directories(${Boost_INCLUDE})
include_directories(./src)

add_subdirectory(./src)
