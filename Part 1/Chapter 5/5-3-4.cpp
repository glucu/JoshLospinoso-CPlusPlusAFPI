#include <iostream>

/*  Add an AccountDatabase reference member to Bank. Use constructor injection to add an InMemoryAccountDatabase to the Bank.
 *  Modify ConsoleLogger to accept a const char* at construction. When
 *  ConsoleLogger logs, prepend this string to the logging output. 
 *  Notice that you can modify logging behavior without having to modify Bank
 */

struct Logger
{
    virtual ~Logger() = default;
    virtual void log_transfer(long from, long to, double amount) = 0;
};

struct ConsoleLogger : Logger
{
    ConsoleLogger(const char *str)
            : m_string_to_add{ str } { }

    ConsoleLogger(const ConsoleLogger& other) = default;
    ConsoleLogger& operator=(const ConsoleLogger& other) = default;

    virtual void log_transfer(long from, long to, double amount) override
    {
        std::cout << m_string_to_add << " [cons] " << from << " -> " << to << ":" << amount << "\n";
    }

private:
    const char *m_string_to_add;
};

struct FileLogger : Logger
{
    virtual void log_transfer(long from, long to, double amount) override
    {
        std::cout << "[file]" << from << " " << to << " " << amount << "\n";
    }
};

struct AccountDatabase
{
    virtual ~AccountDatabase() = default;
    virtual void retrieve_and_set(long from, long to, double amount) = 0;
};

struct InMemoryAccountDatabase : AccountDatabase
{
    virtual void retrieve_and_set(long from, long to, double amount) override
    {
        std::cout << "DEBIT Account ID: " << from << " " << amount << "\n"
                  << "CREDIT Account ID: " << to << " " << amount << "\n";
    }
};

struct Bank
{
public:
    Bank(InMemoryAccountDatabase& accD)
            : accDatabase{ accD } { }

    void set_logger(Logger *new_logger)
    {
        logger = new_logger;
    }
    void make_transfer(long from, long to, double amount)
    {
        if(logger)
            logger->log_transfer(from, to, amount);

        accDatabase.retrieve_and_set(from, to, amount);
    }

private:
    Logger* logger{};
    InMemoryAccountDatabase& accDatabase;
};

int main()
{
    ConsoleLogger console_logger{ "" };
    FileLogger file_logger;
    InMemoryAccountDatabase bankAccounts;
    Bank bank{ bankAccounts };

    bank.set_logger(&console_logger);
    bank.make_transfer(1000, 2000, 49.95);
    bank.set_logger(&file_logger);
    bank.make_transfer(2000, 4000, 20.00);
    
    return 0;
}