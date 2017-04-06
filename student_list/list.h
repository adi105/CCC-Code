#pragma once
//**************************************************************************************************
// Program Name:	list.h
// Developer:		Adrian Bernat
// Course Number:	CS-162-02
// Date:			2-1-17
// IDE:				Visual Studio 2015
// Description:		Header file that stores all of the code for the List class, which includes
//					functions to manipulate an array of strings.
//**************************************************************************************************

#include <string>
//Constants
const int MAX_ITEMS = 10;

class List {
public:
	//Constructor
	List();

	//Inserts the given string into the array
	//The string must not be present already or be null
	//Returns true if insertion was successful, false otherwise
	bool insert(const std::string& data);

	//Tests to see if the given string is present in the array
	//Returns true if the string is in the list, false otherwise
	bool inList(const std::string& data);

	//Removes the given string from the array
	//Returns true if the string was removed, false otherwise
	bool remove(const std::string& data);

	//Accessors
	//Tests if the array is currently empty
	bool empty() const;

	//Tests if the array is currently full.
	bool full() const;

	//Prints the contents of the array onto the console.
	void printList();


private:
	std::string items[MAX_ITEMS];
	int totalItems;
};