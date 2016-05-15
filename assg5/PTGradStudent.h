#ifndef PT_GRAD_STUDENT_H
#define PT_GRAD_STUDENT_H

#include <string>
#include "GradStudent.h"
using namespace std;

class PTGradStudent : public GradStudent {
public:
   PTGradStudent(string sid = "0000000000");
   virtual string computeCourseGrade() const;
};
#endif // PT_GRAD_STUDENT_H
