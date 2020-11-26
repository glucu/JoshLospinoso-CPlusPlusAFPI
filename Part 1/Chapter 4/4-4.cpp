#include <iostream>
#include <chrono>

/*  Implement a move constructor and a move assignment operator for
 *  TimerClass. A moved-from TimerClass shouldn�t print any output to the console
 *  when it gets destructed.
 */

struct TimerClass
{
    TimerClass()
        : m_timestamp{ std::chrono::steady_clock::now() }
    { }

    ~TimerClass()
    {
        auto current = std::chrono::steady_clock::now() -  m_timestamp;
        std::cout << m_name << std::chrono::duration_cast<std::chrono::microseconds>(current).count();
        std::cout << " microseconds\n";
    }

    // Copy constructor
    TimerClass(const TimerClass& rhs)
        : m_timestamp{ rhs.m_timestamp }
    { }

    // Copy assignment
    TimerClass& operator=(const TimerClass& rhs)
    {
        if (this == &rhs)
            return *this;

        m_timestamp = rhs.m_timestamp;

        return *this;
    }

    // Move constructor
    TimerClass(TimerClass&& rhs) noexcept
        : m_timestamp{ rhs.m_timestamp }
   { }

    // Move assignment
    TimerClass& operator=(TimerClass&& rhs) noexcept
    {
        if (this == &rhs)
            return *this;

        m_timestamp = rhs.m_timestamp;

        return *this;
    }
    
    std::chrono::steady_clock::time_point m_timestamp;

};