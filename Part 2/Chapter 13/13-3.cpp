#include <iostream>
#include <cstring>
#include <set>
#include <functional>

/*
 * Write a program that accepts any number of command line arguments
 * and prints them in alphanumerically sorted order. Use a std::set<const char*>
 * to store the elements, then iterate over the set to obtain the sorted result. You’ll
 * need to implement a custom comparator that compares two C-style strings.
 */

bool compare_string(const char* lhs, const char* rhs) {
	return std::strcmp(lhs, rhs) < 0;
}

int main(int argc, const char** argv) {

	if (argc < 3) {
		std::cerr << "Nothing to sort.\n";
		return 0;
	}
	std::set<const char*, std::function<bool(const char*, const char*)>> data(compare_string);
	for (std::size_t i{ 1 }; i != argc; ++i) {
		data.insert(argv[i]);
	}

	for (const auto& elem : data) {
		std::cout << elem << ' ';
	}

	return 0;
}