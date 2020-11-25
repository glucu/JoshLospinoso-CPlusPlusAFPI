#include <iostream>
#include <iterator>

/* 
   Add a read_from and a write_to function to Listing 3-6. These functions
   should read or write to upper or lower as appropriate.  
   Perform bounds checking to prevent buffer overflows.
*/

void write_to(char *ptr, std::size_t len, const int index, char input)
{
    if(index < 0 || index > len - 1)
        std::cerr << "Invalid index at " << index << '\n';  // NOTE: std::cerr << is the same as std::cout << except it
    else                                                    // prints the message in RED. Used for error handling.
        ptr[index] = input;
}

void read_from(const char *ptr, std::size_t len, const int index)
{
    if(index < 0 || index > len - 1)
        std::cerr << "Invalid index at " << index << '\n';
    else
        std::cout << "ptr[" << index << "] = " << ptr[index] << '\n';
}

int main()
{
    char lower[] = "abc?e";
    auto lower_len{ std::size(lower) };  // Note: Prior to C++17, you can use sizeof(lower) / sizeof(lower[0]) 
                                         // to determine how many elements are in an array
                                         // Same for latter
    char upper[] = "ABC?E";
    auto upper_len{ std::size(upper) };

    write_to(lower, lower_len, 3, 'd');
    read_from(lower, lower_len, 3);

    write_to(upper, upper_len, 3, 'D');
    read_from(upper, upper_len, 3);

    //write_to(lower, lower_len, 5, 'g'); <-- uncommenting this will be out of range
    //read_from(lower, lower_len, 5);

    std::cout << "lower: " << lower << '\n';
    std::cout << "upper: " << upper << '\n';
}