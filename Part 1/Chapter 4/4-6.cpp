#include <iostream>
#include <chrono>

/*  Experiment with your TimerClass. Create a timer and move it into a function that performs   
    some computationally intensive operation (for example, lots
    of math in a loop). Verify that your timer behaves as you expect.
*/

// Note: I really didn't understand what he mean't by, "lots of math in a loop." So,
// I decided to just use an example using fibonacci computation found in cppreference.com

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

        std::cout << m_name << std::chrono::duration_cast<std::chrono::microseconds>(end_time).count();
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

long long fibonacci(unsigned n)
{
    if (n < 2) return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    TimerClass a{ "A: " };
    std::cout << "f(42) = " << fibonacci(42) << '\n';

    return 0;
}