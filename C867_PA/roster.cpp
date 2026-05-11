/*
* Student: Josh Hasam
* ID: 012723312
* Course: C867 - Scripting & Programming Applications
* Language: C++
*/

#include "roster.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Requirement F1: Constructor
Roster::Roster() {}

// Requirement F5: Destructor (Releasing memory to prevent leaks)
Roster::~Roster() {} // With unique_ptr, memory is automatically managed, so we don't need to manually delete anything here.

// Requirement F3: Define the add method
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	std::array<int, 3> daysInCourse = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterVector.push_back(std::make_unique<Student>(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeprogram));
}

// Requirement E3: Parse method
void Roster::parse(string row) {
	stringstream ss(row);
	string tokens[9];
	string temp;
	int i = 0;

	// Split the string by commas and store in tokens array
	while (getline(ss, temp, ',') && i < 9) {
		tokens[i++] = temp;
	}
	// Convert degree program string to enum
	DegreeProgram degreeProgram = SOFTWARE;
	if (tokens[8] == "SECURITY") degreeProgram = SECURITY;
	else if (tokens[8] == "NETWORK") degreeProgram = NETWORK;

	add(tokens[0], tokens[1], tokens[2], tokens[3], stoi(tokens[4]), stoi(tokens[5]), stoi(tokens[6]), stoi(tokens[7]), degreeProgram);
}

// Requirement F4: printAll
void Roster::printAll() {
	for (const auto& student : classRosterVector) {
		student->print();
	}
}

// Requirement F4: printAverageDaysInCourse
void Roster::printAverageDaysInCourse(string studentID) {
	for (const auto& student : classRosterVector) {
		if (student->GetStudentID() == studentID) {
			auto& days = student->GetDaysInCourse();
			cout << "Student ID: " << studentID << ", average days in course: " << (days[0] + days[1] + days[2]) / 3.0 << endl;
			return;
			}
	}
}

// Requirement F4: printByDegreeProgram
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (const auto& student : classRosterVector) {
		if (student->GetDegreeProgram() == degreeProgram) {
			student->print();
		}
	}
}

// Requirement F4: printInvalidEmails
void Roster::printInvalidEmails() {
	cout << "Displaying invalid emails:" << endl;
	for (const auto& student : classRosterVector) {
		string email = student->GetEmailAddress();
		// Check for invalid email conditions
		if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
			cout << email << " is invalid." << endl;
			}
		}
	}

// Requirement E3b: Remove method (with shift and shrink logic)
void Roster::remove(string studentID) {
	bool found = false;
	for (auto it = classRosterVector.begin(); it != classRosterVector.end(); ) {
		if ((*it)->GetStudentID() == studentID) {
			it = classRosterVector.erase(it); // Automatically shifts and shrinks the vector
			found = true;
			cout << "Student with ID " << studentID << " has been removed." << endl;

		}
		else {
			++it; // Move to the next element only if not erasing
		}
	}
		if (!found) {
			cout << "The student with the ID " << studentID << " was not found." << endl;
		}
	}