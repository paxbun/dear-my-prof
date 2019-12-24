# Copyright (c) 2019 Dear My Professor Authors
# Author: paxbun

add_library(dear-my-prof-core STATIC
    Source/Core.cpp
    Source/StringTransformFactory.cpp
)
target_link_libraries(dear-my-prof-core
    PUBLIC dear-my-prof-plat-defs
)
target_include_directories(dear-my-prof-core
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Public
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Private
)
set_target_properties(dear-my-prof-core PROPERTIES
    POSITION_INDEPENDENT_CODE ON
)
# Output Directories
add_custom_command(TARGET dear-my-prof-core POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            $<TARGET_FILE:dear-my-prof-core>
            ${CMAKE_BINARY_DIR}/core_out/$<TARGET_FILE_NAME:dear-my-prof-core>
)