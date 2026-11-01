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

class BankClient {
private:
    vector<Account*> accounts;

public:
    BankClient(const vector<Account*>& accounts) : accounts(accounts) {}

    void processTransactions() {
        for (Account* acc : accounts) {
            acc->deposit(1000);

            // Expects every account to withdraw safely; crashes on FixedTermAccount
            try {
                acc->withdraw(500);
            } catch (const logic_error& e) {
                cout << "Exception caught: " << e.what() << endl;
            }
        }
    }
};

int main() {
    SavingAccount saving;
    CurrentAccount current;
    FixedTermAccount fixedTerm;

    vector<Account*> accounts = { &saving, &current, &fixedTerm };

    BankClient client(accounts);
    client.processTransactions();

    return 0;
}
