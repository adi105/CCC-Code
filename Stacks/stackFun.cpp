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
void calculator(string infix);
string stripWhiteSpace(string infix);
bool isValid(string infix);
bool isOperator(char letter);
string convertPostfix(string infix);
bool evaluate(string postfix, int& result);
int operatorWeight(char op);
bool hasHigherPrecedence(char op1, char op2);

int main() {
	cout << "Author: Adrian Bernat" << endl << endl;

	calculator("5 # 2");

	calculator("5 * - 6 8");

	calculator("5*2   +  3");

	calculator("3 + 5 * (7-2)");

	calculator("3 + ( (8-5) * (4+9) )");

	calculator("6 / 3");

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

//checks if the string contains any invalid characters,
//i.e. anything other than a digit and an operator.
//returns true if valid, false if invalid
//=======================================================
bool isValid(string infix) {
	//test for empty string
	if (infix == "")
		return false;
	for (int index = 0; index < infix.length(); index++) {
		if (isdigit(infix.at(index)) == 0) {
			if (!isOperator(infix.at(index))) {
				cout << "INFIX:\tERROR: " << infix.at(index) << " is not a valid character." << endl << endl;
				return false;
			}
		}
	}
	cout << "INFIX:\t" << infix << endl;
	return true;
}

//converts the given infix string to postfix by using
//a stack and string
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
				while (!numStack.empty() && (hasHigherPrecedence(numStack.top(), infix.at(index)))) {
					postFix += numStack.top();
					numStack.pop();
				}
				numStack.push(infix.at(index));
			}
			else if (numStack.empty())
				numStack.push(infix.at(index));
		}
		else if (infix.at(index) == ')') {
			while (numStack.empty() == false && numStack.top() != '(') {
				postFix += numStack.top();
				numStack.pop();
			}
			numStack.pop();
		}
	}

	while (!numStack.empty()) {
		if (numStack.top() != '(' && numStack.top() != ')') {
			postFix += numStack.top();
			numStack.pop();
		}
		else {
			numStack.pop();
		}
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
		break;
	case '*':
	case '/':
		weight = 2;
		break;
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

//function that evaluates the postix string and returns the
//result of the calculation
//==========================================================
bool evaluate(string postfix, int& result) {
	stack<int> calcStack;

	//iterate through the string
	for (int index = 0; index < postfix.length(); index++) {
		//if the char is an int
		if (isdigit(postfix.at(index))) {
			int operand = postfix.at(index) - '0';
			calcStack.push(operand);
		}
		else {
			//store the previous two numbers in integers, to perform the operation
			int num1 = calcStack.top();
			calcStack.pop();
			
			//checks if the stack encounters an operator and does not have two integers inside of it
			if (calcStack.empty())
				return false;

			int num2 = calcStack.top();
			calcStack.pop();

			//switch statement to perform the given operation
			switch (postfix.at(index)) {
			case '+':
				result = (num1 + num2);
				break;
			case '-':
				result = (num2 - num1);
				break;
			case '*':
				result = (num1 * num2);
				break;
			case '/':
				result = (num2 / num1);
			}
			calcStack.push(result);
		}
	}
	return true;
}

//tests if the given char is an operator for code brevity
//========================================================
bool isOperator(char letter) {
	if (letter == ')' || letter == '(' || letter == '+' || letter == '-' || letter == '*' || letter == '/')
		return true;
	else
		return false;
}

//this contains the main sequence of converting to postfix, then to infix,
//then calculating the results.
//=================================================================
void calculator(string infix) {
	string postFix;
	int total = 0;

	cout << "Processing " << infix << endl;

	//strip the white space from the input
	string noWhiteSpace = stripWhiteSpace(infix);

	//validate the whitespace
	if (!isValid(noWhiteSpace))
		return;

	//convert to postfix
	postFix = convertPostfix(noWhiteSpace);
	cout << "POSTFIX:" << postFix << endl;

	if (evaluate(postFix, total))
		cout << "TOTAL:\t" << total << endl << endl;
	else
		cout << "TOTAL:\tERROR" << endl << endl;
}