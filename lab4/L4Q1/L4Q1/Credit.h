//#pragma once

#ifndef CREDIT_H
#define CREDIT_H

#include <iostream>


//Return this number if it is a single digit, otherwise return the sum of the two digits
int getDigit(int num);

//Return true if the cardNumber start with prefix
bool startsWith(const std::string& cardNumber, const std::string& prefix);

//Return true if the cardNumber startsWith() "4", "5", "37" or "6"
bool hasValidPrefix(const std::string& cardNumber);

//Return sum of odd-place digits in the card number
int sumOfOddPlace(const std::string& cardNumber);

//Return sum of even-place digits in the card number
int sumOfDoubleEvenPlace(const std::string& cardNumber);

//Return true if the card number is valid (passes all tests)
bool isValid(const std::string& cardNumber);

#endif // !1