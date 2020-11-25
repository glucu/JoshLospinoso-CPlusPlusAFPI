#include <iostream>

/*  Create a function called absolute_value that returns the absolute value of
 *  its single argument. The absolute value of an integer x is the following: x (itself)
 *  if x is greater than or equal to 0; otherwise, it is x times −1. You can use the
 *  program in Listing 1-9 as a template.
 */

/*  COMMENT
 *
 *  I will choose to make my own template rather then following 
 *  the template given by the exercise.
 */

int absolute_value(int x)
{
	if(x >= 0) return x;
	else       return -x;
}

int main()
{
	std::cout << "Please enter an integer and I will tell you the "
	          << " absolute value of it\n";
	int x{};
	std::cin >> x;

	std::cout << "The absolute value of " << x << " is " << absolute_value(x) << '\n';

	return 0;
}