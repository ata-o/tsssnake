#include <iostream>
#include "SimpleDraw.h"
#include "Fruit.h"
#include "Snake.h"
#include <string> 
using namespace std;

int main()
{
	setWindowSize(500, 500);

	bool screenFailFlag = false;
	bool selfFailFlag = false;

	Fruit fruit;
	Snake snake;

	fruit.spawn(snake.getX(), snake.getY());
	cout << "Score: " << snake.getScore(); //initialization of some things

	while (getMouseButton() != '1')
	{

		useBrush(1, RGB(0, 0, 0));
		drawRectangle(0, 0, 500, 500);	//clear screen

		fruit.draw();
		snake.draw();

		if (snake.eat(fruit))
		{
			system("cls");
			cout << "Score: " << snake.getScore() << endl;
			fruit.spawn(snake.getX(), snake.getY());
		}

		if (snake.screenFail(500, 500))
		{
			screenFailFlag = true;
			break;
		}

		if (snake.selfFail())
		{
			selfFailFlag = true;
			break;
		}

		snake.move();

		Sleep(100);
	}
	if (screenFailFlag)
	{
		drawText(150, 200, "Fail! You have touched a wall");
		drawText(150, 215, "Press Left Mouse Button To Quit");
		while (getMouseButton() != 1);
		return 0;
	}
	else if (selfFailFlag)
	{
		drawText(150, 200, "Fail! You have touched yourself");
		drawText(150, 215, "Press Left Mouse Button To Quit");
		while (getMouseButton() != 1);
		return 0;
	}
	return 0;
}