#include <iostream>
#include <chrono>
#include <exception>
#include <limits>

/*   Experiment with your TimerClass. Create a timer and move it into a function that performs   
 *   some computationally intensive operation (for example, lots
 *   of math in a loop). Verify that your timer behaves as you expect.
 */

/*   COMMENT: 
 *   I really didn't understand what he mean't by, "lots of math in a loop." So,
 *   I decided to just use an example using fibonacci sequences. Of course, it would 
 *   be considered appropriate to test for int overflow considering we have discussed error
 *   handling. In addition, main() deals with invalid states that std::cin can cause, so of course,
 *   I check for that as well.
 */


struct TimerClass
{
    TimerClass(const char* name)
        : m_timestamp{ std::chrono::steady_clock::now() },
          m_name{ name } {}

    ~TimerClass()
    {
        auto current = std::chrono::steady_clock::now() -  m_timestamp;
        std::cout << m_name << std::chrono::duration_cast<std::chrono::microseconds>(current).count();
        std::cout << " microseconds\n";
    }

    // Copy constructor
    TimerClass(const TimerClass& rhs)
        : m_timestamp{ rhs.m_timestamp },
          m_name{ rhs.m_name } { }

    // Copy assignment
    TimerClass& operator=(const TimerClass& rhs)
    {
        if (this == &rhs) return *this;

        m_timestamp = rhs.m_timestamp;
        m_name = rhs.m_name;

        return *this;
    }

    // Move constructor
    TimerClass(TimerClass&& rhs) noexcept
        : m_timestamp{ rhs.m_timestamp },
          m_name{ rhs.m_name } { }

    // Move assignment
    TimerClass& operator=(TimerClass&& rhs) noexcept
    {
        if (this == &rhs) return *this;

        m_timestamp = rhs.m_timestamp;
        m_name = rhs.m_name;

        return *this;
    }

    std::chrono::steady_clock::time_point m_timestamp;
    const char* m_name;

};


void fibonacci(int fib1, int fib2, int n, TimerClass &&timer)
{
    if(n < 2) throw std:: runtime_error{"n must be at least 2."};

    std::cout << fib1 << ", " << fib2 << ", ";
    for(int i{2}; i < n; ++i) {

        int temp{fib1+fib2};

        if(temp < 0) throw std::runtime_error{"int overflow!"};

        fib1 = fib2;
        fib2 = temp;

        std::cout << fib2;
        if(i < n-1) std::cout << ", ";
    }
    std::cout << "\n\n";
}

int main()
{
    try {
        
        std::cout << "How many fibonacci numbers do you want to see computed?\n";
        std::cout << "Enter -1 to quit.\n";
        
         while(true) {

            std::cout << "> "; 
            int n{};
            std::cin >> n;

            if(std::cin) {

                if(n == -1) break;

                std::cout << "fibonacci(" << n << "): ";
                fibonacci(1, 2, n, TimerClass{"Time: "}); std::cout << "\n\n";
            }
            else if(std::cin.fail()) {

                std::cin.clear();  // set the stream state back to good()
                std::cin.ignore(std::numeric_limits<int>::max(), '\n'); // clear anything left in buffer

                std::cout << "Sorry, you didn't enter a number. Try again\n";
            }
            else {

                throw std::runtime_error{"bad input"}; // reached eof() or bad() state.
            }
            
        }
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