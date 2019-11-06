#include "stdafx.h"
#include "Apple.h"

Apple::Apple(char color)
{
	appleColor = color;
}
Apple::~Apple() 
{

}
char Apple::getColor()
{
	return appleColor;
}

bool Apple::isTheSameColor(char snakeColor)
{
	if (appleColor == snakeColor)
		return true;
	else
		return false;
}
