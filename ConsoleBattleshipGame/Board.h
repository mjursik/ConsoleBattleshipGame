#pragma once

#include <vector>
#include <string>
#include "Polje.h"
#include "Ship.h"
#include "Koordinate.h"

using namespace std;

class Board
{
private:
	uint16_t _maxRows = 0;
	vector<Ship> _ships;
	vector<std::vector<Polje>> _polja;
	vector<char> ABC;

	int _totalAttempts;

	void IspisiZaglavlje();
	void InitPolja();
public:
	Board(int);
	~Board();
	void PrintBoard();
	void PrintAttempts();
	void AddShip(int, int, Ship);
	void RasporediBrodove();
	int CharIndex(char);
	int Shoot(const int, const int);
	void FindShip(int, Ship&);
	void PrintSummary();
	koordinate_t MaxRowsCols();
	void Test();
};

