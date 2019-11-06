#pragma once

#include "Drawable.h"

#include <string>
using namespace std;

class Snake : public Drawable
{
	int headPosX;
	int headPosY;
	string m_color;

public:

	Snake();
	~Snake();
	void eatApple(string color);
};