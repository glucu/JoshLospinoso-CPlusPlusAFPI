#include <iostream>
#include <chrono>

/*  Implement a copy constructor and a copy assignment operator for
 *  TimerClass. The copies should share timestamp values.
 */

class TimerClass {

public:
    TimerClass()
        : m_timestamp{ std::chrono::steady_clock::now() }
    { }

    ~TimerClass() {

        auto current = std::chrono::steady_clock::now() - m_timestamp;
        std::cout << std::chrono::duration_cast<std::chrono::microseconds>(current).count();
        std::cout << " microseconds\n";
    }

    // Copy constructor
    TimerClass(const TimerClass &rhs)
        : m_timestamp{ rhs.m_timestamp }
    { }

    // Copy assignment
    TimerClass& operator=(const TimerClass &rhs) {

        if (this == &rhs) return *this;

        m_timestamp = rhs.m_timestamp;

        return *this;
    }

private:
    std::chrono::steady_clock::time_point m_timestamp;
};