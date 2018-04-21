#pragma once
class Polje
{
private:
	bool _isShip;
	bool _isHit;
	int _shipId;
	bool _visited;
public:
	Polje();
	~Polje();
	void setShip(bool, int);
	void setHit(bool);
	void visited();
	bool isShip();
	bool isHit();
	bool isVisited();
	int getShipId();
};
