#include "stdafx.h"
#include "InputHandler.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
//#include "Snake.h"
#include "World.h"

InputHandler* InputHandler::m_pInputHandler = nullptr;

InputHandler::InputHandler(Renderer& renderer) : m_renderer(renderer) //(Snake& snake1, Snake& snake2, World& world) : , m_snake1(snake1), m_snake2(snake2), m_world(world)
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
		case 'a': //m_snake1.moveLeft();
			((World*)m_renderer.getByName("world"))->moveSnake("m_snake1", 'l');
			break;
		case 'd': //m_snake1.moveRigth();
			((World*)m_renderer.getByName("world"))->moveSnake("m_snake1", 'r');
			break;
		case 'w': //m_snake1.moveUp();
			((World*)m_renderer.getByName("world"))->moveSnake("m_snake1", 'u');
			break;
		case 's': //m_snake1.moveDown();
			((World*)m_renderer.getByName("world"))->moveSnake("m_snake1", 'd');
			break;

			//Snake2
		case 'j': //m_snake2.moveLeft();
			((World*)m_renderer.getByName("world"))->moveSnake("m_snake2", 'l');
			break;
		case 'l': //m_snake2.moveRigth();
			((World*)m_renderer.getByName("world"))->moveSnake("m_snake2", 'r');
			break;
		case 'i': //m_snake2.moveUp();
			((World*)m_renderer.getByName("world"))->moveSnake("m_snake2", 'u');
			break;
		case 'k': //m_snake2.moveDown();
			((World*)m_renderer.getByName("world"))->moveSnake("m_snake2", 'd');
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