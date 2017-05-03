//******************************************************************************
// Program Name:	PriorityQueue
// Developer:		Adrian Bernat
// Course Number:	CS-260
// Date:			4-30-17
// IDE:				Visual Studio 2015
// Description:		Contains the implementation for the PriorityQueue class
//*******************************************************************************
#include "PriorityQueue.h"

//=====================================================
void PriorityQueue::printSim(dataStruct printArray[], int size) {
	for (int index = 0; )
	return;
}


//======================================================
void PriorityQueue::addDataStruct(dataStruct data) {
	priorityQ[data.initialPriority].push(data);
}

//======================================================
void PriorityQueue::prioritySimulation(dataStruct printArray[MAX_ITEMS]) {
	int clock = 0;

	//deal with top priority items
	while (!priorityQ[0].empty()) {
		dataStruct inputSim = priorityQ[0].front();
		if (inputSim.timeLeft <= 20) {
			clock += inputSim.timeLeft;
			inputSim.timeLeft = 0;
			inputSim.timeEnded = clock;
			inputSim.finalPriority = 0;
			priorityQ[0].pop();
			printArray[inputSim.PID] = inputSim;
		}
		else {
			clock += 20;
			inputSim.timeLeft -= 20;
			priorityQ[0].pop();
			priorityQ[1].push(inputSim);
		}
	}

	//the second priority
	while (priorityQ[1].empty() != true) {
		dataStruct inputSim = priorityQ[1].front();
		if (inputSim.timeLeft <= 20) {
			clock += inputSim.timeLeft;
			inputSim.timeLeft = 0;
			inputSim.timeEnded = clock;
			inputSim.finalPriority = 1;
			priorityQ[1].pop();
			printArray[inputSim.PID] = inputSim;
		}
		else {
			clock += 20;
			inputSim.timeLeft -= 20;
			priorityQ[1].pop();
			priorityQ[2].push(inputSim);
		}
	}

	//third priority items
	while (priorityQ[2].empty() != true) {
		dataStruct inputSim = priorityQ[2].front();
		if (inputSim.timeLeft <= 20) {
			clock += inputSim.timeLeft;
			inputSim.timeLeft = 0;
			inputSim.timeEnded = clock;
			inputSim.finalPriority = 2;
			priorityQ[2].pop();
			printArray[inputSim.PID] = inputSim;
		}
		else {
			clock += 20;
			inputSim.timeLeft -= 20;
			priorityQ[2].pop();
			priorityQ[3].push(inputSim);
		}
	}
	
	//fourth priority items
	while (priorityQ[3].empty() != true) {
		dataStruct inputSim = priorityQ[3].front();
		if (inputSim.timeLeft <= 20) {
			clock += inputSim.timeLeft;
			inputSim.timeLeft = 0;
			inputSim.timeEnded = clock;
			inputSim.finalPriority = 3;
			priorityQ[3].pop();
			printArray[inputSim.PID] = inputSim;
		}
		else {
			clock += 20;
			inputSim.timeLeft -= 20;
			priorityQ[3].pop();
			priorityQ[4].push(inputSim);
		}
	}

	//final priority level
	while (priorityQ[4].empty() != true) { //least priority items
		dataStruct inputSim = priorityQ[4].front();
		if (inputSim.timeLeft <= 20) {
			clock += inputSim.timeLeft;
			inputSim.timeLeft = 0;
			inputSim.timeEnded = clock;
			inputSim.finalPriority = 4;
			priorityQ[4].pop();
			printArray[inputSim.PID] = inputSim;
		}
		else {
			clock += 20;
			inputSim.timeLeft -= 20;
			priorityQ[4].pop();
			//we need to reroute items into the same queue until they are finished, as they all have the same priority
			priorityQ[4].push(inputSim);
		}
	}
}

