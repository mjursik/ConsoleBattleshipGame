// ConsoleBattleshipGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "Polje.h"
#include <vector>
#include "Board.h"
#include <algorithm>
#include <cctype>

using namespace std;

void StartGame();

int main()
{
	StartGame();
}


void StartGame() {
	Board board1 = Board(10);
	board1.RasporediBrodove();
	
	string koordinate = "";
	int row = 0;
	int col = 0;

	do
	{
		cout << "Unesite koordinate (npr. B2): ";
		cin >> koordinate;

		if (koordinate.length() >= 2)
		{
			col = board1.CharIndex(static_cast<char>(toupper(koordinate[0])));
			string sRow = koordinate.substr(1, koordinate.length() - 1);
			row = stoi(sRow) - 1;

			int hit = board1.Shoot(row, col);

			switch (hit)
			{
			case 1:
				cout << "Pogodak" << endl;
				break;
			case -1:
				cout << "Vec pogodeno" << endl;
				break;
			case 0:
				cout << "Promasaj" << endl;
				break;
			default:
				break;
			}
		}

	} while (koordinate[0] != 'q');

	cin.get();
}