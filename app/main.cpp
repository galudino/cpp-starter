///
/// \file       main.cpp
/// \brief      Entry point for the starter command-line application.
///
/// \author     galudino
/// \date       2026-10-24
///

#include <starter/greeting.hpp>
#include <starter/ring_buffer.hpp>
#include <starter/sensor.h>

#include <cstdlib>
#include <iostream>

///
/// \brief      Application entry point.
///
/// \return     EXIT_SUCCESS on successful execution.
///
int main() {
    std::cout << starter::make_greeting("Codespaces") << '\n';

    // Queue a few readings from the C library, then drain them in order.
    auto readings = starter::ring_buffer<int, 4>{};

    while (readings.push(sensor_read())) {
    }

    while (const auto reading = readings.pop()) {
        std::cout << "Sensor reading: " << *reading << '\n';
    }

    return EXIT_SUCCESS;
}
