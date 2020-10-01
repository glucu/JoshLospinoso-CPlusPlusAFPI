#include <iostream>

/*
   Write another function called sum that takes two int arguments and returns
   their sum. How can you modify the template in Listing 1-9 to test your new
   function?
*/

int sum(int x, int y)
{
	return x + y;
}

int main()
{
	int num1{ 15 };
	int num2{ 10 };

	std::cout << num1 << " + " << num2 << " == " << sum(num1, num2) << '\n';

	return 0;
}