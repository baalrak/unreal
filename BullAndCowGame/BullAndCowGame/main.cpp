#include <iostream>
#include <string>
#include <algorithm>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void IntroMessage();
void PlayGame();
FText GetGuess();
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
	const int32 WORD_LENGTH = 5;
	// Initial game output
	std::cout << "Welcome to Bulls and Cows, a fun word game\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I am thinking of?\n";
	return;
}


void PlayGame() {
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	// Get the guess from the player and repeat the guess back.
	for (int32 i = 0; i < MaxTries; i++) {
		BCGame.SetCurrentTry(i+1);
		std::cout << "Try Number: " << BCGame.GetCurrentTry() << "\n";
		FText Guess = GetGuess();
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bulls: " << BullCowCount.Bulls << " and Cows: " << BullCowCount.Cows << "!\n";
	}
}


FText GetGuess() {
	// Get a guess from the player
	std::cout << "Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}


bool AskToPlayAgain() {
	std::cout << "Do you want to play again? [Y/N]";
	FText PlayAgain = "";
	std::getline(std::cin, PlayAgain);
	transform(PlayAgain.begin(), PlayAgain.end(), PlayAgain.begin(), ::toupper);
	if (PlayAgain.compare("Y") == 0) {
		return true;
	}
	else {
		return false;
	}
}
