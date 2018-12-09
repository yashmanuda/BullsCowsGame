#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset() {
	constexpr int32 MAX_TRIES = 5;
	const FString HIDDEN_WORD = "planet";
	
	MyHiddenWord = HIDDEN_WORD;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const {
	return false;
}

bool FBullCowGame::IsValidGuess(FString) {
	return false;
}


FBullCowCount FBullCowGame::SubmitGuess(FString Guess) {
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 HiddenWordLength = MyHiddenWord.length();
	
	//hidden word
	for (int32 i = 0; i < HiddenWordLength; i++) {
		//guess word 
		for (int32 j = 0; j < HiddenWordLength; j++) {
			if (i == j) {
				if (MyHiddenWord[i] == Guess[j])
					(BullCowCount.Bulls)++;
			}
			else {
				if (MyHiddenWord[i] == Guess[j])
					(BullCowCount.Cows)++;
			}
		}
	}

	return BullCowCount;
}
