#pragma once
#include "position.h"

class Stone
{
	Position m_pos;

	public:
		Stone(Position pos);
		~Stone();
		
		Position getPosition();
		void draw();
};