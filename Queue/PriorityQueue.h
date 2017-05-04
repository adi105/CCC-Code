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

const int MAX_ITEMS = 100;
const int MAX_PRIORITY = 5;
const int TIME_SLICE = 20;

struct dataStruct {
	int PID;
	int timeNeeded;
	int timeEnded;
	int timeLeft;
	int initialPriority;
	int finalPriority;
};

class PriorityQueue {
public:
	//runs the simulation that tells how long the processes take to finish
	void prioritySimulation(int size);

	//inserts the given data into the queue based on its priority
	void addDataStruct(dataStruct data);

	//prints the data to the console
	void printSim(dataStruct printArray[], int size);

private:
	std::queue<dataStruct> priorityQ[MAX_PRIORITY];
};