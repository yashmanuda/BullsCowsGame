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
	bIsGameWon = false;
	return;
}

bool FBullCowGame::IsGameWon() const {
	return bIsGameWon;
}

EGuessStatus FBullCowGame::IsValidGuess(FString Guess) const {
	if (!IsIsogram(Guess)) {
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess)) {
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
	// game won if number of bulls is equal to word length
	bIsGameWon = (BullCowCount.Bulls == GetHiddenWordLength());
	
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const {
	if (Word.length() < 2) {
		return true;
	}
	TMap<char, bool> LetterSeen;

	for (auto Letter : Word) {
		Letter = tolower(Letter);
		if (LetterSeen[Letter]) {
			return false;
		}
		else {
			LetterSeen[Letter] = true;
		}
	}

	return true;
}

bool FBullCowGame::IsLowercase(FString Word) const {
	for (auto Letter: Word) {
		if (!islower(Letter)) {
			return false;
		}
	}
	return true;
}
