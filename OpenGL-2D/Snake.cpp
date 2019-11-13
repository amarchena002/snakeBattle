#include "stdafx.h"
#include "Sprite.h"
#include "Snake.h"

Snake::Snake()
{}

Snake::Snake(Position position, string dir, string color)
{
	m_headPosition = position;
	m_direction = dir;
	m_color = color;
	//snake = //inicializar array
	m_snakeLength = 2; //initial length
	m_snake = vector <Position>();
	m_snake.push_back(m_headPosition);
}

Snake::~Snake()
{
}

void Snake::moveUp()
{
	m_headPosition.setY(m_headPosition.getY() - 1);
	m_direction = dir_up;
}

void Snake::moveDown()
{
	m_headPosition.setY(m_headPosition.getY() + 1);
	m_direction = dir_down;
}

void Snake::moveRigth()
{
	m_headPosition.setX(m_headPosition.getX() + 1);
	m_direction = dir_rigth;
}

void Snake::moveLeft()
{
	m_headPosition.setX(m_headPosition.getX() - 1);
	m_direction = dir_left;
}

void Snake::eatApple(string color)
{
	if (color == m_color) 
	{
		m_snakeLength++;

	}
	else
	{
		m_snakeLength--;
	}
}

void Snake::eatStone()
{
	//reducir array snake[snakeLength] 
	m_snakeLength = m_snakeLength - 1;
}