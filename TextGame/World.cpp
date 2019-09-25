#include "stdafx.h"
#include "World.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <chrono>
#include <thread>
#include <fstream>
#include "System.h"
#include "stdafx.h"
#include <stdio.h>
#include <istream>


World::World(int x, int y, vector<char> vector)
{
	m_x = x;
	m_y = y;
	m_cells = vector;
}

World::World(std::string nameFile)
{
	System::hideCursor();

	//initialize the timer. We want to display the time elapsed since the game began in draw()
	m_timer.start();

	//TODO: initalize everything else
	//...

	
}


World::~World()
{
}


void World::draw()
{
	drawMaze();

	//TODO: -write the points each player has
	std::cout << "Player 1 : " + m_player1.getcoin();
	std::cout << "\n";
	std::cout << "Player 2 : " + m_player2.getcoin();
	std::cout << "\n";
	//TODO: -write the time elapsed since the beginning
	//		-set the proper position/color
	std::cout << m_timer.getElapsedTime() << "   ";
}

int World::getCoins()
{
	return m_coins;
}

char World::getCell(int x, int y)
{
	return m_cells.at(y*m_y + x);
}

void World::changeCells(Player playerB, Player playerA, char ch)
{
	m_cells.assign(playerB.getY()*m_y + playerB.getX(), ' ');
	m_cells.assign(playerA.getY()*m_y + playerA.getX(), ch);
	if (playerA.getcoin() > playerB.getcoin())
	{
		m_coins = m_coins - 1;
	}
}


void World::drawMaze()
{
	System::clear();

	//TODO: -draw the maze: walls and each of the cells
	for (int i = 0; i < m_y; i++)
	{
		for (int j = 0; j < m_x; j++)
		{
			std::cout << m_cells.at(i*m_x + j);
		}
		std::cout << "\n";
	}

	//we sleep for a while
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
//TODO: comprobar movimiento
//TODO: cargar fichero