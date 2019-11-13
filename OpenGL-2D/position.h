#pragma once
#include "stdafx.h"

class Position
{
	int m_x;
	int m_y;

public:
	Position();
	Position(int x, int y);
	~Position();
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
};

