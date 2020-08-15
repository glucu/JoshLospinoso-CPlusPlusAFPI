#include <iostream>

/* Generate an InMemoryAccountDatabase that implements AccountDatabase */

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