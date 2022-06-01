#ifndef SNAP_H_
#define SNAP_H_
#include <iostream>
#include <string>

using namespace std;

class Snap {	
private:
	string studentId;
	string studentName;
	string studentAdd;
	string studentPhone;
public:
	Snap() : studentId("Id"), studentName("Name"), studentAdd("Address"), studentPhone("Phone Number") {}	//default constructor for snap
	Snap(string id, string name, string add, string phone) : studentId(id), studentName(name), studentAdd(add), studentPhone(phone) {} //constructor for snap
	~Snap() {}

	string getName() { return studentName; }
	string printSchedule() { return studentName + ", " + studentId + ", " + studentAdd + ", " + studentPhone; }

	friend ostream& operator<< (ostream& os, const Snap& snap) {		//assignment operator for <<
		os << "snap(" << snap.studentId << "," << snap.studentName << "," << snap.studentAdd << "," << snap.studentPhone << ")";
		return os;
	}
};
#endif
