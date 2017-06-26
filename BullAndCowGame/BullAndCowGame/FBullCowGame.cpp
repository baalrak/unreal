#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() {
	Reset();
}

// Getters
int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const {	return MyCurrentTry; }

// Setters
void FBullCowGame::SetCurrentTry(int tryNumber) { MyCurrentTry = tryNumber; }

// Functions
void FBullCowGame::Reset() {
	MyCurrentTry	= 0;
	MyMaxTries		= 8;
}

bool FBullCowGame::IsGameWon() const {
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string) {
	return false;
}
