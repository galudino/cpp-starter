#
# Application executable.
#

add_executable(starter
    main.cpp
)

target_link_libraries(starter PRIVATE
    starter::greeting
    starter::sensor
)

set_project_warnings(starter)
