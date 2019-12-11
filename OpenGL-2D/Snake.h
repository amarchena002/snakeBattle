#pragma once

#include "Drawable.h"
#include "Position.h"
#include <vector>
#include <string>
using namespace std;

class Snake : public Drawable
{
	Position m_headPosition;
	char m_direction; // Up, Down, Left, Rigth
	vector<Position> m_snake;
	int m_snakeLength;
	Position m_tailPosition;
	string m_color;
	float m_speed;
	char m_directionAfter;
	char m_dirAux;
	char const dir_up = 'u';
	char const dir_down = 'd';
	char const dir_right = 'r';
	char const dir_left = 'l';
	

public:

	Snake();

	Snake(Position position, char dir,string color);
	~Snake();

	void moveUp();
	void moveRight();
	void moveDown();
	void moveLeft();
	vector<Position> getVector();

	void eatApple(string color);
	void eatStone();
	void eatBomb();
	char getDirection();
	void setDirectionAfter(char direction);
	virtual void draw();
	virtual string getName();
	void updatePos();
	Position getHeadPosition();
	string getColor();
	void borderCollision();
};