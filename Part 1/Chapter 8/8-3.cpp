#include <iostream>

/* Integrate PrimeNumberRange into Listing 8-27, adding another loop that
   generates all prime numbers less than 5,000.
*/

struct FibonacciIterator {

	bool operator!=(int x) const {
		return x >= current;
	}

	FibonacciIterator& operator++() {

		const auto tmp = current;
		current += last;
		last = tmp;
		return *this;
	}

	int operator*() const {

		return current;
	}

private:
	int current{ 1 }, last{ 1 };
};

struct FibonacciRange {

	explicit FibonacciRange(int max) : max{ max } { }

	FibonacciIterator begin() const {

		return FibonacciIterator{};
	}

	int end() const {

		return max;
	}

private:
	const int max;
};

class PrimeNumberRange
{

public:
    explicit PrimeNumberRange(int n)
    {
        if (n < 2)
            m_current = -1;
        else
        {
            m_capacity = n;
            m_current = 2;
        }
    }

    int getCurrent() const
    {
        return m_current;
    }

    int next()
    {
        int i;
        for (i = m_current + 1; i <= m_capacity; ++i)
        {
            bool flag{ true };
            for (int j = 2; j < i; j++)
                if (i % j == 0)
                {
                    flag = 0;
                    break;
                }

            if (flag)
            {
                m_current = i;
                break;
            }
        }

        if (m_capacity < i)
            m_current = -1;

        return m_current;
    }

    int operator++()
    {
        return next();
    }

private:
    int m_capacity{};
    int m_current{};
};

int main()
{
	std::cout << "Fibonacci: ";
	for (const auto i : FibonacciRange{ 5000 }) 
	{
		std::cout << i << ' ';
	}

	std::cout << "\n\n";


	PrimeNumberRange prime{ 5000 };

	std::cout << "Prime: ";
	std::cout << prime.getCurrent() << ' ';

	while (true)
	{
		int n = ++prime;
		if (n < 0)
			return true;

		std::cout << n << ' ';
	}

    return 0;
}