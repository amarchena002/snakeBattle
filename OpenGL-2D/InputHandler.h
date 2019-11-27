#pragma once

#include "Snake.h"
#include "World.h"

class Renderer;

class InputHandler
{
	static InputHandler* m_pInputHandler;
	Renderer& m_renderer;

	Snake &m_snake1, &m_snake2;
	World& m_world;

public:
	InputHandler(Renderer& renderer); //(, Snake& snake1, Snake& snake2, World& world);
	~InputHandler();

	void initialize();

	void processKeyboard(unsigned char key, int x, int y);
	static void __processKeyboard(unsigned char key, int x, int y);
};

