//******************************************************************************
// Program Name:	knightsTour.cpp
// Developer:		Adrian Bernat
// Course Number:	CS-162-02
// Date:			3-11-17
// IDE:				Visual Studio 2015
// Description:		Contains the code that implements the functions contained
//					in knightsTour.h
//*******************************************************************************

#include <iostream>
#include <iomanip>
#include "knightsTour.h"
using namespace std;

//===============================================
void Chess::boardPrinter() {
	static int numOfSolutions = 1;
	
	int x = 0; // Counter to control printing new lines

	cout << "Solution #" << numOfSolutions << endl;

	for (int row = 0; row < boardSize; row++)
		for (int col = 0; col < boardSize; col++) {
			cout << setfill('0') << setw(2) << chessBoard[row][col] << " ";
			x++;
			if (x == boardSize) {
				cout << endl;
				x = 0;
			}
		}
	cout << endl;
	numOfSolutions++;
	cout << "\n";
}

//================================================================
//Checks to see if the given move is valid. Returns true if the 
//move is valid, and false if the move is out of bounds.
//================================================================
bool Chess::isMoveInvalid(int xCoord, int yCoord, int boardSize) {
	if ((xCoord < 0 || xCoord >= boardSize) || (yCoord < 0 || yCoord >= boardSize) || chessBoard[xCoord][yCoord] > 0)
		return true;

	else
		return false;
}

//====================================================================
//Checks to see if the board is full by iterating through the board
//If all of the slots are occupied, returns true; else, returns false
//===================================================================
bool Chess::isBoardFull() {
	for (int row = 0; row < boardSize; row++) {
		for (int col = 0; col < boardSize; col++) {
			if (chessBoard[row][col] == 0) {
				return false;
			}
		}
	}
	return true;
}