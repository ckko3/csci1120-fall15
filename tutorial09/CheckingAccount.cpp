#include <iostream>
#include "CheckingAccount.h"
using namespace std;

CheckingAccount::CheckingAccount(double money, double fee):Account(money) {
	CheckingAccount::feePerTrans = fee;                                  // constructor and initialize the fee
}

void CheckingAccount::credit(double money) {                    // redefine the credit function
	Account::credit(money - CheckingAccount::feePerTrans);
}

bool CheckingAccount::debit(double money) {                     // redefine the debit function
	if (Account::debit(money)) {
		Account::debit(CheckingAccount::feePerTrans);
		return true;
	}	
	else {
		return false;
	}
}

// debit(money + CheckingAccount::feePerTrans);
 