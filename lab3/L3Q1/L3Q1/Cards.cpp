#include <iostream>
#include "Cards.h"

//Pick a random card from the deck
int pickRandomCard() {
	int min = 0;
	int max = Constants::CARD_COUNT - 1;
	int random = min + (rand() % (max - min + 1));

	return random;
};

//Return an enum representing the Rank of the card index given
Rank getRank(int cardIndex) {
	int rankIndex = cardIndex % Constants::NUM_RANKS;

	Rank rankOfCard = static_cast<Rank>(rankIndex);

	return rankOfCard;
};

//Return an enum representing the Suit of the card index given
Suit getSuit(int cardIndex) {
	int suitIndex = cardIndex % Constants::NUM_SUITS;

	Suit suitOfCard = static_cast<Suit>(suitIndex);

	return suitOfCard;
};

//Return true if all the Booleans in the given array are true
bool allSuitsPicked(const bool suitsPicked[], int length) {
	for (int i = 0; i < length; i++) {
		if (suitsPicked[i] == false) {
			return false;
		}
	}

	return true;
};

//Return an int representing the number of card picks it takes to cover 4 suits.
int getPickCountNeededForSuit(bool verbose) {
	bool seenSuit[] = { false, false, false, false };
	int countPicked = 0;

	while (!allSuitsPicked(seenSuit, sizeof(seenSuit))) {
		int randomCardIndex = pickRandomCard();

		Rank rank = getRank(randomCardIndex);

		Suit suit = getSuit(randomCardIndex);

		int suitName = static_cast<int>(suit);
		int rankName = static_cast<int>(rank);

		countPicked++;

		//seenSuit[suitName]
		if (verbose) {
			std::cout << Constants::RANKS[rankName] << " of " << Constants::SUITS[suitName] << '\n';
		}
		seenSuit[suitName] = true;
	};

	return countPicked;
};

