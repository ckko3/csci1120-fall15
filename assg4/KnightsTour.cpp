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

KnightsTour::KnightsTour(int x, int y){
  // set data member board all false except initial position
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      board[i][j] = false; // set all value false
  board[x][y] = true; // set initial position true
  // initialize data member posX posY
  posX = x; posY = y;
}

void KnightsTour::print() const{
  // print out configuration of the knight's tour
  cout << "  0 1 2 3 4 5" << endl; // print header
  for (int i = 0; i < N; i++) { // print all other stuff
    cout << i;
    for (int j = 0; j < N; j++) {
      if (i == posX && j == posY)
        cout << " K"; // print K
      else if (board[i][j])
        cout << " O"; // print O
      else
        cout << " ."; // print .
      }
      cout << endl;
    }
}

bool KnightsTour::hasMoreMoves() const{
  // check whether the knight has more possible moves to make
  // create a temporary similar board with 10 rows and cols
  bool tmpboard[N+4][N+4];
  for (int i = 0; i < N+4; i++)
    for (int j = 0; j < N+4; j++)
      tmpboard[i][j] = true; // set all value to true

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      tmpboard[i+2][j+2] = board[i][j]; // replace the value with real board as inner part of tmpboard

  if ( (tmpboard[posX-2+2][posY-1+2]) && (tmpboard[posX-2+2][posY+1+2]) &&
       (tmpboard[posX-1+2][posY-2+2]) && (tmpboard[posX-1+2][posY+2+2]) &&
       (tmpboard[posX+1+2][posY-2+2]) && (tmpboard[posX+1+2][posY+2+2]) &&
       (tmpboard[posX+2+2][posY-1+2]) && (tmpboard[posX+2+2][posY+1+2]) ) // all possible destination are visited
    return false;
  else
    return true;
}

bool KnightsTour::isSolved() const{
  // check whether the knight's tour is completed succuessfully
  int k = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (board[i][j])
        k++;
  if (k == 36)
    return true;
  else
    return false;
}

bool KnightsTour::move(int x, int y){
  // try to move the knight from current position to row x column y
  // check whether move is valid
  if (x < 0 || x > 5 || y < 0 || y > 5) // invalid move
    return false;
  // check whether destination is unvisited
  else if (board[x][y]) // destination already visited
    return false;
  // check whether move like L
  else if ( (x==posX-2 && y==posY-1) || (x==posX-2 && y==posY+1) ||
            (x==posX-1 && y==posY-2) || (x==posX-1 && y==posY+2) ||
            (x==posX+1 && y==posY-2) || (x==posX+1 && y==posY+2) ||
            (x==posX+2 && y==posY-1) || (x==posX+2 && y==posY+1) ) { // is L move
            board[x][y] = true; // update board
            posX = x; posY = y; // update position
            return true;
          }
  else // not L move
    return false;
}

void KnightsTour::lookAhead(int &r, int &c) const{
  // suggest a move for the knight to the user
  // guarantee that if no possible moves, no update will be done on r and c
  // 6x6 array to count the number of onward moves
  int count[N][N];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      count[i][j] = -1; // initialze as -1

  // create a temporary similar board with 10 rows and cols
  bool tmpboard[N+4][N+4];
  for (int i = 0; i < N+4; i++)
    for (int j = 0; j < N+4; j++)
      tmpboard[i][j] = true; // set all value to true

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      tmpboard[i+2][j+2] = board[i][j]; // replace the value with real board as inner part of tmpboard

  // if move is unvisited, ie. possible move, set count equal zero
  if (!tmpboard[posX-2+2][posY-1+2]) count[posX-2][posY-1] = 0;
  if (!tmpboard[posX-2+2][posY+1+2]) count[posX-2][posY+1] = 0;
  if (!tmpboard[posX-1+2][posY-2+2]) count[posX-1][posY-2] = 0;
  if (!tmpboard[posX-1+2][posY+2+2]) count[posX-1][posY+2] = 0;
  if (!tmpboard[posX+1+2][posY-2+2]) count[posX+1][posY-2] = 0;
  if (!tmpboard[posX+1+2][posY+2+2]) count[posX+1][posY+2] = 0;
  if (!tmpboard[posX+2+2][posY-1+2]) count[posX+2][posY-1] = 0;
  if (!tmpboard[posX+2+2][posY+1+2]) count[posX+2][posY+1] = 0;

  // loop for every possible move, ie. count equal zero
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (count[i][j] == 0) {
        // if there is possible move from it, set count increases by 1
        if (!tmpboard[i-2+2][j-1+2]) count[i][j]++;
        if (!tmpboard[i-2+2][j+1+2]) count[i][j]++;
        if (!tmpboard[i-1+2][j-2+2]) count[i][j]++;
        if (!tmpboard[i-1+2][j+2+2]) count[i][j]++;
        if (!tmpboard[i+1+2][j-2+2]) count[i][j]++;
        if (!tmpboard[i+1+2][j+2+2]) count[i][j]++;
        if (!tmpboard[i+2+2][j-1+2]) count[i][j]++;
        if (!tmpboard[i+2+2][j+1+2]) count[i][j]++;
      }

  int min = 36; // fewest onward move, initialize as some large number
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (count[i][j] >= 0)
        if (count[i][j] < min) { // if count is smaller than minimun
          min = count[i][j]; // set min
          r = i; c = j; // set reference parameter r and c
        }

}
