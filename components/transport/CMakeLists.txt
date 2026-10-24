#
# Header-only transport component.
#

add_library(byte_transport INTERFACE)

target_sources(byte_transport INTERFACE
    FILE_SET HEADERS
    BASE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include"
    FILES
        include/starter/transport.hpp
        include/starter/mock_transport.hpp
)

target_compile_features(byte_transport INTERFACE
    cxx_std_23
)

add_library(starter::transport ALIAS byte_transport)
