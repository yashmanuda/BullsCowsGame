#include <iostream>
#include <string>
#include "FBullCowGame.h";

using FText = std::string;
using int32 = int;

void PrintIntro();
FText GetValidGuess();
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
		FText guess = GetValidGuess();
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

FText GetValidGuess() {
	EGuessStatus Status = EGuessStatus::Invalid;
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();
		FText guess = "";
		std::cout << "Try " << CurrentTry << ". Enter your guess: ";
		std::getline(std::cin, guess);

		Status = BCGame.IsValidGuess(guess);
		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter the word in lowercase.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word with no repeating letters.\n";
			break;
		default:
			return guess;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
}

void PrintIntro() {
	std::cout << "\nWelcome to Bulls & Cows, word game!\n";
	std::cout << "An isogram is a word without any repeating letter.\n\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram word?\n\n";
	return;
}