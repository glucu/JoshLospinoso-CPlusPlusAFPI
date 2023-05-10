#include <iostream>
#include <array>
#include <cstddef>

// Rewrite Listings 2-9, 2-10, and 2-11 in Chapter 2 using std::array.

int main() {

	// Listing 2-9
	std::array<int, 4> arr{ 1,2,3,4 };
	std::cout << "The third element is " << arr[2] << '\n';
	arr[2] = 100;
	std::cout << "The third element is " << arr[2] << '\n';

	std::cout << '\n';

	// Listing 2-10
	unsigned long maximum = 0;
	std::array<unsigned long, 5> values{ 10, 50, 20, 40, 0 };
	for (std::size_t i{}; i != 5; ++i) {
		if (values[i] > maximum) maximum = values[i];
	}
	std::cout << "The maximum value is " << maximum << '\n';

	std::cout << '\n';

	// Listing 2-11
	unsigned long maximum2 = 0;
	std::array<unsigned long, 5> values2{ 10, 50, 20, 40, 0 };
	for (unsigned long value : values2) {
		if (value > maximum2) maximum2 = value;
	}
	std::cout << "The maximum value is " << maximum2 << '\n';

	return 0;
}