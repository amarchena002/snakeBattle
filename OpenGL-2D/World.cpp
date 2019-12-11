#include "World.h"
#include <fstream>
#include "Snake.h"
#include "stdafx.h"
#include "Sprite.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "vector"
#include "../3rd-party/SOIL/src/SOIL.h"
#include "TextureManager.h"



World::World()
{
	//m_width = 20;
	//m_height = 20;	
	//
	//for (int y = 0; y < m_height; y++)
	//{
	//	for (int x = 0; x < m_width; x++)
	//	{
	//		Position pos = Position(x, y);
	//		m_world.push_back(pos);
	//	}
	//}
	//Position pos = Position(m_width-2, 0);
	//m_snake2 = new Snake(pos, 'l', "red");
	//pos = Position(1, m_height-1);
	//m_snake1 = new Snake(pos, 'r', "green");
	//pos = Position(rand() % m_width, rand() % m_height);
	//m_apple2 = new Apple("red", pos);
	//pos = Position(rand() % m_width, rand() % m_height);
	//while (m_apple2->getPosition() == pos)
	//{
	//	pos = Position(rand() % m_width, rand() % m_height);
	//}
	//m_apple1 = new Apple("green", pos);
	//pos = Position(rand() % m_width, rand() % m_height);
	//while (m_apple1->getPosition() == pos || m_apple2->getPosition() == pos)
	//{
	//	pos = Position(rand() % m_width, rand() % m_height);
	//}
	//for (int i = 0; i <10; i++) {
	//	pos = Position(rand() % m_width, rand() % m_height);
	//	while (m_apple1->getPosition() == pos || m_apple2->getPosition() == pos)
	//	{			
	//		pos = Position(rand() % m_width, rand() % m_height);
	//	}		
	//	for (int j = 0; j < i; j++) 
	//	{
	//		if (m_stone[j]->getPosition() == pos && i != j)
	//		{
	//			pos = Position(rand() % m_width, rand() % m_height);
	//			i = 0;
	//		}
	//	}
	//	
	//	m_stone.push_back(new Stone(pos));

	//}

	////Create object Texture:
	//TextureManager::getInstance()->create2DTexture("img/fondo.png");
	//
}

void World::initializeWorld()
{
	m_width = 20;
	m_height = 20;

	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			Position pos = Position(x, y);
			m_world.push_back(pos);
		}
	}
	Position pos = Position(m_width - 2, 0);
	m_snake2 = new Snake(pos, 'l', "red");
	pos = Position(1, m_height - 1);
	m_snake1 = new Snake(pos, 'r', "green");
	pos = Position(rand() % m_width, rand() % m_height);
	m_apple2 = new Apple("red", pos);
	pos = Position(rand() % m_width, rand() % m_height);
	while (m_apple2->getPosition() == pos)
	{
		pos = Position(rand() % m_width, rand() % m_height);
	}
	m_apple1 = new Apple("green", pos);
	pos = Position(rand() % m_width, rand() % m_height);
	while (m_apple1->getPosition() == pos || m_apple2->getPosition() == pos)
	{
		pos = Position(rand() % m_width, rand() % m_height);
	}
	for (int i = 0; i < 10; i++) {
		pos = Position(rand() % m_width, rand() % m_height);
		while (m_apple1->getPosition() == pos || m_apple2->getPosition() == pos)
		{
			pos = Position(rand() % m_width, rand() % m_height);
		}
		for (int j = 0; j < i; j++)
		{
			if (m_stone[j]->getPosition() == pos && i != j)
			{
				pos = Position(rand() % m_width, rand() % m_height);
				i = 0;
			}
		}

		m_stone.push_back(new Stone(pos));

	}

	//Create object Texture:
	TextureManager::getInstance()->create2DTexture("fondo.png");
	TextureManager::getInstance()->create2DTexture("GanadorVerde.png");
	TextureManager::getInstance()->create2DTexture("GanadorRojo.png");

}

string World::getName()
{
	return "world";
}

