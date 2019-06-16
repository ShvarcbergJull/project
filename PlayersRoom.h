#pragma once
#include <vector>
#include "DetailsOfGame.h"

using namespace std;

class Player
{
protected:
	vector<vector<char>> myfield;
	vector<vector<char>> rivfield;
	vector<Ship*> ships;

	virtual void create_field() = 0;
public:
	Player()
	{
		myfield.reserve(10);
		rivfield.reserve(10);
		for (int i = 0; i < 10; i++)
		{
			myfield[i].reserve(10);
			rivfield[i].reserve(10);
			for (int j = 0; j < 10; j++)
			{
				myfield[i][j] = ' ';
				rivfield[i][j] = ' ';
			}
		}

		for (int i = 1; i < 11; i++)
		{
			alf[i + 64] = i;
		}
	}
};

class Human : public Player
{
public:
	Human() : Player() {};

	void create_field();

	void set();

	void viewfields();
};

class Computer : public Player
{
public:
	Computer() : Player() {};

	void create_field();
};
