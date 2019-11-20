#pragma once
#include "position.h"

class Apple
{
	char m_appleColor;
	Position m_pos;

public:

	Apple(char appleColor, Position pos);
	~Apple();

	char getColor();
	Position getPosition();
	bool isTheSameColor(char snakeColor);
};