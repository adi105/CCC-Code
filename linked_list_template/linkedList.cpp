//**************************************************************************************************
// Program Name:	UnOrderedList.cpp
// Developer:		Adrian Bernat
// Course Number:	CS-162-02
// Date:			3-5-17
// IDE:				Visual Studio 2015
// Description:		Contains the implementation for the UnOrderedList class used in the program
//**************************************************************************************************
#include <iostream>
#include "linkedList.h"

using namespace std;

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

//Insert's the item into the first or last item of the linke list, using prepend
//and append functions.
//=============================================================================
template <class dataType>
bool UnOrderedList<dataType>::prepend(const dataType itemToAdd) {
	//test if the string already exists
	if (find(itemToAdd) != 0)
		return false;
	
	//build the new Node<dataType>
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
	//test if the string already exists
	if (find(itemToAdd) != 0)
		return false;

	//build the new Node<dataType>
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

//finds the given string inside of the list if it exists, returns the 
//slot at which the string can be found, or zero if it is not in the list
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

//finds if the given string is in the list, and if it is,
//runs throught he list and deletes it where it is found
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

//Calls the recursion function so that it can access the private
//head member
//==============================================================
template <class dataType>
void UnOrderedList<dataType>::printReverse() const {
	printReverseRecursion(head);
}

//contains the actual code for the recursive function that prints
//the list backwards by using the head of the linked list
//==============================================================
template <class dataType>
void UnOrderedList<dataType>::printReverseRecursion(Node<dataType>* nodeToPrint) const {
	if (nodeToPrint) {
		printReverseRecursion(Node<dataType>ToPrint->link);
		cout << Node<dataType>ToPrint->storage << ", ";
	}
}