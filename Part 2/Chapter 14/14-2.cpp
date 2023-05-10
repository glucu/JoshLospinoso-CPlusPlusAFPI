#include <iostream>
#include <vector>

// Write a function template called sum that accepts a half-open range of
// int objects and returns the sum of the sequence.


template <typename Iter>
int sum(Iter beg, Iter end) {
	int result{};
	while (beg != end) {
		result += *beg;
		++beg;
	}
	return result;
}

int main() {

	std::vector<int> numbers{ 1, 2, 3, 4, 5 };
	auto result = sum(numbers.begin(), numbers.end());
	std::cout << "Sum: " << result << '\n';

	return 0;
}