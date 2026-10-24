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
# Components
#------------------------------------------------------------------------------

add_subdirectory(components/greeting)
add_subdirectory(components/sensor)
add_subdirectory(components/transport)

#------------------------------------------------------------------------------
# Command-line executable
#------------------------------------------------------------------------------

add_subdirectory(app)

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
