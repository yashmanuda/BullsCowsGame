#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset() {
	constexpr int32 MAX_TRIES = 5;
	const FString HIDDEN_WORD = "planets";
	
	MyHiddenWord = HIDDEN_WORD;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const {
	return false;
}

EGuessStatus FBullCowGame::IsValidGuess(FString Guess) const {
	if (false) {
		return EGuessStatus::Not_Isogram;
	}
	else if (false) {
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength() ) {
		return EGuessStatus::Wrong_Length;
	}
	else {
		return EGuessStatus::OK;
	}
}


FBullCowCount FBullCowGame::SubmitGuess(FString Guess) {
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 HiddenWordLength = MyHiddenWord.length();
	
	//hidden word
	for (int32 i = 0; i < HiddenWordLength; i++) {
		//guess word 
		for (int32 j = 0; j < HiddenWordLength; j++) {
			if (MyHiddenWord[i] == Guess[j]) {
				if (i == j)
					(BullCowCount.Bulls)++;
				else
					(BullCowCount.Cows)++;
			}
		}
	}
	return BullCowCount;
}
