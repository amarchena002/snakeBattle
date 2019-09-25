#pragma once

#include "Player.h"
#include "World.h"

class GameLogic
{

	Player m_player1, m_player2,m_playerB;
	World m_world;

public:
	GameLogic(Player& player1, Player& player2, World& world);
	~GameLogic();

	void processInput();
	bool gameHasEnded();
};

