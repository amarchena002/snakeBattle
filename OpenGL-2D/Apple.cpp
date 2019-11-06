#include "stdafx.h"
#include "Apple.h"

Apple::Apple(char color, int x, int y)
{
	appleColor = color;
	posX = x;
	posY = y;
}
Apple::~Apple() 
{

}
char Apple::getColor()
{
	return appleColor;
}

int Apple::getX() 
{
	return posX;
}

int Apple::getY()
{
	return posY;
}
bool Apple::isTheSameColor(char snakeColor)
{
	if (appleColor == snakeColor)
		return true;
	else
		return false;
}
