/* Create a struct Calculator. It should have a single constructor that takes
   an Operation.
*/

struct Calculator
{
    Calculator(const Operation operation)
       : operation{operation} {}

private:
    Operation operation;
};