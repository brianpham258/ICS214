#include <iostream>
#include <time.h>

//Get int from user
int getIntFromUser() {
	int x{};
	std::cin >> x;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Invalid input" << '\n' << "Enter an integer: ";
		std::cin >> x;
	}

	return x;
}

//Prompt user for range
int promptUserForRange() {
	std::cout << "Enter the maximum range: ";
	int max_range{ getIntFromUser() };

	return max_range;
}

//Prompt use for guess
int promptUserForGuess(int range) {
	std::cout << "Pick a random number between 0 and " << range << '\n';
	int num_guess{ getIntFromUser() };

	return num_guess;
}

//Print out success message
void printSuccessMessage(int guessCount) {
	std::cout << "It took you " << guessCount << " guesses." << '\n';
}

//Pick a random number
int pickRandomNumberInRange(int min, int max) {
	int random{};
	random = min + rand() % (max - min + 1);

	return random;
}

//main function
int main() {
	srand(static_cast<unsigned int>(time(0)));

	int counter{ 0 };

	int max_range{ promptUserForRange() };

	int random{ pickRandomNumberInRange(0, max_range) };

	int num_guess{ promptUserForGuess(max_range) };
	counter++;

	while (num_guess != random) {
		if (num_guess > random) {
			std::cout << "Lower" << '\n';
		}
		else if (num_guess < random) {
			std::cout << "Higher" << '\n';
		}
		counter++;
		num_guess = promptUserForGuess(max_range);
	}

	std::cout << "Correct!" << '\n';
	printSuccessMessage(counter);
	
	return 0;
}