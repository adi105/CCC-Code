#pragma once
//******************************************************************************
// Program Name:	PriorityQueue
// Developer:		Adrian Bernat
// Course Number:	CS-260
// Date:			4-30-17
// IDE:				Visual Studio 2015
// Description:		Contains the queues that manage the priority classes
//*******************************************************************************
#include <queue>

struct data {
	int PID;
	int timeTotal;
	int timeEnded;
	int timeLeft;
	int initialPriority;
	int finalPriority;
};

class PriorityQueue {
public:
	
	//inserts the given data into the queue based on its priority
	bool enQueue(int data, int priority);



private:
	std::queue<data> Q[5];
};