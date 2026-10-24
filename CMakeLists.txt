
cmake_minimum_required(VERSION 3.25)

project(
    cpp_starter
    VERSION 1.0.0
    DESCRIPTION "Modern C/C++ command-line starter project"
    LANGUAGES C CXX
)

#------------------------------------------------------------------------------
# Project options
#------------------------------------------------------------------------------

option(BUILD_TESTING "Build unit tests" ON)
option(BUILD_DOCUMENTATION "Enable Doxygen documentation" ON)
option(ENABLE_WARNINGS_AS_ERRORS "Treat warnings as errors" OFF)

#------------------------------------------------------------------------------
# Language standards
#------------------------------------------------------------------------------

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(CTest)
include(cmake/CompilerWarnings.cmake)

#------------------------------------------------------------------------------
# C library
#------------------------------------------------------------------------------

add_library(sensor_driver STATIC
    src/sensor.c
)

target_include_directories(sensor_driver
    PUBLIC
        "${PROJECT_SOURCE_DIR}/include"
)

target_compile_features(sensor_driver PUBLIC c_std_17)
set_project_warnings(sensor_driver)

#------------------------------------------------------------------------------
# C++ library
#------------------------------------------------------------------------------

add_library(starter_lib STATIC
    src/source.cpp
)

target_include_directories(starter_lib
    PUBLIC
        "${PROJECT_SOURCE_DIR}/include"
)

target_compile_features(starter_lib PUBLIC cxx_std_23)
set_project_warnings(starter_lib)

#------------------------------------------------------------------------------
# Command-line executable
#------------------------------------------------------------------------------

add_executable(starter
    src/main.cpp
)

target_link_libraries(starter
    PRIVATE
        starter_lib
        sensor_driver
)

set_project_warnings(starter)

#------------------------------------------------------------------------------
# Tests
#------------------------------------------------------------------------------

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()

#------------------------------------------------------------------------------
# Documentation
#------------------------------------------------------------------------------

if(BUILD_DOCUMENTATION)
    find_package(Doxygen QUIET)

    if(DOXYGEN_FOUND)
        set(DOXYGEN_OUTPUT_DIRECTORY
            "${CMAKE_CURRENT_BINARY_DIR}/docs"
        )

        configure_file(
            "${PROJECT_SOURCE_DIR}/docs/Doxyfile.in"
            "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile"
            @ONLY
        )

        add_custom_target(docs
            COMMAND
                "${DOXYGEN_EXECUTABLE}"
                "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile"
            WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
            COMMENT "Generating Doxygen documentation"
            VERBATIM
        )
    else()
        message(STATUS "Doxygen not found; documentation disabled")
    endif()
endif()
