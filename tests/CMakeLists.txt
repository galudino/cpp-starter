add_executable(greeting_tests
    greeting_tests.cpp
)

add_executable(sensor_tests
    sensor_tests.cpp
)

add_executable(transport_tests
    transport_tests.cpp
)

target_link_libraries(greeting_tests 
    PRIVATE
        starter::greeting
)

target_link_libraries(sensor_tests 
    PRIVATE
        starter::sensor
)

target_link_libraries(transport_tests 
    PRIVATE
        starter::transport
)

set_project_warnings(greeting_tests)
set_project_warnings(sensor_tests)
set_project_warnings(transport_tests)

add_test(
    NAME greeting_library_tests
    COMMAND greeting_tests
)

add_test(
    NAME sensor_library_tests
    COMMAND sensor_tests
)

add_test(
    NAME transport_library_tests
    COMMAND transport_tests
)
