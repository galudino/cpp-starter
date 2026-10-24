///
/// \file       transport_tests.cpp
/// \brief      Unit tests for the transport library.
///
/// \author     galudino
/// \date       2026-10-24
///

#include <starter/mock_transport.hpp>

#include <doctest/doctest.h>

#include <concepts>
#include <cstdint>
#include <type_traits>

namespace {

///
/// \brief      Verify the transport API at compile time.
///
static_assert(
    std::derived_from<starter::mock_transport, starter::byte_transport<starter::mock_transport>>);

static_assert(std::is_default_constructible_v<starter::mock_transport>);

static_assert(requires(starter::mock_transport &transport,
                       const starter::mock_transport &const_transport, std::uint8_t address,
                       std::uint8_t value) {
    { const_transport.read(address) } -> std::same_as<std::uint8_t>;
    { transport.write(address, value) } -> std::same_as<void>;
});

} // namespace

TEST_CASE("mock_transport reads and writes registers") {
    starter::mock_transport transport{};

    auto &base = static_cast<starter::byte_transport<starter::mock_transport> &>(transport);

    // All registers should initially contain zero.
    CHECK(transport.read(0x10) == 0x00);

    // Write and read back a register value.
    transport.write(0x10, 0xAB);

    CHECK(transport.read(0x10) == 0xAB);

    // Writes to different addresses must remain independent.
    transport.write(0x20, 0x42);

    CHECK(transport.read(0x10) == 0xAB);

    CHECK(transport.read(0x20) == 0x42);

    // Exercise the highest valid register address.
    transport.write(0xFF, 0x7E);

    CHECK(transport.read(0xFF) == 0x7E);

    // Verify dispatch through the CRTP base interface.
    base.write(0x30, 0x55);

    CHECK(base.read(0x30) == 0x55);

    CHECK(transport.read(0x30) == 0x55);
}
