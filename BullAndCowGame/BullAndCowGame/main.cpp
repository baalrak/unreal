#include <iostream>
#include <string>
using namespace std;

int main() 
{
	// Constant expressions
	constexpr int WORD_LENGTH = 5;
	// Initial game output
	cout << "Welcome to Bulls and Cows, a fun word game\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I am thinking of?\n";

	// Get a guess from the player
	cout << "Enter your guess: ";
	string Guess = "";
	cin >> Guess;

	// Repeat the guess back to the player
	cout << "You guessed: " << Guess << "!\n";

	return 0;
}