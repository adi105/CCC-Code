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
#include <iostream>
#include <string>
#include <functional>

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

	BinaryTree* copyTree();

	bool clearTree();

	//accessor
	void transverseInOrder(const std::function<void(std::string, int)> &funcToCall);

	void transversePreorder(const std::function<void(std::string, int)> &funcToCall);

	void transversePostorder(const std::function<void(std::string, int)> &funcToCall);

private:
	Node* root;

	void transverseInOrderRec(Node* currentNode, const std::function<void(std::string, int)> &funcToCall, int height);

	void transversePreorderRec(Node* currentNode, const std::function<void(std::string, int)> &funcToCall, int height);

	void transversePostorderRec(Node* currentNode, const std::function<void(std::string, int)> &funcToCall, int height);

	void clearTreeRec(Node* &current);

	void copyTreeRec(Node* &originalRoot, Node* otherTreeRoot);

};