/*
* Student: Josh Hasam
* ID: 012723312
* Course: C867 - Scripting & Programming Applications
* Language: C++
*/

#pragma once
#include <iostream>
#include <string>
#include <array>
#include "degree.h"

class Student {
private:
	//Requirement E1: Private variables
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int age;
	std::array<int, 3> daysInCourse; //Modern array
	DegreeProgram degreeProgram;

public:
	//Requirement E2c: Constructor
	Student(const std::string& studentID, const std::string& firstName, const std::string& lastName, const std::string& emailAddress, int age, const std::array<int, 3>& daysInCourse, DegreeProgram degreeProgram);

	//Requirement E2a: Accessors (Getters)
	std::string GetStudentID() const;
	std::string GetFirstName() const;
	std::string GetLastName() const;
	std::string GetEmailAddress() const;
	int GetAge() const;
	const std::array<int, 3>& GetDaysInCourse() const; //Returns a pointer to the array
	DegreeProgram GetDegreeProgram() const;

	//Requirement E2b: Mutators (Setters)
	void SetStudentID(const std::string& studentID);
	void SetFirstName(const std::string& firstName);
	void SetLastName(const std::string& lastName);
	void SetEmailAddress(const std::string& emailAddress);
	void SetAge(int age);
	void SetDaysInCourse(const std::array<int, 3>& daysInCourse);
	void SetDegreeProgram(DegreeProgram degreeProgram);

	//Requirement E2d: Print function
	void print() const;
};