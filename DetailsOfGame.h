#pragma once
#include <iostream>
#include <map>
#include <math.h>

using namespace std;

map<char, int> alf;

struct Ship
{
public:
	int size;
	pair<char, int> posstart;
	pair<char, int> posend;
	string name;

	Ship(string posst, string pose)
	{
		if (posst.size() > 3 || pose.size() > 3)
		{
			cout << "Неправильный формат номер клетки!" << endl;
		}

		posstart.first = posst[0];
		posend.first = pose[0];

		if (posst.size() == 3)
			posstart.second = 10;
		else
			posstart.second = posst[1] - '0';

		if (pose.size() == 3)
			posend.second = 10;
		else
			posend.second = pose[1] - '0';

		/*----------------------------------------------*/

		if (posstart == posend)
		{
			size = 1;
			name = "Катер";
		}
		else
		{
			size = (posstart.first == posend.first ? abs(posend.second - posstart.second) : abs(alf[posend.first] - alf[posstart.first]));
			size++;
			name = (size == 2 ? "Эсминец" : (size == 3 ? "Крейсер" : "Линкор"));
		}
	}

	bool directionvert()
	{
		if (posstart.first == posend.first)
			return true;
		return false;
	}

	int getv(bool a)
	{
		if (a)
			return  posstart.second;
		return posend.second;
	}

	int getg(bool a)
	{
		if (a)
			return alf[posstart.first];
		return alf[posend.first];
	}
};

/*bool operator ==(pair<char, int> l, pair<char, int>r)
{
	if (l.first == r.first && l.second == r.second)
		return true;
	return false;
}*/
