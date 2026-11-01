#include <iostream>
#include <vector>

using namespace std;

// Base interface: All accounts support deposit
class DepositOnlyAccount {
public:
    virtual void deposit(double amount) = 0;
    virtual ~DepositOnlyAccount() = default;
};

// Sub-interface: Only accounts that support withdrawal inherit this
class WithdrawableAccount : public DepositOnlyAccount {
public:
    virtual void withdraw(double amount) = 0;
};

class SavingAccount : public WithdrawableAccount {
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

class CurrentAccount : public WithdrawableAccount {
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

// FixedTermAccount only inherits DepositOnlyAccount (respects LSP)
class FixedTermAccount : public DepositOnlyAccount {
private:
    double balance;

public:
    FixedTermAccount() : balance(0) {}

    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited: " << amount << " in Fixed Term Account. New Balance: " << balance << endl;
    }
};

// Client function: Only accepts accounts that genuinely support withdrawal
void makeWithdrawal(WithdrawableAccount& acc, double amount) {
    acc.withdraw(amount);
}

int main() {
    SavingAccount saving;
    CurrentAccount current;
    FixedTermAccount fixedTerm;

    // 1. All accounts can deposit
    vector<DepositOnlyAccount*> accounts = { &saving, &current, &fixedTerm };
    for (auto acc : accounts) {
        acc->deposit(1000);
    }

    // 2. Only withdrawable accounts can withdraw
    makeWithdrawal(saving, 500);
    makeWithdrawal(current, 500);

    // makeWithdrawal(fixedTerm, 500); // ❌ Compile error: prevents runtime crash!

    return 0;
}
