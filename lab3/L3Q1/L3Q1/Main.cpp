// author: Quang Pham
#include <iostream>
#include "Cards.h"
#include <time.h>

int main() {
	srand(static_cast<unsigned int>(time(0)));
	int pickedCount = 0;
	int loop = 100000;

	for (int i = 0; i < loop; i++) {
		pickedCount += getPickCountNeededForSuit(false);
	};

	std::cout << "Number of picks: " << pickedCount << '\n';

	double average = static_cast<double>(pickedCount) / loop;
	std::cout << "Average pick: " << average << '\n';

	return 0;
}