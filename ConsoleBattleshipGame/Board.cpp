#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "Board.h"
#include "Polje.h"
#include <algorithm>
#include <cctype>

using namespace std;

Board::Board(int maxRows)
{
	_maxRows = maxRows;
	_totalAttempts = 0;
	ABC = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R', 'S', 'T', 'U', 'V', 'Z' };
	InitPolja();
}

Board::~Board()
{
}

void Board::InitPolja() {
	for (size_t i = 0; i < _maxRows; i++)
	{
		vector<Polje> tmp;
		for (size_t j = 0; j < _maxRows; j++)
		{
			tmp.push_back(Polje());
		}
		_polja.push_back(tmp);
	}
}


void Board::IspisiZaglavlje()
{
	cout << setw(3) << "";

	for (size_t i = 0; i < _maxRows; i++)
	{
		cout << setw(3) << ABC[i];
	}

	cout << endl;
}

void Board::PrintBoard()
{
	IspisiZaglavlje();
	for (size_t i = 0; i < _maxRows; i++)
	{
		cout << setw(3) << i + 1;
		for (size_t j = 0; j < _maxRows; j++)
		{
			cout << setw(3) << (_polja[i][j].isShip() ? "O" : "~");
			if (j == _maxRows - 1)
			{
				cout << endl;
			}
		}
	}
}

void Board::PrintAttempts()
{
	IspisiZaglavlje();
	for (size_t i = 0; i < _maxRows; i++)
	{
		cout << setw(3) << i + 1;
		for (size_t j = 0; j < _maxRows; j++)
		{
			char c = '~';
			if (_polja[i][j].isHit())
			{
				c = 'X';
			}
			else if (_polja[i][j].isVisited())
			{
				c = '#';
			}
			cout << setw(3) << c;
			if (j == _maxRows - 1)
			{
				cout << endl;
			}
		}
	}
}

void Board::AddShip(koordinate_t cor, Ship ship)
{
	int id = _ships.size() + 1;
	int size = ship.getSize();

	_ships.push_back(ship);

}

void Board::RasporediBrodove()
{
	_ships.push_back(Ship(5, 1));
	_polja[0][1].setShip(true, 1);
	_polja[0][2].setShip(true, 1);
	_polja[0][3].setShip(true, 1);
	_polja[0][4].setShip(true, 1);
	_polja[0][5].setShip(true, 1);

	_ships.push_back(Ship(4, 2));
	_polja[2][4].setShip(true, 2);
	_polja[3][4].setShip(true, 2);
	_polja[4][4].setShip(true, 2);
	_polja[5][4].setShip(true, 2);

	_ships.push_back(Ship(3, 3));
	_polja[7][1].setShip(true, 3);
	_polja[7][2].setShip(true, 3);
	_polja[7][3].setShip(true, 3);

	_ships.push_back(Ship(3, 4));
	_polja[9][7].setShip(true, 4);
	_polja[9][8].setShip(true, 4);
	_polja[9][9].setShip(true, 4);

	_ships.push_back(Ship(2, 5));
	_polja[7][6].setShip(true, 5);
	_polja[7][7].setShip(true, 5);
}

int Board::CharIndex(char c)
{
	int pos = distance(ABC.begin(), find(ABC.begin(), ABC.end(), c));
	return pos;
}

int Board::Shoot(koordinate_t cor)
{
	Polje &p = _polja[cor.row][cor.col];
	int id = 0;

	p.visited();
	_totalAttempts++;

	if (p.isShip())
	{
		if (p.isHit())
		{
			return -1;
		}
		else {
			p.setHit(true);
			id = p.getShipId();
			vector<Ship>::iterator it = find_if(_ships.begin(), _ships.end(), [&id](Ship& itm) {
				return itm.getId() == id;
			});

			if (it != _ships.end())
			{
				it->takeHit();
			}
			return 1;
		}
	}
	else
	{
		return 0;
	}
}

void Board::PrintSummary()
{
	int totalHits = 0;
	int totalShipsDown = 0;

	for (size_t i = 0; i < _maxRows; i++)
	{
		for (size_t j = 0; j < _maxRows; j++)
		{
			if (_polja[i][j].isHit())
			{
				totalHits++;
			}
		}
	}

	for (Ship s : _ships)
	{
		if (s.isSunken())
		{
			totalShipsDown++;
		}
	}

	cout << "Ukupno pokušaja: " << _totalAttempts << "  Ukupno pogodaka: " << totalHits << "  Potopljeno brodova: " << totalShipsDown << "/" << _ships.size();
}

koordinate_t Board::MaxRowsCols()
{
	koordinate_t cor;
	cor.col = _maxRows;
	cor.row = _maxRows;
	return cor;
}

void Board::Test() {
	vector<Ship>::iterator it;

	for (it = _ships.begin(); it != _ships.end(); ++it)
	{
		cout << "Ship ID: " << it->getId();
		cout << " Size: " << it->getSize();
		cout << " Total hits: " << it->totalHits();
		cout << " Potopljen: " << it->isSunken() << endl;
	}
}