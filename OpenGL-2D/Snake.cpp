#include "stdafx.h"
#include "Sprite.h"
#include "Snake.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "vector"
#include "Timer.h"
#include <cmath>
using namespace std;

Snake::Snake(Position position, char dir, string color)
{
	//Cambiar a 0.04
	m_headPosition = position;
	m_tailPosition = Position(m_headPosition.getX() - 0.042, m_headPosition.getY());
	m_direction = dir;
	m_directionAfter = dir;
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
	Timer timer = Timer();
	timer.start();
	Position pos = m_headPosition;
	Position pos2;
	Position aux = m_headPosition;
	char directionAfter2 = dir_up;
	if (directionAfter2 == m_direction)
	{
		m_headPosition.setY(m_headPosition.getY() + 1000.0f * timer.getElapsedTime(true));
		for (int i = 0; i < m_snakeLength; i++)
		{
			pos2 = m_snake[i];
			m_snake[i] = pos;
			pos2.setY(pos2.getY() - 1);
			pos = pos2;
		}
		m_tailPosition = pos;
	}
	else
	{
		if (m_direction == dir_right) {
			aux.setX((int)aux.getX() - 1);
		}
		else if (m_direction == dir_left) {
			aux.setX((int)aux.getX());
			
		}	
		if (m_headPosition.hasDecimal(aux))
		{
			m_headPosition.setY(m_headPosition.getY() + 1000.0f * timer.getElapsedTime(true));
			m_direction = m_directionAfter;
			for (int i = 0; i < m_snakeLength; i++)
			{
				pos2 = m_snake[i];
				m_snake[i] = pos;
				pos2.setY(pos2.getY() - 1);
				pos = pos2;
			}
			m_tailPosition = pos;
		}
		else {
			if (m_direction == dir_down) {
				m_directionAfter = dir_up;
				moveDown();
			}
			else if (m_direction == dir_left) {
				m_directionAfter = dir_up;
				moveLeft();
			}
			else if (m_direction == dir_right) {
				m_directionAfter = dir_up;
				moveRight();
			}
		}
	}
}

void Snake::moveDown()
{
	Timer timer = Timer();
	timer.start();
	Position pos = m_headPosition;
	Position pos2;
	Position aux = m_headPosition;
	char directionAfter2 = dir_down;
	if (directionAfter2 == m_direction)
	{
		m_headPosition.setY(m_headPosition.getY() - 1000.0f * timer.getElapsedTime(true));
		for (int i = 0; i < m_snakeLength; i++)
		{
			pos2 = m_snake[i];
			m_snake[i] = pos;
			pos2.setY(pos2.getY() + 1);
			pos = pos2;
		}
		m_tailPosition = pos;
	}
	else
	{
		if (m_direction == dir_right) {
			aux.setX((int)aux.getX() + 1);
			
		}
		else if (m_direction == dir_left) {
			aux.setX((int)aux.getX());
		}
		if (m_headPosition.hasDecimal(aux))
		{
			m_headPosition.setY(m_headPosition.getY() - 1000.0f * timer.getElapsedTime(true));
			m_direction = m_directionAfter;
			for (int i = 0; i < m_snakeLength; i++)
			{
				pos2 = m_snake[i];
				m_snake[i] = pos;
				pos2.setY(pos2.getY() + 1);
				pos = pos2;
			}
			m_tailPosition = pos;
		}
		else {
			if (m_direction == dir_up) {
				m_directionAfter = dir_down;
				moveUp();
			}
			else if (m_direction == dir_left) {
				m_directionAfter = dir_down;
				moveLeft();
			}
			else if (m_direction == dir_right) {
				m_directionAfter = dir_down;
				moveRight();
			}
		}
	}
}

void Snake::moveRight()
{
	Timer timer = Timer();
	timer.start();
	Position pos = m_headPosition;
	Position pos2;
	Position aux = m_headPosition;
	char directionAfter2 = dir_right;
	if (directionAfter2 == m_direction)
	{
		m_headPosition.setX(m_headPosition.getX() + 1000.0f * timer.getElapsedTime(true));
		for (int i = 0; i < m_snakeLength; i++)
		{
			pos2 = m_snake[i];
			m_snake[i] = pos;
			pos2.setX(pos2.getX() - 1);
			pos = pos2;
		}
		m_tailPosition = pos;
	}
	else
	{
		if (m_direction == dir_up) {
			aux.setY((int)aux.getY());
		}
		else if (m_direction == dir_down) {
			aux.setY((int)aux.getY() + 1);
		}
		if (m_headPosition.hasDecimal(aux))
		{
			m_headPosition.setX(m_headPosition.getX() + 1000.0f * timer.getElapsedTime(true));
			m_direction = m_directionAfter;
			for (int i = 0; i < m_snakeLength; i++)
			{
				pos2 = m_snake[i];
				m_snake[i] = pos;
				pos2.setX(pos2.getX() - 1);
				pos = pos2;
			}
			m_tailPosition = pos;
		}
		else {
			if (m_direction == dir_up) {
				m_directionAfter = dir_right;
				moveUp();
			}
			else if (m_direction == dir_left) {
				m_directionAfter = dir_right;
				moveLeft();
			}
			else if (m_direction == dir_down) {
				m_directionAfter = dir_right;
				moveDown();
			}
		}
	}
}

void Snake::moveLeft()
{
	Timer timer = Timer();
	timer.start();
	Position pos = m_headPosition;
	Position pos2;
	Position aux = m_headPosition;
	char directionAfter2 = dir_left;
	if (directionAfter2 == m_direction)
	{
		m_headPosition.setX(m_headPosition.getX() - 1000.0f * timer.getElapsedTime(true));
		for (int i = 0; i < m_snakeLength; i++)
		{
			pos2 = m_snake[i];
			m_snake[i] = pos;
			pos2.setX(pos2.getX() + 1);
			pos = pos2;
		}
		m_tailPosition = pos;
	}
	else
	{
		if (m_direction == dir_up) {
			aux.setY((int)aux.getY());
		}
		else if (m_direction == dir_down) {
			aux.setY((int)aux.getY() + 1);
		}
		if (m_headPosition.hasDecimal(aux))
		{
			m_headPosition.setX(m_headPosition.getX() - 1000.0f * timer.getElapsedTime(true));
			m_direction = m_directionAfter;
			for (int i = 0; i < m_snakeLength; i++)
			{
				pos2 = m_snake[i];
				m_snake[i] = pos;
				pos2.setX(pos2.getX() + 1);
				pos = pos2;
			}
			m_tailPosition = pos;
		}
		else {
			if (m_direction == dir_up) {
				m_directionAfter = dir_left;
				moveUp();
			}
			else if (m_direction == dir_right) {
				m_directionAfter = dir_left;
				moveRight();
			}
			else if (m_direction == dir_down) {
				m_directionAfter = dir_left;
				moveDown();
			}
		}
	}
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
		glTranslatef(m_snake[i].getX()*0.042, m_snake[i].getY()*0.042, -1);
		glScalef(0.02, 0.02, 1);
		glRotatef(0.0, 0, 0, 1);
		//4. Draw the quad centered in [0,0] with coordinates: [-1,-1], [1,-1], [1,1] and [-1,1]
		glTranslatef(m_snake[i].getX()*0.042, m_snake[i].getY()*0.042, -1);
		glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(-11, -11, -1);
		glVertex3f(-9, -11, -1);
		glVertex3f(-11, -9, -1);
		glVertex3f(-9, -9, -1);
		glEnd();
		//5. Restore the transformation matrix
		glPopMatrix();
	}
}

string Snake::getName()
{ 
	return m_color;
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