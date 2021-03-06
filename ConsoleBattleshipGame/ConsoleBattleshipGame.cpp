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
	
	string userInput = "";
	koordinate_t cord;

	do
	{
		board1.PrintSummary();

		cout << endl << endl;

		board1.PrintAttempts();

		cout << endl << "Unesite koordinate (npr. B2)." << endl;
		cout << "Za izlaz unesite 'q': " << endl;
		cout << "Koordinate: ";
		cin >> userInput;

		if (userInput.length() >= 2)
		{
			cord.col = board1.CharIndex(static_cast<char>(toupper(userInput[0])));
			string sRow = userInput.substr(1, userInput.length() - 1);
			try
			{
				cord.row = stoi(sRow) - 1;
			}
			catch (const std::exception&)
			{
				cord.row = -1;
			}

			koordinate_t maxRowsCols = board1.MaxRowsCols();

			if ((cord.col >= 0 && cord.col <= maxRowsCols.col) && (cord.row >= 0 && cord.row <= maxRowsCols.row))
			{
				int hit = board1.Shoot(cord);
			}
		}

		system("cls");

	} while (userInput[0] != 'q');

	cin.get();
}