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

//transverses the binary tree until it finds the place
//for the data, then inserts the data and returns true
//when finished
//==================================================
bool BinaryTree::insert(std::string data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL) {
        root = newNode;
        return true;
    }

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