
///
/// \file       header.hpp
/// \brief      Public interface for the starter C++ library.
///
/// \details    Demonstrates a separately compiled C++ library and
///             a constexpr function defined in a header.
///
/// \author     galudino
/// \date       2026-10-23
///

#ifndef HEADER_HPP
#define HEADER_HPP

#include <string>
#include <string_view>

namespace starter {

///
/// \brief      Generates a greeting for the specified name.
///
/// \param      name        Name of the recipient.
///
/// \return     A formatted greeting string.
///
[[nodiscard]] std::string make_greeting(std::string_view name);

///
/// \brief      Computes the sum of two integers.
///
/// \param      lhs         Left operand.
/// \param      rhs         Right operand.
///
/// \return     Sum of both operands.
///
[[nodiscard]] constexpr int add(int lhs, int rhs) noexcept {
    return lhs + rhs;
}

} // namespace starter

#endif /* HEADER_HPP */
