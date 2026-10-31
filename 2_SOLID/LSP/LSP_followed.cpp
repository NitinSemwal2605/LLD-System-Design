#include <iostream>
#include <vector>

using namespace std;

// 1. Base Interface: Every account can receive deposits
class DepositOnlyAccount {
public:
    virtual void deposit(double amount) = 0;
    virtual ~DepositOnlyAccount() = default;
};

// 2. Sub-Interface: Only withdrawable accounts support withdrawals
class WithdrawableAccount : public DepositOnlyAccount {
public:
    virtual void withdraw(double amount) = 0;
};

// --- Concrete Account Implementations ---

class SavingAccount : public WithdrawableAccount {
private:
    double balance = 0;

public:
    void deposit(double amount) override {
        balance += amount;
        cout << "Savings Account: Deposited " << amount << ", Balance: " << balance << endl;
    }

    void withdraw(double amount) override {
        if (balance >= amount) {
            balance -= amount;
            cout << "Savings Account: Withdrew " << amount << ", Balance: " << balance << endl;
        } else {
            cout << "Savings Account: Insufficient funds!\n";
        }
    }
};

class CurrentAccount : public WithdrawableAccount {
private:
    double balance = 0;

public:
    void deposit(double amount) override {
        balance += amount;
        cout << "Current Account: Deposited " << amount << ", Balance: " << balance << endl;
    }

    void withdraw(double amount) override {
        if (balance >= amount) {
            balance -= amount;
            cout << "Current Account: Withdrew " << amount << ", Balance: " << balance << endl;
        } else {
            cout << "Current Account: Insufficient funds!\n";
        }
    }
};

class FixedTermAccount : public DepositOnlyAccount {
private:
    double balance = 0;

public:
    void deposit(double amount) override {
        balance += amount;
        cout << "Fixed Term Account: Deposited " << amount << ", Balance: " << balance << endl;
    }
    // No withdraw() method here — respects LSP by not promising what it cannot deliver
};

// Client function demonstrating LSP:
// Any WithdrawableAccount can be safely substituted here without runtime errors.
void processWithdrawal(WithdrawableAccount* acc, double amount) {
    acc->withdraw(amount);
}

int main() {
    SavingAccount saving;
    CurrentAccount current;
    FixedTermAccount fixedTerm;

    // 1. Deposit into ALL accounts (all are substitutable for DepositOnlyAccount)
    vector<DepositOnlyAccount*> allAccounts = { &saving, &current, &fixedTerm };
    for (DepositOnlyAccount* acc : allAccounts) {
        acc->deposit(1000);
    }

    cout << endl;

    // 2. Withdraw from accounts that actually support withdrawal
    vector<WithdrawableAccount*> withdrawableAccounts = { &saving, &current };
    for (WithdrawableAccount* acc : withdrawableAccounts) {
        processWithdrawal(acc, 500);
    }

    // FixedTermAccount cannot be added to withdrawableAccounts or passed to processWithdrawal.
    // processWithdrawal(&fixedTerm, 500); // ❌ Compile-time error! (Prevents runtime bugs)

    return 0;
}
