#pragma once
#include "stdafx.h"

class Position
{
	float m_x;
	float m_y;

public:
	Position();
	Position(float x, float y);
	~Position();
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	bool operator== (Position& other);
};

