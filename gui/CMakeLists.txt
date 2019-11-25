# Copyright (c) 2019 Dear My Professor Authors
# Author: paxbun

# Output Path
set(DEAR_MY_PROF_GUI_OUTPUT ${CMAKE_BINARY_DIR}/gui_out)

# npm
if(WIN32)
    set(DEAR_MY_PROF_GUI_NPM "npm.cmd")
else()
    set(DEAR_MY_PROF_GUI_NPM "npm")
endif()

if(CMAKE_BUILD_TYPE MATCHES "Debug")

    # Configure node
    execute_process(
        COMMAND ${DEAR_MY_PROF_GUI_NPM} "install"
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )

    # Copy launch.json to VS Code Settings directory
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/launch.json
        DESTINATION ${PROJECT_SOURCE_DIR}/.vscode
    )

    # Copy native module from output directory
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/__fake__
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_BINARY_DIR}/bind_out/dear-my-prof-bind.node
                ${CMAKE_CURRENT_SOURCE_DIR}/Script/dear-my-prof-bind.node
    )
    add_custom_target(dear-my-prof-gui ALL
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/__fake__
    )
    add_dependencies(dear-my-prof-gui dear-my-prof-bind)

else()

    # Read template from package.json
    file(READ ${CMAKE_CURRENT_SOURCE_DIR}/package.json
        DEAR_MY_PROF_GUI_PACKAGE_TEMPLATE
    )
    
    # Change Icon File Extension
    if(WIN32)
        string(REPLACE "$ICON_EXT$" ".ico"
            DEAR_MY_PROF_GUI_PACKAGE_TEMPLATE ${DEAR_MY_PROF_GUI_PACKAGE_TEMPLATE}
        )
    else()
        string(REPLACE "$ICON_EXT$" ".png"
            DEAR_MY_PROF_GUI_PACKAGE_TEMPLATE ${DEAR_MY_PROF_GUI_PACKAGE_TEMPLATE}
        )
    endif()

    # Write result to package.json
    file(WRITE ${DEAR_MY_PROF_GUI_OUTPUT}/package.json
        ${DEAR_MY_PROF_GUI_PACKAGE_TEMPLATE}
    )

    # Copy prepare_asset.py
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/prepare_asset.py
        DESTINATION ${DEAR_MY_PROF_GUI_OUTPUT}
    )
    
    # Configure node
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
        COMMAND ${Python_EXECUTABLE} "prepare_asset.py"
        COMMAND ${DEAR_MY_PROF_GUI_NPM} "run" "export"
        WORKING_DIRECTORY ${DEAR_MY_PROF_GUI_OUTPUT}
    )
    add_custom_target(dear-my-prof-gui ALL
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/__fake__
    )
    add_dependencies(dear-my-prof-gui dear-my-prof-bind)

endif()