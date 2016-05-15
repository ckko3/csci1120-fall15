/*	CSCI1120
*
*	Assignment:	3
*	Student ID: 1155033234
*	Name	  : Ko Chi Keung
*	e-mail adr: kck.keung@link.cuhk.edu.hk
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;
const int N = 11; // size 11 x 11

// print the board
void printboard (int board[N][N]) {
	cout << "  A B C D E F G H I J K" << endl; // print col header
	for (int i = 0; i < 11; i++) {
		cout << setw(2) << i; // print row header
		for (int k = 0; k < i; k++)
			cout << " ";
		for (int j = 0; j < 11; j++) { // print board content
			switch (board[i][j]) {
			case 0:
				cout << " O";
				break;
			case 1:
				cout << " X";
				break;
			case -1:
				cout << " .";
				break;
			}
		}
		cout << endl;
	}
}

// try to connect the chess
void move(int board[N][N], int i, int A, int B, bool &win) {
	switch (i) {
	case 0:
		if (B == 10) {
			win = true;
			return;
		}
		break;
	case 1:
		if (A == 10) {
			win = true;
			return;
		}
		break;
	}
	board[A][B] = -1;
	if (A == 0 && B == 0) { // top left
		const int r = 2;
		int pos[r][2] = { {0,1},{1,0} };
		for (int j = 0; j < r; j++) {
			int X = pos[j][0];
			int Y = pos[j][1];
			if (board[X][Y] == i) move(board, i, X, Y, win);
		}
	}
	else if (A == 0 && B == 10) { // top right
		const int r = 3;
		int pos[r][2] = { {0,9},{1,9},{2,10} };
		for (int j = 0; j < r; j++) {
			int X = pos[j][0];
			int Y = pos[j][1];
			if (board[X][Y] == i) move(board, i, X, Y, win);
		}
	}
	else if (A == 10 && B == 0) { // bottom left
		const int r = 3;
		int pos[r][2] = { {9,0},{9,1},{10,1} };
		for (int j = 0; j < r; j++) {
			int X = pos[j][0];
			int Y = pos[j][1];
			if (board[X][Y] == i) move(board, i, X, Y, win);
		}
	}
	else if (A == 10 && B == 10) { // bottom right
		const int r = 2;
		int pos[r][2] = { {10,9},{9,10} };
		for (int j = 0; j < r; j++) {
			int X = pos[j][0];
			int Y = pos[j][1];
			if (board[X][Y] == i) move(board, i, X, Y, win);
		}
	}
	else if (A == 0) { // top
		const int r = 4;
		int pos[r][2] = { {0,B-1},{0,B+1},{1,B-1},{1,B} };
		for (int j = 0; j < r; j++) {
			int X = pos[j][0];
			int Y = pos[j][1];
			if (board[X][Y] == i) move(board, i, X, Y, win);
		}
	}
	else if (A == 10) { // bottom
		const int r = 4;
		int pos[r][2] = { {10,B-1},{10,B+1},{9,B},{9,B+1} };
		for (int j = 0; j < r; j++) {
			int X = pos[j][0];
			int Y = pos[j][1];
			if (board[X][Y] == i) move(board, i, X, Y, win);
		}
	}
	else if (B == 0) { // left
		const int r = 4;
		int pos[r][2] = { {A-1,0},{A+1,0},{A-1,1},{A,1} };
		for (int j = 0; j < r; j++) {
			int X = pos[j][0];
			int Y = pos[j][1];
			if (board[X][Y] == i) move(board, i, X, Y, win);
		}
	}
	else if (B == 10) { // right
		const int r = 4;
		int pos[r][2] = { {A-1,10},{A+1,10},{A,9},{A+1,9} };
		for (int j = 0; j < r; j++) {
			int X = pos[j][0];
			int Y = pos[j][1];
			if (board[X][Y] == i) move(board, i, X, Y, win);
		}
	}
	else { // middle
		const int r = 6;
		int pos[r][2] = { {A-1,B},{A-1,B+1},{A,B-1},{A,B+1},{A+1,B-1},{A+1,B} };
		for (int j = 0; j < r; j++) {
			int X = pos[j][0];
			int Y = pos[j][1];
			if (board[X][Y] == i) move(board, i, X, Y, win);
		}
	}

	board[A][B] = i;
}

// check if winning chain formed
void checkwin(int board[N][N], int i, bool &win) {
	switch (i) {
	case 0:
		for (int A = 0; A < 11; A++) {
			if (board[A][0] == 0) {
				move(board, i, A, 0, win);
				if (win)
					break;
			}
		}
		break;
	case 1:
		for (int B = 0; B < 11; B++) {
			if (board[0][B] == 1) {
				move(board, i, 0, B, win);
				if (win)
					break;
			}
		}
		break;
	}
}

int main() {

	int board[N][N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board[i][j] = -1;
	char player[2] = {'O','X'};
	char A;
	int B;
	int i = 0;
	bool win = false;


	while (!win) {

		printboard(board); // print the board

		cout << "Player " << player[i] << ", make your move: ";
		cin >> A >> B;

		//input validation
		while (A < 'A' || A > 'K' || B < 0 || B > 10 || board[B][A - 65] != -1) {
			cout << "Invalid move. Enter again!" << endl;
			cout << "Player " << player[i] << ", make your move: ";
			cin >> A >> B;
		}

		board[B][A - 65] = i; // place the chess
		checkwin(board, i, win); // check if winning chain formed

		if (!win) i = 1 - i; // switch the player
	}

	printboard(board); // print the board
	cout << "Player " << player[i] << " wins!" << endl;

	return 0;

}
