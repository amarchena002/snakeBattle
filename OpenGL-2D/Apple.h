#pragma once
#include "position.h"
#include <string>
using namespace std;

class Apple
{
	string m_appleColor;
	Position m_pos;

public:

	Apple(string appleColor, Position pos);
	~Apple();

	string getColor();
	Position getPosition();
	bool isTheSameColor(string snakeColor);
	void draw();
};