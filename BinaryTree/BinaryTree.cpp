//******************************************************************************
// Program Name:	BinaryTree.cpp
// Developer:		Adrian Bernat
// Course Number:	CS-260
// Date:			5-10-17
// IDE:				Visual Studio 2015
// Description:		Contains the code that implements a binary search tree class
//*******************************************************************************
#include "BinaryTree.h"
#include <iostream>

//==================================================
BinaryTree::BinaryTree() {
	root = NULL;
}

BinaryTree::~BinaryTree() {
	clearTree();
}

//transverses the binary tree until it finds the place
//for the data, then inserts the data and returns true
//when finished
//==================================================
bool BinaryTree::insert(std::string data) {
	//create the new node
	Node* newNode = new Node;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	//check for special case when list is empty
	if (root == NULL) {
		root = newNode;
		return true;
	}

	//transverse the list and insert where needed
	Node* current = root;
	bool done = false;
	while (!done) {
		if (newNode->data < current->data) {
			if (current->left == NULL) {
				current->left = newNode;
				done = true;
			}
			else
				current = current->left;
		}
		else {
			if (current->right == NULL) {
				current->right = newNode;
				done = true;
			}
			else
				current = current->right;
		}
	}
	return true;
}

//===========================================================
bool BinaryTree::remove(std::string data) {
	//declare variables that will be used
	Node* current = root;
	Node* parent = NULL;
	bool isFound = false;

	//find the item to remove
	while (current != NULL && !isFound) {
		if (current->data == data)
			isFound = true;
		else {
			parent = current;
			if (data < current->data)
				current = current->left;
			else
				current = current->right;
		}
	}

	//after the item is found, we need to remove it
	if (isFound) {
		if (current == NULL)
			removeNode(root);
		else if (data < parent->data)
			removeNode(parent->left);
		else
			removeNode(parent->right);
		return true;
	}
	else
		return false;
}

//==========================================================
void BinaryTree::removeNode(Node* &nodeToDelete) {
	Node* temp;
	//if the node has no children
	if (nodeToDelete->left == NULL && nodeToDelete->right == NULL) {
		temp = nodeToDelete;
		nodeToDelete = NULL;
		delete temp;
	}

	//if only one child
	else if (nodeToDelete->right == NULL) {
		temp = nodeToDelete;
		nodeToDelete = nodeToDelete->left;
		delete temp;
	}

	else if (nodeToDelete->left == NULL) {
		temp = nodeToDelete;
		nodeToDelete = nodeToDelete->right;
		delete temp;
	}

	//special case where the node has two children
	else {
		Node* current = nodeToDelete->left;
		Node* parent = NULL;

		while (current->right != NULL) {
			parent = current;
			current = current->right;
		}

		nodeToDelete->data = current->data;

		if (parent == NULL)
			nodeToDelete->left = current->left;
		else
			parent->right = current->left;
		delete current;
	}

}

//===========================================================
bool BinaryTree::clearTree() {
	if (root == NULL) {
		return false;
	}

	else {
		clearTreeRec(root);
		return true;
	}
}

//===========================================================
void BinaryTree::clearTreeRec(Node* &current) {
	//base case
	if (current == NULL)
		return;

	//special case
	clearTreeRec(current->left);
	current->left = NULL;

	clearTreeRec(current->right);
	current->right = NULL;

	delete current;
	current = NULL;
}

//===========================================================
void BinaryTree::printInOrder() {
	printInOrderRec(root);
}

//===========================================================
void BinaryTree::printInOrderRec(Node* node) {
	if (node == NULL)
		return;

	printInOrderRec(node->left);
	std::cout << node->data << " ";
	printInOrderRec(node->right);
}

//===========================================================
void BinaryTree::printPreorder() {
	printPreorderRec(root);
}

//===========================================================
void BinaryTree::printPreorderRec(Node* node) {
	if (node == NULL)
		return;

	std::cout << node->data << " ";
	printInOrderRec(node->left);
	printInOrderRec(node->right);
}

//============================================================
void BinaryTree::printPostorder() {
	printPostorderRec(root);
}

//============================================================
void BinaryTree::printPostorderRec(Node* node) {
	if (node == NULL)
		return;

	printInOrderRec(node->left);
	printInOrderRec(node->right);
	std::cout << node->data << " ";
}