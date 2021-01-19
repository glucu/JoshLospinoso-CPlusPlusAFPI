#ifndef FIBONACCIRANGE_H
#define FIBONACCIRANGE_H

#include "FibonacciIterator.h"

struct FibonacciRange {

	explicit FibonacciRange(int max) : max{ max } { }

	FibonacciIterator begin() const {

		return FibonacciIterator{};
	}

	int end() const {

		return max;
	}

private:
	const int max;
};

#endif // FIBONACCIRANGE_H