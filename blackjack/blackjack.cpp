//**************************************************************************************************
// Program Name:	Card Fun
// Developer:		Adrian Bernat
// Date:			12-3-16
// IDE:				Visual Studio 2015
// Purpose:			Manipulate integer arrays to create an interactive blackjack
//**************************************************************************************************
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <array>
using namespace std;

//Prototypes
void initializeDeck(int deck[]);
void dumpDeck(const int deck[], int size);
void cardShuffle(int deck[], int size);
int getRandomNumber(int low, int high);
void showCard(int card);
void showCards(const int card[], int numCards, bool hideFirstCard);
int cardValue(int card);
int getTopCard(int deck[]);
void addToHand(int hand[], int cardToAdd);
int getHandValue(const int hand[]);
void showHandLogic(const int hand[], bool cardHidePlayer, int counter);
void dealerHandLogic(const int dealer[], bool cardHideDealer, int counter);
bool hitOrStand();


int main() {
	//Declare all of your variables
	int deck[52];
	int hand[10] = {};
	int dealer[10] = {};
	bool cardHidePlayer = false;
	bool cardHideDealer = true;
	bool playerChoice = false;
	int counter = 1;
	int finalHandCount;
	int finalDealerCount;

	//create the game logic by calling the card functions that were made
	initializeDeck(deck);
	cardShuffle(deck, 51);
	
	cout << "Welcome to blackjack! \nWill you win? Will you lose? Whose to know! Try your hand!" << endl;
	
	//Add two cards to the player's hand
	addToHand(hand, getTopCard(deck));
	addToHand(hand, getTopCard(deck));
	
	//Print out the user's hand
	showHandLogic(hand, cardHidePlayer, counter);

	//Print out the dealer's hand
	addToHand(dealer, getTopCard(deck));
	addToHand(dealer, getTopCard(deck));

	dealerHandLogic(dealer, cardHideDealer, counter);
	
	//Continue with the game logic, as far as the player choosing to hit or stand
	playerChoice = hitOrStand();

	while (playerChoice == true && getHandValue(hand) < 22) {
		addToHand(hand, getTopCard(deck));
		counter++;
		showHandLogic(hand, cardHidePlayer, counter);
		dealerHandLogic(dealer, cardHideDealer, counter);
		playerChoice = hitOrStand();
	}
	while (getHandValue(dealer) < 14) {
		addToHand(dealer, getTopCard(deck));
		cout << "The dealer's cards are: ";
		showCards(dealer, counter, cardHideDealer);
		cout << endl;
	}

	//Decide on a final winner
	if (getHandValue(hand) > 21) {
		cout << endl << "Sorry, but you lost!" << endl;
	}
	else if (getHandValue(dealer) > 21) {
		cout << "The dealer's value was " << getHandValue(dealer) << endl;
		cout << "YOU WIN!" << endl;
	}
	else {
		finalHandCount = 21 - getHandValue(hand);
		finalDealerCount = 21 - getHandValue(dealer);
		if (finalHandCount > finalDealerCount) {
			cout << endl << "The Dealer'ss value was " << getHandValue(dealer) << endl;
			cout << "Sorry, but you lost!" << endl;
		}
		else if (finalHandCount < finalDealerCount) {
			cout << endl << "The Dealer's value was " << getHandValue(dealer) << endl;
			cout << "YOU WIN!" << endl;
		}
	}
	
	

	
//	showCard(111);
//	showCards(deck, 51, hideFirstCard);
//	cout << cardValue(deck[2]);
//	cout << getTopCard(deck);
//	cout << getHandValue(hand);

	return 0;
}

//======================================================================================
// Function: initializeDeck
// Description: Initializes the deck array, storing a different number in each slot and
//				"creating" the deck.
//
//	Arguments: int deck[]: the array that will hold the deck of cards
//======================================================================================

void initializeDeck(int deck[]) {
	for (int x = 0; x < 13; x++) {
		deck[x] = 101 + x;
	}
	for (int x = 13; x < 26; x++) {
		deck[x] = 200 + (x - 12);
	}
	for (int x = 26; x < 39; x++) {
		deck[x] = 300 + (x - 25);
	}
	for (int x = 39; x <= 51; x++) {
		deck[x] = 400 + (x - 38);
	}
}

//======================================================================================
// Function: dumpDeck
// Description: Prints out the entire deck, line by line.
//
//	Arguments:
//			const int deck[]: the array that holds the deck of cards
//			int size: the size of the deck			
//
//======================================================================================

void dumpDeck(const int deck[], int size) {
	for (int x = 0; x <= size; x++) {
		cout << deck[x] << endl;
	}
}

//======================================================================================
// Function:	cardShuffle
// Description: randomly rearranges the cards in the deck
//
//	Arguments: 
//			int deck[]: the array that holds the deck of cards
//			int size: the size of the deck of cards
//======================================================================================

void cardShuffle(int deck[], int size) {
	int x = 0;
	while (x < 100) {
		int z = getRandomNumber(0, 51);
		int y = getRandomNumber(0, 51);
		swap(deck[z], deck[y]);
		x++;
	}
		
}

//================================================================
// Function:    getRandomNumber
// Description: returns a random number between given low and high
//	values, inclusive. 
// Arguments:
//	low (I) - The lowest number to be generated
//	high (I) - The highest number to be generated (must be > low)
// Return value:
//	A random number between low and high (inclusive)
//================================================================

