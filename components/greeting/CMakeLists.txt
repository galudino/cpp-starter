#
# Greeting component.
#

add_library(greeting STATIC
    src/greeting.cpp
)

target_sources(greeting PUBLIC
    FILE_SET HEADERS
    BASE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include"
    FILES
        include/starter/greeting.hpp
)

target_compile_features(greeting PUBLIC
    cxx_std_23
)

add_library(starter::greeting ALIAS greeting)

set_project_warnings(greeting)
