#include <iostream>
#include <cstddef>
#include <iterator>

/*
 *   Implement an all function with the following prototype:
 *
 *   template <typename Fn, typename In, typename Out>
 *   constexpr bool all(Fn function, In* input, size_t length);
 *
 *   The Fn function type is a predicate that supports bool operator()(In).
 *   Your all function must test whether function returns true for every element of
 *   input. If it does, return true. Otherwise, return false.
 */

template <typename Fn, typename In>
constexpr bool all(Fn function, In* input, std::size_t length);

int main() {

	constexpr int data[]{ 101, 200, 300, 400, 500 };
	//std::size_t data_len = 5;
	constexpr auto data_len{ std::size(data) };

	auto all_gt100 = all([](auto x) { return x > 100; }, data, data_len);

	if (all_gt100)
		std::cout << "All elements greater than 100.\n";
	else
		std::cout << "Not all elements are greater than 100.\n";

	return 0;
}

template <typename Fn, typename In>
constexpr bool all(Fn function, In* input, std::size_t length) {
	for (std::size_t i{}; i != length; ++i) {
		if (!function(input[i])) return false;
	}
	return true;
}
