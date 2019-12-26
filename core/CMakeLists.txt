# Copyright (c) 2019 Dear My Professor Authors
# Author: paxbun

add_library(dear-my-prof-core STATIC
    Source/App.cpp
    Source/CodaStringTransform.cpp
    Source/CredentialManager.cpp
    Source/DetailPresenter.cpp
    Source/DetailTemplatePresenter.cpp
    Source/EmailList.cpp
    Source/EmailListPresenter.cpp
    Source/LoginPresenter.cpp
    Source/OpenDetailPresenter.cpp
    Source/OpenDetailTemplatePresenter.cpp
    Source/OpenNewEmailPresenter.cpp
    Source/OpenSelectTemplatePresenter.cpp
    Source/OpenNewTemplatePresenter.cpp
    Source/OpenTemplateListPresenter.cpp
    Source/ProfessorList.cpp
    Source/SaveTemplatePresenter.cpp
    Source/SendEmailPresenter.cpp
    Source/StringTransformFactory.cpp
    Source/Subject.cpp
    Source/Template.cpp
    Source/TemplateList.cpp
    Source/TemplateListPresenter.cpp
    Source/TemplatePresenter.cpp
    Source/TemplateString.cpp
    Source/View.cpp
)
target_link_libraries(dear-my-prof-core
    PUBLIC dear-my-prof-plat-defs
    PUBLIC nlohmann_json nlohmann_json::nlohmann_json
    PRIVATE ${Boost_LIBRARIES}
)
target_include_directories(dear-my-prof-core
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Public
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Private
    PRIVATE ${Boost_INCLUDE_DIRS}
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

# Add header-only llibrary for tests
add_library(dear-my-prof-core-tests INTERFACE)
target_include_directories(dear-my-prof-core-tests
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/Private
)

# Tests
if(CMAKE_BUILD_TYPE MATCHES "Debug")

    # StringTransformTest
    add_executable(dear-my-prof-core-string-transform-test
        Test/StringTransformTest.cpp
    )
    target_link_libraries(dear-my-prof-core-string-transform-test
        PUBLIC dear-my-prof-core
        PUBLIC dear-my-prof-core-tests
    )
    add_test(
        NAME core-string-transform-test
        COMMAND dear-my-prof-core-string-transform-test
    )
    
    # ObserverTest
    add_executable(dear-my-prof-core-observer-test
        Test/ObserverTest.cpp
    )
    target_link_libraries(dear-my-prof-core-observer-test
        PUBLIC dear-my-prof-core
        PUBLIC dear-my-prof-core-tests
    )
    add_test(
        NAME core-observer-test
        COMMAND dear-my-prof-core-observer-test
    )

    # TemplateStringTest
    add_executable(dear-my-prof-core-template-string-test
        Test/TemplateStringTest.cpp
    )
    target_link_libraries(dear-my-prof-core-template-string-test
        PUBLIC dear-my-prof-core
        PUBLIC dear-my-prof-core-tests
    )
    add_test(
        NAME core-template-string-test
        COMMAND dear-my-prof-core-template-string-test
    )

endif()