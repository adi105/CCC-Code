//******************************************************************************
// Program Name:	stringList.h
// Developer:		Adrian Bernat
// Course Number:	CS-260
// Date:			4-16-17
// IDE:				Visual Studio 2015
// Description:		Contains the class details for the stringList doubly linked
//					list.
//*******************************************************************************
#pragma once
#include <string>

struct Node {
	std::string data;
	Node* next;
	Node* prev;
};
class stringList {
public:
	//default constructor sets the next and
	//prev of the head to null
	stringList();

	//destructor
	~stringList();

	//mutators
	//inserts the given string into the linked
	//list alphabetically. Returns true if successful,
	//false otherwise.
	bool insert(const std::string item);

	//removes any instances of the given string from the list.
	//returns the amount of strings that the function removed.
	int remove(std::string item);

	//removes all of the items from the list using recursion
	void removeAll();

	int recursionRemoveAll(Node* current);

	//accessors
	//returns how many items are in the list
	int totalItems() const;

	//prints the list from start to finish
	void printForward() const;

	//prints the list in reverse order
	void printReverse() const;

	//counts and returns how many times the given string occurred
	//int find(std::string item) const;

	//counts and returns how many times the given char
	//is present inside of the list
	//int findLetter(char item) const;

private:
	Node* head;
	Node* tail;
	int itemsInList;
};
