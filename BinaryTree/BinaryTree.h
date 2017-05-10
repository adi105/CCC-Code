#pragma once

template <class dataType>
struct Node {
	dataType data;
	Node* left;
	Node* right;
};

template <class dataType>
class BinaryTree {
public:
	//constructor
	BinaryTree();

	//accessor
	void printInOrder();

private:
	Node* root;
	
	//printing in postorder and preorder require access to the root
	//therefore they are private functions
	void printPreRec(Node* curr);

	void printPostRec(Node* curr);

	void printInOrderRec(Node* curr);
};