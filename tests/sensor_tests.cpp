///
/// \file       sensor_tests.cpp
/// \brief      Unit tests for the sensor library.
///
/// \author     galudino
/// \date       2026-10-23
///

#include <starter/sensor.h>

#include <cstdlib>
#include <iostream>
#include <string_view>

namespace {

///
/// \brief      Evaluates a test condition.
///
/// \param      condition   Condition to evaluate.
/// \param      description Description of the test.
///
/// \return     True if the condition is satisfied.
///
bool check(bool condition, std::string_view description) {
    if (!condition) {
        std::cerr << "FAIL: " << description << '\n';
    }

    return condition;
}

///
/// \brief      Tests the C sensor driver.
///
/// \return     True if the simulated reading is correct.
///
bool test_sensor() { return check(sensor_read() == 42, "sensor_read"); }

} // namespace

///
/// \brief      Test application entry point.
///
/// \return     EXIT_SUCCESS if all tests pass; EXIT_FAILURE otherwise.
///
int main() {
    auto success = true;

    success &= test_sensor();

    if (success) {
        std::cout << "All tests passed.\n";
    }

    return success ? EXIT_SUCCESS : EXIT_FAILURE;
}
