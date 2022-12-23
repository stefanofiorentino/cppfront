
file(GLOB REGRESSION_TESTS_CPP2 ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp2)

set(
    CHILD_ABORTED_EXES
    mixed-bounds-check
    mixed-bounds-safety-with-assert
    mixed-initialization-safety-3-contract-violation
    mixed-inspect-with-typeof-of-template-arg-list
)

foreach(REGRESSION_TEST_CPP2 ${REGRESSION_TESTS_CPP2})
    get_filename_component(REGRESSION_TEST_BASE_NAME ${REGRESSION_TEST_CPP2} NAME_WE)
    if(${REGRESSION_TEST_BASE_NAME} MATCHES "^pure2-")
        set(PURE_CPP2 -p)
    endif()
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/test-results/${REGRESSION_TEST_BASE_NAME}.cpp)
        add_custom_command(
            OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${REGRESSION_TEST_BASE_NAME}.cpp
            COMMAND ${PROJECT_NAME} 
            ARGS -n -s ${PURE_CPP2} ${REGRESSION_TEST_CPP2} -o ${CMAKE_CURRENT_BINARY_DIR}/${REGRESSION_TEST_BASE_NAME}.cpp
            DEPENDS 
            ${PROJECT_NAME} ${REGRESSION_TEST_CPP2}
        )
        add_executable(
            ${REGRESSION_TEST_BASE_NAME}
            ${CMAKE_CURRENT_BINARY_DIR}/${REGRESSION_TEST_BASE_NAME}.cpp
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
        if (NOT ";${CHILD_ABORTED_EXES};" MATCHES ";${REGRESSION_TEST_BASE_NAME};")
            add_test(
                NAME ctest-${REGRESSION_TEST_BASE_NAME}
                COMMAND $<TARGET_FILE:${REGRESSION_TEST_BASE_NAME}>
            )
        endif()
    endif()
endforeach()
