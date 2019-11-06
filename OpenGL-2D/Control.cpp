#include "Snake.h"
#include "World.h"
#include "Control.h"


Control::Control(Snake& snake1, Snake& snake2, Worls& world))
{

}
Control::~Control()
{

}

void Control::processInput()
{
	if (!System::keyHit())
		return; //Si no se pulsa nada tira para adelante

	while (System::keyHit())
	{

	}
}