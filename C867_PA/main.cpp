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
	// Requirement F1: Personal Information
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

	return 0;
}