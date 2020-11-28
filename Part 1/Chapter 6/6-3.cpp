#include <iostream>
#include <algorithm>
#include <concepts>
#include <type_traits>

/*   Modify mode to accept an Integer concept. Verify that mode fails to
 *   instantiate with floating types like double.
 */

/*  COMMENT
 *  Visual Studio 2019 supports concepts that you can find in the Standard Libaray headers.
 *  A floating-point type is not an integral. I also want to support other types such as
 *  short, long long, so I went with the std::is_integral_v<T> concept.
 *  Try reading: https://www.modernescpp.com/index.php/c-20-concepts-the-details
 */

template <typename T>
concept Integral = std::is_integral_v<T>; 

template <Integral T>
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
	int int_array[]{ 2, 8, 1, 1, 2, 9, 1, 5, 5, 3 };
	std::size_t length{ std::size(int_array) };

	int float_array[]{2.0f, 8.0f, 1.0f, 1.0f, 2.0f, 9.0f, 1.0f, 5.0f, 5.0f, 3.0f};

	std::sort(std::begin(int_array), std::end(int_array));
	std::sort(std::begin(float_array), std::end(float_array));

	try {

		auto works    = mode(int_array, length);
	//	auto no_works = mode(float_array, length); <-- uncommenting this will cause an error

		// If exception is thrown, this won't execute.
		std::cout << "mode: " << works << '\n';
		//std::cout << "mode: " << no_works << '\n';
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