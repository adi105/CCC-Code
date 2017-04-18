//******************************************************************************
// Program Name:	stringListTest.cpp
// Developer:		Adrian Bernat
// Course Number:	CS-260
// Date:			4-16-17
// IDE:				Visual Studio 2015
// Description:		Contains the code that tests and runs the stringList class,
//					using a doubly linked list on strings.
//*******************************************************************************
#include <iostream>
#include "stringList.h"

using namespace std;

int main() {
	stringList* LL = new stringList;
	LL->insert("Bob");
	LL->insert("George");
	LL->printForward();
	LL->insert("Fred");
	LL->insert("Alfred");
	LL->printForward();

	cout << LL->remove("Fred") << endl;

	LL->printForward();
	LL->printReverse();

	return 0;
}