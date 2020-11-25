#include <iostream>

/*
 *   Write another function called sum that takes two int arguments and returns
 *   their sum. How can you modify the template in Listing 1-9 to test your new
 *   function?
 */

int sum(int x, int y)
{
	return x + y;
}

int main()
{
	std::cout << "Please enter two integer numbers: ";
	int num1{}, num2{};
	std::cin >> num1 >> num2;

	std::cout << "The sum of " << num1 << " and " << num2 << " is " << sum(num1, num2) << '\n';

	return 0;
}