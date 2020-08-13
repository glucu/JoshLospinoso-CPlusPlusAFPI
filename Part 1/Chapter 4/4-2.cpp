#include <iostream>
#include <chrono>

/* In the destructor of TimerClass, record the current timeand subtract the
   time at construction.This time is roughly the age of the timer.Print this value
*/


struct TimerClass
{
    TimerClass()
        : m_timestamp{ std::chrono::steady_clock::now() }
    { }

    ~TimerClass()
    {
        std::chrono::steady_clock::time_point current;
        current = std::chrono::steady_clock::now();

        std::chrono::steady_clock::duration end_time;
        end_time = current - m_timestamp;

        std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time).count();
        std::cout << '\n';
    }

private:
    std::chrono::steady_clock::time_point m_timestamp;
};