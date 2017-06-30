#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() {
	Reset();
}

// Getters
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const {	return MyCurrentTry; }


// Setters
void FBullCowGame::SetCurrentTry(int32 tryNumber) { MyCurrentTry = tryNumber; }


int32 FBullCowGame::GetWordLength() const {
	return MyHiddenWord.length();
}

FString FBullCowGame::GetHiddenWord() const
{
	return MyHiddenWord;
}


FString FBullCowGame::CreateHiddenWord()
{
	srand(time(NULL));
	FString ListWords[] = {"planet","microwave","silent","playground","precaution","disturb","complain","moruya","countryside","night"};
	int Num = rand() % 10 - 1;
	FString Word = ListWords[Num];
	return Word;
}


FBullCowCount FBullCowGame::SubmitGuess(FString Guess) {
	FBullCowCount BullCowCount;
	for (int32 i = 0; i < MyHiddenWord.length(); i++) {
		for (int32 j = 0; j < Guess.length(); j++) {
			if (MyHiddenWord[i] == Guess[j]) {
				if (i == j) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}
			}
		}
	}
	return BullCowCount;
}

// Functions
void FBullCowGame::Reset() {
	MyCurrentTry	= 0;
	MyMaxTries		= 8;
	MyHiddenWord = CreateHiddenWord();
}

bool FBullCowGame::CheckGuessValidity(FString) {
	return false;
}
