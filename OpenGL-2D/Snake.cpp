#include "stdafx.h"
#include "Sprite.h"
#include "Snake.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"


Snake::Snake()
{
}

Snake::~Snake()
{
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
		if (m_color = 'red')
		{
			pSprite->setColor(1, 0, 0);
		}
		else if (m_color = 'green')
		{
			pSprite->setColor(0, 1, 0);
		}
		pSprite->setPosition(snake.at(i)[0], snake.at(i)[1]);
		pSprite->setSize(0.02);
		pSprite->setDepth(-1.5);
		vect.push_back(pSprite);
		
		}
	for (int i = 0; i < sprites.size(); i++) 
	{
		renderer.addObject(sprites.at(i));
	}
	
	
}