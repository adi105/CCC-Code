//******************************************************************************
// Program Name:	hashingFunc.cpp
// Developer:		Adrian Bernat
// Course Number:	CS-260
// Date:			5-21-17
// IDE:				Visual Studio 2015
// Description:		Contains the code that implements a hashing function and tests
//					it out by inserting items from a list of 45,402 words.
//*******************************************************************************

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int NUMBER_OF_WORDS = 45402;
const int DATA_SIZE = 40;

const string FILE_TO_READ = "words.txt";
const string FILE_TO_WRITE = "hashresults.csv";

ifstream fileRead;
ofstream fileWrite;

//prototypes
int hashFunc(string wordToHash);
float findCollision(const int* searchArray);
void outputToFile(const int* arrayToOutput);
string convertToLowercase(string wordToConvert);


int main() {
	//declare variables
	int hashMap[NUMBER_OF_WORDS] = {};
	char wordFromLine[DATA_SIZE] = {};
	string wordFromLineString = "";
	int arrayIndex = 0;

	fileRead.open(FILE_TO_READ);

	//check if it opened
	if (!fileRead.is_open()) {
		cout << "ERROR! Cannot open file." << endl;
		return -1;
	}

	else {
		//go through the file
		while (!fileRead.eof()) {
			fileRead.getline(wordFromLine, DATA_SIZE);

			//convert to a string
			wordFromLineString = wordFromLine;
			wordFromLineString = convertToLowercase(wordFromLineString);

			//calculate the index
			arrayIndex = hashFunc(wordFromLineString) % NUMBER_OF_WORDS;
			arrayIndex = abs(arrayIndex);

			hashMap[arrayIndex]++;
		}

		fileRead.close();

		cout << "CS-260: A6 Hashing, Adrian Bernat, " << findCollision(hashMap) << endl;
	}

	return 0;
}

//========================================================================
int hashFunc(string wordToHash) {
	//declare the variable that will hold the hash value
	int hash = 0;

	for (int letter = 0; letter < wordToHash.size(); letter++) {
		hash += static_cast<int>(wordToHash[letter]);
		hash += static_cast<int>(wordToHash[(wordToHash.size() - 1)]);
	}

	return hash;
}

//========================================================================
string convertToLowercase(string wordToConvert) {
	for (int index = 0; index < wordToConvert.length(); index++) {
		if (wordToConvert[index] >= 65 && wordToConvert[index] <= 90) {
			wordToConvert[index] = tolower(wordToConvert[index]);
		}
		else {
			continue;
		}
	}
	return wordToConvert;
}

//=========================================================================
float findCollision(const int* searchArray) {
	float numberOfCollisions = 0;

	for (int index = 0; index < NUMBER_OF_WORDS; index++) {
		if (searchArray[index] > 1) {
			numberOfCollisions += searchArray[index] - 1;
		}
	}

	return (numberOfCollisions / NUMBER_OF_WORDS) * 100;
}

//=========================================================================
void outputToFile(const int* arrayToOutput) {
	fileWrite.open(FILE_TO_WRITE);

	for (int index = 0; index < NUMBER_OF_WORDS - 1; index++) {
		if (arrayToOutput[index] != 0) {
			fileWrite << arrayToOutput[index] << ",";
		}
	}

	fileWrite << arrayToOutput[NUMBER_OF_WORDS - 1];
	fileWrite.close();
}