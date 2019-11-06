#include "stdafx.h"
#include "Sprite.h"
#include "Snake.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"

Snake::Snake(int posX, int posY, char dir, char color)
{
	headPosX = posX;
	headPosY = posY;
	direction = dir;
	snakeColor = color;
	//snake = //inicializar array
	snakeLength = 2; //initial length

Snake::~Snake()
{
}

Snake::~Snake()
{
}

void Snake::moveUp()
{
	headPosY += 1;
	direction = dir_up;
}

void Snake::moveDown()
{
	headPosY -= 1;
	direction = dir_down;
}

void Snake::moveRigth()
{
	headPosX += 1;
	direction = dir_rigth;
}

void Snake::moveLeft()
{
	headPosX -= 1;
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

	}
}

void Snake::eatStone()
{
	//reducir array snake[snakeLength] 
	snakeLength = snakeLength - 1;
}