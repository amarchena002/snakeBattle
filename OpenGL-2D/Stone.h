#pragma once
#include "position.h"
#include "Drawable.h"
#include "Renderer.h"
using namespace std;
class Stone : public Drawable
{
	Position m_pos;

	public:
		Stone(Position pos);
		~Stone();
		
		Position getPosition();
		virtual void draw();
		virtual string getName();
};