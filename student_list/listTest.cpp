//**************************************************************************************************
// Program Name:	listTest
// Developer:		Adrian Bernat
// Course Number:	CS-162-02
// Date:			2-1-17
// IDE:				Visual Studio 2015
// Description:		Runs through several instances calling the functions of the List class as to test
//					if all of the functions work in every instance possible.
//**************************************************************************************************

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "list.h"

using namespace std;

int main() {
	List names;

	ifstream inputStream;
	string file = "tester.txt";

	//open the file
	inputStream.open(file);
	if (!inputStream) {
		cout << "File " << file << " was not opened. \n";
		return -1;
	}
	else
		cout << "Processing " << file << endl;
	
	//Read the data inside
	string strLine;
	char letter;
	char space;
	while (inputStream.eof() == false) {
		inputStream >> letter;
		getline(inputStream, strLine);
		strLine.erase(0, 1);


		if (letter == 'A') {
			if (names.insert(strLine))
				cout << "Add:\t " << strLine << endl;
			else
				cout << strLine << " has failed to add" << endl;
		}

		else if (letter == 'P') {
			cout << "Print:\t ";
			names.printList();
		}
		else if (letter == 'F') {
			cout << "Find:\t ";
			if (names.inList(strLine))
				cout << strLine << endl;
			else
				cout << strLine << " - FAILED" << endl;
		}
		else if (letter == 'R') {
			if (names.remove(strLine))
				cout << "Remove:\t " << strLine << endl;
			else
				cout << strLine << " - FAILED" << endl; 
		}
		else
			cout << "[ERROR]: " << "Invalid action: " << letter << endl;
	}
}