#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Account {
    string userId;
    string password;
    double balance;
};

void createAccount(vector<Account>& accounts) {
    string userId, password;

    cout << "Please enter your user id: ";
    cin >> userId;

    cout << "Please enter your password: ";
    cin >> password;

    Account newAccount;
    newAccount.userId = userId;
    newAccount.password = password;
    newAccount.balance = 0.0;
    accounts.push_back(newAccount);

    cout << "Thank You! Your account has been created!" << endl;
}

int login(vector<Account>& accounts) {
    string userId, password;

    cout << "Please enter your user id: ";
    cin >> userId;

    cout << "Please enter your password: ";
    cin >> password;

    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].userId == userId && accounts[i].password == password) {
            return i; 
        }
    }

    cout << "*** LOGIN FAILED! ***" << endl;
    return -1; 
}

void withdraw(vector<Account>& accounts, int accountIndex) {
    double amount;

    cout << "Amount of withdrawal: $";
    cin >> amount;

    if (accounts[accountIndex].balance >= amount) {
        accounts[accountIndex].balance -= amount;
        cout << "Withdrawal successful." << endl;
    } else {
        cout << "Insufficient funds." << endl;
    }
}

void deposit(vector<Account>& accounts, int accountIndex) {
    double amount;

    cout << "Amount of deposit: $";
    cin >> amount;

    accounts[accountIndex].balance += amount;
    cout << "Deposit successful." << endl;
}

void requestBalance(const vector<Account>& accounts, int accountIndex) {
    cout << "Your balance is $" << accounts[accountIndex].balance << endl;
}

int main() {
    vector<Account> accounts;

    while (true) {
        cout << "Hi! Welcome to the ATM Machine!" << endl;
        cout << "Please select an option from the menu below:" << endl;
        cout << "l -> Login" << endl;
        cout << "c -> Create New Account" << endl;
        cout << "q -> Quit" << endl;

        char choice;
        cin >> choice;

        if (choice == 'l') {
            int accountIndex = login(accounts);
            if (accountIndex != -1) {
                while (true) {
                    cout << "Access Granted!" << endl;
                    cout << "d -> Deposit Money" << endl;
                    cout << "w -> Withdraw Money" << endl;
                    cout << "r -> Request Balance" << endl;
                    cout << "q -> Quit" << endl;

                    cin >> choice;

                    if (choice == 'd') {
                        deposit(accounts, accountIndex);
                    } else if (choice == 'w') {
                        withdraw(accounts, accountIndex);
                    } else if (choice == 'r') {
                        requestBalance(accounts, accountIndex);
                    } else if (choice == 'q') {
                        break;
                    } else {
                        cout << "Invalid choice. Please try again." << endl;
                    }
                }
            }
        } else if (choice == 'c') {
            createAccount(accounts);
        } else if (choice == 'q') {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

