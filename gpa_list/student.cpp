//**************************************************************************************************
// Program Name:	student.cpp
// Developer:		Adrian Bernat
// Course Number:	CS-162-02
// Date:			2-18-17
// IDE:				Visual Studio 2015
// Description:		Contains the implementation for the student class
//**************************************************************************************************
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "student.h"
using namespace std;

//======================================================================
Student::Student() {
	gpa = 0;
	name = NULL;
}

//==============================================================================================
//Name:		Student(float gpa, char* name)
//Details:	Initializes the GPA of the student to the given GPA only if it is between 0 and 4.
//			Initializes the name of the student to the given char* name.
//===============================================================================================
Student::Student(float gpa, char* name) {
	if (gpa > 4 || gpa < 0)
		this->gpa = 0;
	else
		this->gpa = gpa;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

//================================================================================================
Student::~Student() {
	if (name)
		delete[] name;
}

//==============================================================================================
//Name:		void changeName(const char* newName)
//Details:	Changes the name of the student to the name given by the argument.
//===============================================================================================
void Student::changeName(const char* newName) {
	if (name != NULL) {
		delete name;
		name = new char[strlen(newName + 1)];
		strcpy(this->name, newName);
	}
}

//==============================================================================================
//Name:		bool isEqualTo(const char* compName)
//Details:	Tests the name of the student to the name given by the argument. Returns true
//			if the names are the same, and false if they are different.
//===============================================================================================
bool Student::isEqualTo(const char* compName) const {
	int length = strlen(name);
	for (int index = 0; index <= length; index++) {
		if (compName[index] != name[index])
			return false;
	}
	return true;
}

//===============================================================================================
void Student::print() const {
	std::cout << name << "(" << gpa << ")";
}

