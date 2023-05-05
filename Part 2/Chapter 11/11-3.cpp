#include <cstdio>
#include <memory>

/*
 *   Implement a Hal class that accepts a std::shared_ptr<FILE> in its con-
 *   structor. In Hal’s destructor, write the phrase Stop, Dave. to the file handle held
 *   by your shared pointer. Implement a write_status function that writes the phrase
 *   I'm completely operational. to the file handle. Here’s a class declaration you
 *   can work from:
 */

struct Hal {
public:
	explicit Hal(std::shared_ptr<std::FILE> file)
		: m_file{ file } { }

	~Hal() {
		fprintf(m_file.get(), "Stop, Dave.\n");
	}

	void write_status() {
		fprintf(m_file.get(), "I'm completely operational.\n");
	}

private:
	const std::shared_ptr<std::FILE> m_file;
};


int main() {

	auto file = std::shared_ptr<std::FILE>(std::fopen("HAL9000", "w"), std::fclose);
	Hal hal1{ file }, hal2{ file }, hal3{ file };

	hal1.write_status();
	hal2.write_status();
	hal3.write_status();

	return 0;
}