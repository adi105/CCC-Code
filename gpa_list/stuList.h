#pragma once
//**************************************************************************************************
// Program Name:	studentList.h
// Developer:		Adrian Bernat
// Course Number:	CS-162-02
// Date:			2-22-17
// IDE:				Visual Studio 2015
// Description:		Contains the class that is used to store a list of students.
//**************************************************************************************************
#include "student.h"
const int STUDENT_COUNT = 10;

class StudentList {
public:
	//Constructor
	//Initializes all array slots to null
	StudentList();

	//Destructor
	~StudentList();

	//Mutators
	//Function takes a Student class object and inserts it into an array of Student objects
	//Returns true if successful in inserting, false otherwise
	bool insert(Student* student);

	//Function scans the array for the given name, and if found, removes it from the array
	//Returns true if removed successfully, false if the name was not found
	bool remove(const char* name);

	//Accessors
	//Function returns true if the array is full, false otherwise
	bool full() const;

	//Function returns true if the array is empty, false otherwise
	bool empty() const;

	//Function prints out the contents of the Student object array to the screen
	void print() const;




private:
	Student* students[STUDENT_COUNT];
};