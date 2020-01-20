#include <iostream>
#include <fstream>
#include "Credit.h"

int main() {
	//std::cout << getDigit(22) << std::endl;

	//std::cout << startsWith(invalidCardNumber, "4") << std::endl;

	//std::cout << hasValidPrefix(invalidCardNumber) << std::endl;

	//std::cout << sumOfOddPlace(invalidCardNumber) << std::endl;

	//std::cout << sumOfDoubleEvenPlace(invalidCardNumber) << std::endl;

	//std::cout << isValid(invalidCardNumber) << std::endl;

	std::string inputFilename = "cards.txt";
	std::ifstream fin;
	fin.open("cards.txt");
	if (fin.is_open()) {
		std::string ccNumber;
		while (fin >> ccNumber) {
			if (isValid(ccNumber)) {
				std::cout << "Credit card " << ccNumber << ": Valid!" << std::endl;
			}
			else {
				std::cout << "Credit card " << ccNumber << ": Invalid!" << std::endl;
			}
		}
		fin.close();
	}
	else {
		std::cout << "Error: could not open file: \"" << inputFilename << "\"" << std::endl;
	}

	
	return 0;
}