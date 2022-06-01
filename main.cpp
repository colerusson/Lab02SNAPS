#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Snap.h"
#include "Cdh.h"
#include "Cr.h"
#include "Course.h"
#include "Csg.h"

using namespace std;

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif		

int main(int argc, char* argv[]) {
	VS_MEM_CHECK	//implementing memory check

	if (argc < 3) {
		cerr << "Please provide name of input and output files";
		return 1;
	}
	cout << "Input file: " << argv[1] << endl;
	ifstream in(argv[1]);
	if (!in) {
		cerr << "Unable to open " << argv[1] << " for input";
		return 2;
	}
	cout << "Output file: " << argv[2] << endl;
	ofstream out(argv[2]);
	if (!out) {
		in.close();
		cerr << "Unable to open " << argv[2] << " for output";
		return 3;
	}

	vector<Snap> snaps;		//vectors for each of the classes
	vector<Csg> csg;
	vector<Cdh> cdh;
	vector<Cr> cr;

	string snapIndex = "snap(";
	string csgIndex = "csg(";
	string cdhIndex = "cdh(";
	string crIndex = "cr(";

	cout << "Input Strings:" << endl;
	for (string line; getline(in, line);) {		//loop through all the lines of the input file
		string inputLine(line);
		if (line.size() == 0) continue;
		try {
			cout << inputLine << endl;
			if (snapIndex == line.substr(0, 5)) {		//check for instance of snap and create Snap object and add to vector
				string studentId = line.substr(5, line.find(',') - 5);
				line = line.substr(line.find(',') + 1);
				string studentName = line.substr(0, line.find(','));
				line = line.substr(line.find(',') + 1);
				string studentAdd = line.substr(0, line.find(','));
				line = line.substr(line.find(',') + 1);
				string studentPhone = line.substr(0, line.find(')'));
				snaps.push_back(Snap(studentId, studentName, studentAdd, studentPhone));
				continue;
			}
			else if (csgIndex == line.substr(0, 4)) {		//check for instance of csg and create csg object and add to vector
				string courseId = line.substr(4, line.find(',') - 4);
				line = line.substr(line.find(',') + 1);
				string studentId = line.substr(0, line.find(','));
				line = line.substr(line.find(',') + 1);
				string studentGrade = line.substr(0, line.find(')'));
				csg.push_back(Csg(courseId, studentId, studentGrade));
				continue;
			}
			else if (cdhIndex == line.substr(0, 4)) {		//check for instance of cdh and create cdh object and add to vector
				string courseId = line.substr(4, line.find(',') - 4);
				line = line.substr(line.find(',') + 1);
				string courseDay = line.substr(0, line.find(','));
				line = line.substr(line.find(',') + 1);
				string courseTime = line.substr(0, line.find(')'));
				cdh.push_back(Cdh(courseId, courseDay, courseTime));
				continue;
			}
			else if (crIndex == line.substr(0, 3)) {		//check for instance of cr and create cr object and add to vector
				string courseId = line.substr(3, line.find(',') - 3);
				line = line.substr(line.find(',') + 1);
				string courseRoom = line.substr(0, line.find(')'));
				cr.push_back(Cr(courseId, courseRoom));
				continue;
			}
			throw runtime_error(inputLine);		//create the error if line doesn't match one of the options
		}
		catch (const runtime_error& error) {
			cout << "**Error: " << error.what() << endl;
		}
	}
	in.close();

	cout << endl << "Vectors:" << endl;		//run through each of the vectors and print out the objects using the << operator
	for (size_t i = 0; i < snaps.size(); ++i) {
		cout << snaps[i] << endl;
	}
	for (size_t i = 0; i < csg.size(); ++i) {
		cout << csg[i] << endl;
	}
	for (size_t i = 0; i < cdh.size(); ++i) {
		cout << cdh[i] << endl;
	}
	for (size_t i = 0; i < cr.size(); ++i) {
		cout << cr[i] << endl;
	}

	cout << endl << "Course Grades:" << endl;		//print out the course grades for each student in the courses
	for (size_t i = 0; i < csg.size(); ++i) {
		cout << csg.at(i).toString() << "," << csg.at(i).getGrade() << endl;
	}

	return 0;
}
