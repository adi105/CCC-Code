#include "Sorter.h"

//==================================================================================
Sorter::Sorter() {
	cout << "Setting up arrays..." << endl;

	setupArrays(DS100->normal, DS100->reverse, DS100->random, DS100->ARRAY_SIZE);
	setupArrays(DS1k->normal, DS1k->reverse, DS1k->random, DS1k->ARRAY_SIZE);
	setupArrays(DS10k->normal, DS10k->reverse, DS10k->random, DS10k->ARRAY_SIZE);
	setupArrays(DS100k->normal, DS100k->reverse, DS100k->random, DS100k->ARRAY_SIZE);
	setupArrays(DS1m->normal, DS1m->reverse, DS1m->random, DS1m->ARRAY_SIZE);

	cout << "Setup finished." << endl;
}

//=======================================
Sorter::~Sorter() {

}

//=======================================
void Sorter::startSorting() {
	cout << "Performing Bubble Sort on 100..." << endl;
	bubbleSort(DS100->normal, DS100->reverse, DS100->random, DS100->ARRAY_SIZE);

	cout << "Normal time: " << DS100->timeToSortNormBubble << " seconds." << endl;
	cout << "Reverse time: " << DS100->timeToSortRevBubble << " seconds." << endl;
	cout << "Random time: " << DS100->timeToSortRandBubble << " seconds." << endl;
}

//===========================================
void Sorter::setupArrays(int normal[], int reverse[], int random[], const int ARRAY_SIZE) {
	int slotsFilled = 0;
	int indexToFill = 0;

	srand(42);

	cout << ARRAY_SIZE << "...";

	//normal order
	for (int index = 0; index < ARRAY_SIZE; index++) {
		normal[index] = index;
	}

	//reverse order
	for (int index = ARRAY_SIZE; index != 0; index--) {
		reverse[index - 1] = ARRAY_SIZE - index;
	}
	
	//random order
	
	//setting the array to equal -1
	//makes sure we dont fill any slots twice
	for (int index = 0; index < ARRAY_SIZE; index++)
		random[index] = -1;

	for (int index = 0; index < ARRAY_SIZE; index++) {
		random[index] = rand() % ARRAY_SIZE;
	}

	cout << "Setup is done..." << endl;
}

