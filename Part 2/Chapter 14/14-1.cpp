#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

// Create a corollary to Listing 14-8 using std::prev rather than std::next.

#include <iterator>
TEST_CASE("prev returns iterators at given offsets") {
	std::vector<unsigned char> mission{
	0x9e, 0xc4, 0xc1, 0x29,
	0x49, 0xa4, 0xf3, 0x14,
	0x74, 0xf2, 0x99, 0x05,
	0x8c, 0xe2, 0xb2, 0x2a
	};
	auto itr4 = mission.end();
	std::advance(itr4, -4);
	REQUIRE(*itr4 == 0x8c);
	auto itr5 = std::prev(itr4);
	REQUIRE(*itr5 == 0x05);
	auto itr6 = std::prev(itr4, 4);
	REQUIRE(*itr6 == 0x49);
	REQUIRE(*itr4 == 0x8c);
}