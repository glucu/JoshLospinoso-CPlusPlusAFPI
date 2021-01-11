#include <iostream>
#include <exception>

/*  Add an AccountDatabase reference member to Bank. Use constructor injection to add an InMemoryAccountDatabase to the Bank.
 *  Modify ConsoleLogger to accept a const char* at construction. When
 *  ConsoleLogger logs, prepend this string to the logging output. 
 *  Notice that you can modify logging behavior without having to modify Bank
 */

class Logger {
public:
    virtual ~Logger() = default;
    virtual void log_transfer(long from, long to, double amount) = 0;
};

class ConsoleLogger : public Logger {
public:
    ConsoleLogger(const char *str)
            : m_string_to_add{ str } { }

    ConsoleLogger(const ConsoleLogger& other) = default;
    ConsoleLogger& operator=(const ConsoleLogger& other) = default;

    virtual void log_transfer(long from, long to, double amount) override {

        std::cout << m_string_to_add << "[cons] " << from << " -> " << to << ":" << amount << "\n";
    }

private:
    const char *m_string_to_add;
};

class FileLogger : public Logger {
public:
    virtual void log_transfer(long from, long to, double amount) override {

        std::cout << "[file]" << from << " " << to << " " << amount << "\n";
    }
};

class AccountDatabase {
public:
    virtual ~AccountDatabase() = default;
    virtual void retrieve_and_set(long from, long to, double amount) = 0;
};

class InMemoryAccountDatabase : public AccountDatabase {
public:
    virtual void retrieve_and_set(long from, long to, double amount) override {

        std::cout << "DEBIT Account ID : " << from << " " << amount << "\n"
                  << "CREDIT Account ID: " << to << " " << amount << "\n";
    }
};

class Bank {
public:
    Bank(InMemoryAccountDatabase &accD)
            : logger{nullptr},
              accDatabase{ accD } { }

    void set_logger(Logger *new_logger) {

        logger = new_logger;
    }
    void make_transfer(long from, long to, double amount) {

        if(logger)
            logger->log_transfer(from, to, amount);

        accDatabase.retrieve_and_set(from, to, amount);
    }

private:
    Logger *logger;
    InMemoryAccountDatabase &accDatabase;
};

int main() {

    try {

        ConsoleLogger console_logger{ "" };
        FileLogger file_logger;
        InMemoryAccountDatabase bankAccounts;
        Bank bank{ bankAccounts };

        bank.set_logger(&console_logger);
        bank.make_transfer(1000, 2000, 49.95);

        std::cout << '\n';

        bank.set_logger(&file_logger);
        bank.make_transfer(2000, 4000, 20.00);
    }
    catch(const std::exception &e) {

        std::cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {

        std::cerr << "unknown exception caught\n";
        return 2;
    }
    
    return 0;
}