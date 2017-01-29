#include <iostream>
#include "SimpleDraw.h"
#include "Fruit.h"
#include "Snake.h"
#include <string> 
#include <Windows.h>
#define IDI_ICON1 //i added an icon to this app because it makes me happy


void HideConsole()
{
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

void ShowConsole()
{
	::ShowWindow(::GetConsoleWindow(), SW_SHOW);
}
using namespace std;

int main()
{
	HideConsole();
	setWindowSize(510, 535); //i changed these values because the window overlaps with the background

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

		Sleep(75);
		if (getKey() == 'P')
		{
			while (getKey() == 'P')
			{
			}
		}//yes, you can pause the game now
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
