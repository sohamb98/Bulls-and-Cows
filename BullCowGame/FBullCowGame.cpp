#pragma once

#include "FBullCowGame.h"
#include <map>
#include<cstdlib>
#define TMap std::map

using FText = std::string;
using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	TMap<int32, std::string> WORD = { { 1,"planet"},{ 2,"destroy"},{ 3,"cow"},{ 4,"path"},{5,"dumb"},{ 6,"finder"},{ 7,"author"} };
	int Randum = rand() % 7 + 1;
    FString HIDDEN_WORD;
	HIDDEN_WORD = WORD[Randum];
	MyHiddenWord = HIDDEN_WORD;
	bGameIsWon = false;
	MyCurrentTry = 1;
	return;
}

int FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> WordLengthToMaxTries{ {3,4}, {4,7}, {5,10}, {6,16}, {7,20} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

int FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
 return MyHiddenWord.length();
}

bool FBullCowGame::IsgameWon() const
{
	return bGameIsWon;
}

EGuessStatus FBullCowGame::CheckGuessValidiy(std::string Guess) const
{
	if (!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogramm;
	}
	else if(!IsLowercase(Guess))
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if(Guess.length()!= GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Lenght;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length();
	for (int32 i = 0; i < WordLength; i++) {
		for (int32 j = 0; j < WordLength; j++){
			if (Guess[j] == MyHiddenWord[i])
			{
				if(i == j)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
				
			}
		}
	}
	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}
	return BullCowCount;
	
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	
	if (Word.length() <= 1) {return true; }

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

bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto letter : Word) {
		if (!islower(letter))
		{
			return false;
		}
	}
	return true;
}
