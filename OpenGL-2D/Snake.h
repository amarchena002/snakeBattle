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

	string const dir_up = "up";
	string const dir_down = "down";
	string const dir_rigth = "rigth";
	string const dir_left = "left";
	string m_color;

public:

	Snake(int posX, int posY, string dir);
	~Snake();
	void moveUp();
	void moveRigth();
	void moveDown();
	void moveLeft();
};