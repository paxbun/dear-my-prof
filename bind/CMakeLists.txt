# Copyright (c) 2019 Dear My Professor Authors
# Author: paxbun

find_package(Python 2.7 EXACT REQUIRED COMPONENTS
    Interpreter
)

set(DEAR_MY_PROF_BIND_INSTALL_COMMAND
    "npm" "install" "node-addon-api"
)
set(DEAR_MY_PROF_BIND_CONFIGURE_COMMAND
    "node-gyp" "configure" "--python" ${Python_EXECUTABLE}
)
if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(DEAR_MY_PROF_BIND_BUILD_COMMAND
        "npm" "run" "dbuild"
    )
    set(DEAR_MY_PROF_BIND_OUTPUT_FILE
        ${CMAKE_CURRENT_SOURCE_DIR}/build/Debug/dear-my-prof-bind.node
    )
else()
    set(DEAR_MY_PROF_BIND_BUILD_COMMAND
        "npm" "run" "build"
    )
    set(DEAR_MY_PROF_BIND_OUTPUT_FILE
        ${CMAKE_CURRENT_SOURCE_DIR}/build/Release/dear-my-prof-bind.node
    )
endif()

add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/__fake__
           ${DEAR_MY_PROF_BIND_OUTPUT_FILE}
    COMMAND ${DEAR_MY_PROF_BIND_INSTALL_COMMAND}
    COMMAND ${DEAR_MY_PROF_BIND_CONFIGURE_COMMAND}
    COMMAND ${DEAR_MY_PROF_BIND_BUILD_COMMAND}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
add_custom_target(dear-my-prof-bind ALL
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/__fake__
            ${DEAR_MY_PROF_BIND_OUTPUT_FILE}
)
add_dependencies(dear-my-prof-bind dear-my-prof-core)