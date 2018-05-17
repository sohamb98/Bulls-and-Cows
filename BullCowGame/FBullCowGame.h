#pragma once
#include<string>

using FText = std::string;
using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogramm,
	Wrong_Lenght,
	Not_Lowercase

};

class FBullCowGame {
public:
	FBullCowGame();
	
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsgameWon() const;

	void Reset();
	EGuessStatus CheckGuessValidiy(std::string) const;
	FBullCowCount SubmitValidGuess(FString);


private:
	int MyCurrentTry=1;
	int MyMaxTries = 5;
	FString MyHiddenWord;
	bool bGameIsWon;

	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};