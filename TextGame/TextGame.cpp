// TextGame.cpp : Main program entry point
//

#include "stdafx.h"
#include "World.h"
#include "GameLogic.h"
#include <Vector>


int main()
{
	vector<char> m_world = vector<char>();
	m_world.push_back('#');
	m_world.push_back('#');
	m_world.push_back('#');
	m_world.push_back('#');
	m_world.push_back('#');
	m_world.push_back('#');
	m_world.push_back('#');
	m_world.push_back('#');
	m_world.push_back('#');
	m_world.push_back('#');
	m_world.push_back('#');
	m_world.push_back('#');
	m_world.push_back('#');
	m_world.push_back('#');
	m_world.push_back('#');
	m_world.push_back('#');
	m_world.push_back('#');
	m_world.push_back('#');
	m_world.push_back('#');
	m_world.push_back('#');
	m_world.push_back('#');
	m_world.push_back('#');
	m_world.push_back('#');
	m_world.push_back('#');
	m_world.push_back('#');
	World world(5,5,m_world);
	Player player1, player2;
	GameLogic gameLogic(player1, player2, world);
	world.draw();
	while (!gameLogic.gameHasEnded())
	{
		world.draw();

		gameLogic.processInput();
	}

    return 0;
}

