#include <iostream>

/* 
   Create a method on Calculator called int calculate(int a, int b).
   Upon invocation, this method should perform addition, subtraction, multiplication, or division based on its constructor argument and return the result.
   Experiment with different means of initializing Calculator instances.
*/

enum class Operation
{
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE
};

struct Calculator
{
    Calculator()
    {
        std::cout << "This should not be called.\n";
    }

    Calculator(Operation operation)
       : operation{operation} { }

    int calculate(int a, int b)
    {
        switch(operation)
        {
            case Operation::ADD: {
                return a + b;
            }

            case Operation::SUBTRACT: {
                return a - b;
            }

            case Operation::MULTIPLY: {
                return a * b;
            }

            case Operation::DIVIDE: {
                return a / b;
            }

            default: {
                std::cout << "Not an operator I know of.\n";
                break;
            }
        }
    }

private:
    Operation operation;
};

int main()
{
    Calculator calc1 = { Operation::ADD }; // Okay
    std::cout << "ADD: " << calc1.calculate(5, 6) << '\n';

    Calculator calc2{ Operation::SUBTRACT }; // Okay
    std::cout << "SUBTRACT: " << calc2.calculate(6, 3) << '\n';

    Calculator calc3(Operation::MULTIPLY); // Okay, but because of the fact of "vexing parse", prefer uniform init.
    std::cout << "MULTIPLY: " << calc3.calculate(5, 5) << '\n';

    Calculator oopsCalc4(); // <-- This won't invoke default constructor!

    return 0;
}