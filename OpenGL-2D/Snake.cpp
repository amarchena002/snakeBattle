#include "stdafx.h"
#include "Sprite.h"
#include "Snake.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "vector"
using namespace std;

Snake::Snake(Position position, char dir, string color)
{
	//Cambiar a 0.04
	m_headPosition = position;
	m_tailPosition = Position(m_headPosition.getX() - 0.042, m_headPosition.getY());
	m_direction = dir;
	m_color = color;
	//snake = //inicializar array
	m_snakeLength = 2; //initial length
	m_snake = vector <Position>();
	m_snake.push_back(m_headPosition);
	m_snake.push_back(m_tailPosition);
}
Snake::~Snake()
{
	
}


void Snake::moveUp()
{
	Position pos = m_headPosition;
	Position pos2;
	m_headPosition.setY(m_headPosition.getY() - 1);
	m_direction = dir_up;
	for (int  i = 1; i < m_snakeLength; i++) {
		pos2 = m_snake[i];
		m_snake[i] = pos;
		pos = pos2;
	}
	m_tailPosition = pos;
}

void Snake::moveDown()
{
	Position pos = m_headPosition;
	Position pos2;
	m_headPosition.setY(m_headPosition.getY() + 1);
	m_direction = dir_down;
	for (int i = 1; i < m_snakeLength; i++) {
		pos2 = m_snake[i];
		m_snake[i] = pos;
		pos = pos2;
	}
	m_tailPosition = pos;
}

void Snake::moveRight()
{
	Position pos = m_headPosition;
	Position pos2;
	m_headPosition.setY(m_headPosition.getX() + 1);
	m_direction = dir_right;
	for (int i = 1; i < m_snakeLength; i++) {
		pos2 = m_snake[i];
		m_snake[i] = pos;
		pos = pos2;
	}
	m_tailPosition = pos;
}

void Snake::moveLeft()
{
	Position pos = m_headPosition;
	Position pos2;
	m_headPosition.setY(m_headPosition.getX() - 1);
	m_direction = dir_left;
	for (int i = 1; i < m_snakeLength; i++) {
		pos2 = m_snake[i];
		m_snake[i] = pos;
		pos = pos2;
	}
	m_tailPosition = pos;
}

vector<Position> Snake::getVector()
{
	return m_snake;
}

void Snake::eatApple(string color)
{
	if (color == m_color) 
	{
		m_snakeLength++;
	    m_tailPosition = Position(m_tailPosition.getX() - 0.041, m_tailPosition.getY());
	}
	else
	{
		m_snakeLength--;
		m_snake.pop_back();
		m_tailPosition = m_snake[m_snakeLength - 1];
	}
}

string Snake::getColor()
{
	return m_color;
}

void Snake::eatStone()
{
	//reducir array snake[snakeLength] 
	m_snakeLength = m_snakeLength - 1;
}

void Snake::draw()
{
	updatePos();
	//1. Pass the object's color to OpenGL
	if (m_color == "red")
	{
		glColor3f(1,0,0);
	}
	else if (m_color == "green")
	{
		glColor3f(0,1,0);
	}
	for (int i = 0; i < m_snakeLength; i++)
	{
		//2. Save the current transformation matrix
		glPushMatrix();
		//3. Set the transformation matrix of the quad using position, size and angle
		glTranslatef(m_snake.at(i).getX()*0.042, m_snake.at(i).getY()*0.042, -1);
		glScalef(0.02, 0.02, 1);
		glRotatef(0.0, 0, 0, 1);
		//4. Draw the quad centered in [0,0] with coordinates: [-1,-1], [1,-1], [1,1] and [-1,1]
		glTranslatef(m_snake.at(i).getX()*0.042, m_snake.at(i).getY()*0.042, -1);
		glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(-1, -1, -1);
		glVertex3f(1, -1, -1);
		glVertex3f(-1, 1, -1);
		glVertex3f(1, 1, -1);
		glEnd();
		//5. Restore the transformation matrix
		glPopMatrix();
	}

}

void Snake::updatePos() {
	vector<Position> positions = getVector();
	switch (m_direction)
	{
	case 'l':
		moveLeft();
		break;
	case 'r':
		moveRight();
		break;
	case 'u':
		moveUp();
		break;
	case 'd':
		moveDown();
		break;
	}
}

void Snake::eatBomb()
{
	//snake muere
	m_snakeLength = 0;
}