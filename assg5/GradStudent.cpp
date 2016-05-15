/*	CSCI1120
*
*	Assignment:	5
*	Student ID: 1155033234
*	Name	  : Ko Chi Keung
*	e-mail adr: kck.keung@link.cuhk.edu.hk
*/

#include <string>
#include "GradStudent.h"
using namespace std;

GradStudent::GradStudent(string sid) : Student(sid) {
  quiz = 0;  // initialize quiz as zero
}

double GradStudent::getQuizScore() const {
  return quiz; // return quiz score
}

void GradStudent::setQuizScore(double q) {
  quiz = q < 0 ? 0 : // if smaller than 0, set 0
         q > 100 ? 100 : // if larger than 100, set 100
                   q;  // else set its value
}

double GradStudent::computeTotalScore() const {
  return 0.72 * Student::computeTotalScore() + 0.28 * getQuizScore();  // totalscore = 72% of average plus 28% of quiz
}

string GradStudent::computeCourseGrade() const {
  return computeTotalScore() < 60 || getQuizScore() < 40 ? "Fail" : "Pass";  // if totalscore smaller than 60 or quiz smaller than 40, fail, otherwise pass
}
