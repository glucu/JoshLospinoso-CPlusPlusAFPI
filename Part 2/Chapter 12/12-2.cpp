#include <iostream>
#include <random>
#include <string>

int main() {

    const char alphabet[]{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789" };
    const int alphabet_size{ sizeof(alphabet) - 1 };
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, alphabet_size - 1);
    constexpr int password_length = 12;
    std::string password;
    password.reserve(password_length);
    for (int i{}; i != password_length; ++i) {
        password += alphabet[dis(gen)];
    }

    std::cout << "Password: " << password << '\n';
    
    return 0;
}
