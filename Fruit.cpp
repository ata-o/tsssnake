#include "Fruit.h"
#include "SimpleDraw.h"


void Fruit::spawn()
{
	srand(time(NULL));
	x = 10+(rand() % 10)*50;
	y = 10+(rand() % 10)*50;
}

void Fruit::spawn(double x, double y)
{
	do 
		spawn();
	while (Fruit::x == x && Fruit::y == y);
	
}

void Fruit::draw()
{
	
	useBrush(1, RGB(255, 255, 255));
	drawSquare(x, y, size);
}