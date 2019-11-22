# Copyright (c) 2019 Dear My Professor Authors
# Author: paxbun

add_library(dear-my-prof-core STATIC
    Source/Core.cpp
)
target_link_libraries(dear-my-prof-core
    PUBLIC dear-my-prof-plat-defs
)
target_include_directories(dear-my-prof-core
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Public
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Private
)
# Output Directories
set_target_properties(dear-my-prof-core PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build
    POSITION_INDEPENDENT_CODE ON
)