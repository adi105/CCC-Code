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

template <class dataType>
struct Node {
	dataType storage;
	Node* link;
};

template <class dataType>
class UnOrderedList {
public:
	//constructor
	UnOrderedList();

	//destructor
	~UnOrderedList();

	//mutators======================================================
	//inserts the given item into the linked list at the beginning
	//or end, using prepend and append namely
	bool prepend(const dataType itemToAdd);

	bool append(const dataType itemToAdd);

	//removes the given string from the list
	//returns true if the removal was successful, 
	//false if the string was not in the list
	bool remove(const dataType itemToRemove);

	//clears all of the strings from the list
	void removeAll();

	//accessors====================================================
	void print() const;

	//prints the list in reverse order
	void printReverse() const;

	void printReverseRecursion(Node<dataType>* nodeToPrint) const;

	//returns how many strings are in the list
	int count() const;

	//returns the position of the given string in the list
	//returns zero if the item is not found inside of the list
	int find(const dataType itemToFind) const;

private:
	Node<dataType>* head;
};
