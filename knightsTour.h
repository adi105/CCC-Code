#pragma once
//**************************************************************************************************
// Program Name:	knightsTour.h
// Developer:		Adrian Bernat
// Course Number:	CS-162-02
// Date:			3-11-17
// IDE:				Visual Studio 2015
// Description:		Contains the variables of the chess board so that it can be copied instead of
//					passed by reference.
//**************************************************************************************************
#include <iostream>

class Chess {
public:
	//values to initialize the board
	int boardSize = 5;
	int chessBoard[10][10] = {};
	int startX = 3;
	int startY = 3;
	int possibleRow[8] = { 1,  2,  2, 1, -1, -2, -2, -1 };
	int possibleCol[8] = { -2, -1, 1, 2, -2, -1,  1,  2 };

	//function that prints the board
	void boardPrinter();

	//function that checks to see if the move is valid
	bool isMoveInvalid(int xCoord, int yCoord, int boardSize);

	//function that checks if the board is full
	bool isBoardFull();
};