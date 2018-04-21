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
		board1.PrintSummary();

		cout << endl << endl;

		board1.PrintAttempts();

		cout << endl << "Unesite koordinate (npr. B2)." << endl;
		cout << "Za izlaz unesite 'q': " << endl;
		cout << "Koordinate: ";
		cin >> koordinate;

		if (koordinate.length() >= 2)
		{
			col = board1.CharIndex(static_cast<char>(toupper(koordinate[0])));
			string sRow = koordinate.substr(1, koordinate.length() - 1);
			try
			{
				row = stoi(sRow) - 1;
			}
			catch (const std::exception&)
			{
				row = -1;
			}

			koordinate_t maxRowsCols = board1.MaxRowsCols();

			if ((col >= 0 && col <= maxRowsCols.col) && (row >= 0 && row <= maxRowsCols.row))
			{
				int hit = board1.Shoot(row, col);
			}
		}

		system("cls");

	} while (koordinate[0] != 'q');

	cin.get();
}