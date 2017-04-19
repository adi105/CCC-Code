//******************************************************************************
// Program Name:	stringList.cpp
// Developer:		Adrian Bernat
// Course Number:	CS-260
// Date:			4-16-17
// IDE:				Visual Studio 2015
// Description:		Contains the implementation for the stringList class.
//*******************************************************************************
#include <iostream>
#include "stringList.h"

//=================================================
stringList::stringList() {
	head = NULL;
	tail = NULL;
	itemsInList = 0;
}

//==================================================
stringList::~stringList() {
	
}

//==================================================
bool stringList::insert(const std::string item) {
	//make a new node
	Node* nodeToInsert = new Node;
	nodeToInsert->data = item;
	nodeToInsert->next = NULL;
	nodeToInsert->prev = NULL;

	//case for empty list
	if (head == NULL) {
		head = nodeToInsert;
		tail = nodeToInsert;
		itemsInList++;
		return true;
	}

	//puts an item in the first slot
	if (nodeToInsert->data <= head->data) {
		nodeToInsert->next = head;
		head = nodeToInsert;
		nodeToInsert->next->prev = nodeToInsert;
		itemsInList++;
		return true;
	}

	//puts an item in the last spot of the list
	if (nodeToInsert->data >= tail->data) {
		nodeToInsert->prev = tail;
		nodeToInsert->prev->next = nodeToInsert;
		tail = nodeToInsert;
		itemsInList++;
		return true;
	}

	//insert new node in the middle of the list
	Node* curr = head->next;
	while (curr->data <= nodeToInsert->data) {
		curr = curr->next;
	}
	curr->prev->next = nodeToInsert;
	nodeToInsert->prev = curr->prev;
	nodeToInsert->next = curr;
	curr->prev = nodeToInsert;
	itemsInList++;
	return true;
}

//=================================================
int stringList::totalItems() const {
	int total = 0;
	Node* curr = head;

	while (curr != NULL) {
		total++;
		curr = curr->next;
	}

	return total;
}

//=================================================
void stringList::printForward() const {
	Node* current = head;

	while (current != NULL) {
		if (current->next != NULL) {
			std::cout << current->data << ", ";
			current = current->next;	
		}

		else {
			std::cout << current->data;
			current = current->next;
		}
	}
	std::cout << std::endl;
}

//===================================================
int stringList::remove(std::string item) {
	int deletedItems = 0;
	//special case for empty list
	if (head == NULL)
		return 0;
	
	Node* current = head;
	Node* nextNode = NULL;
	Node* prevNode = NULL;

	//iterate through the list
	while (current != NULL) {
		//if deleting the first item and there are more items in the list
		if (current->data == item && current->prev == NULL && itemsInList > 1) {
			nextNode = current->next;
			head = current->next;

			delete current;
			//we deleted the first node, so we reset the next node's prev to null
			nextNode->prev = NULL;

			//decrememnt and increment
			deletedItems++;
			itemsInList--;

			//set the current back to head
			current = head;
			prevNode = current->prev;
		}
		
		//if we are dealing with a list with only the deleting item
		else if (current->data == item && current->prev == NULL && itemsInList == 1) {
			delete current;

			//reset to an empty list
			head = NULL;
			tail = NULL;

			itemsInList--;
			deletedItems++;
			return deletedItems;
		}

		//deleting the last item in the list
		else if (current->data == item && current->next == NULL) {
			prevNode->next = NULL;
			tail = prevNode;
			delete current;

			current = NULL;
			itemsInList--;
			deletedItems++;
		}

		else if (current->data == item) {
			nextNode = current->next;
			prevNode->next = nextNode;
			nextNode->prev = prevNode;
			delete current;

			deletedItems++;
			itemsInList--;

			current = nextNode;
		}

		else {
			prevNode = current;
			current = current->next;
		}
	}
	return deletedItems;
}

//===================================================
void stringList::removeAll() {
	if (head == NULL)
		return;

	recursionRemoveAll(tail);

	//reset the LL to be empty
	head = NULL;
	tail = NULL;
	itemsInList = 0;
}

//===================================================
int stringList::recursionRemoveAll(Node* current) {
	//base case
	if (current == NULL)
		return 1;

	//normala case
	Node* previous = current->prev;
	delete current; //deletes the current node, 

	recursionRemoveAll(previous); //then does the same thing for the previous node
	return 0;
}

//===================================================
void stringList::printReverse() const {
	Node* current = tail;

	while (current != NULL) {
		if (current->prev != NULL) {
			std::cout << current->data << ", ";
			current = current->prev;
		}

		else {
			std::cout << current->data;
			current = current->prev;
		}
	}
	std::cout << std::endl;
}

//===================================================
int stringList::find(std::string item) const {
	return recursiveFind(head, item);
}

//===================================================
int stringList::recursiveFind(Node* node, std::string item) const {
	//base case
	if (node == NULL) {
		return 0;
	}

	//normal case
	else {
		if (node->data == item)
			return 1 + recursiveFind(node->next, item);

		else
			return recursiveFind(node->next, item);
	}
}

//===================================================
int stringList::findLetter(char letter) const {
	return findLetterRecursion(letter, head);
}

//===================================================
int stringList::findLetterRecursion(char letter, Node* node) const {
	int charCount = 0;
	//base case
	if (node == NULL) {
		return 0;
	}

	//normal case
	if (node->data.find(letter) != std::string::npos) {
		return findLetterRecursion(letter, node->next) + 1;
	}

}