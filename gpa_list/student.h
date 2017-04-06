#pragma once
//**************************************************************************************************
// Program Name:	student.h
// Developer:		Adrian Bernat
// Course Number:	CS-162-02
// Date:			2-18-17
// IDE:				Visual Studio 2015
// Description:		Header file for a class that stores student info
//**************************************************************************************************

class Student {
public:
	//constructors
	//Default constructor initializes GPA to 0 and name to NULL
	Student();

	//Initializes the student to the given GPA and name
	Student(float gpa, char* name);

	//destructor
	~Student();

	//mutators
	//Function changes the name of the student to the new name that is provided by the argument
	void changeName(const char* newName);

	//accessors
	//Function compares the char* given by the argument and the current name stored in the private name variable
	//Returns true if the names are equivalent, false otherwise
	bool isEqualTo(const char* compName) const;
	
	//Function prints the name and gpa of the student to the screen
	void print() const;

private:
	float gpa;
	char* name;

};