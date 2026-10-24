///
/// \file       transport.hpp
/// \brief      CRTP byte transport interface.
///
/// \details    Provides a compile-time interface for reading and
///             writing device registers without virtual dispatch.
///
/// \author     galudino
/// \date       2026-10-24
///

#ifndef STARTER_TRANSPORT_HPP
#define STARTER_TRANSPORT_HPP

#include <cstdint>

namespace starter {

///
/// \brief      CRTP interface for register-oriented byte transports.
///
/// \tparam     Implementation  Concrete transport implementation.
///
template <typename Implementation>
class byte_transport {
public:
    ///
    /// \brief      Read an 8-bit device register.
    ///
    /// \param      address     Register address.
    ///
    /// \return     Value read from the register.
    ///
    [[nodiscard]] std::uint8_t read(std::uint8_t address) const {
        return implementation().Implementation::read(address);
    }

    ///
    /// \brief      Write an 8-bit device register.
    ///
    /// \param      address     Register address.
    /// \param      value       Value to write.
    ///
    void write(std::uint8_t address, std::uint8_t value) {
        implementation().Implementation::write(address, value);
    }

private:
    ///
    /// \brief      Access the concrete implementation.
    ///
    /// \return     Reference to the derived implementation.
    ///
    [[nodiscard]] Implementation &implementation() noexcept {
        return static_cast<Implementation &>(*this);
    }

    ///
    /// \brief      Access the concrete implementation.
    ///
    /// \return     Const reference to the derived implementation.
    ///
    [[nodiscard]] const Implementation &implementation() const noexcept {
        return static_cast<const Implementation &>(*this);
    }
};

} // namespace starter

#endif // STARTER_TRANSPORT_HPP
