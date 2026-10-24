
///
/// \file       main.cpp
/// \brief      Entry point for the starter command-line application.
///
/// \author     galudino
/// \date       2026-10-23
///

#include <sensor/sensor.h>
#include <starter/greeting.hpp>

#include <cstdlib>
#include <iostream>

///
/// \brief      Application entry point.
///
/// \return     EXIT_SUCCESS on successful execution.
///
int main() {
    std::cout << starter::make_greeting("Codespaces") << '\n';
    std::cout << "Valid name initial: " << std::boolalpha << starter::is_valid_initial('C') << '\n';
    std::cout << "Sensor reading: " << sensor_read() << '\n';

    return EXIT_SUCCESS;
}
