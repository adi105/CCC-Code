#pragma once
//**************************************************************************************************
// Program Name:	linkedList.h
// Developer:		Adrian Bernat
// Course Number:	CS-162-02
// Date:			3-5-17
// IDE:				Visual Studio 2015
// Description:		Contains the information for a linked list class and struct
//**************************************************************************************************
#include <iostream>
#include <string>

using namespace std;

struct Node {
	string storage;
	Node* link;
};

class linkedList {
public:
	//constructor
	linkedList();

	//destructor
	~linkedList();

	//mutators======================================================
	//inserts the given string into the list if it does not already exist
	//returns true if successful, false if it is already present
	bool insert(const string stringToAdd);

	//removes the given string from the list
	//returns true if the removal was successful, 
	//false if the string was not in the list
	bool remove(const string stringToRemove);

	//clears all of the strings from the list
	void removeAll();

	//makes an exact copy of the list
	//returns a pointer to the new list
	linkedList* duplicate() const;

	//accessors====================================================
	void print() const;

	//prints the list in reverse order
	void printReverse() const;

	void printReverseRecursion(Node* pointer) const;

	//returns how many strings are in the list
	int count() const;

	//returns the position of the given string in the list
	//returns zero if the item is not found inside of the list
	int find(const string stringToFind) const;

private:
	Node* head;	
};