#include <iostream>
#include <stdexcept>

class Account {
public:
    Account()
       : m_balance{0.0} { }

    explicit Account(const double amount)
       : m_balance{amount} { }

    virtual ~Account() = default;

    virtual void deposit(const double amount) {

        if(amount <= 0)
            throw std::runtime_error{ "deposit(const double amount): Cannot deposit. Amount must be at least 1." };

        m_balance += amount;
    }

    virtual void withdraw(const double amount) {

        if(m_balance >= amount) {

            m_balance -= amount;
        }
        else {

            throw std::runtime_error{ "withdraw(const double amount): Cannot withdraw. amount be less then the current balance." };
        }
    }

    virtual void printBalance() const {

        std::cout << "Current balance: $" << m_balance << '\n';
    }

protected:
    double m_balance;
};

class CheckingAccount : public Account {
public:
    CheckingAccount() : Account() { }
    explicit CheckingAccount(const double amount) : Account(amount) 
    { }
};

class SavingsAccount : public Account {
public:
    SavingsAccount() : Account() { }
    SavingsAccount(const double amount) : Account(amount)
    { }
};

class Bank {
public:
    template <typename account1, typename account2>
    void make_transfer(account1 &from, account2 &to, const double amount) {

        from.withdraw(amount);
        to.deposit(amount);
    }
};

int main() {

    try {

        Bank bank{};

        CheckingAccount account1{1234.50};
        SavingsAccount account2{500.00};

        bank.make_transfer(account1, account2, 100.00);

        account1.printBalance();
        account2.printBalance();

    }
    catch(const std::runtime_error &e) {

        std::cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {

        std::cerr << "unknown exception caught\n";
        return 2;
    }

    return 0;
}