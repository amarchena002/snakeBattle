#include "Position.h"



Position::Position()
{
}

Position::Position(float x, float y)
{
	m_x = x;
	m_y = y;
}


Position::~Position()
{
}

void Position::setX(float x)
{
	m_x = x;
}

void Position::setY(float y)
{
	m_y = y;
}

float Position::getX()
{
	return m_x;
}

float Position::getY()
{
	return m_y;
}
