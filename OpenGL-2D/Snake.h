#pragma once

#include "Drawable.h"

#include <string>
using namespace std;

class Snake : public Drawable
{
	int headPosX;
	int headPosY;
	string direction; // Up, Down, Left, Rigth
	int snake[20]; //max 20 change!
	int snakeLength;
	char snakeColor;
	string m_color;

	char const dir_up = 'u';
	char const dir_down = 'd';
	char const dir_rigth = 'r';
	char const dir_left = 'l';
	

public:

	Snake(int posX, int posY, char dir, char color);
	~Snake();

	void moveUp();
	void moveRigth();
	void moveDown();
	void moveLeft();

	void eatApple(string color);
	void eatStone();
	virtual void draw();
};