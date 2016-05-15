/*	CSCI1120
*
*	Assignment:	2
*	Student ID: 1155033234
*	Name	  : Ko Chi Keung
*	e-mail adr: kck.keung@link.cuhk.edu.hk
*/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


int main() {

	int players, games;

	//enter # of players
	cout << "How many players (2-4)? ";
	cin >> players;

	while (players < 2 || players > 4)	{
		cout << "Number of players must be 2-4! Try again." << endl;
		cout << "How many players (2-4)? ";
		cin >> players;
	}

	int p1 = 0;
	int p2 = 0;
	int p3 = 0;
	int p4 = 0;

	//enter # of games
	cout << "How many games? ";
	cin >> games;

	while (games < players)	{
		cout << "At least " << players << " games! Try again." << endl;
		cout << "How many games? ";
		cin >> games;
	}

	//initialize random number generator
	srand(players * games);

	//start game
	int currentplayer = 1;
	for (int i = 1; i <= games; i++) {
		int a = 1, b = 100, secret = rand() % 100 + 1, guess;
		bool endgame = false;

		cout << "Game #" << i << ":" << endl;

		while (!endgame) {
			cout << "Player " << currentplayer << ", make a guess (" << a << "-" << b << "): ";
			cin >> guess;

			//validate guess
			while (guess < a || guess > b) {
				cout << "Guess must be " << a << "-" << b << "! Try again." << endl;
				cout << "Player " << currentplayer << ", make a guess (" << a << "-" << b << "): ";
				cin >> guess;
			}

			//hi
			if (guess > secret)	{
				cout << "Your guess is HI." << endl;
				b = guess - 1;
				currentplayer == players ? currentplayer = 1 : currentplayer++;
			}
			//lo
			else
				if (guess < secret)	{
					cout << "Your guess is LO." << endl;
					a = guess + 1;
					currentplayer == players ? currentplayer = 1 : currentplayer++;
				}
			//boom
				else {
					cout << "Boom! Player " << currentplayer << " loses." << endl;
					endgame = true;
					switch (currentplayer) {
					case 1: p1++; break;
					case 2: p2++; break;
					case 3: p3++; break;
					case 4: p4++; break;
					}
				}
		}
	}

	//stat: lose count
	for (int i = 1; i <= players; i++) {
		cout << "Player " << i << " loses ";
		switch (i) {
		case 1: cout << p1; break;
		case 2: cout << p2; break;
		case 3: cout << p3; break;
		case 4: cout << p4; break;
		}
		cout << " time(s)." << endl;
	}

	//stat: overall winners
	int min;
	cout << "Overall winner(s):" << endl;
	switch (players) {
	case 2:
		min = p1 < p2 ? p1 : p2;
		break;
	case 3:
		min = p1 < p2 ? (p1 < p3 ? p1 : p3) : (p2 < p3 ? p2 : p3);
		break;
	case 4:
		min = (p1 < p2 ? p1 : p2) < (p3 < p4 ? p3 : p4) ? (p1 < p2 ? p1 : p2) : (p3 < p4 ? p3 : p4);
		break;
	}
	for (int i = 1; i <= players; i++) {
		switch (i) {
		case 1: if (p1 == min) cout << "Player " << i << endl; break;
		case 2: if (p2 == min) cout << "Player " << i << endl; break;
		case 3: if (p3 == min) cout << "Player " << i << endl; break;
		case 4: if (p4 == min) cout << "Player " << i << endl; break;
		}
	}

	return 0;

}
