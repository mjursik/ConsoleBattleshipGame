#include "stdafx.h"
#include "Polje.h"


Polje::Polje()
{
	_isShip = false;
	_isHit = false;
	_shipId = -1;
	_visited = false;
}


Polje::~Polje()
{
}

void Polje::setShip(bool ship, int id)
{
	_isShip = ship;
	_shipId = id;
}

void Polje::setHit(bool hit)
{
	_isHit = hit;
}

void Polje::visited()
{
	_visited = true;
}

bool Polje::isShip()
{
	return _isShip;
}

bool Polje::isHit()
{
	return _isHit;
}

bool Polje::isVisited()
{
	return _visited;
}

int Polje::getShipId()
{
	return _shipId;
}
