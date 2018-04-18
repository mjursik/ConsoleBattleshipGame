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
	bool isShip();
	bool isHit();
	int getShipId();
};