void World::colision(string snakeColor) {
	
	Position posApple1 = m_apple1->getPosition();
	Position posApple2 = m_apple2->getPosition();
	/*Position posBomb = m_bomb->getPosition();*/
	vector<Position> posStones = vector<Position>();
	for (int i = 0; i < 10; i++) 
	{
		if (m_stone[i] != nullptr) 
		{
			posStones.push_back(m_stone[i]->getPosition());
		}

	}
	//m_snake1 is green
	if (snakeColor == m_snake1->getColor())
	{
		if (m_snake1->getHeadPosition().hasDecimal(posApple1)) 
		{
			m_snake1->eatApple(m_apple1->getColor());
			m_apple1->~Apple();
			setApple("green");
		}
		else if (m_snake1->getHeadPosition().hasDecimal(posApple2))
		{
			m_snake1->eatApple(m_apple2->getColor());
			m_apple2->~Apple();
			setApple("red");
		}
		else
		{
			for (int i = 0; i < posStones.size(); i++) 
			{
				if (m_snake1->getHeadPosition().hasDecimal(posStones[i])) 
				{
					m_snake1->eatStone();
					m_stone[i] = new Stone();
				}
			}
			for (int j = 0; j < m_snake2->getVector().size(); j++)
			{
				if (m_snake1->getHeadPosition().hasDecimal(m_snake2->getVector()[j]))
				{
					m_snake1 = new Snake();
				}
			}
		}
	}
	else if (snakeColor == m_snake2->getColor())
	{
		if (m_snake2->getHeadPosition().hasDecimal(posApple1))
		{
			m_snake2->eatApple(m_apple1->getColor());
			m_apple1->~Apple();
			setApple("green");
		}
		else if (m_snake2->getHeadPosition().hasDecimal(posApple2))
		{
			m_snake2->eatApple(m_apple2->getColor());
			m_apple2->~Apple();
			setApple("red");
		}
		else
		{
			for (int i = 0; i < posStones.size(); i++)
			{
				if (m_snake2->getHeadPosition().hasDecimal(posStones[i]))
				{
					vector<Stone*> auxVector = vector<Stone*>();
					m_snake2->eatStone();
					m_stone[i] = new Stone();
				}
			}
			for (int j = 0; j < m_snake1->getVector().size(); j++)
			{
				if (m_snake2->getHeadPosition().hasDecimal(m_snake1->getVector()[j]))
				{
					m_snake2 =new Snake();
				}
			}
		}
	}
	//if (posWanted == posApple1)
	//{
	//	snake.eatApple(m_apple1->getColor());
	//}
	//else if(posWanted == posApple2)
	//{
	//	snake.eatApple(m_apple2->getColor());
	//}
	//*else if (posWanted == posBomb)
	//{
	//	snake.eatBomb();
	//}*/
	//else
	//{
	//	for (int i = 0; i < sizeof(m_stone); i++)
	//	{
	//		Position posStone = m_stone[i]->getPosition();
	//		if (posWanted == posStone)
	//		{
	//			snake.eatStone();
	//		}
	//	}
	//}

	//colision con los bordes del mapa
	if (m_snake1->getHeadPosition().getX() > m_width || m_snake1->getHeadPosition().getX() <0 || m_snake1->getHeadPosition().getY() > m_height || m_snake1->getHeadPosition().getY() < 0)
	{
		m_snake1->borderCollision();
	}
	else if (m_snake2->getHeadPosition().getX() > m_width || m_snake2->getHeadPosition().getX() < 0 || m_snake2->getHeadPosition().getY() > m_height|| m_snake2->getHeadPosition().getY() < 0) 
	{
		m_snake2->borderCollision();
	}
}


World::~World()
{
}

void World::setApple(string Color)
{
	//comer manzana y generar una nueva manzana del mismo color
	//string m_color = apple->getColor();
	//string s_color = snake.getColor();
	//if (m_color.compare(s_color) == 0) {	//comparar si la serpiente es del mismo color que la manzana
	//	apple->~Apple();					// eliminar manzana
	//	snake.eatApple(m_color);		//aumenta el tamaño al comer la manzana
		//crear una nueva manzana del mismo color en una posición aleatoria, previa comparación si casilla vacía
		// Apple(string color, Position pos)
		//Apple apple(m_color, posit);
	//}
	Position pos = Position(rand() % m_width, rand() % m_height);
		if (Color == "red")
		{
			for (int i = 0; i < m_stone.size(); i++)
			{
				if (pos == m_stone[i]->getPosition() && m_stone[i]|| m_apple1->getPosition() == pos)
				{
					pos = Position(rand() % m_width, rand() % m_height);
				}
				for (int j = 0; j < i; j++)
				{
					if (m_stone[j]->getPosition() == pos && i != j || m_apple1->getPosition() == pos)
					{
						pos = Position(rand() % m_width, rand() % m_height);
						i = 0;
					}
				}
			}
			m_apple2 = new Apple("red", pos);
		}
		else if (Color == "green")
		{
			for (int i = 0; i < m_stone.size(); i++)
			{
				if (pos == m_stone[i]->getPosition() || m_apple2->getPosition() == pos)
				{
					pos = Position(rand() % m_width, rand() % m_height);
				}
				for (int j = 0; j < i; j++)
				{
					if (m_stone[j]->getPosition() == pos && i != j || m_apple2->getPosition() == pos)
					{
						pos = Position(rand() % m_width, rand() % m_height);
						i = 0;
					}
				}
			}
			m_apple1 = new Apple("green", pos);
		}

	// no: 
		// dejar manzana
		// detectar colision?


}

