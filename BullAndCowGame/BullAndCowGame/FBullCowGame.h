#pragma once
#include <string>

class FBullCowGame {
public:
	FBullCowGame(); // Constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	
	void Reset(); // TODO: make a more rich return
	bool CheckGuessValidity(std::string);
	void SetCurrentTry(int);


private:
	int MyCurrentTry;
	int MyMaxTries;
};