#pragma once
#define WEEKDAY_H

// All the days of the week
enum Weekday {
	Saturday,
	Sunday,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday
};

// Prompt user for a year
int promptForYear();

// Prompt user for a month
int promptForMonth();

// Prompt user for a day
int promptForDayOfMonth();

// Calculcate week day
Weekday calculateWeekday(int month, int dayOfMonth, int year);

// get week day name
std::string getWeekdayName(Weekday day);