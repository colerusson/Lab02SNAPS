#ifndef COURSE_H_
#define COURSE_H_
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Course {		//base class Course
private:
	string courseId;
public:
	Course() : courseId("Course") {}		//default constructor for Course
	Course(string course) : courseId(course) {}		//constructor for Course
	~Course() {}

	string toString() const {		//toString function that is used in derived classes of Course
		stringstream out;
		out << courseId;
		return out.str();
	}

};
#endif 
