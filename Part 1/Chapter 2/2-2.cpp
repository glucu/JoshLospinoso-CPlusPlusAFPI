/* 
   Create a struct Calculator. It should have a single constructor that takes
   an Operation.
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
    Calculator(Operation operation)
       : operation{operation} { }

private:
    Operation operation;
};