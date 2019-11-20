#include "World.h"
#include <fstream>
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
	for (int x = 0; x < m_height; x++)
	{
		i = 1;
		for (int y = 0; y < m_width; y++)
		{
			m_world.push_back();
		}
	}
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
		glTranslatef(m_world.at(i).getX(), m_world.at(i).getY(), -2);
		glScalef(0.02, 0.02, 1);
		glRotatef(0.0, 0, 0, 1);
		//4. Draw the quad centered in [0,0] with coordinates: [-1,-1], [1,-1], [1,1] and [-1,1]
		glTranslatef(m_world.at(i).getX(), m_world.at(i).getY(), -2);
		glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(-1, -1, -2);
		glVertex3f(1, -1, -2);
		glVertex3f(-1, 1, -2);
		glVertex3f(1, 1, -2);
		glEnd();
		//5. Restore the transformation matrix
		glPopMatrix();
	}
}

