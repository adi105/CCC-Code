//**************************************************************************************************
// Program Name:	linkedList.cpp
// Developer:		Adrian Bernat
// Course Number:	CS-162-02
// Date:			3-5-17
// IDE:				Visual Studio 2015
// Description:		Contains the implementation for the linkedList class used in the program
//**************************************************************************************************
#include <iostream>
#include "linkedList.h"

using namespace std;

//============================================
linkedList::linkedList() {
	head = NULL;
}

//===========================================
linkedList::~linkedList() {
	removeAll();
}

//Checks to see if the string given is already inside the list, and if not, 
//iterates throught the list and inserts the string into the next possible slot
//=============================================================================
bool linkedList::insert(const string stringToAdd) {
	//test if the string exists
	if (find(stringToAdd) != 0)
		return false;

	//build the new node
	Node* newNode = new Node;
	newNode->storage = stringToAdd;
	newNode->link = NULL;

	//insert the node into the list
	if (head == NULL) {
		head = newNode;
		return true;
	}

	//insert before first item
	if (newNode->storage < head->storage) {
		newNode->link = head;
		head = newNode;
		return true;
	}

	//iterate through
	Node* previous = head;
	while (previous->link != NULL && previous->link->storage < newNode->storage) {
		previous = previous->link;
	}

	newNode->link = previous->link;
	previous->link = newNode;
}

//creates a deep copy of the original list, allocating new memory
//and defining that memory to the same data as each node in the original list.
//============================================================================
linkedList* linkedList::duplicate() const {
	linkedList* newLL = new linkedList;
	
	Node* current;
	Node* newPrevious = new Node;
	Node* newNode;

	current = head;
	newPrevious->link = NULL;
	newPrevious->storage = current->storage;
	newLL->head = newPrevious;

	int totalItems = count();

	for (int index = 1; index < totalItems; index++) {
		newNode = new Node;
		current = current->link;
		
		//copy over the data to the new list
		newNode->storage = current->storage;
		
		//create a link in the new node
		newPrevious->link = newNode;

		//iterate through our list
		newPrevious = newPrevious->link;
	}

	newPrevious->link = NULL;
	return newLL;
}

//finds the given string inside of the list if it exists, returns the 
//slot at which the string can be found, or zero if it is not in the list
//=======================================================================
int linkedList::find(const string stringToFind) const {
	int counter = 1;

	//find the data
	Node* current = head;
	while (current != NULL) {
		if (current->storage == stringToFind)
			return counter;
		else {
			counter++;
			current = current->link;
		}
	}
	return 0;
	
}

//finds if the given string is in the list, and if it is,
//runs throught he list and deletes it where it is found
//=======================================================
bool linkedList::remove(const string stringToRemove) {
	//Check if the string exists
	if (!find(stringToRemove))
		return false;

	//Special Case: Head
	if (head->storage == stringToRemove) {
		Node* tempPointer = head;
		head = head->link;
		delete tempPointer;
		return true;
	}
	
	
	//regular case
	Node* previous = head;
	while (previous->link != NULL && previous->link->storage != stringToRemove) {
		previous = previous->link;
	}
	Node* tempPointer = previous->link;
	previous->link = previous->link->link;
	delete tempPointer;
	return true;
}

//==========================================
void linkedList::removeAll() {
	Node* current = head;
	while (current != NULL) {
		Node* tempPointer = current;
		current = current->link;
		delete tempPointer;
	}
	head = NULL;
}

//==========================================
int linkedList::count() const {
	int count = 0;
	Node* current = head;
	while (current != NULL) {
		count++;
		current = current->link;
	}
	return count;
}

//==========================================
void linkedList::print() const {
	Node* current = head;
	while (current != NULL) {
		cout << current->storage;
		if (current->link != NULL)
			cout << ", ";
		current = current->link;
	}
}

//Calls the recursion function so that it can access the private
//head member
//==============================================================
void linkedList::printReverse() const {
	printReverseRecursion(head);
}

//contains the actual code for the recursive function that prints
//the list backwards by using the head of the linked list
//==============================================================
void linkedList::printReverseRecursion(Node* nodeToPrint) const {
	if (nodeToPrint) {
		printReverseRecursion(nodeToPrint->link);
		cout << nodeToPrint->storage << ", ";
	}
}