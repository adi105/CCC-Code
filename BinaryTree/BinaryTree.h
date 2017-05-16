//******************************************************************************
// Program Name:	BinaryTree.h
// Developer:		Adrian Bernat
// Course Number:	CS-260
// Date:			5-10-17
// IDE:				Visual Studio 2015
// Description:		Contains the code that creates a binary search tree class
//					and declares all of the functions required
//*******************************************************************************
#pragma once
#include <string>

struct Node {
	std::string data;
	Node* left;
	Node* right;
};

class BinaryTree {
public:
	//constructor
	BinaryTree();

	//destructor
	~BinaryTree();

	//mutator
	bool insert(std::string data);

	bool remove(std::string data);

	void removeNode(Node* &nodeToDelete);

	bool clearTree();

	void clearTreeRec(Node* &current);

	//accessor
	void printInOrder();

	void printPreorder();

	void printPostorder();

	void printInOrderRec(Node* node);

	void printPreorderRec(Node* node);

	void printPostorderRec(Node* node);

private:
	Node* root;

};