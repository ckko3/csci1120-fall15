/*	CSCI1120
*
*	Assignment:	4
*	Student ID: 1155033234
*	Name	  : Ko Chi Keung
*	e-mail adr: kck.keung@link.cuhk.edu.hk
*/

#include <iostream>
#include "KnightsTour.h"
using namespace std;

int main() {

    int start_r, start_c, r, c;

    // prompt, enter starting position
    cout << "Enter knight's starting position (row col): ";
    cin >> start_r >> start_c;

    // invalid position
    while(start_r < 0 || start_r > 5 || start_c < 0 || start_c > 5){
      cout << "Invalid. Try again!" << endl;
      cout << "Enter knight's starting position (row col): ";
      cin >> start_r >> start_c;
    }

    // initialze object KnightsTour
    KnightsTour kt(start_r,start_c);

    // loop for the progress, until no possible moves
    while (kt.hasMoreMoves()) {
    // print board
    kt.print();

    // prompt, enter move
    cout << "Make a move (row col): ";
    cin >> r >> c;

    // make a move
    if (!kt.move(r,c)) { // input is invalid
      kt.lookAhead(r,c); // suggest a move
      cout << "Invalid. Make a suggested move for you: " << r << " " << c << endl;
      kt.move(r,c); // move knight to suggested destination
    }
  }

    // no more possible moves
    kt.print(); // last print
    // check whether is solved or not
    if (kt.isSolved())
      cout << "Finished. Well done!" << endl; // solved
    else
      cout << "Sorry. No more moves!" << endl; // no moves
    return 0;
}
