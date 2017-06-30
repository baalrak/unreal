#pragma once
#include <string>
#include <cstdlib>
#include <time.h>

using FString = std::string;
using int32 = int;


struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows	= 0;
};

class FBullCowGame {
public:
	FBullCowGame(); // Constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetWordLength() const;
	
	void Reset(); // TODO: make a more rich return
	bool CheckGuessValidity(FString);
	void SetCurrentTry(int32);
	FString CreateHiddenWord();

	FBullCowCount SubmitGuess(FString);


private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};