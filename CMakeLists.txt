# Copyright (c) 2019 Dear My Professor Authors
# Author: paxbun

cmake_minimum_required(VERSION 3.13)
project(dear-my-prof VERSION 1.0)
enable_testing()

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Platform Definitions
add_library(dear-my-prof-plat-defs INTERFACE)
if(CMAKE_BUILD_TYPE MATCHES "Debug")
    target_compile_definitions(dear-my-prof-plat-defs
        INTERFACE "-DDEAR_MY_PROF_PLAT_DEBUG=1"
    )
else()
    target_compile_definitions(dear-my-prof-plat-defs
        INTERFACE "-DDEAR_MY_PROF_PLAT_DEBUG=0"
    )
endif()

add_subdirectory(core)