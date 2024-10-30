cmake_minimum_required(VERSION 3.4)
project(python_accidental_noise_library)

add_subdirectory(ThirdParty/pybind11)
pybind11_add_module(python_accidental_noise_library src/main.cpp)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(python_accidental_noise_library
                           PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
