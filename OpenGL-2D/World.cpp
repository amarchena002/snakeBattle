#include "stdafx.h"
#include "Sprite.h"

#include "World.h"
#include "Snake.h"
#include "Apple.h"
#include "Stone.h"
#include <fstream>


// Create a Cleared World
World::World()
{
	m_points1 = 0; //Snake1 Points
	m_points2 = 0;  //Snake1 Points

	int m_width = 10;
	int m_height = 10;
	
	for (int x = 0; x < m_width; x++)
	{
		for (int y = 0; y < m_height; y++)
		{
			m_world[x][y] = '-'; // empty cell
		}
	}
}




// Create a World with Snakes & Apples
World::World(/*Snake snake1, Snake snake2,*/ Apple apple1, Apple apple2)
{
	m_points1 = 0; //Snake1 Points
	m_points2 = 0; //Snake2 Points

	int m_width = 10;
	int m_height = 10;
	
	for (int x = 0; x < m_width; x++)
	{
		for (int y = 0; y < m_height; y++)
		{
			m_world[x][y] = '-'; // empty cell
		}
	}

	//Change the cells with the elements Snakes 1&2 and Apples 1&2
	
	//SNAKES --> Snake(Position position, string dir, string color)
	
	//Snake1:
	/*Snake p_snake1 = snake1;
	for (int i=0; i<p_snake1.getSize(); i++)
	{


		//m_world[p_snake1.getX()][p_apple1.getY()] = p_apple1.getColor();
	}
	*/
	


	//Snake2:

	//APPLES --> Apple(char color, int x, int y)
	//Apple1:
	Apple p_apple1 = apple1;
	m_world[p_apple1.getX()][p_apple1.getY()] = p_apple1.getColor();

	//Apple2:
	Apple p_apple2 = apple2;
	m_world[p_apple2.getX()][p_apple2.getY()] = p_apple2.getColor();

}

void draw()
{

}


void changeCells(char oldCell, char newCell, char)
{

}



/*


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

*/