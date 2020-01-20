#include <iostream>
#include "weekday.h"

int main() {
	// Prompt user for a year
	int year = promptForYear();

	// Prompt user for a month
	int month = promptForMonth();

	// Prompt user for a day
	int dayOfMonth = promptForDayOfMonth();
	
	// Calculcate week day
	Weekday week_day = calculateWeekday(month, dayOfMonth, year);

	// Get week day name
	std::string day_name = getWeekdayName(week_day);

	// Get day name
	std::cout << "Day of the week is " + day_name << '\n';
	return 0;
};