#include "FibonacciIterator.h"
#include "PrimeNumberRange.h"

#include <iostream>

/*  Integrate PrimeNumberRange into Listing 8-27, adding another loop that
 *  generates all prime numbers less than 5,000.
 */


int main() {

	std::cout << "Fibonacci: ";
	for (const auto &i : FibonacciRange{ 5000 })  {

		std::cout << i << ' ';
	}

	std::cout << "\n\n";
    
    PrimeNumberRange prime{ 5000 };

	std::cout << "Prime: ";
	std::cout << prime.getCurrent() << ' ';

	while (true) {

		int n{ ++prime };
		if (n < 0)
			return true;

		std::cout << n << ' ';
	}

    return 0;
}