
///
/// \file       transport_tests.cpp
/// \brief      Unit tests for the transport library.
///
/// \author     galudino
/// \date       2026-10-23
///

#include <starter/mock_transport.hpp>

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
/// \brief      Verify mock transport register operations.
///
bool test_mock_transport() {
    starter::mock_transport transport{};

    auto success = true;

    // All registers should initially contain zero.
    success &= check(transport.read(0x10) == 0x00, "Mock transport registers initialize to zero");

    // Write and read back a register value.
    transport.write(0x10, 0xAB);

    success &=
        check(transport.read(0x10) == 0xAB, "Mock transport preserves written register values");

    // Writes to different addresses must remain independent.
    transport.write(0x20, 0x42);

    success &=
        check(transport.read(0x10) == 0xAB, "Writing another register preserves the first value");

    success &= check(transport.read(0x20) == 0x42, "Mock transport supports multiple registers");

    // Exercise the highest valid register address.
    transport.write(0xFF, 0x7E);

    success &=
        check(transport.read(0xFF) == 0x7E, "Mock transport supports the final register address");

    return success;
}

} // namespace

///
/// \brief      Test application entry point.
///
/// \return     EXIT_SUCCESS if all tests pass; EXIT_FAILURE otherwise.
///
int main() {
    auto success = true;

    success &= test_mock_transport();

    if (success) {
        std::cout << "All tests passed.\n";
    }

    return success ? EXIT_SUCCESS : EXIT_FAILURE;
}
