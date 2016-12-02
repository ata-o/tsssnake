#include "Snake.h"
#include "SimpleDraw.h"



Snake::Snake()
{
	headX = 100;
	headY = 100;
	_dir = RIGHT;
	size = 2;
	barr = new Block[size];
	
	barr[1].x = headX - 10;
	barr[0].x = headX - 20;
	barr[0].y = headY;
	barr[1].y = headY;
}

Snake::~Snake()
{
	delete[] barr;
}


bool Snake::eat(Fruit a)
{
	if (a.getX() == headX && a.getY() == headY)
	{
		score += 10;
		Block *dumbarr = new Block[size + 1];
		for (int i = 0; i < size; i++)
		{
			dumbarr[i].x = barr[i].x;
			dumbarr[i].y = barr[i].y;
		}
		dumbarr[size].x = headX;
		dumbarr[size].y = headY;
		delete[] barr;
		barr = new Block[size + 1];
		for (int i = 0; i < size; i++)
		{
			barr[i].x = dumbarr[i].x;
			barr[i].y = dumbarr[i].y;
		}
		delete[] dumbarr;
		size++;
		return true;
	}
	else
		return false;
}

void Snake::drawTrail()
{
	for (int i = 0; i < size; i++)
	{
		drawSquare(barr[i].x, barr[i].y, 10);
	}
}

void Snake::draw()
{
	usePen(1,1,RGB(255,255,255));
	drawTrail();
	drawSquare(headX, headY, 10);
	
}
void Snake::changeDir()
{
	/*
	keycodes
	 LEFT = 37
	 UP = 38
	 RIGHT = 39
	 DOWN = 40
	 */
	switch (getKey())
	{
	case 37:
		if(_dir != RIGHT)
			_dir = LEFT;
		break;
	case 38:
		if (_dir != DOWN)
			_dir = UP;
		break;
	case 39:
		if (_dir != LEFT)
			_dir = RIGHT;
		break;
	case 40:
		if (_dir != UP)
			_dir = DOWN;
		break;
	default:
		break;
	}
}

void Snake::move()
{
	changeDir();
	for (int i = 0; i < size - 1; i++)
	{
		barr[i].x = barr[i + 1].x;
		barr[i].y = barr[i + 1].y;
	}
	barr[size - 1].x = headX;
	barr[size - 1].y = headY;
	switch (_dir)
	{
	case RIGHT:
		headX += 10;

		break;
	case LEFT:
		headX -= 10;

		break;
	case UP:
		headY -= 10;

		break;
	case DOWN:
		headY += 10;
		break;
	}
}

bool Snake::screenFail(double x, double y)
{
	if (headX + 11 >= x)
		return true;
	else if (headX <= 0)
		return true;
	else if (headY <= 0)
		return true;
	else if (headY + 11 >= y)
		return true;
	else if (1)
		return false;
}

bool Snake::selfFail()
{
	for (int i = 0; i < size; i++)
	{
		if (barr[i].x == headX && barr[i].y == headY)
		{
			return 1;
		}
	}
	return 0;
}