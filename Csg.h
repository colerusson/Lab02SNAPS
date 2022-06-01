#ifndef CSG_H_
#define CSG_H_
#include <iostream>
#include <string>
#include "Course.h"

using namespace std;

class Csg : public Course {		//Csg class, derived from Course base class
private:
	string studentId;
	string studentGrade;
public:
	Csg() : Course(), studentId("Id"), studentGrade("Grade") {}		//default constructor for csg
	Csg(const string& courseId, string id, string grade) : Course(courseId), studentId(id), studentGrade(grade) {}		//constructor for csg
	~Csg() {}

	string getGrade() { return studentGrade; }

	friend ostream& operator<< (ostream& os, const Csg& csg) {		//assignment operator that calls toString in course class
		os << "csg(" << csg.toString() << "," << csg.studentId << "," << csg.studentGrade << ")";
		return os;
	}
};
#endif 
