#pragma once

#include <string>
#include <vector>
#include "Apple.h"
#include "Snake.h"
using namespace std;


class World
{
	 
	int m_x;
	int m_y;
	vector<char> m_cells;

	//int m_width; //ancho
	//int m_height; //alto
	char m_world[10][10];
	
	
	// Snake m_snake1;
	// Snake m_snake2;

	// Apple m_apple1;
	// Apple m_apple2;

	int m_points1; //Puntos Snake 1
	int m_points2; //Puntos Snake 2


public:
	World();
	~World();

	void draw();
	void changeCells();
	//void addPoint(char snake);

	void setApple(Apple apple, Snake snake);


};
