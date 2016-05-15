#include <iostream>
#include "Account.h"
using namespace std;

class SavingsAccount:public Account{
public:
	SavingsAccount(double money, double rate);  // constructor for SavingsAccount
	double calculateInterest();                 // new member function 
private:
	double interestRate;                        // new private data member
};

