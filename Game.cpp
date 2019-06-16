#include <string>
#include "PlayersRoom.h"

using namespace std;

void Human::set()
{
	for (int i = 0; i < ships.size(); i++)
	{
		if ((*ships[i]).size != 1 && (*ships[i]).size != 2)
		{
			if ((*ships[i]).directionvert())
				for (int j = (*ships[i]).getv(1); j < (*ships[i]).getv(0); j++)
					myfield[j][(*ships[i]).getg(1)] = '+';
			else
				for (int j = (*ships[i]).getg(1); j < (*ships[i]).getg(0); j++)
					myfield[(*ships[i]).getv(1)][j] = '+';
		}
		else
		{
			myfield[(*ships[i]).getv(1)][(*ships[i]).getg(1)] = '+';
			myfield[(*ships[i]).getv(0)][(*ships[i]).getg(0)] = '+';
		}
	}
}

void Human::create_field()
{
	string start, end;
	cout << "Начнём расставлять с Линкора(4-х палубный)! Введите клетку, где расположен нос коробля: ";
	getline(cin, start);
	cout << "Теперь клетку, где расположена корма: ";
	getline(cin, end);

	Ship* sh = new Ship(start, end);
	ships.push_back(sh);

	cout << endl << "Теперь два Крейсера(3-х палубные)! ";
	for (int i = 0; i < 2; i++)
	{
		cout << "Введите клетки, где расположен нос и корма для " << i + 1 << " корабля: ";
		getline(cin, start);
		getline(cin, end);
		Ship* sh1 = new Ship(start, end);
		ships.push_back(sh1);
	}

	cout << endl << "Теперь три Эсминеца(2-х палубные)! ";
	for (int i = 0; i < 3; i++)
	{
		cout << "Введите клетки, где расположен нос и корма для " << i + 1 << " корабля: ";
		getline(cin, start);
		getline(cin, end);
		Ship* sh2 = new Ship(start, end);
		ships.push_back(sh2);
	}

	cout << endl << "Теперь четыре Катера(1-а палубные)! ";
	for (int i = 0; i < 4; i++)
	{
		cout << "Введите клетки, где расположен нос и корма для " << i + 1 << " корабля: ";
		getline(cin, start);
		getline(cin, end);
		Ship* sh1 = new Ship(start, end);
		ships.push_back(sh1);
	}
}

void Human::viewfields()
{
	cout << ' ';
	for (int i = 0; i < 2; i++)
	{
		for (const auto &j : alf)
			cout << ' ' << j.first;
		if (i == 0)
			cout << "   ";
	}

	cout << endl << ' ';
	for (int i = 0; i < 20; i++)
	{
		cout << ' ' << '-';
		if (i == 9)
			cout << "   ";
	}

	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << '|';
		for (int k = 0; k < 10; k++)
			cout << myfield[i][k] << '|';
		cout << ' ' << i + 1 << '|';
		for (int k = 0; k < 10; k++)
			cout << rivfield[i][k] << '|';

		cout << endl << ' ';
		for (int i = 0; i < 20; i++)
		{
			cout << ' ' << '-';
			if (i == 9)
				cout << "   ";
		}
		cout << endl;
	}
}
