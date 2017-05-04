//******************************************************************************
// Program Name:	PriorityQueue
// Developer:		Adrian Bernat
// Course Number:	CS-260
// Date:			4-30-17
// IDE:				Visual Studio TIME_SLICE15
// Description:		Contains the implementation for the PriorityQueue class
//*******************************************************************************
#include <iostream>
#include "PriorityQueue.h"

//=====================================================
void PriorityQueue::printSim(dataStruct printArray[], int size) {
	printf("%-15s %-15s %-15s %-15s %-15s %-15s \n", "ProcessID", "Priority(Init)", "Time Needed", "Time Started", "Time Ended", "Priority(Final)");

	for (int index = 0; index < size; index++) {
		printf("%-15d %-15d %-15d %-15d %-15d %-15d \n", printArray[index].PID + 1, printArray[index].initialPriority, printArray[index].timeNeeded, 0, printArray[index].timeEnded, printArray[index].finalPriority);
	}
}


//======================================================
void PriorityQueue::addDataStruct(dataStruct data) {
	priorityQ[data.initialPriority].push(data);
}

//======================================================
void PriorityQueue::prioritySimulation(int size) {
	int clock = 0;
	dataStruct printArray[MAX_ITEMS];

	//deal with priorities up until the last, as they are identical
	for (int index = 0; index < (MAX_PRIORITY - 1); index++) {
		while (priorityQ[index].empty() != true) {
			dataStruct inputSim = priorityQ[index].front();
			if (inputSim.timeLeft <= TIME_SLICE) {
				clock += inputSim.timeLeft;
				inputSim.timeLeft = 0;
				inputSim.timeEnded = clock;
				inputSim.finalPriority = index;
				priorityQ[index].pop();
				printArray[inputSim.PID] = inputSim;
			}
			else {
				clock += TIME_SLICE;
				inputSim.timeLeft -= TIME_SLICE;
				priorityQ[index].pop();
				priorityQ[(index + 1)].push(inputSim);
			}
		}
	}

	//final priority level
	while (priorityQ[MAX_PRIORITY - 1].empty() != true) {
		dataStruct inputSim = priorityQ[MAX_PRIORITY - 1].front();
		if (inputSim.timeLeft <= TIME_SLICE) {
			clock += inputSim.timeLeft;
			inputSim.timeLeft = 0;
			inputSim.timeEnded = clock;
			inputSim.finalPriority = 4;
			priorityQ[MAX_PRIORITY - 1].pop();
			printArray[inputSim.PID] = inputSim;
		}
		else {
			clock += TIME_SLICE;
			inputSim.timeLeft -= TIME_SLICE;
			priorityQ[MAX_PRIORITY - 1].pop();
			//we need to reroute items into the same queue until they are finished, as they all have the same priority
			priorityQ[MAX_PRIORITY - 1].push(inputSim);
		}
	}
	//print the sim results once the simulation is done
	printSim(printArray, size);
}
