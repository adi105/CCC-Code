//******************************************************************************
// Program Name:	SchedulerSimTest
// Developer:		Adrian Bernat
// Course Number:	CS-260
// Date:			4-30-17
// IDE:				Visual Studio 2015
// Description:		Contains the code that tests the Scheduler Simulator written
//					with queues.
//*******************************************************************************
#include <iostream>
#include "PriorityQueue.h"
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
	PriorityQueue* priorityQ = new PriorityQueue;
	string fileName;
	//see if any arguments were passsed in console
	if (argc >= 2) {
		fileName = argv[1];
	}
	
	//else, use sim.data
	else {
		fileName = "sim.data";
	}
	
	//handle an invalid filename error
	ifstream fileData(fileName);
	if (fileData.fail()) {
		cerr << "Invalid Filename, exiting..." << endl;
		return 0;
	}

	//use ifstream commands to take info from the file
	//and construct the dataStruct to add to the queue
	int count = 0;
	int pid = 0;
	int time;
	int priority;
	while (fileData >> priority) {
		dataStruct newData;
		fileData >> time;
		newData.initialPriority = priority;
		newData.timeNeeded = time;
		newData.timeLeft = time;
		newData.PID = pid;
		pid++;
		priorityQ->addDataStruct(newData);
		count++;
	}

	//output to the console
	cout << "NAME: Adrian Bernat" << endl;
	cout << "FILE NAME: " << fileName << endl << endl;

	priorityQ->prioritySimulation(count);

	return 0;
}