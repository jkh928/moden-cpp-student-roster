/*
*Student: Josh Hasam
* ID : 012723312
* Course : C867 - Scripting & Programming Applications
* Language : C++
*/

#include "roster.h"
#include <iostream>
#include <string>

using namespace std;

// Initialize the array pointers to nullptr in the constructor
Roster::Roster() {
	for (int i = 0; i < numStudents; ++i) {
		classRosterArray[i] = nullptr;
	}
}

// Requirement F5: Destructor definition
Roster::~Roster() {
}

// Requirement F3: Define the add method
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {

	// Create an array for the 3 daysInCourse values
	int daysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	// Create a NEW Student object on the heap and put it in the next available slot
	// Increment lastIndex first so the first student goes into index 0
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeprogram);
}

void Roster::parse(string studentData) {
	// 1. Find the first comma to get the Student ID
	size_t rhs = studentData.find(",");
	string sID = studentData.substr(0, rhs);

	// 2. Move to the next field (First Name)
	size_t lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string sFirst = studentData.substr(lhs, rhs - lhs);

	// 3. Last Name
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string sLast = studentData.substr(lhs, rhs - lhs);

	// 4. Email
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string sEmail = studentData.substr(lhs, rhs - lhs);

	// 5. Age (Convert to int)
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int sAge = stoi(studentData.substr(lhs, rhs - lhs));

	// 6. Days in Course 1, 2, and 3
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int d1 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int d2 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int d3 = stoi(studentData.substr(lhs, rhs - lhs));

	// 7. Degree Program (Logic to convert string to Enum)
	lhs = rhs + 1;
	string sDegreeStr = studentData.substr(lhs);
	DegreeProgram sDegree = SOFTWARE; // Default
	if (sDegreeStr == "SECURITY") sDegree = SECURITY;
	else if (sDegreeStr == "NETWORK") sDegree = NETWORK;

	// 8. Finally, call the add method we just wrote
	add(sID, sFirst, sLast, sEmail, sAge, d1, d2, d3, sDegree);
}

// Requirement F4: Print all students in the roster
void Roster::printAll() {
	for (int i = 0; i <= lastIndex; i++) {
		// Always check for nullptr to prevent crashes
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
}

