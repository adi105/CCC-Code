//**************************************************************************************************
// Program Name:	list.cpp
// Developer:		Adrian Bernat
// Course Number:	CS-162-02
// Date:			2-1-17
// IDE:				Visual Studio 2015
// Description:		Implementation file that defines all of the functions declared inside the list
//					class in the header file.
//**************************************************************************************************

#include <iostream>
#include <string>
#include <algorithm>
#include "list.h"

List::List() {
	totalItems = 0;
	for (int arrayCount = 0; arrayCount < MAX_ITEMS; arrayCount++) {
		items[arrayCount] = {};
	}
}

//==============================================================================================
//Name:		bool insert(const string& data)
//Details:	Tests if the data entered is pre-existent, would flood the array, or if it is empty
//			If not, inserts the string into the next available spot in the array.
//===============================================================================================
bool List::insert(const std::string& data) {
	if (data == "" || full() || inList(data))
		return false;

	items[totalItems] = data;
	totalItems++;
	return true;
}

//=================================
bool List::empty() const {
	if (totalItems == 0)
		return true;

	else
		return false;
}

//==================================
bool List::full() const {
	if (totalItems == MAX_ITEMS)
		return true;

	else
		return false;
}

//==============================================================================================
//Name:		bool inList(const string& data)
//Details:	Tests if the data entered already exists within the bounds of the string array
//===============================================================================================
bool List::inList(const std::string& data) {
	bool find;
	if (std::find(std::begin(items), std::end(items), data) != std::end(items))
		return true;

	else
		return false;
}

//================================================================================
void List::printList() {

	if (totalItems == 1) {
		for (int count = 0; count <= totalItems; count++) {
			std::cout << items[count] << " ";
		}
	}
	else {
		for (int count = 0; count < totalItems; count++) {
			std::cout << items[count] << " ";
		}
	}
	std::cout << std::endl;
}


//==============================================================================================
//Name:		bool remove(const string& data)
//Details:	Uses a counter integer to test what index would point to the string if it exists
//			in the array, then uses this as an index to move everything to the right of that
//			index one spot left, and make the final slot empty, therefore deleting the string.
//===============================================================================================
bool List::remove(const std::string& data) {
	int counter = 0;

	if (inList(data) == true) {
		totalItems--;
		for (int count = 0; count < totalItems; count++) {
			if (items[count] != data) {
				counter++;
			}
			else if (items[count] == data) {
				break;
			}
		}
		for (int index = counter; index < MAX_ITEMS - 1; index++) {
			items[index] = items[index + 1];
		}
		items[totalItems] = {};
		return true;
	}
	else {
		return false;
	}
}