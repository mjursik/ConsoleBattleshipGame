#pragma once

#include <vector>
#include <string>
#include "Polje.h"
#include "Ship.h"

using namespace std;

class Board
{
private:
	uint16_t _maxRows = 0;
	vector<Ship> _ships;
	vector<std::vector<Polje>> _polja;
	vector<char> ABC = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R', 'S', 'T', 'U', 'V', 'Z' };

	void IspisiZaglavlje();
	void InitPolja();
public:
	Board(int);
	~Board();
	void PrintBoard();
	void AddShip(int, int, Ship);
	void RasporediBrodove();
	int CharIndex(char);
	int Shoot(const int, const int);
	Ship FindShip(int);
	void Test();
};

