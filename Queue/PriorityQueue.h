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

const int TIME_SLICE = 20;
const int DATA_SIZE = 20;
const int MAX_ITEMS = 100;

struct dataStruct {
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
	void prioritySimulation(dataStruct printArray[MAX_ITEMS]);
	
	void addDataStruct(dataStruct data);
	
	void printSim(dataStruct printArray[], int size);



private:
	std::queue<dataStruct> priorityQ[5];

};