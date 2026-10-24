
#
# Sensor C library.
#

add_library(sensor_driver STATIC
    src/sensor.c
)

target_sources(sensor_driver PUBLIC
    FILE_SET HEADERS
    BASE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include"
    FILES
        include/sensor/sensor.h
)

target_compile_features(sensor_driver PUBLIC
    c_std_17
)

add_library(starter::sensor ALIAS sensor_driver)

set_project_warnings(sensor_driver)
