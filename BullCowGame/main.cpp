#pragma once
#include <iostream>
#include <string>
#include "FBullCowGame.h"
#include <map>
#define TMap std::map

using namespace std;
using FText = string;
using int32 = int;

FBullCowGame BCGame;

void  PrintIntro() {
	//introduce the game

	constexpr int32 WORLD_LENGHT = 5;
	cout << "Welcome to Bulls and Cows, a fun word game" << endl;
	cout << "Can you guess the " << BCGame.GetHiddenWordLength() +1 << " letter isogram that I'am thinking of?" << endl;
	cout << " ,             ,   " << endl;
	cout << " /  Bulls&Cows \\  " << endl;
	cout << "((__-^^-,-^^-__)) " << endl;
	cout << " `-_---' `---_-'  " << endl;
	cout << "  <__|o` 'o|__>   " << endl;
	cout << "     \\  `  /      " << endl;
	cout << "      ): :(       " << endl;
	cout << "      :o_o:       " << endl;
	cout << "       " - "        " <<endl;
	return;
}

FText GetValidGuess() {
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess = "";
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();
		cout << "Try" << CurrentTry<<" of "<<BCGame.GetMaxTries()<< " Enter your guess: ";
		getline(cin, Guess);

		Status = BCGame.CheckGuessValidiy(Guess);
		switch (Status) {
		case EGuessStatus::Wrong_Lenght:
			cout << "Please Enter a " << BCGame.GetHiddenWordLength() << " letter word" << endl;
			break;
		case EGuessStatus::Not_Isogramm:
			cout << "Please Enter a word without repeating letters" << endl;
			break;
		case EGuessStatus::Not_Lowercase:
			cout << "Please enter all lower case letters " << endl;
			break;
		default:
			break;
		}
		cout << endl;
	} while (Status != EGuessStatus::OK);
	return Guess;
	
}

bool AskToPlayAgain();

void PlayGame();

void PrintGameSummary();

int main() {

	bool bPlayAgain;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	return 0;
}

void PrintGameSummary()
{
	if (BCGame.IsgameWon()) {
		cout << "Congrats You have won! :D" << endl;
	}
	else {
		cout << "Better Luck Next Time :(" << endl;
	}
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	
	while(!BCGame.IsgameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		FText Guess = " ";
		Guess=GetValidGuess();

		
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		cout << "Bulls: " << BullCowCount.Bulls<< endl;
		cout <<" Cows: " <<BullCowCount.Cows<<endl;
	}
	PrintGameSummary();
	return;
}



bool AskToPlayAgain()
{
	cout << "Do you want to play again(Y/N)" << endl;
	FText Response = "";
	getline(cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}
