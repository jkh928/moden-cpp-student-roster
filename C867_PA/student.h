/*
* Student: Josh Hasam
* ID: 012723312
* Course: C867 - Scripting & Programming Applications
* Language: C++
*/

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "degree.h"

class Student {
private:
	//Requirement E1: Private variables
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int age;
	int daysToComplete[3]; //Array of 3 integers
	DegreeProgram degreeProgram;

public:
	//Requirement E2c: Constructor
	Student(const std::string& studentID, const std::string& firstName, const std::string& lastName, const std::string& emailAddress, int age, int daysToComplete[], DegreeProgram degreeProgram);

	//Requirement E2a: Accessors (Getters)
	std::string GetStudentID();
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetEmailAddress();
	int GetAge();
	int* GetDaysToComplete(); //Returns a pointer to the array
	DegreeProgram GetDegreeProgram();

	//Requirement E2b: Mutators (Setters)
	void SetStudentID(const std::string& studentID);
	void SetFirstName(const std::string& firstName);
	void SetLastName(const std::string& lastName);
	void SetEmailAddress(const std::string& emailAddress);
	void SetAge(int age);
	void SetDaysToComplete(int daysToComplete[]);
	void SetDegreeProgram(DegreeProgram degreeProgram);

	//Requirement E2d: Print function
	void print();
};

#endif