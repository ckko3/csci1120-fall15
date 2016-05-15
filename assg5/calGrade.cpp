/*	CSCI1120
*
*	Assignment:	5
*	Student ID: 1155033234
*	Name	  : Ko Chi Keung
*	e-mail adr: kck.keung@link.cuhk.edu.hk
*/

#include <iostream>
#include <fstream>  // for using ifstream
#include <cstdlib>  // for using exit()
#include <iomanip>  // for using setprecision
#include "Student.h"
#include "GradStudent.h"
#include "PTGradStudent.h"
using namespace std;

int main() {
    Student *students[200]; // Array of superclass pointers
    GradStudent *gPtr;  // GradStudent pointer

    /* Program Input */
    ifstream fin("data.txt"); // create ifstream object
    // fail to open the file for reading
    if (fin.fail()) {
      cout << "Cannot open data file. Program exit!" << endl;
      exit(1);  // terminate the program
    }

    int n;  //  number of student
    string type;  // student type
    string id;  // student id
    double score; // assignment score
    double quiz;  // quiz score

    fin >> n; // read n
    //cout << n << endl;
    for (int i=0; i<n; i++) {
      fin >> type >> id;  // read type and id
      //cout << i << " " << type << " " << id << endl;

      if (!type.compare("N")) students[i] = new Student(id);  // type = "N", Student
      if (!type.compare("G")) students[i] = new GradStudent(id);  // type = "G", GradStudent
      if (!type.compare("PT")) students[i] = new PTGradStudent(id); // type = "PT", PTGradStudent

      for (int j=1; j<=6; j++) {
        fin >> score;
        //cout << score << " ";
        students[i]->setAssignmentScore(j,score); // set assignment score for all
      }
      gPtr = dynamic_cast<GradStudent *>(students[i]);
      if (gPtr != NULL) { // GradStudent object
        fin >> quiz;
        //cout << quiz;
        gPtr->setQuizScore(quiz); // set quiz score only for GradStudent
      }
      //cout << endl;
    }
    fin.close();  // close stream

    /* Program Output */
    cout << "Results of " << n << " students:" << endl;
    for (int i=0; i<n; i++) {
      cout << students[i]->getID(); // print student id
      cout << " ";
      cout << fixed << setprecision(2) << students[i]->computeTotalScore(); // print total score in 2 decimal places
      cout << " ";
      cout << students[i]->computeCourseGrade();  // print grade, pass or fail
      cout << endl;
    }

    return 0;
}
