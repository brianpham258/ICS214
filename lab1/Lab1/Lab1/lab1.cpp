#include <iostream>

//main function
int main() {
	
	int max_range{};
	max_range = promptUserForRange();

	int random{};
	random = pickRandomNumberInRange(0, max_range);

	int num_guess{};
	num_guess = promptUserForGuess(max_range);

	while (num_guess != random) {
		if (num_guess < random) {
			std::cout << "Lower";
		}
		else if (num_guess > random) {
			std::cout << "Higher";
		}

		num_guess = promptUserForGuess(max_range);
	}

	std::cout << "Correct!";
	return 0;
}

//Prompt user for range
int promptUserForRange() {
	std::cout << "Enter the maximum range: ";
	int max_range{};
	std::cin >> max_range;
	return max_range;
}

//Prompt use for guess
int promptUserForGuess(int range) {
	std::cout << "Guess a number between 0 and " << range << ':\n';
	int num_guess{};
	std::cin >> num_guess;
	return num_guess;
}

//Print out success message
void printSuccessMessage(int guessCount) {
	std::cout << "It took you " << guessCount << "guesses." << '\n';
}

//Pick a random number
int pickRandomNumberInRange(int min, int max) {
	int random = rand() % (max + 1);
	return random;
}