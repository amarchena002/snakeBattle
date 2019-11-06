#include "stdafx.h"
#include "Sprite.h"
#include "Snake.h"

Snake::Snake(int posX, int posY, string dir)
{
	headPosX = posX;
	headPosY = posY;
	direction = dir;
	//snake =
	snakeLength = 2; //initial length

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