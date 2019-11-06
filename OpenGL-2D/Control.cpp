#include "Snake.h"
#include "World.h"
#include "Control.h"


Control::Control(Snake& snake1, Snake& snake2, Worls& world) : m_snake1(snake1), m_snake2(snake2), m_world(world)
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
		case 'a': snake1.moveLeft();
			break;
		case 'd': snake1.moveRight();
			break;
		case 'w': snake1.moveUp();
			break;
		case 's': snake1.moveDown();
			break;

			//Para Snake2
		case 'j': snake2.moveLeft();
			break;
		case 'l': snake2.moveRight();
			break;
		case 'i': snake2.moveUp();
			break;
		case 'k': snake2.moveDown();
			break;

			//Para salir
		case 27: esc = true; //Si pulsamos "Esc" se sale del juego
			return ;
		}
	}
}
