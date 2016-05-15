/*	CSCI1120
 *
 *	Assignment:	1
 *	Student ID: 1155033234
 *	Name	  : Ko Chi Keung
 *	e-mail adr: kck.keung@link.cuhk.edu.hk
 */

#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

int march, april = 0;

//declare foo
void foo(int year){

	int a, b, c, d, e, f, g, h, i, k, m, l, month, day;

	//calculation
	a = year % 19;
	b = (int)floor(year / 100);
	c = year % 100;
	d = (int)floor(b / 4);
	e = b % 4;
	f = (int)floor((b + 8) / 25);
	g = (int)floor((b - f + 1) / 3);
	h = (19 * a + b - d - g + 15) % 30;
	i = (int)floor(c / 4);
	k = c % 4;
	l = (32 + 2 * e + 2 * i - h - k) % 7;
	m = (int)floor((a + 11 * h + 22 * l) / 451);
	month = (int)floor((h + l - 7 * m + 114) / 31);
	day = ((h + l - 7 * m + 114) % 31) + 1;

	//count number
	switch (month)	{
		case 3: march++; break;
		case 4: april++; break;
	}

	//print Easter Day
	cout << "Easter Day in " << year << " is "
		<< setfill('0') << setw(2) << day << "/"
		<< setfill('0') << setw(2) << month << "/"
		<< year << "." << endl;

}

int main() {

	int input1, input2;

	//read input
	cout << "Enter year range: ";
	cin >> input1 >> input2;

	//call foo
	for (int i = fmin(input1, input2); i <= fmax(input1, input2); i++) {
		foo(i);
	}

	//print count
	cout << "In March: " << march << endl;
	cout << "In April: " << april << endl;

	return 0;

}
