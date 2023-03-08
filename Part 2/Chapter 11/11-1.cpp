#include <cstdio>
#include <memory>

/* 
 * Reimplement Listing 11-13 to use a std::shared_ptr rather than a
 * std::unique_ptr. Notice that although you’ve relaxed the ownership require-
 * ments from exclusive to non-exclusive, you’re still transferring ownership
 * to the say_hello function.
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
    // File closed here
    return 0;
}