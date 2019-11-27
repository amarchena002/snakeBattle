#include "World.h"
#include <fstream>
#include "Snake.h"
#include "stdafx.h"
#include "Sprite.h"
#include "Snake.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "vector"



World::World()
{
	m_width = 10;
	m_height = 10;	
	
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			Position pos = Position(x, y);
			m_world.push_back(pos);
		}
	}
	Position pos = Position(m_width-1, 0);
	m_snake1 = new Snake(pos, "r", "red");
	pos = Position(1, m_height-1);
	m_snake2 = new Snake(pos, "l", "green");
	pos = Position(rand() % m_width, rand() % m_height);
	m_apple1 = new Apple("red", pos);
	pos = Position(rand() % m_width, rand() % m_height);
	while (m_apple1->getPosition() == pos)
	{
		pos = Position(rand() % m_width, rand() % m_height);
	}
	m_apple2 = new Apple("green", pos);
	pos = Position(rand() % m_width, rand() % m_height);
	while (m_apple1->getPosition() == pos || m_apple2->getPosition() == pos)
	{
		pos = Position(rand() % m_width, rand() % m_height);
	}
	for (int i = 0; i <sizeof(m_stone); i++) {
		while (m_apple1->getPosition() == pos || m_apple2->getPosition() == pos)
		{			
			pos = Position(rand() % m_width, rand() % m_height);
		}
		for (int j = 1; j < i; j++) 
		{
			if (m_stone[j]->getPosition() == pos)
			{
				pos = Position(rand() % m_width, rand() % m_height);
				i = 0;
				j = 0;
			}
		}
		m_stone[i] = new Stone(pos);
	}
	
}

void World::colision(Position posWanted, Snake snake) {
	
	Position posApple1 = m_apple1->getPosition();
	Position posApple2 = m_apple2->getPosition();
	/*Position posBomb = m_bomb->getPosition();*/

	if (posWanted == posApple1)
	{
		snake.eatApple(m_apple1->getColor());
	}
	else if(posWanted == posApple2)
	{
		snake.eatApple(m_apple2->getColor());
	}
	/*else if (posWanted == posBomb)
	{
		snake.eatBomb();
	}*/
	else
	{
		for (int i = 0; i < sizeof(m_stone); i++)
		{
			Position posStone = m_stone[i]->getPosition();
			if (posWanted == posStone)
			{
				snake.eatStone();
			}
		}
	}
}


World::~World()
{
}

void World::setApple(Apple apple, Snake snake)
{
	//comer manzana 
	//generar nueva manzana
	string m_color = apple.getColor();
	string s_color = snake.getColor();

	//comparar si la serpiente es del mismo color que la manzana
	if (m_color.compare(s_color)==0) { // si: 
		// eliminar manzana
		apple.~Apple();
		//aumentar tamaño?

		// crear nueva manzana del mismo color:
		// Apple(string color, Position pos)

		//Apple apple(m_color, posit);
	}
		


	// no: 
		// dejar manzana
		// detectar colision?


}








//World::World(/*Snake snake1, Snake snake2, Apple apple1, Apple apple2*/)
/*{
	m_points1 = 0;
	m_points2 = 0;

	int m_width = 10;
	int m_height = 10;

	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			m_world[x][y] = '-'; // empty cell
		}
	}

	//Change the cells with the elements Snakes 1&2 and Apples 1&2


}
*/

//World::World(string nameFile)
//{
//	m_points1 = 0;
//	m_points2 = 0;
//
//	ifstream inputFile(nameFile, fstream::in);
//	if (inputFile.is_open())
//	{
//		char data = ' ';
//		string size = "";
//		while (data != ',')
//		{
//			inputFile >> data;
//			if (data != ',')
//				size += data;
//		}
//		m_x += stoi(size);
//		size = "";
//		data = ' ';
//		while (data != ';')
//		{
//			inputFile >> data;
//			if (data != ';')
//				size += data;
//		}
//		m_y += stoi(size);
//		data = ' ';
//		for (int i = 0; i < m_y; i++)
//		{
//			for (int j = 0; j < m_x; j++)
//			{
//				inputFile >> data;
//				if (data == '?')
//				{
//					//m_coins++;
//				}
//				if (data == '1')
//				{
//					//m_snake1 = Snake(j, i);
//				}
//				if (data == '2')
//				{
//					//m_snake2 = Snake(j, i);
//				}
//				m_world.push_back(data);
//			}
//		}
//
//		inputFile.close();
//	}
//}

void World::draw()
{
	//1. Pass the object's color to OpenGL
	glColor3f(132, 215, 91);
	for (int i = 0; i < m_world.size(); i++)
	{
		//2. Save the current transformation matrix
		glPushMatrix();
		//3. Set the transformation matrix of the quad using position, size and angle
		glTranslatef(m_world.at(i).getX()*0.042, m_world.at(i).getY()*0.042, -2);
		glScalef(0.02, 0.02, 1);
		glRotatef(0.0, 0, 0, 1);
		//4. Draw the quad centered in [0,0] with coordinates: [-1,-1], [1,-1], [1,1] and [-1,1]
		glTranslatef(m_world.at(i).getX()*0.042, m_world.at(i).getY()*0.042, -2);
		glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(-1, -1, -2);
		glVertex3f(1, -1, -2);
		glVertex3f(-1, 1, -2);
		glVertex3f(1, 1, -2);
		glEnd();
		//5. Restore the transformation matrix
		glPopMatrix();
	}
	m_snake1->draw();
	m_snake2->draw();
}