int getRandomNumber(int low, int high) {
	static bool firstTime = true;
	int randNum;


	//if first time called, seed random number generator
	if (firstTime) {
		srand(static_cast<unsigned int>(time(NULL)));
		firstTime = false;
	}


	//generate random number between given low and high values (inclusive)
	randNum = rand() % (high - low + 1) + low;


	return randNum;
}

//======================================================================================
// Function:	showCard
// Description: print out the given cards rank, including house and suit
//
//	Arguments:
//			int card: the card whose information will be displayed
//======================================================================================

void showCard(int card) {
	switch (card % 100) {
	case 1:
		cout << "A";
		break;
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
		cout << card % 100;
		break;
	case 11:
		cout << "J";
		break;
	case 12:
		cout << "Q";
		break;
	case 13:
		cout << "K";
		break;
	}

	//Then determine the card suit
	if (card > 400) {
		cout << static_cast<char>(6);
	}
	else if (card > 300) {
		cout << static_cast<char>(5);
	}
	else if (card > 200) {
		cout << static_cast<char>(4);
	}
	else {
		cout << static_cast<char>(3);
	}
	//Then output a space character of some sort
	cout << " ";
}

//======================================================================================
// Function:	showCards
// Description: print out the given cards rank, including house and suit
//
//	Arguments:
//			const int card: the cards whose information will be displayed
//			int numCards: the number of cards that are being displayed
//			bool hideFirstCard: states whether the first card should be shown or hidden
//======================================================================================

void showCards(const int card[], int numCards, bool hideFirstCard) {
	for (int x = 0; x <= numCards; x++) {
		if (hideFirstCard == true) {
			if (x < 1) {
				cout << "** ";
			}
			else {
				int y = card[x];
				showCard(y);
			}
		}
		else {
			int y = card[x];
			showCard(y);
		}
	}
}

//======================================================================================
// Function:	cardValue
// Description: print out the value of the card
//
//	Arguments:
//			int card: gives the card whose value will be printed
//
//	Return:
//			int value: returns the cards value
//======================================================================================

int cardValue(int card) {
	int value;

	switch (card % 100) {
	case 1:
		value = 11;
		break;
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
		value = card % 100;
		break;
	case 11:
		value = 10;
		break;
	case 12:
		value = 10;
		break;
	case 13:
		value = 10;
		break;
	}
	return value;
}

//======================================================================================
// Function:	getTopCard
// Description: Return the top card of the deck
//
//	Arguments:
//			int deck[]: the array that holds the deck of cards
//
//	Return:
//			int topCard: the top card of the deck
//======================================================================================

int getTopCard(int deck[]) {
	int topCard;
	
	for (int x = 0; x < 51; x++) {
		if (deck[x] > 0) {
			topCard = deck[x];
			deck[x] = 0;
			break;
		}
		else {
			topCard = 0;
		}
	}
	return topCard;
}

//======================================================================================
// Function:	addToHand
// Description: Adds the given card to the hand array
//
//	Arguments:
//			int hand[]: the array that holds the hand of cards
//			int cardToAdd: the card that will be added to the hand
//
//======================================================================================

void addToHand(int hand[], int cardToAdd) {
	for (int x = 0; x < 10; x++) {
		if (hand[x] == 0) {
			hand[x] = cardToAdd;
			break;
		}
	}
}

//======================================================================================
// Function: getHandValue
// Description: prints the value of the hand
//
//	Arguments:
//			const int hand[]: the array that holds the hand of cards
//======================================================================================

int getHandValue(const int hand[]) {
	int handValue = 0;

	for (int x = 0; x < 10; x++) {
		if (hand[x] > 0) {
			handValue = handValue + cardValue(hand[x]);
		}
	}
	return handValue;
}

//======================================================================================
// Function: showHandLogic
// Description: holds the message that is given to the user, so that it can be looped
//
//	Arguments:
//			const int hand[]: the array that holds the hand of the player
//			bool cardHidePlayer: tells the function to show the first card
//			int counter: tells the function what "round" it is
//======================================================================================

void showHandLogic(const int hand[], bool cardHidePlayer, int counter) {
	//Print out the user's hand
	
	cout << endl << "Your hand consists of the following cards: ";
	showCards(hand, counter, cardHidePlayer);
	cout << endl << "Value: " << getHandValue(hand) << endl;
}

//======================================================================================
// Function: dealerHandLogic
// Description: holds the message that is given to the user concerning the dealer's hand,
//				so that it can be looped
//
//	Arguments:
//			const int dealer[]: the hand of the dealer
//			bool cardHideDealer: tells the program to hide the first card
//			itn counter: a counter that tells the function what "round" it is
//======================================================================================

void dealerHandLogic(const int dealer[], bool cardHideDealer, int counter) {
	cout << endl << "The dealer's hand consists of: ";
	showCards(dealer, counter, cardHideDealer);
}

//======================================================================================
// Function: hitOrStand
// Description: the logical loop that tells the main function whether the player wants
//				to hit or stand
//======================================================================================

bool hitOrStand() {
	char playerChoice;
	bool hitOrStand = false;

	cout << endl << "Would you like to hit or stand? y for hit, n for stand ";
	cin >> playerChoice;
	if (playerChoice == 'y' || playerChoice == 'Y') {
		hitOrStand = true;
	}
	return hitOrStand;
}