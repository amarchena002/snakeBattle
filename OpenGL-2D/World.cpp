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
	m_snake1 = new Snake(pos, 'l', "red");
	pos = Position(1, m_height-1);
	m_snake2 = new Snake(pos, 'r', "green");
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
	for (int i = 0; i <10; i++) {
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
		
		m_stone[i] = new Stone(pos);

	}

	//Create object Texture:
	TextureManager::getInstance()->create2DTexture("img/fondo.jpg");
	
}

string World::getName()
{
	return "world";
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
	//comer manzana y generar una nueva manzana del mismo color
	string m_color = apple.getColor();
	string s_color = snake.getColor();

	if (m_color.compare(s_color) == 0) {	//comparar si la serpiente es del mismo color que la manzana
		apple.~Apple();					// eliminar manzana
		snake.eatApple(m_color);		//aumenta el tamaño al comer la manzana

		//crear una nueva manzana del mismo color en una posición aleatoria, previa comparación si casilla vacía
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
		if (m_color.compare("red") == 0) {
			Position pos = Position(rand() % m_width, rand() % m_height);
			m_apple1 = new Apple("red", pos);
			pos = Position(rand() % m_width, rand() % m_height);
			while (m_apple1->getPosition() == pos)
			{
				pos = Position(rand() % m_width, rand() % m_height);
			}
		}
		else if (m_color.compare("green") == 0) {
			Position pos = Position(rand() % m_width, rand() % m_height);
			m_apple2 = new Apple("green", pos);
			while (m_apple1->getPosition() == pos || m_apple2->getPosition() == pos)
			{
				pos = Position(rand() % m_width, rand() % m_height);
			}
		}

	}
	else { // serpiente no del mismo color
	 // dejar manzana? detectar colision? --> R: (La serpiente lo hace en otro método)
	 // NOTHING
	}
}
*/

void World::draw()
{

	//Use object Texture:
	TextureManager::getInstance()->useTexture("img/fondo.jpg");

	//1. Pass the object's color to OpenGL
	glColor3f(132, 215, 91);
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
		glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(-11, -11, -2);
		glVertex3f(-9, -11, -2);
		glVertex3f(-11, -9, -2);
		glVertex3f(-9, -9, -2);
		glEnd();
		//5. Restore the transformation matrix
		glPopMatrix();
	}
	m_snake1->draw();
	m_snake2->draw();

	

}

void World::moveSnake(string snake, char t)
{
	if(snake == "m_snake1"){
		if (t=='u')
		{
			m_snake1->moveUp();
		}
		else if (t == 'd') 
		{
			m_snake1->moveDown();
		}
		else if (t == 'r')
		{
			m_snake1->moveRight();
		}
		else if (t == 'l')
		{
			m_snake1->moveLeft();
		}
	}
	else if (snake == "m_snake2") {
		if (t == 'u')
		{
			m_snake2->moveUp();
		}
		else if (t == 'd')
		{
			m_snake2->moveDown();
		}
		else if (t == 'r')
		{
			m_snake2->moveRight();
		}
		else if (t == 'l')
		{
			m_snake2->moveLeft();
		}
	}
}

