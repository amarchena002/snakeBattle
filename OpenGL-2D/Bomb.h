#pragma once
#include "position.h"

class Bomb
{
	Position m_pos;

public:
	Bomb(Position pos);
	~Bomb();

	Position GetPosition();
};