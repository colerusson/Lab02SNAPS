#ifndef CR_H_
#define CR_H_
#include <iostream>
#include <string>
#include "Course.h"

using namespace std;

class Cr : public Course {		//Cr class, derived from Course base class
private:
	string courseRoom;
public:
	Cr() : Course(), courseRoom("Location") {}		//default constructor for cr
	Cr(const string& courseId, string room) : Course(courseId), courseRoom(room) {}		//constructor for cr
	~Cr() {}

	string GetRoom() { return courseRoom; }
	string GetCourseName() { return toString(); }

	friend ostream& operator<< (ostream& os, const Cr& cr) {		//assignment operator that calls toString in course class
		os << "cr(" << cr.toString() << "," << cr.courseRoom << ")";
		return os;
	}
};
#endif
