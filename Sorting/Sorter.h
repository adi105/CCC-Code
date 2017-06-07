#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Sorter {
public:
	
	Sorter();

	~Sorter();

	void startSorting();

private:
	struct dataSet100 {
		const int ARRAY_SIZE = 100;

		int normal[100];
		int reverse[100];
		int random[100];

		float timeToSortNormBubble = 0;
		float timeToSortNormSelection = 0;
		float timeToSortNormQuick = 0;

		float timeToSortRevBubble = 0;
		float timeToSortRevSelection = 0;
		float timeToSortRevQuick = 0;

		float timeToSortRandBubble = 0;
		float timeToSortRandSelection = 0;
		float timeToSortRandQuick = 0;
	};

	struct dataSet1K {
		const int ARRAY_SIZE = 1000;

		int normal[1000];
		int reverse[1000];
		int random[1000];

		float timeToSortNormBubble = 0;
		float timeToSortNormSelection = 0;
		float timeToSortNormQuick = 0;

		float timeToSortRevBubble = 0;
		float timeToSortRevSelection = 0;
		float timeToSortRevQuick = 0;

		float timeToSortRandBubble = 0;
		float timeToSortRandSelection = 0;
		float timeToSortRandQuick = 0;
	};

	struct dataSet10K {
		const int ARRAY_SIZE = 10000;

		int normal[10000];
		int reverse[10000];
		int random[10000];

		float timeToSortNormBubble = 0;
		float timeToSortNormSelection = 0;
		float timeToSortNormQuick = 0;

		float timeToSortRevBubble = 0;
		float timeToSortRevSelection = 0;
		float timeToSortRevQuick = 0;

		float timeToSortRandBubble = 0;
		float timeToSortRandSelection = 0;
		float timeToSortRandQuick = 0;
	};

	struct dataSet100K {
		const int ARRAY_SIZE = 100000;

		int normal[100000];
		int reverse[100000];
		int random[100000];

		float timeToSortNormBubble = 0;
		float timeToSortNormSelection = 0;
		float timeToSortNormQuick = 0;

		float timeToSortRevBubble = 0;
		float timeToSortRevSelection = 0;
		float timeToSortRevQuick = 0;

		float timeToSortRandBubble = 0;
		float timeToSortRandSelection = 0;
		float timeToSortRandQuick = 0;
	};

	struct dataSet1M {
		const int ARRAY_SIZE = 1000000;

		int normal[1000000];
		int reverse[1000000];
		int random[1000000];

		float timeToSortNormBubble = 0;
		float timeToSortNormSelection = 0;
		float timeToSortNormQuick = 0;

		float timeToSortRevBubble = 0;
		float timeToSortRevSelection = 0;
		float timeToSortRevQuick = 0;

		float timeToSortRandBubble = 0;
		float timeToSortRandSelection = 0;
		float timeToSortRandQuick = 0;
	};

	//other variables
	dataSet100* DS100 = new dataSet100;
	dataSet1K* DS1k = new dataSet1K;
	dataSet10K* DS10k = new dataSet10K;
	dataSet100K* DS100k = new dataSet100K;
	dataSet1M* DS1m = new dataSet1M;
	
	clock_t clock;

	void setupArrays(int normal[], int reverse[], int rand[], const int arraySize);

	void bubbleSort(int normal[], int reverse[], int rand[], const int arraySize);

	void bubbleSortRec(int arr[], const int arraySize);

	void selectionSort(int normal[], int reverse[], int rand[], const int arraySize);

	void selectionSortRec(int arr[], const int arraySize);

	void quickSort(int normal[], int reverse[], int rand[], const int arraySize);

	void swap(int arr[], int index1, int index2);

};