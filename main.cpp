//#include <iostream>
//#include <locale.h>
#include "PlayersRoom.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Welcom!" << endl;

	Human* player1 = new Human();

	player1->create_field();
	player1->viewfields();

	system("pause");
	return 0;
}
