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

//prototype
void printNode(const string &data, int level);

int main() {
	cout << "CS260 Assignment 5a -  Binary Trees" << endl;

	cout << "Author: Adrian Bernat" << endl;

	//declare a tree
	BinaryTree bTree;
	BinaryTree* bTree2;

	//insert a few names
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
	
	//print in order
	bTree.transverseInOrder(printNode);
	cout << endl;

	//make a deep copy
	bTree2 = bTree.copyTree();

	//delete a few names
	cout << "Deleting Squirtle..." << endl;
	bTree.remove("Squirtle");
	bTree.transverseInOrder(printNode);
	cout << endl;

	cout << "Deleting Meowth..." << endl;
	bTree.remove("Meowth");
	bTree.transverseInOrder(printNode);
	cout << endl;

	cout << "Deleting Blastoise..." << endl;
	bTree.remove("Blastoise");
	bTree.transverseInOrder(printNode);
	cout << endl;

	cout << "Deleting Jynx..." << endl;
	bTree.remove("Jynx");
	bTree.transverseInOrder(printNode);
	cout << endl;

	//print the full copied tree contents
	cout << "Copied tree's contents: \nInorder:" << endl;
	bTree2->transverseInOrder(printNode);
	cout << endl;

	cout << "Postorder:" << endl;
	bTree2->transversePostorder(printNode);
	cout << endl;

	cout << "Preorder:" << endl;
	bTree2->transversePreorder(printNode);
	cout << endl;

	//remove all nodes from copy and print
	bTree2->clearTree();
	bTree2->transverseInOrder(printNode);
	return 0;
}

void printNode(const string &data, int level) {
	if (level < 0)
		level = 0;

	cout << data << "(" << level << ") ";
}

