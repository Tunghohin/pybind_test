cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(pybind_test LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRCS_FFI CONFIGURE_DEPENDS ./src/ffi/*.cpp ./include/ffi/*.h)

find_package(Python 3.12 COMPONENTS Interpreter Development REQUIRED)
add_subdirectory(./deps/pybind11)

pybind11_add_module("${PROJECT_NAME}-pybind" ${SRCS_FFI})