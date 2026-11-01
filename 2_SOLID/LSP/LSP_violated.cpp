#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Account {
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual ~Account() = default;
};

class SavingAccount : public Account {
private:
    double balance;

public:
    SavingAccount() : balance(0) {}

    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited: " << amount << " in Savings Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) override {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from Savings Account. New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in Savings Account!\n";
        }
    }
};

class CurrentAccount : public Account {
private:
    double balance;

public:
    CurrentAccount() : balance(0) {}

    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited: " << amount << " in Current Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) override {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from Current Account. New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in Current Account!\n";
        }
    }
};

// Violating LSP: FixedTermAccount cannot support withdrawal and throws an exception
class FixedTermAccount : public Account {
private:
    double balance;

public:
    FixedTermAccount() : balance(0) {}

    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited: " << amount << " in Fixed Term Account. New Balance: " << balance << endl;
    }

    // Violating LSP: Breaks base class contract
    void withdraw(double amount) override {
        throw logic_error("Withdrawal not allowed in Fixed Term Account!");
    }
};

// Client function: Expects all Accounts can safely withdraw
void makeWithdrawal(Account& acc, double amount) {
    acc.withdraw(amount);
}

int main() {
    SavingAccount saving;
    CurrentAccount current;
    FixedTermAccount fixedTerm;

    // 1. All accounts can deposit
    vector<Account*> accounts = { &saving, &current, &fixedTerm };
    for (auto acc : accounts) {
        acc->deposit(1000);
    }

    // 2. Withdraw from accounts
    makeWithdrawal(saving, 500);
    makeWithdrawal(current, 500);

    // Violating LSP: Compiles fine, but crashes at runtime!
    try {
        makeWithdrawal(fixedTerm, 500);
    } catch (const logic_error& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}
