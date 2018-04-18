#pragma once

class Ship {
private:
	int _id;
	int _size;
	int _hits;
public:
	Ship(int, int);
	~Ship();
	int getSize();
	int getId();
	int totalHits();
	void takeHit();
	int isSunken();
};
