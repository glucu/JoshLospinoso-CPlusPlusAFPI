#include <iostream>
/*  Add an Element* previous to Listing 3-9 to make a doubly linked list. Add
    an insert_before method to Element. Traverse the list from front to back, then
    from back to front, using two separate for loops. Print the operating_number
    inside each loop
*/

struct Element
{
    Element* next{};
    Element* previous{};

    void insert_after(Element* new_element)
    {
        new_element->previous = this;
        if(next)
            next->previous = new_element;

        new_element->next = next;
        next = new_element;

    }

    void insert_before(Element* new_element)
    {
        new_element->previous = this;
        if (next) next->previous = new_element;
        new_element->next = next;
        next = new_element;
    }

    char prefix[2];
    short operating_number;
};

int main()
{
    Element trooper1, trooper2, trooper3, trooper4;

    trooper1.operating_number = 421;

    trooper1.insert_after(&trooper2);

    trooper2.operating_number = 2187;

    trooper2.insert_after(&trooper3);

    trooper3.operating_number = 555;

    trooper4.operating_number = 625;

    trooper1.insert_before(&trooper4);

    for (Element *cursor = &trooper1; cursor; cursor = cursor->next)
    {
        std::cout << cursor->operating_number << " --> ";
    }
    std::cout << "nullptr\n";

    for(Element *cursor = &trooper3; cursor; cursor = cursor->previous)
    {
        std::cout << cursor->operating_number << " --> ";
    }
    std::cout << "nullptr\n";
}