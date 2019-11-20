#include "stdafx.h"
#include "Apple.h"
#include "position.h"


Apple::Apple(string color, Position pos)
{
	m_appleColor = color;
	m_pos = pos;
}

Apple::~Apple() 
{
}

string Apple::getColor()
{
	return m_appleColor;
}

Position Apple::getPosition() 
{
	return m_pos;
}

bool Apple::isTheSameColor(string snakeColor)
{
	if (m_appleColor.compare(snakeColor)==0) //--> Comparación de strings
	//if (m_appleColor == snakeColor)
		return true;
	else
		return false;
}
