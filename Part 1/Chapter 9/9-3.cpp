#include <iostream>
#include <cstddef>
#include <iterator>

/*
   Implement an all function with the following prototype:

   template <typename Fn, typename In, typename Out>
   constexpr bool all(Fn function, In* input, size_t length);

   The Fn function type is a predicate that supports bool operator()(In).
   Your all function must test whether function returns true for every element of
   input. If it does, return true. Otherwise, return false.
*/

template <typename Fn, typename In>
constexpr bool all(Fn function, In* input, size_t length);

int main()
{
	int data[]{ 100, 200, 300, 400, 500 };
	//std::size_t data_len = 5;
	auto data_len{ std::ssize(data) };

	auto all_gt100 = all([](auto x) { return x > 100; }, data, data_len);

	if (all_gt100)
		std::cout << "All elements greater than 100.\n";
	else
		std::cout << "Not all elements are greater than 100.\n";

	return 0;
}

template <typename Fn, typename In>
constexpr bool all(Fn function, In* input, size_t length)
{
	bool flag{};
	for (size_t i{}; i < length; ++i)
	{
		if (function(input[i]))
			flag = true;
		else
			return false;
	}

	return flag;
}
