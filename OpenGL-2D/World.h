#pragma once
#include "position.h"
#include "Snake.h"
#include "Stone.h"
#include "Apple.h"
#include "Bomb.h"
#include <string>
#include <vector>
#include "Apple.h"
#include "Snake.h"
#include "Drawable.h"
#include "Position.h"
using namespace std;


class World:public Drawable
{
	 
	int m_x;
	int m_y;
	//vector<Position> m_cells;

	int m_width; //ancho
	int m_height; //alto
	vector<Position> m_world;
	
	
	 Snake* m_snake1;
	 Snake* m_snake2;

	 Apple* m_apple1;
	 Apple* m_apple2;
	 Stone* m_stone[10];
	 Bomb* m_bomb;

	int m_points1; //Puntos Snake 1
	int m_points2; //Puntos Snake 2


public:
	World();
	~World();

	virtual void draw();
	void changeCells();
	void addPoint(char snake);
	virtual string getName();
	void colision(Position posWanted, Snake snake);

	//void addPoint(char snake);

	void setApple(Apple apple, Snake snake);
	void moveSnake(string snake, char t);


};
