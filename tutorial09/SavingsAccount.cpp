#include <iostream>
#include "SavingsAccount.h"
using namespace std;

SavingsAccount::SavingsAccount(double money, double rate):Account(money){
	SavingsAccount::interestRate = rate;                     // constructor and initialize the interest rate
}

double SavingsAccount::calculateInterest() {
	return getBalance() * SavingsAccount::interestRate / 100;  // calculate the interest
}

