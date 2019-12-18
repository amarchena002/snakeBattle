#pragma once
#include "position.h"
#include "Snake.h"
#include "Stone.h"
#include "Apple.h"
#include "Bomb.h"
#include <string>
#include <vector>
#include "Apple.h"
#include "Drawable.h"
#include "Position.h"
using namespace std;


class World:public Drawable
{
	int m_width; //ancho
	int m_height; //alto
	vector<Position> m_world;
	
	
	 Snake* m_snake1;
	 Snake* m_snake2;

	 Apple* m_apple1;
	 Apple* m_apple2;
	 vector<Stone*> m_stone;
	 Bomb* m_bomb;
public:
	World();
	~World();

	virtual void draw();
	void changeCells();
	void addPoint(char snake);
	virtual string getName();
	void colision(string snake);

	//void addPoint(char snake);

	void setApple(string Color);
	void moveSnake(string snake, char t);


};
