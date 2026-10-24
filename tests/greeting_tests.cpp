
///
/// \file       greeting_tests.cpp
/// \brief      Unit tests for the greeting library.
///
/// \author     galudino
/// \date       2026-10-23
///

#include <starter/greeting.hpp>

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
/// \brief      Tests the greeting generator.
///
/// \return     True if all tests pass.
///
bool test_make_greeting() {
    const auto greeting = starter::make_greeting("World");
    return check(greeting == "Hello, World!", "make_greeting");
}

///
/// \brief      Tests integer addition.
///
/// \return     True if all tests pass.
///
bool test_add() {
    static_assert(starter::add(2, 3) == 5);

    auto success = true;

    success &= check(starter::add(-2, 3) == 1, "add: mixed signs");
    success &= check(starter::add(0, 0) == 0, "add: zeros");

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

    success &= test_make_greeting();
    success &= test_add();

    if (success) {
        std::cout << "All tests passed.\n";
    }

    return success ? EXIT_SUCCESS : EXIT_FAILURE;
}
