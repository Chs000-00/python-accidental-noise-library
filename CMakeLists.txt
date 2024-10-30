cmake_minimum_required(VERSION 3.4)
project(PyBindANL)

add_subdirectory(ThirdParty/pybind11)
pybind11_add_module(PyBindANL src/main.cpp)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(PyBindANL
                           PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})