//******************************************************************************
// Program Name:	stackFun
// Developer:		Adrian Bernat
// Course Number:	CS-260
// Date:			4-25-17
// IDE:				Visual Studio 2015
// Description:		Contains the code that uses the stack template library to
//					create a postfix calculator
//*******************************************************************************
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

//prototypes
string stripWhiteSpace(string infix);
bool isValid(string infix);
string convertPostfix(string infix);
void evaluate();
int operatorWeight(string op);
bool hasHigherPrecedence(char op1, char op2);

int main() {
	string infix = "5 * - 6 8";
	string postFix;

	cout << "Author: Adrian Bernat" << endl << endl;
	cout << "Processing " << infix << endl;

	//strip the white space from the input
	string noWhiteSpace = stripWhiteSpace(infix);

	//validate the whitespace
	isValid(noWhiteSpace);

	//convert to postfix
	postFix = convertPostfix(noWhiteSpace);
	cout << postFix << endl;

	return 0;
}

//=======================================================
string stripWhiteSpace(string infix) {
	string newString;
	
	//strips all of the whitespace from a string
	while (infix.find(' ') != infix.npos)
		newString = infix.erase(infix.find(' '), 1);
	
	return newString;
}

//=======================================================
bool isValid(string infix) {
	for (int index = 0; index < infix.length(); index++) {
		if (isdigit(infix.at(index)) == 0) {
			if (infix.at(index) != ')' && infix.at(index) != '(' && infix.at(index) != '+' && infix.at(index) != '-' && infix.at(index) != '*' && infix.at(index) != '/') {
				cout << "INFIX:\tERROR: " << infix.at(index) << " is not a valid character." << endl;
				return false;
			}
		}
	}
	cout << "INFIX:\t" << infix << endl;
	return true;
}

//=======================================================
string convertPostfix(string infix) {
	string postFix;
	stack<char> numStack;

	for (int index = 0; index < infix.length(); index++) {
		if (isdigit(infix.at(index))) {
			postFix += (infix.at(index));
		}

		else if (infix.at(index) == '(') {
			numStack.push(infix.at(index));
		}

		else if (infix.at(index) == '+' || infix.at(index) == '-' || infix.at(index) == '*' || infix.at(index) == '/') {
			if (!numStack.empty()) {
				while (hasHigherPrecedence(numStack.top(), infix.at(index))) {
					postFix += numStack.top();
					numStack.pop();
				}
				numStack.push(infix.at(index));
			}
			else if (numStack.empty())
				numStack.push(infix.at(index));
		}
		else if (infix.at(index) == ')') {
			while (!numStack.empty() && numStack.top() != '(') {
				postFix += numStack.top();
				numStack.pop();	
			}
			numStack.pop();
		}
	}

	while (!numStack.empty()) {
		postFix += numStack.top();
		numStack.pop();
	}
	return postFix;
}

//calculates the weight of the operators
//by using a switch statement
//=======================================
int operatorWeight(char op) {
	int weight = 0;
	switch (op) {
	case '+':
	case '-':
		weight = 1;
	case '*':
	case '/':
		weight = 2;
	}
	return weight;
}

//this function tests if the char in the first argument slot
//has a higher precedence than the char in the second slot
//returns true if first char has higher precedence
//returns false otherwise
//==========================================================
bool hasHigherPrecedence(char op1, char op2) {
	int op1Weight = operatorWeight(op1);
	int op2Weight = operatorWeight(op2);

	//if the weights are the same, we assume the first one has higher precedence
	if (op1Weight == op2Weight)
		return true;

	return op1Weight > op2Weight ? true : false;
}