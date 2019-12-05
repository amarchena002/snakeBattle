#pragma once
#include "Position.h"
#include <string>
#include "Drawable.h"
#include "Renderer.h"
using namespace std;

class Apple:public Drawable
{
	string m_appleColor;
	Position m_pos;

public:

	Apple(string appleColor, Position pos);
	~Apple();

	string getColor();
	Position getPosition();
	bool isTheSameColor(string snakeColor);
	virtual void draw();
	virtual string getName();
};