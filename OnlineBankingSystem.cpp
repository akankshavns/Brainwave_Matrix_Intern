#include <iostream>
#include <unordered_map>
using namespace std;

// Account structure with constructor
struct Account 
{
    string Name;
    int PIN;
    double balance;

    // Constructor for easy initialization
    Account(string n = "", int p = 0, double b = 0.0)
        : Name(n), PIN(p), balance(b) {}
};

class BankSystem
{
private:
    unordered_map<string, Account> accounts; 
    int pin, EnteredPin;
    string userName, name;
    double TotalBalance = 500.67;

public:
    // Create Account
    void createAccount() {
        cout << "Enter a username: ";
        cin >> userName;
        if (accounts.find(userName) != accounts.end()) {
            cout << "Username already exists! Try another.\n";
            return;
        }

        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Please Enter your 4-digit PIN: ";
        cin >> pin;

        if (pin >= 1000 && pin <= 9999) {
            cout << "\nAccount created successfully\n";
            accounts[userName] = Account(name, pin, 0.0);  // Corrected Initialization
        } else {
            cout << "\nPlease Enter a valid 4-digit PIN\n";
        }
    }

    // Login Method
    bool login(string& username) {
        cout << "Enter username: ";
        cin >> username;

        if (accounts.find(username) == accounts.end()) {
            cout << "Account not found!\n";
            return false;
        }

        cout << "Enter PIN: ";
        cin >> EnteredPin;

        if (accounts[username].PIN != EnteredPin) {
            cout << "Incorrect PIN!\n";
            return false;
        }

        cout << "Login successful! Welcome, " << accounts[username].Name << "\n";
        return true;
    }

    // Change PIN
    void changePin(string userName) {
        int NewPin, OldPin;

        cout << "Enter your old PIN: ";
        cin >> OldPin;

        if (accounts[userName].PIN == OldPin) {
            cout << "Enter your new 4-digit PIN: ";
            cin >> NewPin;

            if (NewPin >= 1000 && NewPin <= 9999) {
                accounts[userName].PIN = NewPin;
                cout << "\nPIN changed successfully!\n";
            } else {
                cout << "\nPlease enter a valid 4-digit PIN\n";
            }
        } else {
            cout << "\nIncorrect PIN! Please enter the correct old PIN to reset.\n";
        }
    }

    // Withdraw Money
    void withdrawMoney(string userName) {
        int Amount;

        cout << "Enter your 4-digit PIN number: ";
        cin >> EnteredPin;

        if (accounts[userName].PIN != EnteredPin) {
            cout << "\nIncorrect PIN! Please enter the correct PIN\n";
        } else {
            cout << "Enter withdrawal amount: ";
            cin >> Amount;

            if (Amount <= 0) {
                cout << "\nInvalid amount. Please enter a valid withdrawal amount.\n";
            } else if (accounts[userName].balance >= Amount) {
                accounts[userName].balance -= Amount;
                cout << "\nWithdrawal successful! Your new balance: $" << accounts[userName].balance << endl;
            } else {
                cout << "\nInsufficient funds! Your current balance is: $" << accounts[userName].balance << endl;
            }
        }
    }

    // Deposit Money
    void depositMoney(string username, double depositAmount) {
        cout << "Enter your 4-digit PIN number: ";
        cin >> EnteredPin;

        if (accounts[username].PIN == EnteredPin) {
            accounts[username].balance += depositAmount;
            cout << "\nBalance credited successfully! Your new balance: $" << accounts[username].balance << endl;
        } else {
            cout << "\nIncorrect PIN! Access denied. Please enter the correct PIN\n";
        }
    }

    void transfer(string username) {
        string recipient;
        double amount;
        cout << "Enter recipient's username: ";
        cin >> recipient;
        if (accounts.find(recipient) == accounts.end()) {
            cout << "Recipient not found!\n";
            return;
        }
        cout << "Enter amount to transfer: ";
        cin >> amount;
        if (amount > accounts[username].balance) {
            cout << "Insufficient balance!\n";
            return;
        }
        accounts[username].balance -= amount;
        accounts[recipient].balance += amount;
        cout << "Transfer successful! Your new balance: $" << accounts[username].balance << "\n";
    }

    // Balance Enquiry
    void BalanceEnquiry(string userName) {
        cout << "Enter your 4-digit PIN number: ";
        cin >> EnteredPin;

        if (accounts[userName].PIN == EnteredPin) {
            cout << "\nYour Total Balance is: $" << accounts[userName].balance << endl;
        } else {
            cout << "\nIncorrect PIN! Access denied. Please enter the correct PIN\n";
        }
    }
};

int main() {
    int option;
    string userName;
    BankSystem obj;

    do {
        cout << "\nChoose Your Option\n";
        cout << "1. Create Account.\n";
        cout << "2. Login Account.\n";
        cout << "3. Exit.\n";
        cout << "Enter your option: ";
        cin >> option;

        switch (option) {
            case 1:
                obj.createAccount();
                break;

            case 2:
                if (obj.login(userName)) {
                    do {
                        cout << "\nChoose Your Option\n";
                        cout << "1. Change PIN.\n";
                        cout << "2. Withdraw Money.\n";
                        cout << "3. Deposit Money.\n";
                        cout << "4. Check Balance.\n";
                        cout << "5. Transfer Monery.\n";
                        cout << "6. Exit.\n";
                        cout << "Enter your option: ";
                        cin >> option;

                        switch (option) {
                            case 1:
                                obj.changePin(userName);
                                break;
                            case 2:
                                obj.withdrawMoney(userName);
                                break;
                            case 3:
                                double DepositAmount;
                                cout << "Enter the amount for deposit: ";
                                cin >> DepositAmount;
                                if (DepositAmount <= 0) {
                                    cout << "Invalid Amount\n";
                                } else {
                                    obj.depositMoney(userName, DepositAmount);
                                }
                                break;
                            case 4:
                                obj.BalanceEnquiry(userName);
                                break;
                            case 5 :
                                obj.transfer(userName);
                                break;
                            case 6:
                                cout << "\nThank you for using the Online Banking System. Goodbye!\n";
                                break;
                            default:
                                cout << "\nInvalid Option! Please choose a valid option.\n";
                                break;
                        }
                    } while (option != 6);
                }
                break;

            case 3:
                cout << "Thank you for using Online Banking!\n";
                break;

            default:
                cout << "\nInvalid Option! Please choose a valid option.\n";
                break;
        }

    } while (option != 3);

    return 0;
}
