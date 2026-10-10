#include <iostream>
#include <string>

class BankAccount {
private:
    // Data is hidden (private)
    std::string accountNumber;
    double balance;

public:
    // Constructor to initialize the account
    BankAccount(std::string accNum, double initialBalance) {
        accountNumber = accNum;
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            balance = 0.0;
            std::cout << "Initial balance cannot be negative. Set to $0.00.\n";
        }
    }

    // Getter method for controlled read access
    double getBalance() const {
        return balance;
    }

    // Controlled write access for deposits
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Successfully deposited $" << amount << ".\n";
        } else {
            std::cout << "Deposit amount must be positive!\n";
        }
    }

    // Controlled write access for withdrawals with validation logic
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Successfully withdrew $" << amount << ".\n";
        } else {
            std::cout << "Invalid withdrawal amount or insufficient funds!\n";
        }
    }
};

int main() {
    BankAccount myAccount("ACC98765", 1000.0);

    // Direct access is blocked by the compiler:
    // myAccount.balance = 50000.0; // Error: 'balance' is private!

    // Interaction happens exclusively through public methods
    myAccount.deposit(250.0);
    myAccount.withdraw(400.0);

    // Read the balance safely using the getter
    std::cout << "Current Balance: $" << myAccount.getBalance() << "\n";

    return 0;
}