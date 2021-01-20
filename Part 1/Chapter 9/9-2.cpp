#include <iostream>

/*  Implement a program that accepts an arbitrary number of command line
 *  arguments, m_counts the m_length in characters of each argument, and prints a
 *  histogram of the argument m_length distribution.
 */

class Characterm_length {
public:
	Characterm_length(int max)
		: m_counts{ new int[max] },
		  m_length{ max }
	{ }

	~Characterm_length() {

		if (m_counts)
			delete[] m_counts;
	}

	void count_m_length(const char* x) const;
	friend std::ostream& operator<<(std::ostream& out, const Characterm_length& a);

private:
	int* m_counts{};
	int  m_length{};

};

void Characterm_length::count_m_length(const char* x) const {

	int index{ };

	int m_length_count{ };

	static int i{ };

	char c{ };
	c = x[0];
	while (c != '\0') {

		m_length_count++;

		index++;

		c = x[index];
	}

	this->m_counts[i++] = m_length_count;
}

std::ostream& operator<<(std::ostream& out, const Characterm_length& a) {

	for (int i{}; i < a.m_length; ++i)
		out << "m_length: " << a.m_counts[i] << '\n';

	return out;
}

int main(int argc, char** argv) {

	Characterm_length a{ argc - 2 };

	for (int i{ 2 }; i < argc; ++i){
		
		a.count_m_length(argv[i]);
	}

	std::cout << a;

	return 0;
}