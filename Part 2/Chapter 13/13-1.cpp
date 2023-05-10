#include <iostream>
#include <vector>

/*
 *  Write a program that default constructs a std::vector of unsigned longs.
 *  Print the capacity of vector and then reserve 10 elements. Next, append the
 *  first 20 elements of the Fibonacci series to the vector. Print capacity again.
 *  Does capacity match the number of elements in the vector? Why or why not?
 *  Print the elements of vector using a range-based for loop.
 *
 *
 *  The capacity of the vector will likely be greater than or equal to 20
 *  because the vector may have allocated more memory than is currently
 *  needed to accommodate future growth.
 */

void get_info(const std::vector<unsigned long>& vec) {
	std::cout << "vec.size() = " << vec.size() << '\n';
	std::cout << "vec.capacity() = " << vec.capacity() << '\n';
}

void print_elements(const std::vector<unsigned long>& vec) {
	for (const auto& elem : vec) {
		std::cout << elem << ' ';
	}
	std::cout << '\n';
}

int main() {

	std::vector<unsigned long> vec;

	get_info(vec);

	vec.reserve(10);

	vec.assign({ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181 });

	get_info(vec);

	print_elements(vec);

	return 0;
}