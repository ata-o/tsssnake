#pragma once
#include "Fruit.h"
class Snake
{
	enum dir {UP, DOWN, LEFT, RIGHT};
	int _dir;
	int size;
	double headX, headY;
	int score = 0;
	struct Block 
	{
		double x, y;
	};
	Block *barr;

public:
	Snake();
	~Snake();
	int getScore() { return score; }
	double getX() { return headX; }
	double getY() { return headY; }
	void setX(double x) { headX = x; }
	void setY(double y) { headY = y; }

	void drawTrail();
	void draw();
	bool eat(Fruit);
	void move();
	void changeDir();
	bool screenFail(double, double);
	bool selfFail();
	

};

