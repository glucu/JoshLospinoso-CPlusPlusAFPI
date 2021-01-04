#include <iostream>
#include <chrono>

/*  In the destructor of TimerClass, record the current time and subtract the
 *  time at construction.This time is roughly the age of the timer. Print this value.
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

private:
    std::chrono::steady_clock::time_point m_timestamp;
};