/*
*Student: Josh Hasam
* ID : 012723312
* Course : C867 - Scripting & Programming Applications
* Language : C++
*/

#pragma once
#include "student.h"

class Roster {
public:
	int lastIndex = -1;
	const static int numStudents = 5;
	// Requirement F1: Array of pointers to hold student data
	Student* classRosterArray[numStudents];

	// Requirement F5: Constructor and Destructor
	Roster();
	~Roster();

	// Requirement E3 & F2: Parsing and Adding
	void parse(std::string row);
	void add(std::string studentID,
		std::string firstName,
		std::string lastName,
		std::string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram degreeprogram);

	// Requirement E3: Management and Print functions
	void remove(std::string studentID);
	void printAll();
	void printAverageDaysInCourse(std::string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
};