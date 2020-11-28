#include <iostream>
#include <algorithm>
#include <type_traits>

// Implement mode as a template function

template <typename T>
T mode(const T *values, std::size_t length)
{
	if (length <= 0) return 0;
	if (!values)     throw std::invalid_argument{ "Invalid argument passed." };

	T number{ values[0] };
	T mode{ number };
	int count{ 1 };
	int count_mode{ 1 };

	for (std::size_t i{ 1 }; i < length; ++i)
	{
		if (values[i] == number)
			++count;
		else
		{
			if (count > count_mode)
			{
				count_mode = count;
				mode = number;
			}

			count = 1;
			number = values[i];
		}
	}

	return mode;
}

int main()
{
	int values[]{ 2, 8, 1, 1, 2, 9, 1, 5, 5, 3 };
	std::size_t length{ std::size(values) };

	std::sort(std::begin(values), std::end(values));

	try {
		auto result{ mode(values, length) };

		// If exception is thrown, this won't execute.
		std::cout << "mode: " << result << '\n';
	}
	catch (const std::exception &e) {

		std::cerr << "exception: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		
		std::cerr << "Unknown Exception caught\n";
		return 2;
	}
}