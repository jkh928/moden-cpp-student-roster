/*
* Student: Josh Hasam
* ID: 012723312
* Course: C867 - Scripting & Programming Applications
* Language: C++
*/

#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main() {
	// Requirement F1: Personal Information Header
	cout << "Course Title: C867 - Scripting and Programming Applications" << endl;
	cout << "Language Used: C++" << endl;
	cout << "WGU Student ID: 012723312" << endl;
	cout << "Name: Josh Hasam" << endl << endl;

	// Requirement A: studentData Table
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Josh,Hasam,jhasam2@wgu.edu,37,21,14,32,SOFTWARE"
	};

	// Requirement F2: Create instance of Roster class
	Roster classRoster;

	// Requirement F3: Parse and add each student to the roster
	for (int i = 0; i < 5; i++) {
		classRoster.parse(studentData[i]);
	}

	// Requirement G: Demonstration Sequence
	cout << "Displaying all students:" << endl;
	classRoster.printAll();
	cout << endl;

	classRoster.printInvalidEmails();
	cout << endl;

	cout << "Displaying average days in course:" << endl;
	classRoster.printAverageDaysInCourse("A1");
	classRoster.printAverageDaysInCourse("A2");
	classRoster.printAverageDaysInCourse("A3");
	classRoster.printAverageDaysInCourse("A4");
	classRoster.printAverageDaysInCourse("A5");
	cout << endl;

	cout << "Showing students in degree program: SOFTWARE" << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;

	cout << "Removing A3:" << endl;
	classRoster.remove("A3");
	cout << endl;

	cout << "Verifying removal of A3 (printAll):" << endl;
	classRoster.printAll();
	cout << endl;

	cout << "Attempting to remove A3 again:" << endl;
	classRoster.remove("A3");
	cout << endl;

	// Requirement F5: Destructor is called automatically when main returns
	return 0;
}