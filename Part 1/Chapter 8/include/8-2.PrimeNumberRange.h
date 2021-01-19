#ifndef PRIMENUMBERRANGE_H
#define PRIMENUMBERRANGE_H

#include <cstddef>

/*  Implement a PrimeNumberRange class that can be used in a range exception
 *  to iterate over all prime numbers less than a given value.Again, use a separate
 *  headerand source file.
 */

class PrimeNumberRange {
public:
    explicit PrimeNumberRange(int n)
    {
        if (n < 2)
            m_current = -1;
        else {

            m_capacity = n;
            m_current = 2;
        }
    }

    int getCurrent() const {

        return m_current;
    }

    int next() {

        int i{};
        for (i = m_current + 1; i <= m_capacity; ++i) {

            bool flag{ true };
            for (int j{ 2 }; j < i; ++j)

                if (i % j == 0) {

                    flag = 0;
                    break;
                }

            if (flag) {

                m_current = i;
                break;
            }
        }

        if (m_capacity < i)
            m_current = -1;

        return m_current;
    }

    int operator++() {

        return next();
    }

private:
    std::size_t m_capacity{};
    std::size_t m_current{};
};

#endif // PRIMENUMBERRANGE_H