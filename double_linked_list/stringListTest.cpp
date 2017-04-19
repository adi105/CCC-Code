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
	LL->insert("Fred");

	LL->insert("Bob");
	LL->insert("Bob");
	LL->insert("George");
	LL->insert("George");
	LL->printForward();

	cout << "Bob is present " << LL->find("Bob") << " times." << endl;
	cout << "George is present " << LL->find("George") << " times." << endl;
	cout << "Fred is present " << LL->find("Fred") << " times." << endl;

	cout << "The letter 'o' is present " << LL->findLetter('o') << " times." << endl;
	cout << "The letter 'a' is present " << LL->findLetter('a') << " times." << endl;
	cout << "The letter 'e' is present " << LL->findLetter('e') << " times." << endl;
	cout << "The letter 'g' is present " << LL->findLetter('g') << " times." << endl;

	return 0;
}