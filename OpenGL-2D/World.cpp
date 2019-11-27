#include "World.h"
#include <fstream>
#include "Snake.h"



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
	Position pos = Position(m_width, 0);
	m_snake1 = new Snake(pos, "r", "red");
	pos = Position(0, m_height);
	m_snake1 = new Snake(pos, "l", "green");
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
		while (m_apple1->getPosition() == pos || m_apple2->getPosition() == pos || m_bomb->getPosition() == pos)
		{			
			pos = Position(rand() % m_width, rand() % m_height);
		}
		int j = 0;
		while (m_stone[j]->getPosition() == pos)
		{
			pos = Position(rand() % m_width, rand() % m_height);
		}
		m_stone[i] = new Stone(pos);
	}
	
}

void World::colision(Position posWanted, Snake snake) {
	
	Position posApple1 = m_apple1->getPosition();
	Position posApple2 = m_apple2->getPosition();
	//Position posStone = m_stone->getPosition();
	Position posBomb = m_bomb->getPosition();

	if (posWanted == posApple1)
	{
		snake.eatApple(m_apple1->getColor());
	}
	else if(posWanted == posApple2)
	{
		snake.eatApple(m_apple2->getColor());
	}
	else if (posWanted == posBomb)
	{
		snake.eatBomb();
	}
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

	if (m_color.compare(s_color)==0) {	//comparar si la serpiente es del mismo color que la manzana
		apple.~Apple();					// eliminar manzana
		snake.eatApple(m_color);		//aumenta el tamaño al comer la manzana

		//crear una nueva manzana del mismo color en una posición aleatoria, previa comparación si casilla vacía
		// Apple(string color, Position pos)
		if (m_color.compare("red")==0) {
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

	} else { // serpiente no del mismo color
		// dejar manzana? detectar colision? --> R: (La serpiente lo hace en otro método)
		// NOTHING
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

