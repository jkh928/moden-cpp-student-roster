/*
* Student: Josh Hasam
* ID: 012723312
* Course: C867 - Scripting & Programming Applications
* Language: C++
*/

#include <iostream>
#include <string>
#include "student.h"

using namespace std;

// Requirement E2c: Constructor using all input parameters from the table
Student::Student(const string& studentID, const string& firstName, const string& lastName, const string& emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram)
	: studentID(studentID), firstName(firstName), lastName(lastName), emailAddress(emailAddress), age(age), degreeProgram(degreeProgram)
{
	// Using a loop to copy array elements
	for (int i = 0; i < 3; ++i) {
		this->daysInCourse[i] = daysInCourse[i];
	}
}

// Requirement E2a: Accessors (Getters)
string Student::GetStudentID() {
	return this->studentID;
}

string Student::GetFirstName() {
	return this->firstName;
}

string Student::GetLastName() {
	return this->lastName;
}

string Student::GetEmailAddress() {
	return this->emailAddress;
}

int Student::GetAge() {
	return this->age;
}

// Returns a pointer to the array (Competency 4048.2.5)
int* Student::GetDaysInCourse() {
	return this->daysInCourse;
}

DegreeProgram Student::GetDegreeProgram() {
	return this->degreeProgram;
}


// Requirement E2b: Mutators (Setters)
void Student::SetStudentID(const string& studentID) {
	this->studentID = studentID;
}

void Student::SetFirstName(const string& firstName) {
	this->firstName = firstName;
}

void Student::SetLastName(const string& lastName) {
	this->lastName = lastName;
}

void Student::SetEmailAddress(const string& emailAddress) {
	this->emailAddress = emailAddress;
}

void Student::SetAge(int age) {
	this->age = age;
}

void Student::SetDaysInCourse(int daysInCourse[]) {
	for (int i = 0; i < 3; ++i) {
		this->daysInCourse[i] = daysInCourse[i];
	}
}

void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

// Requirement E2d: Print specific student data in the required format
void Student::print() {
	// 1. Format the output with tabs (\t)
	cout << this->studentID << "\t";
	cout << "First Name: " << this->firstName << "\t";
	cout << "Last Name: " << this->lastName << "\t";
	cout << "Age: " << this->age << "\t";
	// 2. Format the days array output
	cout << "daysInCourse: {" << this->daysInCourse[0] << ", " << this->daysInCourse[1] << ", " << this->daysInCourse[2] << "}\t";
	cout << "Degree Program: ";
	// 3. Convert the enum to a string for printing
	if (this->degreeProgram == SECURITY) cout << "Security";
	else if (this->degreeProgram == NETWORK) cout << "Network";
	else if (this->degreeProgram == SOFTWARE) cout << "Software";
	cout << endl;
}
