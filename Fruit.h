#pragma once
#include <stdlib.h>     
#include <time.h> 

class Fruit
{
	double  x, y;
	const int size = 10;
public:
	double getX() { return x; }
	double getY() { return y; }
	void setX(double x) { this->x = x; }
	void setY(double y) { this->y = y; }
	void spawn();
	void spawn(double x, double y);
	void draw();

};

