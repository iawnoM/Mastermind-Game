//Riley Monwai CST-210
//Lydia Fritz 3/7/21
//This is the main class for my Mastermind program which 
//uses several loops to simulate user guesses and input.

#include <iostream>
#include"Game.h"
#include "Guess.h"
#include <Windows.h>

using namespace std;

Guess getInput(int,int,int,int);

int main() {
	string input;
	cout << "Welcome to mastermind!! Press any key to start! ";
	cin >> input;
	do { //Game loop 
		Game g;
		cout << "Generating secret code "; Sleep(500); cout << ". "; //Sleep for slowly adding dots
		Sleep(500);  cout << ". "; Sleep(500); cout << ". "; Sleep(500);
		//cout << g; //Display secret code
		cout << "Please enter 4 integers(0-5) for a guess in 0 0 0 0 format: ";
		
		while (g.getRemainingGuesses() > 0) { //While user has guesses
			int a; int b; int c; int d;
			cin >> a >> b >> c >> d;
			Guess userGuess = getInput(a,b,c,d);

			g.playTurn(); //One less guess
			string feedback = g.giveFeedback(userGuess);//Find black peg count and determine feedback string
			if (g.isWinner()) { //4 black pegs
				cout << "Guesser Wins!!" << endl;
				break; //Don't display remaining guesses
			}
			else if (g.getRemainingGuesses() == 0) { //no guesses left
				cout << "Out of turns... Guesser looses!" << endl;
				cout << g; //Display code if player looses
				break; //Don't display remaining guesses
			}
			cout << feedback << endl;//Print feedback
			cout << "You have " << g.getRemainingGuesses() << " guesses left!" << endl;
			cout << "Guess again! ";
		}
		// Do you want to play game again
		cout << "Do you want to play again? Y for yes, any key for no: ";
		cin >> input;
		cout << endl;
	} while (input == "Y");
		
	return 0;
}

Guess getInput(int a, int b, int c, int d) {
	while (a > 5 || b > 5 || c > 5 || d > 5) {
		cout << "Guess input must be between 0 and 5..." << endl;
		cout << "Please enter another guess: ";
		cin >> a >> b >> c >> d;
	}
	Guess g(a, b, c, d);
	return g;
}


