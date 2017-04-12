#pragma once
//**************************************************************************************************
// Program Name:	linkedList.h
// Developer:		Adrian Bernat
// Course Number:	CS-162-02
// Date:			4-12-17
// IDE:				Visual Studio 2015
// Description:		Contains the information for an unordered linked list class and node struct
//**************************************************************************************************
#include <iostream>
#include <string>

template <class dataType>
struct Node {
	dataType storage;
	Node* link;

	//implemented default constructor
	//and special constructor for the student class to work
	Node() {
		link = NULL;
	}

	Node(dataType data) {
		storage = data;
		link = NULL;
	}
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

	//removes the given item from the list
	//returns true if the removal was successful, 
	//false if the item was not in the list
	bool remove(const dataType itemToRemove);

	//clears all of the items from the list
	void removeAll();

	//accessors====================================================
	void print() const;

	//returns how many items are in the list
	int count() const;

	//returns the position of the given item in the list
	//returns zero if the item is not found inside of the list
	int find(const dataType itemToFind) const;

private:
	Node<dataType>* head;
};

//============================================
template <class dataType>
UnOrderedList<dataType>::UnOrderedList() {
	head = NULL;
}

//===========================================
template <class dataType>
UnOrderedList<dataType>::~UnOrderedList() {
	removeAll();
}

//Insert's the item into the first or last item of the linked list, using prepend
//and append functions.
//=============================================================================
template <class dataType>
bool UnOrderedList<dataType>::prepend(const dataType itemToAdd) {
	//test if the item already exists
	if (find(itemToAdd) != 0)
		return false;

	//build the new node
	Node<dataType>* newNode = new Node<dataType>;
	newNode->storage = itemToAdd;
	newNode->link = NULL;

	//take care of empty list case
	if (head == NULL) {
		head = newNode;
		return true;
	}

	//insert into the first slot of the list
	newNode->link = head;
	head = newNode;
	return true;
}

template <class dataType>
bool UnOrderedList<dataType>::append(const dataType itemToAdd) {
	//test if the item already exists
	if (find(itemToAdd) != 0)
		return false;

	//build the new node
	Node<dataType>* newNode = new Node<dataType>;
	newNode->storage = itemToAdd;
	newNode->link = NULL;

	//take care of empty list case
	if (head == NULL) {
		head = newNode;
		return true;
	}

	//insert into the end of the list
	Node<dataType>* previous = head;
	while (previous->link != NULL) {
		previous = previous->link;
	}

	newNode->link = previous->link;
	previous->link = newNode;

}

//finds the given item inside of the list if it exists, returns the 
//slot at which the item can be found, or zero if it is not in the list
//=======================================================================
template <class dataType>
int UnOrderedList<dataType>::find(const dataType itemToFind) const {
	int counter = 1;

	//find the data
	Node<dataType>* current = head;
	while (current != NULL) {
		if (current->storage == itemToFind)
			return counter;
		else {
			counter++;
			current = current->link;
		}
	}
	return 0;

}

//finds if the given item is in the list, and if it is,
//runs throught the list and deletes it where it is found
//=======================================================
template <class dataType>
bool UnOrderedList<dataType>::remove(const dataType itemToRemove) {
	//Check if the string exists
	if (!find(itemToRemove))
		return false;

	//Special Case: Head
	if (head->storage == itemToRemove) {
		Node<dataType>* tempPointer = head;
		head = head->link;
		delete tempPointer;
		return true;
	}


	//regular case
	Node<dataType>* previous = head;
	while (previous->link != NULL && previous->link->storage != itemToRemove) {
		previous = previous->link;
	}
	Node<dataType>* tempPointer = previous->link;
	previous->link = previous->link->link;
	delete tempPointer;
	return true;
}

//==========================================
template <class dataType>
void UnOrderedList<dataType>::removeAll() {
	Node<dataType>* current = head;
	while (current != NULL) {
		Node<dataType>* tempPointer = current;
		current = current->link;
		delete tempPointer;
	}
	head = NULL;
}

//==========================================
template <class dataType>
int UnOrderedList<dataType>::count() const {
	int count = 0;
	Node<dataType>* current = head;
	while (current != NULL) {
		count++;
		current = current->link;
	}
	return count;
}

//==========================================
template <class dataType>
void UnOrderedList<dataType>::print() const {
	Node<dataType>* current = head;
	while (current != NULL) {
		cout << current->storage;
		if (current->link != NULL)
			cout << ", ";
		current = current->link;
	}
	cout << endl;
}