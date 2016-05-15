#include <iostream>
#include "Account.h"
using namespace std;

Account::Account(double money) {
	Account::accountBalance = money;
	if (Account::accountBalance < 0) {  // justify the initial balance
		Account::accountBalance = 0;
		cout << "The initial balance was invalid." << endl; // output error message
	}
}

void Account::credit(double money) {
	Account::accountBalance = Account::accountBalance + money;  // add amount of money
}

bool Account::debit(double money) {
	if (Account::accountBalance < money) {                // justify the withdraw amount
		cout << "Debit amount exceeded account balancce." << endl; // output error message
		return false;
	}
	else {
		Account::accountBalance = Account::accountBalance - money;  // subtract the amount
		return true;
	}	
}

double Account::getBalance() {
	return Account::accountBalance;
}
