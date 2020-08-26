#include <iostream>
#include <utility>

/* Implement a fold function template with the following prototype 
   template <typename Fn, typename In, typename Out>
   constexpr Out fold(Fn function, In* input, size_t length, Out initial);

  The value of sum should be 1,500. Use fold to calculate the following quantities:
  the maximum, the minimum, and the number of elements greater than 200
*/

template <typename Fn, typename In, typename Out>
constexpr Out fold(Fn function, In* input, std::size_t length, Out initial);

int main()
{
	int data[]{ 100, 200, 300, 400, 500 };
	std::size_t data_len = 5;

	// calculate sum
	auto d_sum = [](auto x, auto y) { return x + y; };
	auto sum = fold(d_sum, data, data_len, 0);
	std::cout << "Sum: " << sum << '\n';

	// calculate maximum
	auto d_maximum = [](auto x, auto y) { return (x < y) ? y : x; };
	auto maximum = fold(d_maximum, data, data_len, 0);
	std::cout << "maximum: " << maximum << '\n';

	// calculate minimum
	auto d_minimum = [](auto x, auto y) { return (x < y) ? x : y; };
	auto minimum = fold(d_minimum, data, data_len, data[0]);
	std::cout << "minimum: " << minimum << '\n';

	// find elements greater than 200
	constexpr int n{ 200 };
	auto d_greater = [n](auto x, auto y) { return (y > n) ? x + 1 : x; };
	auto greater = fold(d_greater, data, data_len, 0);
	std::cout << "Number of elements greater than " << n << ": " << greater << '\n';

	return 0;
}

template <typename Fn, typename In, typename Out>
constexpr Out fold(Fn function, In* input, std::size_t length, Out initial)
{
	for (std::size_t index{}; index < length; ++index)
	{
		initial = function(std::move(initial), input[index]);
	}

	return initial;
}