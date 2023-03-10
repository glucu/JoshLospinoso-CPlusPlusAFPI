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
    Hal(std::shared_ptr<FILE> file);
    ~Hal();
    
    void write_status();

    std::shared_ptr<FILE> file;
};

Hal::Hal(std::shared_ptr<FILE> file)
    : file{file} { }

Hal::~Hal() {
    fprintf(file.get(), "Stop, Dave.\n");
}

void Hal::write_status() {
    fprintf(file.get(), "I'm completely operational.\n");
}


int main() {
    
    auto file_ptr{ std::shared_ptr<FILE>(std::fopen("output.txt", "w"), std::fclose) };
    Hal hal1{file_ptr}, hal2{file_ptr}, hal3{file_ptr};
    hal1.write_status();
    hal2.write_status();
    hal3.write_status();

    return 0;
}