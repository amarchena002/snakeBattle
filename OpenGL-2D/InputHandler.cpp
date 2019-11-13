#include "stdafx.h"
#include "InputHandler.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "Snake.h"
#include "World.h"

InputHandler* InputHandler::m_pInputHandler = nullptr;

InputHandler::InputHandler(Renderer& renderer, Snake& snake1, Snake& snake2, World& world) : m_renderer(renderer), m_snake1(snake1), m_snake2(snake2), m_world(world)
{
	m_pInputHandler = this;
}


InputHandler::~InputHandler()
{
}

void InputHandler::initialize()
{
	glutKeyboardFunc(__processKeyboard);
}


void InputHandler::processKeyboard(unsigned char key, int x, int y)
{
	//keyboard callback function
	switch (key)
	{
			//Snake1
		case 'a': m_snake1.moveLeft();
			break;
		case 'd': m_snake1.moveRigth();
			break;
		case 'w': m_snake1.moveUp();
			break;
		case 's': m_snake1.moveDown();
			break;

			//Snake2
		case 'j': m_snake2.moveLeft();
			break;
		case 'l': m_snake2.moveRigth();
			break;
		case 'i': m_snake2.moveUp();
			break;
		case 'k': m_snake2.moveDown();
			break;

			//Exit
		case 27: exit(0);
	}
}

void InputHandler::__processKeyboard(unsigned char key, int x, int y)
{
	if (m_pInputHandler)
		m_pInputHandler->processKeyboard(key, x, y);
}