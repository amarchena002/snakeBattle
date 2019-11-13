#include "stdafx.h"
#include "Sprite.h"
#include "Snake.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "vector"

Snake::Snake(int posX, int posY, char dir, char color)
{
	headPosX = posX;
	headPosY = posY;
	direction = dir;
	snakeColor = color;
	//snake = //inicializar array
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

void Sprite::draw()
{
	Renderer renderer;
	InputHandler inputHandler(renderer);

	renderer.initialize(argc, argv);
	inputHandler.initialize();

	vector<Sprite> sprites;

	for (int i = 0; i < snakeLength; i++)
	{
		Sprite *pSprite = new Sprite();
		if (m_color == "red")
		{
			pSprite->setColor(1, 0, 0);
		}
		else if (m_color == "green")
		{
			pSprite->setColor(0, 1, 0);
		}
		pSprite->setPosition(snake.at(i)[0], snake.at(i)[1]);
		pSprite->setSize(0.02);
		pSprite->setDepth(-1.5);
		sprites.push_back(pSprite);

	}
	for(int i = 0; i < sprites.size(); i++)
	{
		renderer.addObject(sprites.at(i));
	}


}