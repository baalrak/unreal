#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() {
	Reset();
}

// Getters
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const {	return MyCurrentTry; }

// Setters
void FBullCowGame::SetCurrentTry(int32 tryNumber) { MyCurrentTry = tryNumber; }

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	FBullCowCount BullCowCount;
	for (int32 i = 0; i < MyHiddenWord.length(); i++) {
		for (int32 j = 0; j < MyHiddenWord.length(); j++) {
			if (MyHiddenWord[i] == Guess[j]) {
				BullCowCount.Bulls++;
			}
		}
	}
	return BullCowCount;
}

// Functions
void FBullCowGame::Reset() {
	MyCurrentTry	= 0;
	MyMaxTries		= 8;
	FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
}

bool FBullCowGame::IsGameWon() const {
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString) {
	return false;
}
