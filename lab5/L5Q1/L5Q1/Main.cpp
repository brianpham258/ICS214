// This file is contains our main() routine which determines where our program execution 
// begins and ends.
#include <iostream>
#include "MainMenu.h"

// Set up a pointer for tracking a linked list of Employees
// Display a menu allowing a user various choices, and process those choices
// Clean up any dynamically allocated memory before finishing
int main()
{
	// a pointer to our linked list of employees.
	Employee* pEmployees = nullptr;

	bool exitMainMenu{ false };	// init to default value
	int menuChoice{ -1 };			// init to a known starting value

	// display the main menu, allow the user to make choices, and handle the input
	do {
		displayMainMenu();
		int menuChoice{ getInt() };
		while (menuChoice == -1) {
			std::cout << "Invalid input.\n";
			displayMainMenu();
			menuChoice = getInt();
		}
		// handle the input, determine if we have an exit condition
		exitMainMenu = handleMenuInput(pEmployees, menuChoice);
	} while (!exitMainMenu);

	// cleanup! - deallocate any employees in our linked list before setting the list to nullptr;
	// TODO
	while (pEmployees) {
		removeEmployee(pEmployees, pEmployees->id);
	}
	return 0;
}
