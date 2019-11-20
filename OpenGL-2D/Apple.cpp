#include "stdafx.h"
#include "Apple.h"
#include "position.h"

Apple::Apple(char color, Position pos)
{
	m_appleColor = color;
	m_pos = pos;
}

Apple::~Apple() 
{
}

char Apple::getColor()
{
	return m_appleColor;
}

Position Apple::getPosition() 
{
	
	return m_pos;
}

bool Apple::isTheSameColor(char snakeColor)
{
	if (m_appleColor == snakeColor)
		return true;
	else
		return false;
}
