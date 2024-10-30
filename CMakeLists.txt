cmake_minimum_required(VERSION 3.4)
project(pyanlib)

add_definitions(-DUSETHREAD)

add_subdirectory(ThirdParty/pybind11)
pybind11_add_module(pyanlib src/main.cpp)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(pyanlib
                           PRIVATE VERSION_INFO=${VERSION_INFO})
