#include "Bank.h"

int main() {
    Account account1 (0);
    cout << "Account created: " << endl << account1 << endl;

    account1.deposit(1000);
    cout << "Deposit 1000 RON: " << endl;
    cout << account1 << endl;

    cout << "Withdraw 500 RON: " << endl;
    account1.withdraw(500);
    cout << account1 << endl;

    cout << "Withdraw 1000 RON: " << endl;
    account1.withdraw(1000);
    cout << account1 << endl;

    Customer customer1("Black", "Jones");
    customer1.newAccount(0);
    customer1.newAccount(1000);
    cout << customer1;

    Bank bank("OTP bank");
    bank.loadCustomers("customers.txt");
    bank.printCustomers();

    bank.getCustomer(2).newAccount(0);
    bank.getCustomer(2).newAccount(1000);
    bank.getCustomer(3).newAccount(3453);
    bank.getCustomer(3).newAccount(3566);
    bank.getCustomer(4).newAccount(342);
    bank.getCustomer(5).newAccount(700);

    bank.printCustomersAndAccounts();
}
