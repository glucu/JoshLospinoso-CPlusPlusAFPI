#include "../FibonacciRange.h"
#include "../FibonacciIterator.h"
#include <cstdio>

int main()
{
	FibonacciRange range{ 5000 };
	const auto end = range.end();
	for (auto x = range.begin(); x != end; ++x) {

		const auto i = *x;

		printf("%d ", i);
	}

	return 0;
}