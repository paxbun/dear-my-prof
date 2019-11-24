# Copyright (c) 2019 Dear My Professor Authors
# Author: paxbun

# Sources
set(DEAR_MY_PROF_BIND_SOURCES
    Source/Bind.cpp
)

# Build Script Output Path
set(DEAR_MY_PROF_BIND_OUTPUT ${CMAKE_BINARY_DIR}/bind_out)

# Copy package.json
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/package.json
    DESTINATION ${DEAR_MY_PROF_BIND_OUTPUT}
)

# Configure node-addon-api
if(WIN32)
    set(DEAR_MY_PROF_BIND_NPM "npm.cmd")
    set(DEAR_MY_PROF_BIND_NODE_GYP "node-gyp.cmd")
else()
    set(DEAR_MY_PROF_BIND_NPM "npm")
    set(DEAR_MY_PROF_BIND_NODE_GYP "node-gyp")
endif()
# execute_process(
#     COMMAND ${DEAR_MY_PROF_BIND_NPM} "install" "-g" "node-gyp"
# )
execute_process(
    COMMAND ${DEAR_MY_PROF_BIND_NPM} "install" "node-addon-api"
    WORKING_DIRECTORY ${DEAR_MY_PROF_BIND_OUTPUT}    
)
execute_process(
    COMMAND "node" "-p" "require('node-addon-api').include"
    WORKING_DIRECTORY ${DEAR_MY_PROF_BIND_OUTPUT}
    OUTPUT_VARIABLE DEAR_MY_PROF_BIND_INCLUDE_DIR
)
execute_process(
    COMMAND "node" "-p" "require('node-addon-api').gyp"
    WORKING_DIRECTORY ${DEAR_MY_PROF_BIND_OUTPUT}
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
if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(DEAR_MY_PROF_BIND_BUILD_COMMAND
        ${DEAR_MY_PROF_BIND_NODE_GYP} "build" "--verbose" "--debug" "--python" ${Python_EXECUTABLE}
    )
    set(DEAR_MY_PROF_BIND_OUTPUT_FILE
        ${DEAR_MY_PROF_BIND_OUTPUT}/build/Debug/dear-my-prof-bind.node
    )
else()
    set(DEAR_MY_PROF_BIND_BUILD_COMMAND
        ${DEAR_MY_PROF_BIND_NODE_GYP} "build" "--python" ${Python_EXECUTABLE}
    )
    set(DEAR_MY_PROF_BIND_OUTPUT_FILE
        ${DEAR_MY_PROF_BIND_OUTPUT}/build/Release/dear-my-prof-bind.node
    )
endif()
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/__fake__
           ${DEAR_MY_PROF_BIND_OUTPUT_FILE}
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
set(DEAR_MY_PROF_BIND_LIBRARY_DIR ${CMAKE_BINARY_DIR}/core_out)
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

# Configure GYP
execute_process(
    COMMAND ${DEAR_MY_PROF_BIND_NODE_GYP} "configure" "--python" ${Python_EXECUTABLE}
    WORKING_DIRECTORY ${DEAR_MY_PROF_BIND_OUTPUT}
    RESULT_VARIABLE TESTTEST
)