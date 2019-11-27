#include "Snake.h"
#include "World.h"
#include "Control.h"



Control::Control(Snake& snake1, Snake& snake2, World& world) : m_snake1(snake1), m_snake2(snake2), m_world(world)
{

}

Control::~Control()
{

}

void Control::processInput()
{
	while(System::keyHit())
	{
		char c = System::getNextKey();

		switch (c)
		{
			//Para Snake1
		case 'a': m_snake1.moveLeft();
			break;
		case 'd': m_snake1.moveRigth();
			break;
		case 'w': m_snake1.moveUp();
			break;
		case 's': m_snake1.moveDown();
			break;

			//Para Snake2
		case 'j': m_snake2.moveLeft();
			break;
		case 'l': m_snake2.moveRigth();
			break;
		case 'i': m_snake2.moveUp();
			break;
		case 'k': m_snake2.moveDown();
			break;

			//Para salir
		case 27: esc = true; //Si pulsamos "Esc" se sale del juego
			return ;
		}
	}
}
