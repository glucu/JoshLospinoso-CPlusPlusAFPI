#include <iostream>
#include <cstddef>
#include <ostream>

/*  Implement a program that accepts an arbitrary number of command line
 *  arguments, m_counts the m_length in characters of each argument, and prints a
 *  histogram of the argument m_length distribution.
 */

class Histogram {
public:
    explicit Histogram(std::size_t len)
        : m_data{ new std::size_t[len]{} },
          m_size{},
          m_length{ len },
          m_tally{} { }

    ~Histogram() {
        delete[] m_data;
    }

    Histogram(const Histogram&) = delete;
    Histogram& operator=(const Histogram&) = delete;

    void ingest(const char* text) {
        std::size_t index{};
        while (text[index]) {
            ++m_tally;
            ++index;
        }
        m_data[m_size++] = m_tally;
        m_tally = 0;
    }

    friend std::ostream& operator<<(std::ostream& out, const Histogram& hist) {
        for (std::size_t i{}; i != hist.get_length(); ++i) {
            out << "Argument #" << (i + 1) << ": " << hist.m_data[i] << '\n';
        }
        return out;
    }

    std::size_t get_length() const { return m_length; }


private:
    std::size_t* m_data;
    std::size_t m_size;
    std::size_t m_length;
    std::size_t m_tally;
};


int main(int argc, char** argv) {

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " [arguments...]\n";
        return 1;
    }

    Histogram hist{ argc };

    for (std::size_t i{ 1 }; i < hist.get_length(); ++i) {
        hist.ingest(argv[i]);
    }

    std::cout << hist << '\n';

    return 0;
}