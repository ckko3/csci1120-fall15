#include <iostream>
//#include "Account.h"
//#include "SavingsAccount.h"
#include "CheckingAccount.h"
using namespace std;

/*int main() {  // test the Account superclass
	
	Account consumerAccount(2);
	cout << "accountBalance " << consumerAccount.getBalance() << endl;
	return 0;

	consumerAccount.credit(4);
	cout << "accountBalance " << consumerAccount.getBalance() << endl;
	consumerAccount.debit(5);
	cout << "accountBalance " << consumerAccount.getBalance() << endl;
	return 0;*/
/*
int main() {  // test the subclass of savingsAccount

	SavingsAccount savingsAccount(1.2, 10);
	cout << "interest: " << savingsAccount.calculateInterest() << endl;
	savingsAccount.credit(5);
	cout << "accountBalance " << savingsAccount.getBalance() << endl;
	savingsAccount.debit(1);
	cout << "accountBalance " << savingsAccount.getBalance() << endl;
	cout << "interest: " << savingsAccount.calculateInterest() << endl;

	return 0;*/

int main() {  // test the subclass of checkingAcount

	CheckingAccount checkingAcount(1.2, 0.5);
	cout << "accountBalance " << checkingAcount.getBalance() << endl;
	checkingAcount.credit(0.8);
	cout << "accountBalance " << checkingAcount.getBalance() << endl;
	checkingAcount.debit(5);
	cout << "accountBalance " << checkingAcount.getBalance() << endl;
	checkingAcount.credit(3);
	cout << "accountBalance " << checkingAcount.getBalance() << endl;
	checkingAcount.debit(2);
	cout << "accountBalance " << checkingAcount.getBalance() << endl;

	return 0;
}