void World::draw()
{
	if (m_snake1->getVector().size() == 0 || m_snake2->getVector().size() == 0)
	{
		//glColor3f(0, 1, 0);
		////2. Save the current transformation matrix
		//glPushMatrix();
		////3. Set the transformation matrix of the quad using position, size and angle
		//glTranslatef(m_world.at(1).getX()*20, m_world.at(1).getY()*20, -2);
		//glScalef(0.02, 0.02, 1);
		////glRotatef(0.0, 0, 0, 1);
		////4. Draw the quad centered in [0,0] with coordinates: [-1,-1], [1,-1], [1,1] and [-1,1]
		//glTranslatef(m_world.at(1).getX()*20, m_world.at(1).getY()*20, -2);
		////glBegin(GL_QUADS);
		//glBegin(GL_TRIANGLE_STRIP);
		//glTexCoord3f(0, 0, -3);
		//glVertex3f(-11, -11, -3);
		//glTexCoord3f(1, 0, -3);
		//glVertex3f(-9, -11, -3);
		//glTexCoord3f(0, 1, -3);
		//glVertex3f(-11, -9, -3);
		//glTexCoord3f(1, 1, -3);
		//glVertex3f(-9, -9, -3);
		//glEnd();
		////5. Restore the transformation matrix
		//glPopMatrix();

		if (m_snake1->getVector().size() == 0) 
		{
			TextureManager::getInstance()->useTexture("GanadorRojo.png");

		}
		else if (m_snake2->getVector().size() == 0)
		{
			TextureManager::getInstance()->useTexture("GanadorVerde.png");
		}
	}
	else {

		//Use object Texture:
		TextureManager::getInstance()->useTexture("fondo.png");

		//1. Pass the object's color to OpenGL
		//glColor3f(132, 215, 91);
		for (int i = 0; i < m_world.size(); i++)
		{
			//2. Save the current transformation matrix
			glPushMatrix();
			//3. Set the transformation matrix of the quad using position, size and angle
			glTranslatef(m_world.at(i).getX()*0.042, m_world.at(i).getY()*0.042, -2);
			glScalef(0.02, 0.02, 1);
			//glRotatef(0.0, 0, 0, 1);
			//4. Draw the quad centered in [0,0] with coordinates: [-1,-1], [1,-1], [1,1] and [-1,1]
			glTranslatef(m_world.at(i).getX()*0.042, m_world.at(i).getY()*0.042, -2);
			//glBegin(GL_QUADS);
			glBegin(GL_TRIANGLE_STRIP);
			glTexCoord3f(0, 0, -3);
			glVertex3f(-11, -11, -3);
			glTexCoord3f(1, 0, -3);
			glVertex3f(-9, -11, -3);
			glTexCoord3f(0, 1, -3);
			glVertex3f(-11, -9, -3);
			glTexCoord3f(1, 1, -3);
			glVertex3f(-9, -9, -3);
			glEnd();
			//5. Restore the transformation matrix
			glPopMatrix();
		}
		m_apple1->draw();
		m_apple2->draw();
		for (int i = 0; i < 10; i++)
		{
			if (m_stone[i] != nullptr)
			{
				m_stone[i]->draw();
			}

		}
		colision(m_snake1->getColor());
		colision(m_snake2->getColor());
		m_snake1->draw();
		m_snake2->draw();
	}
}
void World::moveSnake(string snake, char t)
{
	if(snake == "m_snake1")
	{
		m_snake1->setDirectionAfter(t);
	}
	else if (snake == "m_snake2") 
	{
		m_snake2->setDirectionAfter(t);
	}
}

