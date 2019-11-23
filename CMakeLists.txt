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

# CRT Compile Option for Windows
set(DEAR_MY_PROF_FLAGS
    CMAKE_CXX_FLAGS
    CMAKE_CXX_FLAGS_DEBUG
    CMAKE_CXX_FLAGS_RELEASE
    CMAKE_CXX_FLAGS_MINSIZEREL
    CMAKE_CXX_FLAGS_RELWITHDEBINFO
    CMAKE_C_FLAGS
    CMAKE_C_FLAGS_DEBUG
    CMAKE_C_FLAGS_RELEASE
    CMAKE_C_FLAGS_MINSIZEREL
    CMAKE_C_FLAGS_RELWITHDEBINFO
)
foreach(DEAR_MY_PROF_FLAG ${DEAR_MY_PROF_FLAGS})
    string(REPLACE "/MD" "/MT" ${DEAR_MY_PROF_FLAG} "${${DEAR_MY_PROF_FLAG}}")
endforeach()

add_subdirectory(core)
add_subdirectory(bind)