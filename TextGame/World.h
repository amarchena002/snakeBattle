#pragma once
#include "Timer.h"
#include <string>
#include <vector>
#include "Player.h"
using namespace std;

class World
{
	Timer m_timer;
	int m_x;
	int m_y;
	int m_coins;
	vector<char> m_cells;
	Player m_player1;
	Player m_player2;

	void drawMaze();

public:
	World(string nameFile);
	~World();

	void draw();
	int getCoins();
	char getCell(int x, int y);
	void changeCells(int x1, int y1, int x2, int y2);
};