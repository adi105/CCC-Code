#include "Sorter.h"

//==================================================================================
Sorter::Sorter() {
	arr[MAX_SIZE] = { 0 };
}

//=======================================
Sorter::~Sorter() {

}

//=========================================================
//Declare the static array outside of the header
int Sorter::arr[MAX_SIZE] = { 0 };
//=========================================================
void Sorter::initialize(const int arraySize, bool reverse, bool random) {
	if (reverse) {
		for (int index = arraySize; index != 0; index--)
			arr[index - 1] = arraySize - index;
	}

	else if (random) {
		for (int index = 0; index < arraySize; index++) {
			arr[index] = -1;
		}

		for (int index = 0; index < arraySize; index++) {
			arr[index] = rand() % arraySize;
		}
	}

	else {
		int num = 0;
		for (int index = 0; index < arraySize; index++) {
			arr[index] = num;
			num++;
		}
	}
}
//=======================================
void Sorter::startSorting() {
	cout << "Performing Bubble Sort on 100..." << endl;
	doSort(bubbleNormalTime, bubbleReverseTime, bubbleRandomTime, 100, (*this.*&Sorter::bubbleSort)(arr, 100));

	cout << "Normal time: " << bubbleNormalTime << " seconds." << endl;
	cout << "Reverse time: " << bubbleReverseTime << " seconds." << endl;
	cout << "Random time: " << bubbleRandomTime << " seconds." << endl << endl;

	//=========================================================================
}

//==========================================================================================================================================
void Sorter::doSort(float normalTime, float reverseTime, float randomTime, int arraySize, const function<void(int[], int)> &funcToCall) {
	initialize(100, false, false);
	clockTime = clock();
	funcToCall(arr, arraySize);
	normalTime = static_cast<float>(clock() - clockTime) / CLOCKS_PER_SEC;

	initialize(100, true, false);
	clockTime = clock();
	funcToCall(arr, arraySize);
	reverseTime = static_cast<float>(clock() - clockTime) / CLOCKS_PER_SEC;

	initialize(100, false, true);
	clockTime = clock();
	funcToCall(arr, arraySize);
	reverseTime = static_cast<float>(clock() - clockTime) / CLOCKS_PER_SEC;
}

//===========================================================================
void Sorter::bubbleSort(int arr[], int arraySize) {
	int index1;
	bool isSorted = false;

	while (isSorted == false) {
		isSorted = true;

		for (int index = 0; index < arraySize; index++) {
			if (arr[index] > arr[index + 1]) {
				isSorted = false;
				index1 = arr[index];
				arr[index] = arr[index + 1];
				arr[index + 1] = index1;
			}
		}
	}
}

//===============================================================================
