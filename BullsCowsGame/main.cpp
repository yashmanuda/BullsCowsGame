#include <iostream>
#include <string>
#include "FBullCowGame.h";

using FText = std::string;
using int32 = int;

void PrintIntro();
FText GetGuess();
void PlayGame();
bool AskToPlayAgain();
FBullCowGame BCGame;

int main() {

	do {
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());
	return 0;
}

void PlayGame() {
	
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	// TODO change to while loop 
	for (int32 count = 0; count < MaxTries; count++) {
		FText guess = GetGuess();
		FBullCowCount BullCowCount = BCGame.SubmitGuess(guess);

		std::cout << "Bulls: " << BullCowCount.Bulls << " Cows: " << BullCowCount.Cows << "\n\n";

	}

	// TODO summarise the game	
}

bool AskToPlayAgain() {
	std::cout << "Do you wanna play again? (Y/N)";
	FText response = "";
	std::getline(std::cin,response);
	if (response != "y" && response != "Y" && response != "n" && response != "N") {
		std::cout << "\nInvalid input, please try again.\n";
		return AskToPlayAgain();
	}
	return (response == "y") || (response == "Y");
}

FText GetGuess() {
	int32 CurrentTry = BCGame.GetCurrentTry();
	FText guess = "";
	std::cout << "Try "<<CurrentTry<<". Enter your guess: ";
	std::getline(std::cin,guess);
	return guess;
}

void PrintIntro() {
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "\nWelcome to Bulls & Cows, word game!\n";
	std::cout << "An isogram is a word without any repeating letter.\n\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram word?\n\n";
	return;
}