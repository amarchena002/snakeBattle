#include "Drawable.h"

#include "Snake.h"
#include "Apple.h"
#include "Stone.h"

#include <string>
#include <vector>
using namespace std;


class World // : public Drawable
{
	 
	int m_x;
	int m_y;
	//vector<char> m_cells;

	//int m_width; //ancho
	//int m_height; //alto
	char m_world[10][10];
	
	
	// Snake m_snake1;
	// Snake m_snake2;

	Apple m_apple1;
	Apple m_apple2;

	int m_points1; //Snake1 Points
	int m_points2; //Snake2 Points


public:
	World();
	World(string nameFile);
	World(/*Snake snake1, Snake snake2,*/ Apple apple1, Apple apple2);
	//World(int x, int y, vector<char> vector);
	~World();

	void draw();
	void changeCells();
	//void addPoint(Snake snake);


};