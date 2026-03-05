/*
* Student: Josh Hasam
* ID: 012723312
* Course: C867 - Scripting & Programming Applications
* Language: C++
*/

#include "roster.h"
#include <iostream>
#include <string>

using namespace std;

// Requirement F1: Constructor
Roster::Roster() {
	for (int i = 0; i < numStudents; ++i) {
		classRosterArray[i] = nullptr;
	}
}

// Requirement F5: Destructor (Releasing memory to prevent leaks)
Roster::~Roster() {
	for (int i = 0; i <= lastIndex; i++) {
		if (classRosterArray[i] != nullptr) {
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
		}
	}
}

// Requirement F3: Define the add method
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	if (lastIndex < numStudents - 1) {
		int daysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
		classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeprogram);
	}
}

// Requirement E3: Parse method
void Roster::parse(string studentData) {
	size_t rhs = studentData.find(",");
	string sID = studentData.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string sFirst = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string sLast = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string sEmail = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int sAge = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int d1 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int d2 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int d3 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	string sDegreeStr = studentData.substr(lhs);
	DegreeProgram sDegree = SOFTWARE;
	if (sDegreeStr == "SECURITY") sDegree = SECURITY;
	else if (sDegreeStr == "NETWORK") sDegree = NETWORK;

	add(sID, sFirst, sLast, sEmail, sAge, d1, d2, d3, sDegree);
}

// Requirement F4: printAll
void Roster::printAll() {
	for (int i = 0; i <= lastIndex; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
}

// Requirement F4: printAverageDaysInCourse
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i <= lastIndex; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->GetStudentID() == studentID) {
			int* days = classRosterArray[i]->GetDaysInCourse();
			cout << "Student ID: " << studentID << ", average days in course: " << (days[0] + days[1] + days[2]) / 3 << endl;
			return;
		}
	}
}

// Requirement F4: printByDegreeProgram
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i <= lastIndex; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}

// Requirement F4: printInvalidEmails
void Roster::printInvalidEmails() {
	cout << "Displaying invalid emails:" << endl;
	for (int i = 0; i <= lastIndex; i++) {
		if (classRosterArray[i] != nullptr) {
			string email = classRosterArray[i]->GetEmailAddress();
			if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
				cout << email << " - is invalid." << endl;
			}
		}
	}
	cout << endl;
}

// Requirement E3b: Remove method (with shift and shrink logic)
void Roster::remove(string studentID) {
	bool found = false;
	for (int i = 0; i <= lastIndex; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->GetStudentID() == studentID) {
			found = true;
			delete classRosterArray[i];

			for (int j = i; j < lastIndex; j++) {
				classRosterArray[j] = classRosterArray[j + 1];
			}
			classRosterArray[lastIndex] = nullptr;
			lastIndex--;
			cout << "Student " << studentID << " removed." << endl;
			return;
		}
	}
	if (!found) cout << "The student with the ID: " << studentID << " was not found." << endl;
}