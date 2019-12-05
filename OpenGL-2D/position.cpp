#include "stdafx.h"
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

bool Position::operator== (Position& other)
{
	return other.getX() == getX() && other.getY() == getY();
}

bool Position::hasDecimal(Position& other)
{
	if (other.getX() - getX() == 0 && other.getY() - getY() < 0.5f && other.getY() - getY() > 0)
	{
		setY(other.getY());
		return true;
	}
	else if (getX() - other.getX() == 0 && getY() - other.getY() < 0.5f && getY() - other.getY() > 0)
	{
		setY(other.getY());
		return true;
	}
	else if(other.getX() - getX() < 0.5f && other.getX() - getX() > 0 && other.getY() - getY() == 0)
	{
		setX(other.getX());
		return true;
	}
	else if (getX() - other.getX() < 0.5f && getX() - other.getX() > 0 && getY() - other.getY() == 0)
	{
		setX(other.getX());
		return true;
	}
	else 
	{
		return false;
	}
}