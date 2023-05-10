#include <iostream>
#include <chrono>
#include <vector>
#include <iterator>
#include <forward_list>

/*
*  Write a program that uses the Stopwatch class in Listing 12-25 to deter-
*  mine the runtime performance of std::advance when given a forward iterator
*  from a large std::forward_list and a large std::vector. How does the run-
*  time change with the number of elements in the container? (Try hundreds of
*  thousands or millions of elements.)
*/


struct Stopwatch {
	Stopwatch(std::chrono::nanoseconds& result)
		: result{ result },
		start{ std::chrono::high_resolution_clock::now() } { }
	~Stopwatch() {
		result = std::chrono::high_resolution_clock::now() - start;
	}
private:
	std::chrono::nanoseconds& result;

	const std::chrono::time_point<std::chrono::high_resolution_clock> start;
};

int main() {

	constexpr int numElements{ 1'000'000 };

	std::forward_list<int> forwardList;
	for (int i{}; i != numElements; ++i) {
		forwardList.push_front(i);
	}

	std::chrono::nanoseconds forwardListTime;
	{
		Stopwatch timer(forwardListTime);
		auto it = forwardList.begin();
		std::advance(it, numElements / 2);
	}

	std::vector<int> vector(numElements);
	for (int i{}; i != numElements; ++i) {
		vector[i] = i;
	}

	std::chrono::nanoseconds vectorTime;
	{
		Stopwatch timer(vectorTime);
		auto it = vector.begin();
		std::advance(it, numElements / 2);
	}

	std::cout << "std::advance runtime with std::forward_list: " << forwardListTime.count() << " ns\n";
	std::cout << "std::advance runtime with std::vector: " << vectorTime.count() << " ns\n";

	return 0;
}