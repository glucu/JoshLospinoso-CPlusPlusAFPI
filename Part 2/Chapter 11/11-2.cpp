#include <cstdio>
#include <memory>

/* 
 *  Remove the std::move from the call to say_hello. Then make an addi-
 *  tional call to say_hello. Notice that the ownership of file_guard is no longer
 *  transferred to say_hello. This permits multiple calls.
 */

// using FileGuard = std::unique_ptr<FILE, int(*)(FILE*)>;
using FileGuard = std::shared_ptr<FILE>;

void say_hello(FileGuard file) {
    fprintf(file.get(), "HELLO DAVE");
}

int main() {

    auto file = fopen("HAL9000", "w");
    if (!file) return 1;
    FileGuard file_guard{ file, fclose };
    // File open here
    say_hello(file_guard);
    say_hello(file_guard);
    // File closed here
    return 0;
}