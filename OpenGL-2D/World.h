#pragma once
#include "position.h"
#include "Snake.h"
#include "Stone.h"
#include "Apple.h"
#include "Bomb.h"
#include <string>
#include <vector>
using namespace std;


class World
{
	 
	int m_x;
	int m_y;
	//vector<Position> m_cells;

	int m_width; //ancho
	int m_height; //alto
	vector<Position> m_world;
	
	
	 Snake m_snake1;
	 Snake m_snake2;

	 Apple m_apple1;
	 Apple m_apple1;
	 vector<Stone> m_stone;
	 Bomb bomb;

	int m_points1; //Puntos Snake 1
	int m_points2; //Puntos Snake 2


public:
	World();
	World(string nameFile);
	//World(/*Snake snake1, Snake snake2, Apple apple1, Apple apple2*/);
	//World(int x, int y, vector<char> vector);

	
	~World();

	void draw();
	void changeCells();
	void addPoint(char snake);


};
