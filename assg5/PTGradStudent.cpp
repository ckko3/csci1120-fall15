/*	CSCI1120
*
*	Assignment:	5
*	Student ID: 1155033234
*	Name	  : Ko Chi Keung
*	e-mail adr: kck.keung@link.cuhk.edu.hk
*/

#include <string>
#include "PTGradStudent.h"
using namespace std;

PTGradStudent::PTGradStudent(string sid) : GradStudent(sid) {}  // do nothing just call superclass constructor

string PTGradStudent::computeCourseGrade() const {
  return computeTotalScore() < 55 || getQuizScore() < 35 ? "Fail" : "Pass";  // if totalscore smaller than 55 or quiz smaller than 35, fail, otherwise pass
}
