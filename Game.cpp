//Riley Monwai CST-210
//Lydia Fritz 3/7/21 

#include "Game.h"
#include "Guess.h"
#include <iostream>
#include <string>

Game::Game()
{
	srand(time(NULL));
	setSecretCode();
}

void Game::setSecretCode()
{
	for (int i = 0; i < 4; i++) {
		secretCode[i] = rand() % 6;
	}
}

string Game::giveFeedback(Guess g)
	//Creates 2 arrays of integers
	//Each node corresponds to a certain color
{
	int whitePegCt = 0;
	int blackPegCt = 0;
	//Black pegs
	for (int i = 0; i < 4; i++) {
		if (g.operator[](i) == secretCode[i]) {
			blackPegCt++;
		}
	}
	//White Pegs
	int secretCodeColors[6] { 0,0,0,0,0,0 }; 
	int guessColors[6] = { 0,0,0,0,0,0 };

	for (int i = 0; i < 4; i++) { //Adding numbers to array
		guessColors[g.operator[](i)] ++; //Guess code
		secretCodeColors[secretCode[i]] ++; //Secret code
	}
	
	for (int i = 0; i < 6; i++) { //Adding white pegs
		whitePegCt += min(secretCodeColors[i], guessColors[i]); //Add minumum value at i of the 2 arrays
	}
	whitePegCt -= blackPegCt;
	
	//Win condition
	if (blackPegCt == 4) {
		winner = true;
	} 
	return "White Pegs: " + to_string(whitePegCt) + " Black pegs: " + to_string(blackPegCt);
}

int Game::getRemainingGuesses()
{
	return numGuesses;
}

void Game::playTurn()
{
	numGuesses--;
}

bool Game::isWinner()
{
	return winner;
}

ostream& operator<<(ostream& out, const Game& rhs)
{
	cout << "The Secret code is {" << rhs.secretCode[0] << "," << rhs.secretCode[1] << "," <<
		rhs.secretCode[2] << "," << rhs.secretCode[3] << "}" << endl;
	return out;
}
