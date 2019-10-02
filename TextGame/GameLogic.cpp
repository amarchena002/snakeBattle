#include "stdafx.h"
#include <iostream>
#include "GameLogic.h"
#include "System.h"
#include "World.h"
#include <stdio.h>


GameLogic::GameLogic(Player& player1, Player& player2, World& world)
	: m_player1(player1), m_player2(player2), m_world(world)
{
	m_player1 = player1;
	m_player2 = player2;
	m_world = world;
}


GameLogic::~GameLogic()
{
}

void GameLogic::processInput()
{
	if (!System::keyHit())
		return; //no keyboard event to be processed


	while (System::keyHit())
	{
		char c = System::getNextKey();
		switch (c)
		{

		case 'a':
			//Do whatever needs to be done when 'a' is pressed
			m_playerB = m_player2;
			m_player2.moveLeft();
			break;
		case 's':
			//Do whatever needs to be done when 's' is pressed
			m_playerB = m_player2;
			m_player2.moveDown();
			m_world.changeCells(m_playerB, m_player2, 2);
			break;
		case 'd':
			m_playerB = m_player2;
			m_player2.moveRight();
			m_world.changeCells(m_playerB, m_player2, 2);
			break;
		case 'w':
			m_playerB = m_player2;
			m_player2.moveUp();
			m_world.changeCells(m_playerB, m_player2, 2);
			break;
		case '4':	
			m_playerB = m_player1;
			m_player1.moveLeft();
			m_world.changeCells(m_playerB, m_player1, 1);
			break;
		case '2':
			m_playerB = m_player1;
			m_player1.moveDown();
			m_world.changeCells(m_playerB, m_player1, 1);
			break;
		case '6':
			m_playerB = m_player1;
			m_player1.moveRight();
			m_world.changeCells(m_playerB, m_player1, 1);
			break;
		case '8':
			m_playerB = m_player1;
			m_player1.moveUp();
			m_world.changeCells(m_playerB, m_player1, 1);
			break;
		//...
		//...
		//...
		case 27:
			//'Esc' key pressed. Exit the game
			return;
		}
	}
}

bool GameLogic::gameHasEnded()
{
	if (m_world.getCoins() == 0)
	{
		if (m_player1.getcoin() > m_player2.getcoin())
		{
			std::cout << "Winner player 1";
		}
		else if (m_player1.getcoin() == m_player2.getcoin())
		{
			std::cout << "Tie";
		}
		else
			std::cout << "Winner player2";
		return true;
	}
		//TODO: We need to check it the game has ended	
	else
	{
		return false;
	}		
}