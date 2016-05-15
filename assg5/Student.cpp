/*	CSCI1120
*
*	Assignment:	5
*	Student ID: 1155033234
*	Name	  : Ko Chi Keung
*	e-mail adr: kck.keung@link.cuhk.edu.hk
*/

#include <string>
#include "Student.h"
using namespace std;

Student::Student(string sid) {
  // handle sid
  int i = 0;
  int len = sid.length();  // get the length of sid
  while (i < len) {
    if (!isdigit(sid[i])) {
      sid.erase(i,1);  // if not digit, erase it
      len--; // decrease len by 1
    }
    else
      i++;
  }
  /* sid contains only digits */

  if (len < 10) // shorter than 10, add '0'
    id.append(10-len,'0').append(sid);
  else if (len > 10) // longer than 10, trim to retain rightmost 10 digits
    id = sid.substr(len-10);
  else  // equal to 10
    id = sid;

  // initialize 6 assignments
  for (int i=0; i<6; i++)
    assignment[i] = 0; // initialize as zero
}

string Student::getID() const {
  return id; //return id
}

double Student::getAssignmentScore(int i) const {
  return assignment[i-1]; // assume i is always 1-6
}

void Student::setAssignmentScore(int i, double score) {
  if (i >= 1 && i <= 6)
    assignment[i-1] = score < 0 ? 0 : // if smaller than 0, set 0
                      score > 100 ? 100 : // if larger than 100, set 100
                                    score;  // else set its value
}

double Student::computeTotalScore() const {
  double sum = 0;  // sum of score
  for (int i=1; i<=6; i++)
    sum += getAssignmentScore(i);
  return sum/6;  // average of score
}

string Student::computeCourseGrade() const {
  return computeTotalScore() < 50 ? "Fail" : "Pass"; // if totalscore smaller than 50, fail, otherwise pass
}
