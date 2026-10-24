#
# Application executable.
#

add_executable(starter
    main.cpp
)

target_link_libraries(starter PRIVATE
    starter_lib
    sensor_driver
)

set_project_warnings(starter)
