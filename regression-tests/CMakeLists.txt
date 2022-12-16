
file(GLOB REGRESSION_TESTS_CPP2 ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp2)

foreach(REGRESSION_TEST_CPP2 ${REGRESSION_TESTS_CPP2})
    get_filename_component(REGRESSION_TEST_BASE_NAME ${REGRESSION_TEST_CPP2} NAME_WE)
    
    if(${REGRESSION_TEST_BASE_NAME} MATCHES "^pure2-")
        set(PURE_CPP2 -p)
    endif()
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/test-results/${REGRESSION_TEST_BASE_NAME}.cpp)
        add_custom_command(
            OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${REGRESSION_TEST_BASE_NAME}.cpp
            COMMAND ${PROJECT_NAME}
            ARGS -n -s ${PURE_CPP2} ${REGRESSION_TEST_CPP2}
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
        add_test(
            NAME ctest-${REGRESSION_TEST_BASE_NAME}
            COMMAND $<TARGET_FILE:${REGRESSION_TEST_BASE_NAME}>
        )
    endif()
endforeach()

# set_tests_properties(ctest-mixed-bounds-check PROPERTIES WILL_FAIL TRUE)

