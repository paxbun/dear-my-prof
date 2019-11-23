# Copyright (c) 2019 Dear My Professor Authors
# Author: paxbun

# Output Path
set(DEAR_MY_PROF_GUI_OUTPUT ${CMAKE_BINARY_DIR}/gui_out)

# Copy package.json
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/package.json
    DESTINATION ${DEAR_MY_PROF_GUI_OUTPUT}
)

# Configure node
if(WIN32)
    set(DEAR_MY_PROF_GUI_NPM "npm.cmd")
else()
    set(DEAR_MY_PROF_GUI_NPM "npm")
endif()
execute_process(
    COMMAND ${DEAR_MY_PROF_GUI_NPM} "install"
    WORKING_DIRECTORY ${DEAR_MY_PROF_GUI_OUTPUT}
)

# Define Build Commands
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/__fake__
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/Asset
            ${DEAR_MY_PROF_GUI_OUTPUT}/Asset
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/Script
            ${DEAR_MY_PROF_GUI_OUTPUT}/Script
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/Style
            ${DEAR_MY_PROF_GUI_OUTPUT}/Style
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/View
            ${DEAR_MY_PROF_GUI_OUTPUT}/View
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_BINARY_DIR}/bind_out/dear-my-prof-bind.node
            ${DEAR_MY_PROF_GUI_OUTPUT}/Script/dear-my-prof-bind.node
    COMMAND "npm" "run" "export"
    WORKING_DIRECTORY ${DEAR_MY_PROF_GUI_OUTPUT}
)
add_custom_target(dear-my-prof-gui ALL
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/__fake__
)
add_dependencies(dear-my-prof-gui dear-my-prof-bind)