#include "World.h"
#include <fstream>



World::World()
{
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

World::World(string nameFile)
{
	m_points1 = 0;
	m_points2 = 0;

	ifstream inputFile(nameFile, fstream::in);
	if (inputFile.is_open())
	{
		char data = ' ';
		string size = "";
		while (data != ',')
		{
			inputFile >> data;
			if (data != ',')
				size += data;
		}
		m_x += stoi(size);
		size = "";
		data = ' ';
		while (data != ';')
		{
			inputFile >> data;
			if (data != ';')
				size += data;
		}
		m_y += stoi(size);
		data = ' ';
		for (int i = 0; i < m_y; i++)
		{
			for (int j = 0; j < m_x; j++)
			{
				inputFile >> data;
				if (data == '?')
				{
					//m_coins++;
				}
				if (data == '1')
				{
					//m_snake1 = Snake(j, i);
				}
				if (data == '2')
				{
					//m_snake2 = Snake(j, i);
				}
				m_cells.push_back(data);
			}
		}

		inputFile.close();
	}
}

