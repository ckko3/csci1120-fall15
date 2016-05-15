#include <iostream>
#include "Account.h"
using namespace std;

class CheckingAccount:public Account{
public:
	CheckingAccount(double money, double fee);  // constructor for CheckingAccount
	void credit(double money);         // redefine the credit member function in the superclass
	bool debit(double money);          // redefine the debit member function in the superclass
	
private:
	double feePerTrans;                         // new data member
};

