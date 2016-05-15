#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
public:
   Student(string sid = "0000000000");
   string getID() const;
   double getAssignmentScore(int i) const;
   void setAssignmentScore(int i, double score);
   virtual double computeTotalScore() const;
   virtual string computeCourseGrade() const;
private:
   string id;
   double assignment[6];
};
#endif // STUDENT_H
