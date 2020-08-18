#include <iostream>
#include <algorithm>
#include <type_traits>
#include <stdexcept>

/* Modify mode to accept an Integer concept. Verify that mode fails to
   instantiate with floating types like double
*/

template <typename T>
int mode(const T *values, std::size_t length)
{
	static_assert(std::is_integral<T>(), "Type must be an integer.");

	if (length <= 0)
		return 0;

	if (!values)
		throw std::invalid_argument{ "Invalid argument passed." };

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
    int values[]{ 2, 1, 1, 5, 7, 1, 2, 3, 3, 1};
	std::size_t length{ std::size(values) };

	std::sort(std::begin(values), std::end(values));

	try
	{
		auto result{ mode(values, length) };

		// If exception is thrown, this won't execute.
		std::cout << "mode: " << result << '\n';
	}
	catch (const std::invalid_argument &e)
	{
		std::cerr << "Standard exception: " << e.what() << '\n';
	}
	catch (...)
	{
		std::cerr << "Unknown Exception caught.\n";
	}
}