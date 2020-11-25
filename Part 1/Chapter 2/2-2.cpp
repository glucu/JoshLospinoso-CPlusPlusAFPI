/* 
 *  Create a struct Calculator. It should have a single constructor that takes
 *  an Operation.
 */

enum class Operation
{
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE
};

class Calculator
{
public:
    Calculator(Operation operation);

private:
    Operation m_operation;
};