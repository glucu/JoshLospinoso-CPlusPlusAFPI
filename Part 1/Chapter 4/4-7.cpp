#include <iostream>
#include <cstring>
#include <stdexcept>
#include <utility>

/*  Identify each method in the SimpleString class (Listing 4-38).  
 *  Try reimplementing it from scratch without referring to the book.
 */

// Note: I used a class instead of a struct.

class SimpleString
{
public:
    explicit SimpleString(size_t max_size);                 // one-argument constructor
    ~SimpleString();                                        // Destructor

    SimpleString(const SimpleString &rhs);                  // Copy constructor
    SimpleString& operator=(const SimpleString &rhs);       // Copy assignment operator 

    SimpleString(SimpleString &&rhs) noexcept;              // Move constructor
    SimpleString& operator=(SimpleString &&rhs) noexcept;   // Move assignment constructor

    void print(const char* tag) const
    { std::cout << tag << ": " << m_buffer << '\n'; }       // Print tag followed by C-Style array 

    bool append_line(const char *x);                        // appends a new line to the buffer.

private:
    size_t m_max_size;
    char*  m_buffer;
    size_t m_length;
};

SimpleString::SimpleString(size_t max_size)
    : m_max_size{ max_size },
      m_length{}
{
    if (max_size == 0)
    {
        throw std::runtime_error{ "Max size must be at least 1." };
    }

    m_buffer = new char[max_size];
    m_buffer[0] = 0;
}

SimpleString::~SimpleString()
{ delete[] m_buffer; }

SimpleString::SimpleString(const SimpleString &rhs)
    : m_max_size{ rhs.m_max_size },
      m_buffer{ new char[rhs.m_max_size] },
      m_length{ rhs.m_length }
{
    std::strncpy(m_buffer, rhs.m_buffer, m_max_size);
}

SimpleString& SimpleString::operator=(const SimpleString &rhs)
{
    if (this == &rhs) return *this;
    
    const auto new_buffer = new char[rhs.m_max_size];
    delete[] m_buffer;
    m_buffer = new_buffer;
    m_length = rhs.m_length;
    m_max_size = rhs.m_max_size;
    
    std::strncpy(m_buffer, rhs.m_buffer, m_max_size);
    
    return *this;
}


SimpleString::SimpleString(SimpleString &&rhs) noexcept
    : m_max_size{ rhs.m_max_size },
      m_buffer{ rhs.m_buffer },
      m_length{ rhs.m_length }
{
    rhs.m_length = 0;
    rhs.m_buffer = nullptr;
    rhs.m_max_size = 0;
}

 SimpleString& SimpleString::operator=(SimpleString &&rhs) noexcept
{
    if (this == &rhs) return *this;
    
    delete[] m_buffer;
    m_buffer = rhs.m_buffer;
    m_length = rhs.m_length;
    m_max_size = rhs.m_max_size;
    
    rhs.m_buffer = nullptr;
    rhs.m_length = 0;
    rhs.m_max_size = 0;
    
    return *this;
}

bool SimpleString::append_line(const char *x)
{
    const auto x_len = strlen(x);
    
    if (x_len + m_length + 2 > m_max_size) return false;
    
    std::strncpy(m_buffer + m_length, x, m_max_size - m_length);
    m_length += x_len;
    m_buffer[m_length++] = '\n';
    m_buffer[m_length] = 0;
    
    return true;
}

int main()
{
    try {

        SimpleString a{ 50 };
        a.append_line("C++ is the better programming language!");
        
        SimpleString b{ 50 };
        b.append_line("No, Java is way better!");

        a.print("a ");
        b.print("b ");
        
        b = a; // <-- Lets change b's mind with copy assignment ;)
        
        a.print("a ");
        b.print("b ");
    }
    catch(const std::exception &e) {

        std::cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {

        std::cerr << "unknown exception caught\n";
        return 2;
    }

    return 0;
}