#ifndef CDH_H_
#define CDH_H_
#include <iostream>
#include <string>
#include "Course.h"

using namespace std;

class Cdh : public Course {		//Cdh class, derived from Course base class
private:
	string courseDay;
	string courseTime;
public:
	Cdh() : Course(), courseDay("Schedule-Days"), courseTime("Schedule-Time") {}		//default constructor for csg
	Cdh(const string& courseId, string day, string time) : Course(courseId), courseDay(day), courseTime(time) {}		//constructor for csg
	~Cdh() {}

	string GetCourseName() { return toString(); }
	string GetDay() { return courseDay; }
	string GetTime() { return courseTime; }

	friend ostream& operator<< (ostream& os, const Cdh& cdh) {		//assignment operator that calls toString in course class
		os << "cdh(" << cdh.toString() << "," << cdh.courseDay << "," << cdh.courseTime << ")";
		return os;
	}
};
#endif