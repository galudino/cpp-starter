
#
# Greeting C++ library.
#

add_library(starter_lib STATIC
    src/greeting.cpp
)

target_sources(starter_lib PUBLIC
    FILE_SET HEADERS
    BASE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include"
    FILES
        include/starter/greeting.hpp
)

target_compile_features(starter_lib PUBLIC
    cxx_std_23
)

add_library(starter::greeting ALIAS starter_lib)

set_project_warnings(starter_lib)
