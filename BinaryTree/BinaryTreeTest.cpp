//******************************************************************************
// Program Name:	BinaryTreeTest
// Developer:		Adrian Bernat
// Course Number:	CS-260
// Date:			5-10-17
// IDE:				Visual Studio 2015
// Description:		Contains the code that holds the main function for the binary
//					search tree and tests the various functions inside the class
//*******************************************************************************

#include "BinaryTree.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	cout << "CS260 Assignment 5a -  Binary Trees, part 1" << endl;

	cout << "Author: Adrian Bernat" << endl;

	BinaryTree bTree;

	bTree.insert("Jynx");
	bTree.insert("Charmander");
	bTree.insert("Snorlax");
	bTree.insert("Clefairy");
	bTree.insert("Diglett");
	bTree.insert("Kakuna");
	bTree.insert("Meowth");
	bTree.insert("Nidorino");
	bTree.insert("Pikachu");
	bTree.insert("Blastoise");
	bTree.insert("Squirtle");
	bTree.insert("Ivysaur");
	bTree.insert("Bulbasaur");
	bTree.insert("Abra");
	cout << endl;

	cout << "Output in order:" << endl;
	bTree.printInOrder();
	cout << endl << endl;

	bTree.clearTree();
	bTree.printInOrder();

	//cout << "Output in postorder:" << endl;
	//bTree.printPostorder();
	//cout << endl << endl;

	//cout << "Output in preorder:" << endl;
	//bTree.printPreorder();
	cout << endl << endl;

	return 0;
}