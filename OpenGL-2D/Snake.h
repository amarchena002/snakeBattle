#pragma once

#include "Drawable.h"
#include "Position.h"
#include <vector>
#include <string>
using namespace std;

class Snake : public Drawable
{
	Position m_headPosition;
	string m_direction; // Up, Down, Left, Rigth
	vector<Position> m_snake;
	int m_snakeLength;
	string m_color;
	vector<Sprite> sprites;

	char const dir_up = 'u';
	char const dir_down = 'd';
	char const dir_rigth = 'r';
	char const dir_left = 'l';
	

public:

	Snake(Position position, string dir,string color);
	~Snake();

	void moveUp();
	void moveRigth();
	void moveDown();
	void moveLeft();

	void eatApple(string color);
	void eatStone();
	virtual void draw();
};