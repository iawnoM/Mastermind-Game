//Riley Monwai CST-210
//Lydia Fritz 3/7/21

#pragma once
#ifndef GAME_H
#define GAME_H
#include "Guess.h"

using namespace std;

class Game {

private:
	int numGuesses = 10; 
	int secretCode[4];
	bool winner = false;

public:
	Game();
	string giveFeedback(Guess);
	int getRemainingGuesses();
	void playTurn();
	bool isWinner();
	void setSecretCode();
	friend ostream& operator<<(ostream& out, const Game& rhs);
};

#endif // !GAME_H
