#include <chrono>

/*  Create a struct TimerClass. In its constructor, record the current time in a
 *  field called timestamp (compare with the POSIX function gettimeofday).
 */

class TimerClass {
    
public:
    TimerClass()
        : m_timestamp{ std::chrono::steady_clock::now() }
    { }

private:
    std::chrono::steady_clock::time_point m_timestamp;
};