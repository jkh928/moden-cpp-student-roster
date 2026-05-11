/*
* Student: Josh Hasam
* ID: 012723312
* Course: C867 - Scripting & Programming Applications
* Language: C++
*/

#include<iomanip>
#include "student.h"

using namespace std;

// Requirement E2c: Constructor using all input parameters from the table
Student::Student(const string& studentID, const string& firstName, const string& lastName, const string& emailAddress, int age, const std::array<int, 3>& days, DegreeProgram degreeProgram)
	: studentID(studentID), firstName(firstName), lastName(lastName), emailAddress(emailAddress), age(age), daysInCourse(days), degreeProgram(degreeProgram)
{
	
}

// Requirement E2a: Accessors (Getters)
string Student::GetStudentID() const {
	return studentID;
}

string Student::GetFirstName() const {
	return firstName;
}

string Student::GetLastName() const {
	return lastName;
}

string Student::GetEmailAddress() const {
	return emailAddress;
}

int Student::GetAge() const {
	return age;
}

// Returns a pointer to the array (Competency 4048.2.5)
const std::array<int, 3>& Student::GetDaysInCourse() const {
	return daysInCourse;
}

DegreeProgram Student::GetDegreeProgram() const {
	return degreeProgram;
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

void Student::SetDaysInCourse(const std::array<int, 3>& daysInCourse) {
	for (int i = 0; i < 3; ++i) {
		this->daysInCourse = daysInCourse;
	}
}

void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

// Requirement E2d: Print specific student data in the required format
void Student::print() const {
	// 1. Set fixed widths for each columns to ensure perfect alignment
	cout << left << setw(6) << studentID;
	cout << "First Name: " << left << setw(12) << firstName;
	cout << "Last Name: " << left << setw(12) << lastName;
	cout << "Age: " << setw(6) << age;
	
	// 2. Format the days array output
	cout << "daysInCourse: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}";
	
	// 3. Convert the enum to a string for printing
	cout << left << setw(10) << "" << "Degree Program: ";

	if (degreeProgram == SECURITY) cout << "Security";
	else if (degreeProgram == NETWORK) cout << "Network";
	else cout << "Software";

	cout << endl;
}
