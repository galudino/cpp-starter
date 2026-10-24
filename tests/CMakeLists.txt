
add_executable(starter_tests
    library_tests.cpp
)

target_link_libraries(starter_tests
    PRIVATE
        starter_lib
        sensor_driver
)

set_project_warnings(starter_tests)

add_test(
    NAME starter_library_tests
    COMMAND starter_tests
)
