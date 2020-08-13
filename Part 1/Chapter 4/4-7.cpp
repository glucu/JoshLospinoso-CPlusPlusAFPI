#include <iostream>
#include <cstring>
#include <stdexcept>
#include <utility>

/*  Identify each method in the SimpleString class (Listing 4-38).  
    Try reimplementing it from scratch without referring to the book.
*/

// Note: I used a class instead of a struct.

class SimpleString
{
public:
    // 1-arg constructor
    SimpleString(size_t max_size)
            : max_size{ max_size },
              length{}
    {
        if (max_size == 0)
        {
            throw std::runtime_error{ "Max size must be at least 1." };
        }

        buffer = new char[max_size];
        buffer[0] = 0;
    }

    // Destructor
    ~SimpleString()
    {
        delete[] buffer;
    }

    // Copy constructor
    SimpleString(const SimpleString &other)
       : max_size{ other.max_size },
         buffer{ new char[other.max_size] },
         length{ other.length }
    {
        std::strncpy(buffer, other.buffer, max_size);
    }

    // Move constructor
    SimpleString(SimpleString &&other) noexcept
       : max_size{ other.max_size },
         buffer{ other.buffer },
         length{ other.length }
    {
        other.length = 0;
        other.buffer = nullptr;
        other.max_size = 0;
    }

    // Copy assignment operator
    SimpleString& operator=(const SimpleString &other)
    {
        if (this == &other)
            return *this;

        const auto new_buffer = new char[other.max_size];
        delete[] buffer;
        buffer = new_buffer;
        length = other.length;
        max_size = other.max_size;
        std::strncpy(buffer, other.buffer, max_size);

        return *this;
    }

    // Move assignment operator
    SimpleString& operator=(SimpleString &&other) noexcept
    {
        if (this == &other)
            return *this;

        delete[] buffer;
        buffer = other.buffer;
        length = other.length;
        max_size = other.max_size;
        other.buffer = nullptr;
        other.length = 0;
        other.max_size = 0;

        return *this;
    }

    void print(const char* tag) const
    {
        std::cout << tag << ": " << buffer << '\n';
    }

    bool append_line(const char *x)
    {
        const auto x_len = strlen(x);

        if (x_len + length + 2 > max_size)
            return false;

        std::strncpy(buffer + length, x, max_size - length);
        length += x_len;
        buffer[length++] = '\n';
        buffer[length] = 0;

        return true;
    }

private:
    size_t max_size;
    char* buffer;
    size_t length;
};

int main()
{
    SimpleString a{ 50 };
    a.append_line("C++ is the better programming language!");

    SimpleString b{ 50 };
    b.append_line("No, Java is way better!");

    b= a; // <-- Lets change b's mind with copy assignment ;)

    a.print("a: ");
    b.print("b: ");

    return 0;
}