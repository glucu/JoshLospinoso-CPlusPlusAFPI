#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <cstddef>

/*  The mode of a series of values is the value that appears most commonly.
 *  Implement a mode function using the following signature: int mode(const
 *  int* values, size_t length). If you encounter an error condition, such as
 *  input having multiple modes and no values, return zero.
 */

int mode(const int *values, std::size_t length) {

	if (length <= 0) return 0;
	if (!values)     throw std::invalid_argument{ "mode(const int *values, std::size_t length): null pointer" };

	int number{ values[0] };
	int mode{ number };
	int count{ 1 };
	int count_mode{ 1 };

	for (std::size_t i{ 1 }; i < length; ++i) {

		if (values[i] == number)
			++count;
		else {

			if (count > count_mode) {

				count_mode = count;
				mode = number;
			}

			count = 1;
			number = values[i];
		}
	}

	return mode;
}

int main() {

	int values[]{ 6, 3, 9, 6, 6, 5, 9 };
	std::size_t length{ std::size(values) };

	std::sort(std::begin(values), std::end(values));

	try {

		auto result = mode(values, length);

		// If exception is thrown, this won't execute.
		std::cout << "mode: " << result << '\n';
	}
	catch (const std::invalid_argument &e) {

		std::cerr << "exception: " << e.what() << '\n';
		return 1;
	}
	catch (...) {

		std::cerr << "Unknown Exception caught\n";
		return 2;
	}
}