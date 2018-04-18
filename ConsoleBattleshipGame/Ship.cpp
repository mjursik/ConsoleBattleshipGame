#include <ctime>
#include <chrono>
#include "stdafx.h"
#include "Ship.h"


Ship::Ship(int s, int id)
{
	_size = s;
	_hits = 0;
	_id = id;
}


Ship::~Ship()
{
}

int Ship::getSize()
{
	return _size;
}

int Ship::getId()
{
	return _id;
}

int Ship::totalHits()
{
	return _hits;
}

void Ship::takeHit()
{
	if (_hits < _size)
	{
		_hits++;
	}
}

int Ship::isSunken()
{
	return _hits == _size;
}
