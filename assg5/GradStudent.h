#ifndef GRAD_STUDENT_H
#define GRAD_STUDENT_H

#include <string>
#include "Student.h"
using namespace std;

class GradStudent : public Student {
public:
   GradStudent(string sid = "0000000000");
   double getQuizScore() const;
   void setQuizScore(double q);
   virtual double computeTotalScore() const;
   virtual string computeCourseGrade() const;
private:
   double quiz;
};
#endif // GRAD_STUDENT_H
