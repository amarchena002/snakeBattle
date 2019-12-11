#pragma once
#include "position.h"
#include "Drawable.h"
#include "Renderer.h"
#include "Sprite.h"
using namespace std;
class Stone : public Sprite
{
	Position m_pos;

	public:
		Stone();
		Stone(Position pos, string filename);
		Stone(Position pos);
		~Stone();
		
		Position getPosition();
		virtual void draw();
		virtual string getName();
};