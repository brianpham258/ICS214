#ifndef CARD_H
#define CARD_H

enum class Suit {
	SPADES,
	HEARTS,
	DIAMONDS,
	CLUBS
};
enum class Rank {
	ACE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	JACK,
	QUEEN,
	KING
};

namespace Constants {
	constexpr int CARD_COUNT{ 52 };
	constexpr int NUM_RANKS{ 12 };
	constexpr int NUM_SUITS{ 4 };

	const std::string SUITS[] { "Spades", "Hearts", "Diamonds", "Clubs" };
	const std::string RANKS[] { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Jack", "Queen", "King" };
};

//Pick a random card from the deck
int pickRandomCard();

//Return an enum representing the Rank of the card index given
Rank getRank(int cardIndex);

//Return an enum representing the Suit of the card index given
Suit getSuit(int cardIndex);


//Return true if all the Booleans in the given array are true
bool allSuitsPicked(const bool suitsPicked[], int length);

//Return an int representing the number of card picks it takes to cover 4 suits.
int getPickCountNeededForSuit(bool verbose = true);

#endif