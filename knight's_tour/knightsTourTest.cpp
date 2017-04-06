//******************************************************************************
// Program Name:	knightsTour.cpp
// Developer:		Adrian Bernat
// Course Number:	CS-162-02
// Date:			3-11-17
// IDE:				Visual Studio 2015
// Description:		Contains the code that runs a knight's tour calculator
//*******************************************************************************
#include <iostream>
#include "knightsTour.h"
using namespace std;

//prototypes
int solveKnightsTour(Chess chess, int row, int column, int currentMoveNumber, bool toPrint);

int main() {
	Chess chess;
	bool toPrint;
	
	cout << "Welcome to the Knight's Tour Calculator!" << endl << endl;

	//inquiry for whether solutions should be printed
	cout << "Do you want the solutions to be printed? [1 = yes || 0 = no] ";
	cin >> toPrint;
	
	//inquiry for how big the board should be
	cout << "How large should the board be? [i.e. type 5 for 5x5 board]: ";
	cin >> chess.boardSize;

	//inquiry for starting position of the knight
	cout << "What is your starting X coordinate? [default = 3]: ";
	cin >> chess.startX;
	cout << "What is your starting Y coordinate? [default = 3]: ";
	cin >> chess.startY;

	chess.startX--;
	chess.startY--;

	cout << endl;

	cout << "Total Solutions: " << solveKnightsTour(chess, chess.startX, chess.startY, 1, toPrint) << endl;
	
	//allows the user to keep the console open
	cin.get();
	cin.ignore();

	return 0;
}

//function to solve the tour
int solveKnightsTour(Chess chess, int row, int column, int currentMoveNumber, bool toPrint) {
	int totalSolutions = 0;
	int originalNumber = 0;

	//if the move is invalid, there are no solutions
	if (chess.isMoveInvalid(row, column, chess.boardSize)) {
		return 0;
	}

	chess.chessBoard[row][column] = currentMoveNumber;

	//condition to test if the board is full
	if (chess.isBoardFull() == true) {
		if (toPrint)
			chess.boardPrinter();
		return 1;
	}

	//recursion

	originalNumber = currentMoveNumber;
	for (int moves = 0; moves < 8; moves++) {
		totalSolutions += solveKnightsTour(chess, (row + chess.possibleRow[moves]), (column + chess.possibleCol[moves]), ++currentMoveNumber, toPrint);
		currentMoveNumber = originalNumber;
	}

	return totalSolutions;


}

/*
Extra Credit Answers:
1.	If we had a 4x4 board, then there would be no possible solutions to the knight's tour.

2.	The recursive function needs a copy of the board to function, because it is playing out 
	the game on the board individually with each of the first 8 calls. Every time it goes
	"down the rabbit hole," it needs a new copy of the board.
*/