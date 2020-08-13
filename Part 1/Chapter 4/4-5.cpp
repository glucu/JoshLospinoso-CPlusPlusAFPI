#include <iostream>
#include <chrono>

/* Elaborate the TimerClass constructor to accept an additional const char*
   name parameter.When TimerClass is destructedand prints to stdout, include
   the name of the timer in the output
*/

struct TimerClass
{
    TimerClass(char* name)
        : m_timestamp{ std::chrono::steady_clock::now() },
        m_name{ name } {}

    ~TimerClass()
    {
        std::chrono::steady_clock::time_point current;
        current = std::chrono::steady_clock::now();

        std::chrono::steady_clock::duration end_time;
        end_time = current - m_timestamp;

        std::cout << m_name << ": " << std::chrono::duration_cast<std::chrono::microseconds>(end_time).count();
        std::cout << '\n';
    }

    // Copy semantics

    // Copy constructor
    TimerClass(const TimerClass& rhs)
        : m_timestamp{ rhs.m_timestamp },
        m_name{ rhs.m_name } { }

    // Copy assignment
    TimerClass& operator=(const TimerClass& rhs)
    {
        if (this == &rhs)
            return *this;

        m_timestamp = rhs.m_timestamp;
        m_name = rhs.m_name;

        return *this;
    }

    // Move semantics

    // Move constructor
    TimerClass(TimerClass&& rhs) noexcept
        : m_timestamp{ rhs.m_timestamp },
        m_name{ rhs.m_name } {}

    // Move assignment
    TimerClass& operator=(TimerClass&& rhs) noexcept
    {
        if (this == &rhs)
            return *this;

        m_timestamp = rhs.m_timestamp;
        m_name = rhs.m_name;

        return *this;
    }

private:
    std::chrono::steady_clock::time_point m_timestamp;
    char* m_name;

};
