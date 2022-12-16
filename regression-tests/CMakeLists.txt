
file(GLOB REGRESSION_TESTS_CPP2 ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp2)

foreach(REGRESSION_TEST_CPP2 ${REGRESSION_TESTS_CPP2})
    get_filename_component(REGRESSION_TEST_BASE_NAME ${REGRESSION_TEST_CPP2} NAME_WE)
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${REGRESSION_TEST_BASE_NAME}.cpp
        COMMAND ${PROJECT_NAME} ARGS ${REGRESSION_TEST_CPP2} -pure-cpp2
        DEPENDS ${PROJECT_NAME}
    )
    add_executable(
        ${REGRESSION_TEST_BASE_NAME}
        ${CMAKE_CURRENT_SOURCE_DIR}/${REGRESSION_TEST_BASE_NAME}.cpp
    )
    target_include_directories(
        ${REGRESSION_TEST_BASE_NAME}
            PRIVATE
        ${CMAKE_SOURCE_DIR}/include
    )
    target_compile_features(
        ${REGRESSION_TEST_BASE_NAME}
            PUBLIC
        cxx_std_20
    )
endforeach()

