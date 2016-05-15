#include <iostream>
using namespace std;

class Account {
public:
	Account(double money);  // constructor
	void credit(double money); // to save some money in accountBalance
	bool debit(double money);  // to withdraw some money in accountBalance
	double getBalance();       // obtain the accountBalance via method
private:
	double accountBalance;
};

