#include <iostream>
#include "weekday.h"

// Get an integer from user
int getIntFromUser() {
	int i;
	std::cin >> i;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Invalid input" << '\n' << "Enter an integer: ";
		std::cin >> i;
	}

	return i;
};

// Prompt user for a year
int promptForYear() {
	std::cout << "Enter year (e.g., 2019): ";
	int year = getIntFromUser();

	return year;
};

// Prompt user for a month
int promptForMonth() {
	std::cout << "Enter month 1-12: ";
	int month = getIntFromUser();

	return month;
};

// Prompt user for a day
int promptForDayOfMonth() {
	std::cout << "Enter day of month 1-31: ";
	int day = getIntFromUser();

	return day;
};

// Calculcate week day
Weekday calculateWeekday(int month, int dayOfMonth, int year) {
	if (month == 1 || month == 2) {
		month += 12;
		year--;
	}

	int dayOfWeek = (dayOfMonth + 26 * (month + 1) / 10 + year % 100 + (year % 100) / 4 + (year / 100) / 4 + 5 * (year / 100)) % 7;

	//std::cout << dayOfWeek << '\n';

	Weekday day_of_week = static_cast<Weekday>(dayOfWeek);

	return day_of_week;
};

// get week day name
std::string getWeekdayName(Weekday day) {
	std::string day_name = "error";

	switch (day) {
		case Weekday::Saturday:
			day_name = "Saturday";
			break;
		case Weekday::Sunday:
			day_name = "Sunday";
			break;
		case Weekday::Monday:
			day_name = "Monday";
			break;
		case Weekday::Tuesday:
			day_name = "Tuesday";
			break;
		case Weekday::Wednesday:
			day_name = "Wednesday";
			break;
		case Weekday::Thursday:
			day_name = "Thursday";
			break;
		case Weekday::Friday:
			day_name = "Friday";
			break;
	}

	return day_name;
};