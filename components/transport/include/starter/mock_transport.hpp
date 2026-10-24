///
/// \file       mock_transport.hpp
/// \brief      CRTP byte transport implementation.
///
/// \details    Provides a compile-time implementation for reading and
///             writing device registers without virtual dispatch.
///
/// \author     galudino
/// \date       2026-10-24
///

#ifndef STARTER_MOCK_TRANSPORT_HPP
#define STARTER_MOCK_TRANSPORT_HPP

#include <array>
#include <cstdint>

#include <starter/transport.hpp>

namespace starter {

///
/// \brief      Mock register-based transport for testing.
///
/// \details    Simulates a device with 256 addressable 8-bit registers.
///             No physical hardware or external dependencies are required.
///
class mock_transport final : public byte_transport<mock_transport> {
public:
    ///
    /// \brief      Read a register.
    ///
    /// \param      address  Register address.
    ///
    /// \return     Value stored at the specified address.
    ///
    [[nodiscard]] std::uint8_t read(std::uint8_t address) const noexcept {
        return m_registers[address];
    }

    ///
    /// \brief      Write a register.
    ///
    /// \param      address  Register address.
    /// \param      value    Value to store.
    ///
    void write(std::uint8_t address, std::uint8_t value) noexcept { m_registers[address] = value; }

private:
    std::array<std::uint8_t, 256> m_registers{};
};

} // namespace starter

#endif // STARTER_MOCK_TRANSPORT_HPP
