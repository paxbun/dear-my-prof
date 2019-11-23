# Copyright (c) 2019 Dear My Professor Authors
# Author: paxbun

find_package(Python 2.7 EXACT REQUIRED COMPONENTS
    Interpreter
)

# Sources
set(DEAR_MY_PROF_BIND_SOURCES
    Source/Bind.cpp
)

# Build Script Output Path
set(DEAR_MY_PROF_BIND_OUTPUT ${CMAKE_BINARY_DIR}/bind)

# Configure node-gyp
if(WIN32)
    set(DEAR_MY_PROF_BIND_NPM "npm.cmd")
else()
    set(DEAR_MY_PROF_BIND_NPM "npm")
endif()
execute_process(
    COMMAND ${DEAR_MY_PROF_BIND_NPM} "install" "-g" "node-gyp"
)
execute_process(
    COMMAND ${DEAR_MY_PROF_BIND_NPM} "install" "node-addon-api"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}    
)
execute_process(
    COMMAND "node" "-p" "require('node-addon-api').include"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    OUTPUT_VARIABLE DEAR_MY_PROF_BIND_INCLUDE_DIR
)
execute_process(
    COMMAND "node" "-p" "require('node-addon-api').gyp"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    OUTPUT_VARIABLE DEAR_MY_PROF_BIND_GYP
)
string(
    REPLACE "\n" ""
    DEAR_MY_PROF_BIND_INCLUDE_DIR ${DEAR_MY_PROF_BIND_INCLUDE_DIR}
)
string(
    REPLACE "\"" ""
    DEAR_MY_PROF_BIND_INCLUDE_DIR ${DEAR_MY_PROF_BIND_INCLUDE_DIR}
)
string(
    REPLACE "\\" "/"
    DEAR_MY_PROF_BIND_INCLUDE_DIR ${DEAR_MY_PROF_BIND_INCLUDE_DIR}
)
string(
    REPLACE "\n" ""
    DEAR_MY_PROF_BIND_GYP ${DEAR_MY_PROF_BIND_GYP}
)
string(
    REPLACE "\\" "/"
    DEAR_MY_PROF_BIND_GYP ${DEAR_MY_PROF_BIND_GYP}
)

# Define Build Commands
set(DEAR_MY_PROF_BIND_CONFIGURE_COMMAND
    "node-gyp" "configure" "--python" ${Python_EXECUTABLE}
)
if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(DEAR_MY_PROF_BIND_BUILD_COMMAND
        "node-gyp" "build" "--debug" "--python" ${Python_EXECUTABLE}
    )
    set(DEAR_MY_PROF_BIND_OUTPUT_FILE
        ${DEAR_MY_PROF_BIND_OUTPUT}/build/Debug/dear-my-prof-bind.node
    )
else()
    set(DEAR_MY_PROF_BIND_BUILD_COMMAND
        "node-gyp" "build" "--python" ${Python_EXECUTABLE}
    )
    set(DEAR_MY_PROF_BIND_OUTPUT_FILE
        ${DEAR_MY_PROF_BIND_OUTPUT}/build/Release/dear-my-prof-bind.node
    )
endif()
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/__fake__
           ${DEAR_MY_PROF_BIND_OUTPUT_FILE}
    COMMAND ${DEAR_MY_PROF_BIND_CONFIGURE_COMMAND}
    COMMAND ${DEAR_MY_PROF_BIND_BUILD_COMMAND}
    COMMAND ${CMAKE_COMMAND} -E copy ${DEAR_MY_PROF_BIND_OUTPUT_FILE}
            ${DEAR_MY_PROF_BIND_OUTPUT}/dear-my-prof-bind.node
    WORKING_DIRECTORY ${DEAR_MY_PROF_BIND_OUTPUT}
)
add_custom_target(dear-my-prof-bind ALL
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/__fake__
            ${DEAR_MY_PROF_BIND_OUTPUT_FILE}
)
add_dependencies(dear-my-prof-bind dear-my-prof-core)

# Include Directories and Library Directory
set(DEAR_MY_PROF_BIND_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/Include
    ${PROJECT_SOURCE_DIR}/core/Public
    ${DEAR_MY_PROF_BIND_INCLUDE_DIR}
)
get_target_property(DEAR_MY_PROF_BIND_LIBRARY_DIR dear-my-prof-core
    ARCHIVE_OUTPUT_DIRECTORY
)
string(
    REPLACE "\\" "/"
    DEAR_MY_PROF_BIND_LIBRARY_DIR ${DEAR_MY_PROF_BIND_LIBRARY_DIR}
)

# Read template
file(READ ${CMAKE_CURRENT_SOURCE_DIR}/binding.gyp
    DEAR_MY_PROF_BIND_TEMPLATE
)

# Fill $SOURCES$
list(TRANSFORM DEAR_MY_PROF_BIND_SOURCES PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/")
foreach(DEAR_MY_PROF_BIND_SOURCE ${DEAR_MY_PROF_BIND_SOURCES})
    file(RELATIVE_PATH DEAR_MY_PROF_BIND_SOURCE_REL
        ${DEAR_MY_PROF_BIND_OUTPUT} ${DEAR_MY_PROF_BIND_SOURCE}
    )
    list(APPEND DEAR_MY_PROF_BIND_SOURCES_REL ${DEAR_MY_PROF_BIND_SOURCE_REL})
endforeach()
list(TRANSFORM DEAR_MY_PROF_BIND_SOURCES_REL PREPEND "\"")
list(TRANSFORM DEAR_MY_PROF_BIND_SOURCES_REL APPEND "\"")
list(JOIN DEAR_MY_PROF_BIND_SOURCES_REL ",\n" DEAR_MY_PROF_BIND_SOURCES_REL)
string(
    REPLACE "$SOURCES$" ${DEAR_MY_PROF_BIND_SOURCES_REL}
    DEAR_MY_PROF_BIND_TEMPLATE ${DEAR_MY_PROF_BIND_TEMPLATE}
)

# Fill $INCLUDE_DIRS$
list(TRANSFORM DEAR_MY_PROF_BIND_INCLUDE_DIRS PREPEND "\"")
list(TRANSFORM DEAR_MY_PROF_BIND_INCLUDE_DIRS APPEND "\"")
list(JOIN DEAR_MY_PROF_BIND_INCLUDE_DIRS ",\n" DEAR_MY_PROF_BIND_INCLUDE_DIRS)
string(
    REPLACE "$INCLUDE_DIRS$" ${DEAR_MY_PROF_BIND_INCLUDE_DIRS}
    DEAR_MY_PROF_BIND_TEMPLATE ${DEAR_MY_PROF_BIND_TEMPLATE}
)

# Fill $DEP_GYP$
string(
    REPLACE "$DEP_GYP$" "\"${DEAR_MY_PROF_BIND_GYP}\""
    DEAR_MY_PROF_BIND_TEMPLATE ${DEAR_MY_PROF_BIND_TEMPLATE}
)

# Fill $LIBRARY_DIR$
string(
    REPLACE "$LIBRARY_DIR$" "${DEAR_MY_PROF_BIND_LIBRARY_DIR}"
    DEAR_MY_PROF_BIND_TEMPLATE ${DEAR_MY_PROF_BIND_TEMPLATE}
)

# Write result to binding.gyp
file(WRITE ${DEAR_MY_PROF_BIND_OUTPUT}/binding.gyp
    ${DEAR_MY_PROF_BIND_TEMPLATE}
)