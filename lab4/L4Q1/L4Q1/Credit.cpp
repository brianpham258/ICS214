#include <iostream>
#include <string>
#include "Credit.h"

//Return this number if it is a single digit, otherwise return the sum of the two digits
int getDigit(int num) {
	if (num >= 0 && num < 10) {
		return num;
	}
	
	int secondDigit = num % 10;
	int firstDigit = num / 10; // % 10;

	int sum = firstDigit + secondDigit;
	
	return sum;
}

//Return true if the cardNumber start with prefix
bool startsWith(const std::string& cardNumber, const std::string& prefix) {
														//std::cout << cardNumber.length() << " " << prefix.substr(0, 1) << std::endl;
	if (cardNumber.substr(0, prefix.length()) == prefix) {
		return true;
	}

	return false;
}

//Return true if the cardNumber startsWith() "4", "5", "37" or "6"
bool hasValidPrefix(const std::string& cardNumber) {
	if(  startsWith(cardNumber, "4") ||
		startsWith(cardNumber, "5") ||
		startsWith(cardNumber, "37") ||
		startsWith(cardNumber, "6") )
	{
														//std::cout << "true" << std::endl;
		return true;
	}

	return false;
}

//Return sum of odd-place digits in the card number
int sumOfOddPlace(const std::string& cardNumber) {
	int sum = 0;

	for (int i = cardNumber.length() - 1; i >= 0; i -= 2) {
		int digit = cardNumber[i] - '0';
		sum += digit;
	}

	return sum;
}

//Return sum of even-place digits in the card number
int sumOfDoubleEvenPlace(const std::string& cardNumber) {
	int sumEvenPos = 0;

	for (int i = cardNumber.length() - 2; i >= 0; i -= 2) {
		int digit = cardNumber[i] - '0';
														//std::cout << digit << std::endl;
		int doubleDigit = digit * 2;
														//std::cout << doubleDigit << std::endl;
		int digitSum = getDigit(doubleDigit);
														//std::cout << digitSum << std::endl;
		sumEvenPos += digitSum;
														//std::cout << sumEvenPos << std::endl;
	}

	return sumEvenPos;
}

//Return true if the card number is valid (passes all tests)
bool isValid(const std::string& cardNumber) {
	int sumOddPos = 0;
	int sumEvenPos = 0;

	if (hasValidPrefix(cardNumber) == true) {
		sumOddPos = sumOfOddPlace(cardNumber);
														//std::cout << sumOddPos << std::endl;
														//std::cout << "---------------------------------" << std::endl;
		sumEvenPos = sumOfDoubleEvenPlace(cardNumber);
														//std::cout << sumEvenPos << std::endl;

		if ((sumEvenPos + sumOddPos) % 10 == 0) {
			return true;
		}
	}

	return false;
}