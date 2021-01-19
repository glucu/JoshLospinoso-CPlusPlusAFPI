#ifndef FIBONACCIITERATOR_H
#define FIBONACCIITERATOR_H

struct FibonacciIterator {

	bool operator!=(int x) const {
		return x >= current;
	}

	FibonacciIterator& operator++() {

		const auto tmp = current;
		current += last;
		last = tmp;
		return *this;
	}

	int operator*() const {

		return current;
	}

private:
	int current{ 1 }, last{ 1 };
};

#endif // FIBONACCIITERATOR_H