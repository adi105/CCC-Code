//**************************************************************************************************
// Program Name:	studentList.cpp
// Developer:		Adrian Bernat
// Course Number:	CS-162-02
// Date:			2-21-17
// IDE:				Visual Studio 2015
// Description:		Contains the implementation for the studentList class
//**************************************************************************************************
#include <iostream>
#include "studentList.h"
using namespace std;

//============================================================
StudentList::StudentList() {
	for (int x = 0; x < STUDENT_COUNT; x++) {
		students[x] = NULL;
	}
}

//============================================================
StudentList::~StudentList() {
	for (int x = 0; x < STUDENT_COUNT; x++) {
		if (students[x] != nullptr)
			delete students[x];
	}
}

//==============================================================================================
//Name:		bool insert(Student* student)
//Details:	Takes the Student* student and inserts it into the first NULL spot in the array.
//			Returns true if the insertion happened and false if no insertion was performed.
//===============================================================================================
bool StudentList::insert(Student* student) {
	for (int index = 0; index < STUDENT_COUNT; index++)
		if (students[index] == NULL) {
			students[index] = new Student;
			students[index] = student;
			return true;
		}
	return false;
}

//==============================================================================================
bool StudentList::full() const {
	int counter = 0;
	for (int index = 0; index < STUDENT_COUNT; index++) {
		if (students[index] != NULL)
			counter++;
	}
	if (counter == STUDENT_COUNT)
		return true;
	else
		return false;
}

//================================================================================================
bool StudentList::empty() const {
	int counter = 0;
	for (int index = 0; index < STUDENT_COUNT; index++) {
		if (students[index] != NULL)
			counter++;
	}
	if (counter == 0)
		return true;
	else
		return false;
}

//=================================================================================================
void StudentList::print() const {
	for (int index = 0; index < STUDENT_COUNT; index++) {
		if (students[index] != NULL && index != 9) {
			students[index]->print();
			cout << ", ";
		}
		else if (index == 9 && students[index] != NULL)
			students[index]->print();
	}
	cout << endl;
}

//==============================================================================================
//Name:		bool remove(const char* name)
//Details:	Tests if the given name is in the array of students. If the name is found to exist,
//			the name is deleted, reinitialized to NULL, and the function returns true.
//===============================================================================================
bool StudentList::remove(const char* name) {
	for (int index = 0; index < STUDENT_COUNT; index++) {
		if (students[index] != NULL && students[index]->isEqualTo(name) == true) {
			delete students[index];
			students[index] = NULL;
			return true;
		}
	}
	return false;
}