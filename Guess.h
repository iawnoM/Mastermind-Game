//Riley Monwai CST-210
//Lydia Fritz 3/7/21

#pragma once
#ifndef GUESS_H
#define GUESS_H

#include <iostream>
#include <vector>
using namespace std;

class Guess
{
private:
	int a;
	int b;
	int c;
	int d;
	int userGuess[4];
public:
	Guess(int,int,int,int);
	void setGuess(int, int, int, int);
	void setNums(int, int, int, int);
	int operator[](int i);
	friend ostream& operator<<(ostream& out, const Guess& rhs);
	//friend istream& operator>>(istream& in, Guess& rhs);
	};

#endif  