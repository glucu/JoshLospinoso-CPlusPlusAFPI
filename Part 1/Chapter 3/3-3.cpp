#include <iostream>
/*
    Add an Element* previous to Listing 3-9 to make a doubly linked list. Add
    an insert_before method to Element. Traverse the list from front to back, then
    from back to front, using two separate for loops. Print the operating_number
    inside each loop
*/

struct Element
{
    Element* next;
    Element* previous;

    Element(const short on)
        : operating_number{ on },
        next{ nullptr },
        previous{ nullptr }
    { }

    void insert_after(Element* new_element)
    {
        if (new_element == nullptr)
            return;

        new_element->previous = this;

        if (this->next)
            this->next->previous = new_element;

        new_element->next = this->next;
        this->next = new_element;
    }

    void insert_before(Element* new_element)
    {
        if (new_element == nullptr)
            return;

        new_element->next = this;

        if (this->previous)
            this->previous->next = new_element;

        new_element->previous = this->previous;
        this->previous = new_element;

    }

    char prefix[2];
    short operating_number;
};

int main()
{
    Element trooper1{ 421 },
        trooper2{ 2187 },
        trooper3{ 005 };

    trooper1.insert_after(&trooper2);
    trooper2.insert_after(&trooper3);

    Element trooper4{ 111 };
    trooper1.insert_before(&trooper4);


    for (Element* cursor = &trooper4; cursor; cursor = cursor->next)
    {
        std::cout << cursor->operating_number << '\t';
    }
    std::cout << '\n';

    for (Element* cursor = &trooper3; cursor; cursor = cursor->previous)
    {
        std::cout << cursor->operating_number << '\t';
    }
    std::cout << '\n';
}