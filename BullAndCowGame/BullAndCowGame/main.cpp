#include <iostream>
#include <string>
#include <algorithm>
#include "FBullCowGame.h"

void IntroMessage();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

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
	std::cout << "Welcome to Bulls and Cows, a fun word game\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I am thinking of?\n";
	return;
}


void PlayGame() {
	BCGame.Reset();
	int maxTries = BCGame.GetMaxTries();
	// Get the guess from the player and repeat the guess back.
	for (int i = 0; i < maxTries; i++) {
		BCGame.SetCurrentTry(i+1);
		std::cout << "Try Number: " << BCGame.GetCurrentTry() << "\n";
		std::string guess = GetGuess();
		std::cout << "You guessed: " << guess << "!\n";
	}
}


std::string GetGuess() {
	// Get a guess from the player
	std::cout << "Enter your guess: ";
	std::string guess = "";
	std::getline(std::cin, guess);
	return guess;
}


bool AskToPlayAgain() {
	std::cout << "Do you want to play again? [Y/N]";
	std::string playAgain = "";
	std::getline(std::cin, playAgain);
	transform(playAgain.begin(), playAgain.end(), playAgain.begin(), ::toupper);
	if (playAgain.compare("Y") == 0) {
		return true;
	}
	else {
		return false;
	}
}
