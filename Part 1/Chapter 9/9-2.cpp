#include <iostream>

/* Implement a program that accepts an arbitrary number of command line
   arguments, counts the length in characters of each argument, and prints a
   histogram of the argument length distribution.
*/

class CharacterLength
{
public:
	CharacterLength(int max)
		: counts{ new int[max] },
		length{ max }
	{ }

	~CharacterLength()
	{
		if (counts)
			delete[] counts;
	}

	void count_length(const char* x) const;
	void print() const;

private:
	int* counts{};
	int length{};

};

void CharacterLength::count_length(const char* x) const
{
	int index{ };

	int length_count{ };

	static int i{ };

	char c{};
	c = x[0];
	while (c != '\0')
	{
		length_count++;

		index++;

		c = x[index];
	}

	this->counts[i++] = length_count;
}

void CharacterLength::print() const
{
	for (int i{}; i < length; ++i)
	{
		std::cout << "Length: " << counts[i] << '\n';
	}
}


int main(int argc, char** argv)
{
	CharacterLength a{ argc - 2 };

	for (int i{ 2 }; i < argc; ++i)
	{
		a.count_length(argv[i]);
	}

	a.print();

	return 0;
}