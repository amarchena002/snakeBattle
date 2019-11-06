#pragma once

#include "Snake.h"
#include "World.h"

class Control
{
	Snake &m_snake1, &m_snake2;
	World& m_world;
	bool esc = false;

public:
	Control(Snake& snake1, Snake& snake2, World& world);
	~Control();

	void processInput();
};
