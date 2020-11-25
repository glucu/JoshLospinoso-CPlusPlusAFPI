#include <iostream>
/*
 *   Add an Element* previous to Listing 3-9 to make a doubly linked list. Add
 *   an insert_before method to Element. Traverse the list from front to back, then
 *   from back to front, using two separate for loops. Print the operating_number
 *   inside each loop
 */

/* COMMENT
 *
 *  I know this isn't the way from the book, but
 *  because we have defined both behaviors (functions)
 *  we will like to encapsulate the data by seperating the two
 *  with public interface, and implementation details. 
 *  Also, as long as your member function contains 1-2 lines
 *  of code, define them inline. Anything larger should be placed
 *  outside with the scope resolution operator. 
 */

class Link
{
public:
    short operation_number;

    Link(const short on);
    Link* insert_after(Link* new_element);
    Link* insert_before(Link* new_element);

    void traverse_forward(Link* main_trooper) const;
    void traverse_backwards(Link* main_trooper) const;

    Link* get_next() const
    { return next; }

    Link* get_prev() const 
    { return prev; }

private:
    Link *next;
    Link *prev;
};

Link::Link(const short on)
    : operation_number{on},
      next{nullptr},
      prev{nullptr} { }

Link* Link::insert_after(Link* new_element)
{
    if (!new_element)  return this;
    if (!this)         return new_element;

    new_element->prev = this;
    
    if (this->next)
        this->next->prev = new_element;

    new_element->next = this->next;
    this->next = new_element;

    return new_element;
}

Link* Link::insert_before(Link* new_element)
    {
        if (!new_element)  return this;
        if (!this)         return new_element;

        new_element->next = this;

        if (this->prev)
            this->prev->next = new_element;

        new_element->prev = this->prev;
        this->prev = new_element;

        return new_element;
    }

void Link::traverse_forward(Link* main_trooper) const
{
    if(main_trooper) 
    {
        const Link* curr{main_trooper};
        std::cout << "{ ";
        while(curr) 
        {
            std::cout << curr->operation_number;
            if(curr = curr->get_next())
                std::cout << " <=> ";
        }
        std::cout << " }\n";
    }
}

void Link::traverse_backwards(Link *main_trooper) const
{
    const Link* tail{main_trooper};

    while(tail->get_next())
        tail = tail->get_next();

    std::cout << "{ ";
    while(tail)
    {
        std::cout << tail->operation_number;
        if(tail = tail->get_prev())
            std::cout << " <=> ";
    }
    std::cout << " }\n";
}

int main()
{

    Link *main_trooper{new Link{2187}};

    Link* trooper1{new Link{24}};
    Link* trooper2{new Link{55}};
    Link* trooper3{new Link{111}};
    
    main_trooper = main_trooper->insert_before(trooper1);
    main_trooper = main_trooper->insert_before(trooper2);
    main_trooper = main_trooper->insert_before(trooper3);
    
    main_trooper->traverse_forward(main_trooper);
    main_trooper->traverse_backwards(main_trooper);

    return 0;
}