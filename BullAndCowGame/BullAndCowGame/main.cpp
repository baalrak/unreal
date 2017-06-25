#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void IntroMessage();
	void PlayGame();
	string GetGuess();
	bool AskToPlayAgain();


int main() {
	// Call initial game output
	do {
		IntroMessage();
		PlayGame();
	} while (AskToPlayAgain());
	return 0;
}


void IntroMessage() {
	const int WORD_LENGTH = 5;
	// Initial game output
	cout << "Welcome to Bulls and Cows, a fun word game\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I am thinking of?\n";
	return;
}


void PlayGame() {
	const int NUMBER_OF_GUESSES = 5;
	// Get the guess from the player and repeat the guess back.
	for (int i = 0; i < NUMBER_OF_GUESSES; i++) {
		string guess = GetGuess();
		cout << "You guessed: " << guess << "!\n";
	}
}


string GetGuess() {
	// Get a guess from the player
	cout << "Enter your guess: ";
	string guess = "";
	getline(cin, guess);
	return guess;
}


bool AskToPlayAgain() {
	cout << "Do you want to play again? [Y/N]";
	string playAgain = "";
	getline(cin, playAgain);
	transform(playAgain.begin(), playAgain.end(), playAgain.begin(), ::toupper);
	if (playAgain.compare("Y") == 0) {
		return true;
	}
	else {
		return false;
	}
}
