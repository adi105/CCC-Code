#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <functional>

using namespace std;

const int MAX_SIZE = 1000000;

class Sorter {
public:

	Sorter();

	~Sorter();

	void startSorting();

private:
	static int arr[MAX_SIZE];

	float bubbleNormalTime = 0;

	float bubbleReverseTime = 0;

	float bubbleRandomTime = 0;

	void doSort(float normalTime, float reverseTime, float randomTime, int arraySize, const function<void(int[], int)> &funcToCall);

	void initialize(const int arraySize, bool reverse, bool random);

	clock_t clockTime;

	void bubbleSort(int arr[], int arraySize);

	void selectionSort(int arr[], int arraySize);

	//void quickSort(int normal[], int reverse[], int rand[], const int arraySize);

	//void swap(int arr[], int index1, int index2);

};