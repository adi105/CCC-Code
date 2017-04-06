//**************************************************************************************************
// Program Name:	linkedListTest.cpp
// Developer:		Adrian Bernat
// Course Number:	CS-162-02
// Date:			3-5-17
// IDE:				Visual Studio 2015
// Description:		Contains the main function for testing of the linked list class
//**************************************************************************************************
#include <iostream>
#include "linkedList.h"

using namespace std;

//prototypes
void insertion(linkedList* LL, string insert);
void removal(linkedList* LL, string remove);

int main() {
	//create a new Linked List
	linkedList* LL = new linkedList;
	
	//insert a few names
	insertion(LL, "Bill");
	insertion(LL, "Adam");
	insertion(LL, "Zorro");
	insertion(LL, "Adam");
	insertion(LL, "Kelly");
	insertion(LL, "Chris");

	//print out total number of items
	cout << "There are " << LL->count() << " strings in the list." << endl;

	//Create a duplicate
	linkedList* newLL = new linkedList;
	newLL = LL->duplicate();
	
	cout << "The new list is: ";
	newLL->print();
	cout << endl;

	
	//print backwards
	cout << "The list backwards is: ";
	LL->printReverse();
	cout << endl;

	//delete some strings
	removal(LL, "Zorro");
	removal(LL, "Charlie");
	removal(LL, "Becky");
	removal(LL, "Adam");
	removal(LL, "Kelly");

	//manipulate the new list
	cout << "Manipulating of the new list: " << endl << endl;
	insertion(newLL, "Sam");
	cout << "The new list has " << newLL->count() << " strings" << endl;

	cout << "George is in slot " << newLL->find("George") << endl;
	cout << "Adam is in slot " << newLL->find("Adam") << endl;
	cout << "Kelly is in slot " << newLL->find("Kelly") << endl;
	cout << "Zorro is in slot " << newLL->find("Zorro") << endl;

	delete newLL;

	cout << "Done" << endl;
	

	return 0;
}

void insertion(linkedList* LL, string insert) {
	LL->insert(insert);
	cout << "The list is: ";
	LL->print();
	cout << endl;
}

void removal(linkedList* LL, string remove) {
	LL->remove(remove);
	cout << "The list is: ";
	LL->print();
	cout << endl;
}