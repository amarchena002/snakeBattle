#include "stdafx.h"
#include "Sprite.h"
#include "Snake.h"

Snake::Snake(Position position, string dir)
{
	m_headPosition = position;
	direction = dir;
	snakeColor = color;
	//snake = //inicializar array
	snakeLength = 2; //initial length
	snake = vector <Position>();
	snake.push_back(m_headPosition);
}

Snake::~Snake()
{
}

void Snake::moveUp()
{
	m_headPosition.setY(m_headPosition.getY() - 1);
	direction = dir_up;
}

void Snake::moveDown()
{
	m_headPosition.setY(m_headPosition.getY() + 1);
	direction = dir_down;
}

void Snake::moveRigth()
{
	m_headPosition.setX(m_headPosition.getX() + 1);
	direction = dir_rigth;
}

void Snake::moveLeft()
{
	m_headPosition.setX(m_headPosition.getX() - 1);
	direction = dir_left;
}

void Snake::eatApple(string color)
{
	if (color == m_color) 
	{
		snakeLength++;

	}
	else
	{
		snakeLength--;
	}
}

void Snake::eatStone()
{
	//reducir array snake[snakeLength] 
	snakeLength = snakeLength - 1;
}