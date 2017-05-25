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
int hashFunc(string word);
float findCollision(const int* searchArray);
void outputToFile(const int* arrayToOutput);
string convertToLowercase(string wordToConvert);


int main() {
	//declare variables
	int hashMap[NUMBER_OF_WORDS] = {};
	int arrayIndex = 0;

	fileRead.open(FILE_TO_READ);

	//check if it opened
	if (!fileRead.is_open()) {
		cout << "ERROR! Cannot open file." << endl;
		return -1;
	}

	else {
		string word;
		//go through the file
		while (fileRead >> word) {
			arrayIndex = hashFunc(word);
			hashMap[arrayIndex]++;
		}

		fileRead.close();

		cout << "CS-260: A6 Hashing, Adrian Bernat, " << findCollision(hashMap) << endl;
		outputToFile(hashMap);
	}

	return 0;
}

//does the actual hashing of the word as to produce a hashed int, which when modded by the
//total items, will produce the least collision rate
//========================================================================
int hashFunc(string word) {
	int stringValue = 0; //this is the value of the string's letter's ascii values
	int valueToMult = 397; //this value will hold the number as multiplication is done to it
	int totalValue = 0; //this will hold the value of the string's ascii plus the valueToMult
	int primeValue = 0; //this variable will store a prime number equation
	int prime1 = 223;  
	int prime2 = 405413; //these are two random prime numbers

	for (int letter = 0; letter < word.length(); letter++) {
		stringValue += word[letter];
		valueToMult += word[0] * word[1] * word[2];
		valueToMult = (valueToMult * prime1) * prime2;
		valueToMult = ((valueToMult >> 3) + valueToMult + word[letter]);
		valueToMult = ((valueToMult * word[word.length() / 2]) + (valueToMult * word[word.length() / 8]) * 780257) * 5;
		primeValue = 780257 * (valueToMult << 5) * 3;
		valueToMult = valueToMult * primeValue;
		valueToMult = valueToMult + word[letter] / 75210;
		valueToMult = valueToMult + (word[letter] / 2) + (word[letter / 7]);
		totalValue = stringValue + valueToMult;
	}

	int modValue = totalValue % NUMBER_OF_WORDS;
	return abs(modValue);
}

//returns the string converted into all lowercase
//========================================================================
string convertToLowercase(string wordToConvert) {
	for (int index = 0; index < wordToConvert.length(); index++) {
		if (wordToConvert[index] >= 65 && wordToConvert[index] <= 90) {
			wordToConvert[index] = tolower(wordToConvert[index]);
		}
	}
	
	return wordToConvert;
}

//finds how many collisions there were in the array
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
			fileWrite << arrayToOutput[index] << "," << endl;
		}
	}

	fileWrite << arrayToOutput[NUMBER_OF_WORDS - 1];
	fileWrite.close();
}


