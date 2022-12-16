add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/pure2-inspect-expression-in-generic-function-multiple-types.cpp
    COMMAND ${PROJECT_NAME} ARGS ${CMAKE_CURRENT_SOURCE_DIR}/pure2-inspect-expression-in-generic-function-multiple-types.cpp2 -pure-cpp2
    DEPENDS ${PROJECT_NAME}
)
add_executable(
    pure2-inspect-expression-in-generic-function-multiple-types
    ${CMAKE_CURRENT_SOURCE_DIR}/pure2-inspect-expression-in-generic-function-multiple-types.cpp
)
target_include_directories(
    pure2-inspect-expression-in-generic-function-multiple-types 
        PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
)
target_compile_features(
    pure2-inspect-expression-in-generic-function-multiple-types 
        PUBLIC 
    cxx_std_20
)