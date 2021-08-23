//Riley Monwai CST-210
//Lydia Fritz 3/7/21

#include "Guess.h"
#include <iostream>
#include <string>

using namespace std;

Guess::Guess(int a, int b, int c, int d) {
	setNums(a, b, c, d);
	setGuess(a, b, c, d);
}


void Guess::setGuess(int a, int b, int c, int d)
{
	userGuess[0] = a;
	userGuess[1] = b;
	userGuess[2] = c;
	userGuess[3] = d;
}

void Guess::setNums(int a, int b, int c, int d)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}

int Guess::operator[](int i)
{
	return userGuess[i];
}
//Istream in case I want to change sometime
//istream& operator>>(istream& in, Guess& rhs)
//{
//	char c1, c2, c3;
//	int a, b, c, d;
//	in >> a >> c1 >> b >> c2 >> c >> c3 >> d;
//
//	if (!in)return in;
//
//	rhs = Guess(a, b, c, d);
//	return in;
//}

ostream& operator<<(ostream& out, const Guess& rhs)
{
	cout << "{" << rhs.a << "," << rhs.b << "," << rhs.c << "," << rhs.d << "}" << endl;

	return out;
}

