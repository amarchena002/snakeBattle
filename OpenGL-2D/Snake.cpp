#include "stdafx.h"
#include "Sprite.h"
#include "Snake.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "vector"

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