#include <iostream>

/* Create a function called absolute_value that returns the absolute value of
   its single argument. The absolute value of an integer x is the following: x (itself)
   if x is greater than or equal to 0; otherwise, it is x times −1. You can use the
   program in Listing 1-9 as a template.
*/


int absolute_value(int x)
{
	return (x >= 0) ? x : -x;
}

int main()
{
	int my_num1{ -10 };
	std::cout << "The absolute value of " << my_num1 << " is " << absolute_value(my_num1) << '\n';

	int my_num2{ 23 };
	std::cout << "The absolute value of " << my_num2 << " is " << absolute_value(my_num2) << '\n';

	int my_num3{}; // <-- default initialized to zero.
	std::cout << "The absolute value of " << my_num3 << " is " << absolute_value(my_num3) << '\n';

	return 0;
}