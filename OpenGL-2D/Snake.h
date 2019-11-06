#pragma once

#include "Drawable.h"
#include "Position.h"
#include <vector>
#include <string>
using namespace std;

class Snake : public Drawable
{
	Position m_headPosition;
	string direction; // Up, Down, Left, Rigth
	vector<Position> snake;
	int snakeLength;

	string const dir_up = "up";
	string const dir_down = "down";
	string const dir_rigth = "rigth";
	string const dir_left = "left";
	string m_color;

public:

	Snake(Position position, string dir);
	~Snake();
	void moveUp();
	void moveRigth();
	void moveDown();
	void moveLeft();
	void eatApple(string color);
};