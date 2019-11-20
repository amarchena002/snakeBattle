#include "World.h"
#include <fstream>
#include "Snake.h"



World::World()
{
	m_width = 10;
	m_height = 10;	
	for (int x = 0; x < m_height; x++)
	{
		for (int y = 0; y < m_width; y++)
		{
			Position pos = Position(x, y);
			m_world.push_back(pos);
		}
	}
	Position pos = Position(10, 0);
	m_snake1 = new Snake(pos, "r", "red");
	pos = Position(0, 10);
	m_snake1 = new Snake(pos, "l", "green");
	pos = Position(rand() % 10, rand() % 10);
	m_apple1 = new Apple('r', pos);
	pos = Position(rand() % 10, rand() % 10);
	while (m_apple1->getPosition() == pos)
	{
		pos = Position(rand() % 10, rand() % 10);
	}
	m_apple2 = new Apple('g', pos);
	pos = Position(rand() % 10, rand() % 10);
	while (m_apple1->getPosition() == pos || m_apple2->getPosition() == pos)
	{
		pos = Position(rand() % 10, rand() % 10);
	}
	m_bomb = new Bomb(pos);
	while (m_apple1->getPosition() == pos || m_apple2->getPosition() == pos || m_apple2->getPosition())
	{
		pos = Position(rand() % 10, rand() % 10);
	}
	m_stone = Stone();
}

void World::colision(Position posWanted, Snake snake) {
	
	Position posApple1 = m_apple1->getPosition();
	Position posApple2 = m_apple2->getPosition();
	Position posStone = m_stone->getPosition();
	Position posBomb = m_bomb->getPosition();

	if (posWanted == posApple1)
	{
		snake.eatApple(m_apple1->getColor());
	}
	else if(posWanted == posApple2)
	{
		snake.eatApple(m_apple2->getColor());
	}
	else if (posWanted == posStone)
	{
		snake.eatStone();
	}
	else if (posWanted == posBomb)
	{
		snake.eatBomb();
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
//				m_cells.push_back(data);
//			}
//		}
//
//		inputFile.close();
//	}
//}

