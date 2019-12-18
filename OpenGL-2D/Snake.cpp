#include "stdafx.h"
#include "Snake.h"
#include "InputHandler.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "vector"
#include "Timer.h"
#include <cmath>
using namespace std;

Snake::Snake()
{

}

Snake::Snake(Position position, char dir, string color)
{
	//Cambiar a 0.04
	m_headPosition = position;
	if (color == "red")
	{
		m_tailPosition = Position(m_headPosition.getX() + 1, m_headPosition.getY());
	}
	else if (color == "green") 
	{
		m_tailPosition = Position(m_headPosition.getX() - 1, m_headPosition.getY());
	}
	
	m_direction = dir;
	m_directionAfter = dir;
	m_dirBefore = dir;
	m_dirAux = dir;
	m_color = color;
	//snake = //inicializar array
	m_snakeLength = 2; //initial length
	m_snake = vector <Position>();
	m_snake.push_back(m_headPosition);
	m_snake.push_back(m_tailPosition);
	m_speed = 0.005f;

	if (color == "green")
	{
		TextureManager::getInstance()->create2DTexture("SnakeGreen.png");
	}
	else if(color == "red")
	{
		TextureManager::getInstance()->create2DTexture("SnakeRed.png");
	}
	m_rotPos = vector <Position>();
}

Snake::~Snake()
{
	
}

void Snake::moveUp()
{
	Timer timer = Timer();
	timer.start();
	Position pos;
	Position pos2;
	Position aux = m_headPosition;
	vector<Position> rotPosAux = vector <Position>();
	if (m_directionAfter == m_direction || m_dirAux == dir_up)
	{
		m_dirAux = m_directionAfter;
		m_headPosition.setY(m_headPosition.getY() + m_speed);
		pos = m_headPosition;
		aux = pos;
		m_snake[0] = m_headPosition;
		for (int i = 0; i < m_snakeLength; i++)
		{
			pos2 = m_snake[i];
			if (m_rotPos.size() > 0) {
				
				for (int j = m_rotPos.size()-1; j >= 0; j--) {
					//if (m_dirBefore == dir_right && m_rotPos[j].getX() - m_snake[i].getX() < 2 && m_rotPos[j].getX() - m_snake[i].getX() > 0) {
					if (m_dirBefore == dir_right && m_rotPos[j].getX() - m_snake[i].getX() > 1) {
						aux.setX((int)pos2.getX() + 2);
					}
					else if (m_dirBefore == dir_right && m_rotPos[j].getX() - m_snake[i].getX() == 0) {
						aux.setX(pos2.getX());
					}
					//else if (m_dirBefore == dir_left && m_snake[i].getX() - m_rotPos[j].getX() < 2 && m_snake[i].getX()-m_rotPos[j].getX()>0) {
					else if (m_dirBefore == dir_left && m_snake[i].getX() - m_rotPos[j].getX() > 1) {
						aux.setX((int)pos2.getX() - 1);
					}
					else if (m_dirBefore == dir_left && m_rotPos[j].getX() - m_snake[i].getX() == 0) {
						aux.setX(pos2.getX());
					}
					if (aux == m_rotPos[j]) {
						m_snake[i] = aux;
					}
					else {
						m_snake[i] = pos;
					}
					if (aux.getX() == m_rotPos[j].getX() && pos2.getY() - m_rotPos[j].getY() >= 1) {
						pos2.setY(pos2.getY() - 1);

					}
					else if (aux.getX() == m_rotPos[j].getX() && pos2.getY() - m_rotPos[j].getY() < 1 && pos2.getY() - m_rotPos[j].getY() > 0) {
						pos2.setY(pos2.getY() - (pos2.getY() - m_rotPos[j].getY()));

					}
					else if (aux.getX() <= m_rotPos[j].getX() && m_dirBefore == dir_right) {
						pos2.setX(pos2.getX() - 1);

					}
					else if (aux.getX() >= m_rotPos[j].getX() && m_dirBefore == dir_left) {
						pos2.setX(pos2.getX() + 1);

					}
		/*			if (aux.getX() != m_rotPos[j].getX() && aux.getY() != m_rotPos[j].getY()) {
						m_snake[i] = pos;
					}*/
				}
			}
			else {
				m_snake[i] = pos;
				if (pos2.getY() - m_tailPosition.getY() >= 1) {
					pos2.setY(pos2.getY() - 1);

				}
				else if (pos2.getY() - m_tailPosition.getY() < 1 && pos2.getY() - m_tailPosition.getY() > 0)
				{
					pos2.setY(pos2.getY() - (pos2.getY() - m_tailPosition.getY()));
				}
			}
			if (i != m_snakeLength - 1) {
					pos = pos2;
					aux = pos;

				}
			

		}
		m_tailPosition = pos;
		if(!m_rotPos.empty())
		{
			if (m_rotPos[0] == m_tailPosition)
			{
				for (int i = 0; i < m_rotPos.size(); i++)
				{
					if (i != m_rotPos.size() - 1)
					{
						rotPosAux.push_back(m_rotPos.back());
					}
					m_rotPos.pop_back();
				}
				for (int j = 0; j < rotPosAux.size(); j++)
				{
					m_rotPos.push_back(rotPosAux.back());
					rotPosAux.pop_back();
				}
			}
		}
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
			m_rotPos.push_back(m_headPosition);
			m_dirBefore = m_direction;
			m_direction = m_directionAfter;
		}
		else
		{
			if (m_direction == dir_down)
			{
				m_dirAux = dir_down;
				moveDown();
			}
			else if (m_direction == dir_left)
			{
				m_dirAux = dir_left;
				moveLeft();
			}
			else if (m_direction == dir_right)
			{
				m_dirAux = dir_right;
				moveRight();
			}
		}
	}
}

void Snake::moveDown()
{
	Timer timer = Timer();
	timer.start();
	Position pos ;
	Position pos2;
	Position aux = m_headPosition;
	vector<Position> rotPosAux = vector <Position>();
	if (m_directionAfter == m_direction || m_dirAux == dir_down)
	{
		m_dirAux = m_directionAfter;
		m_headPosition.setY(m_headPosition.getY() - m_speed);
		pos = m_headPosition;
		aux = pos;
		m_snake[0] = m_headPosition;
		for (int i = 0; i < m_snakeLength; i++)
		{
			pos2 = m_snake[i];
			if (m_rotPos.size() > 0)
			{
				for (int j = m_rotPos.size()-1; j >= 0; j--)
				{
					//if (m_dirBefore == dir_right && m_rotPos[j].getX() - m_snake[i].getX() < 2 && m_rotPos[j].getX() - m_snake[i].getX() > 0) {
					if (m_dirBefore == dir_right && m_rotPos[j].getX() - m_snake[i].getX() > 1) {
						aux.setX((int)pos2.getX() + 2);
					}
					else if (m_dirBefore == dir_right && m_rotPos[j].getX() - m_snake[i].getX() == 0) {
						aux.setX(pos2.getX());
					}
					//else if (m_dirBefore == dir_left && m_snake[i].getX() - m_rotPos[j].getX() < 2 && m_snake[i].getX()-m_rotPos[j].getX()>0) {
					else if (m_dirBefore == dir_left && m_snake[i].getX() - m_rotPos[j].getX() > 1) {
						aux.setX((int)pos2.getX() - 1);
					}
					else if (m_dirBefore == dir_left && m_rotPos[j].getX() - m_snake[i].getX() == 0) {
						aux.setX(pos2.getX());
					}
					if (aux == m_rotPos[j]) {
						m_snake[i] = aux;
					}
					else {
						m_snake[i] = pos;
					}
					if (aux.getX() == m_rotPos[j].getX() && m_rotPos[j].getY() -pos2.getY() >= 1) {
						pos2.setY(pos2.getY() + 1);

					}
					else if (aux.getX() == m_rotPos[j].getX() && m_rotPos[j].getY()-pos2.getY() < 1 && m_rotPos[j].getY() - pos2.getY()> 0) {
						pos2.setY(pos2.getY() + ( m_rotPos[j].getY() - pos2.getY()));

					}
					else if (aux.getX() <= m_rotPos[j].getX() && m_dirBefore == dir_right) {
						pos2.setX(pos2.getX() - 1);

					}
					else if (aux.getX() >= m_rotPos[j].getX() && m_dirBefore == dir_left) {
						pos2.setX(pos2.getX() + 1);

					}
				/*	if (aux.getX() != m_rotPos[j].getX() && aux.getY() != m_rotPos[j].getY()) {
						m_snake[i] = pos;
					}*/
				}
			}
			else {
				m_snake[i] = pos;
				if (m_tailPosition.getY() - pos2.getY() >= 1) {
					pos2.setY(pos2.getY() + 1);

				}
				else if (m_tailPosition.getY() - pos2.getY() < 1 && m_tailPosition.getY() - pos2.getY() > 0)
				{
					pos2.setY(pos2.getY() + (m_tailPosition.getY() - pos2.getY()));
				}
			}
			if (i != m_snakeLength - 1) {
				pos = pos2;
				aux = pos;
			}
		}
		m_tailPosition = pos;
		if (!m_rotPos.empty())
		{
			if (m_rotPos[0] == m_tailPosition)
			{
				for (int i = 0; i < m_rotPos.size(); i++)
				{
					if (i != m_rotPos.size() - 1)
					{
						rotPosAux.push_back(m_rotPos.back());
					}
					m_rotPos.pop_back();
				}
				for (int j = 0; j < rotPosAux.size(); j++)
				{
					m_rotPos.push_back(rotPosAux.back());
					rotPosAux.pop_back();
				}
			}
		}	
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
			m_rotPos.push_back(m_headPosition);
			m_dirBefore = m_direction;
			m_direction = m_directionAfter;
		}
		else
		{
			if (m_direction == dir_up)
			{
				m_dirAux = dir_up;
				moveUp();
			}
			else if (m_direction == dir_left)
			{
				m_dirAux = dir_left;
				moveLeft();
			}
			else if (m_direction == dir_right)
			{
				m_dirAux = dir_right;
				moveRight();
			}
		}
	}
}

void Snake::moveRight()
{
	Timer timer = Timer();
	timer.start();
	Position pos ;
	Position pos2;
	Position aux = m_headPosition;
	vector<Position> rotPosAux = vector <Position>();
	if (m_directionAfter == m_direction || m_dirAux == dir_right)
	{
		m_dirAux = m_directionAfter;
		m_headPosition.setX(m_headPosition.getX() + m_speed);
		pos = m_headPosition;
		aux = pos;
		m_snake[0] = m_headPosition;
		for (int i = 0; i < m_snakeLength; i++)
		{
			pos2 = m_snake[i];
			if (m_rotPos.size() > 0)
			{
				for (int j = m_rotPos.size()-1; j >= 0; j--) {
					//if (m_dirBefore == dir_right && m_rotPos[j].getX() - m_snake[i].getX() < 2 && m_rotPos[j].getX() - m_snake[i].getX() > 0) {
					if (m_dirBefore == dir_up && m_rotPos[j].getY() - m_snake[i].getY() > 1) {
						aux.setY((int)pos2.getY() + 2);
					}
					else if (m_dirBefore == dir_up && m_rotPos[j].getY() - m_snake[i].getY() == 0) {
						aux.setY(pos2.getY());
					}
					//else if (m_dirBefore == dir_left && m_snake[i].getX() - m_rotPos[j].getX() < 2 && m_snake[i].getX()-m_rotPos[j].getX()>0) {
					else if (m_dirBefore == dir_down && m_snake[i].getY() - m_rotPos[j].getY() > 1) {
						aux.setY((int)pos2.getY() - 1);
					}
					else if (m_dirBefore == dir_down && m_rotPos[j].getY() - m_snake[i].getY() == 0) {
						aux.setY(pos2.getY());
					}
					if (aux == m_rotPos[j]) {
						m_snake[i] = aux;
					}
					else {
						m_snake[i] = pos;
					}
					if (aux.getY() == m_rotPos[j].getY() && pos2.getX() - m_rotPos[j].getX() >= 1) {
						pos2.setX(pos2.getX() - 1);

					}
					else if (aux.getY() == m_rotPos[j].getY() && pos2.getX() - m_rotPos[j].getX() < 1 && pos2.getX() - m_rotPos[j].getX() > 0) {
						pos2.setX(pos2.getX() - (pos2.getX() - m_rotPos[j].getX()));

					}
					else if (aux.getY() <= m_rotPos[j].getY() && m_dirBefore == dir_up) {
						pos2.setY(pos2.getY() - 1);

					}
					else if (aux.getY() >= m_rotPos[j].getY() && m_dirBefore == dir_down) {
						pos2.setY(pos2.getY() + 1);

					}
					//if (aux.getX() != m_rotPos[j].getX() && aux.getY() != m_rotPos[j].getY()) {
					//	m_snake[i] = pos;
					//}
				}

			}
			else {
				m_snake[i] = pos;
				if (pos2.getX() - m_tailPosition.getX() >= 1) {
					pos2.setX(pos2.getX() - 1);

				}
				else if (pos2.getX() - m_tailPosition.getX() < 1 && pos2.getX() - m_tailPosition.getX() > 0)
				{
					pos2.setX(pos2.getX() - (pos2.getX() - m_tailPosition.getX()));
				}
			}
			if (i != m_snakeLength - 1) {
				pos = pos2;
				aux = pos;

			}


		}
		m_tailPosition = pos;
		if (!m_rotPos.empty())
		{
			if (m_rotPos[0] == m_tailPosition)
			{
				for (int i = 0; i < m_rotPos.size(); i++)
				{
					if (i != m_rotPos.size() - 1)
					{
						rotPosAux.push_back(m_rotPos.back());
					}
					m_rotPos.pop_back();
				}
				for (int j = 0; j < rotPosAux.size(); j++)
				{
					m_rotPos.push_back(rotPosAux.back());
					rotPosAux.pop_back();
				}
			}
		}
	}
	else
	{
		if (m_direction == dir_up) {
			
			aux.setY((int)aux.getY() + 1);
		}
		else if (m_direction == dir_down) {
			aux.setY((int)aux.getY());
		}
		if (m_headPosition.hasDecimal(aux))
		{
			m_rotPos.push_back(m_headPosition);
			m_dirBefore = m_direction;
			m_direction = m_directionAfter;
		}
		else
		{
			if (m_direction == dir_down)
			{
				m_dirAux = dir_down;
				moveDown();
			}
			else if (m_direction == dir_left)
			{
				m_dirAux = dir_left;
				moveLeft();
			}
			else if (m_direction == dir_up)
			{
				m_dirAux = dir_up;
				moveUp();
			}
		}
	}
}

void Snake::moveLeft()
{
	Timer timer = Timer();
	timer.start();
	Position pos ;
	Position pos2;
	Position aux = m_headPosition;
	vector<Position> rotPosAux = vector <Position>();
	if (m_directionAfter == m_direction || dir_left == m_dirAux)
	{
		m_dirAux = m_directionAfter;
		m_headPosition.setX(m_headPosition.getX() - m_speed);
		pos = m_headPosition;
		aux = pos;
		m_snake[0] = m_headPosition;

		for (int i = 0; i < m_snakeLength; i++)
		{
			pos2 = m_snake[i];
			if (m_rotPos.size() > 0)
			{
				for (int j = m_rotPos.size()-1; j >= 0; j--) {
					//if (m_dirBefore == dir_right && m_rotPos[j].getX() - m_snake[i].getX() < 2 && m_rotPos[j].getX() - m_snake[i].getX() > 0) {
					if (m_dirBefore == dir_up && m_rotPos[j].getY() - m_snake[i].getY() > 1) {
						aux.setY((int)pos2.getY() + 2);
					}
					else if (m_dirBefore == dir_up && m_rotPos[j].getY() - m_snake[i].getY() == 0) {
						aux.setY(pos2.getY());
					}
					//else if (m_dirBefore == dir_left && m_snake[i].getX() - m_rotPos[j].getX() < 2 && m_snake[i].getX()-m_rotPos[j].getX()>0) {
					else if (m_dirBefore == dir_down && m_snake[i].getY() - m_rotPos[j].getY() > 1) {
						aux.setY((int)pos2.getY() - 1);
					}
					else if (m_dirBefore == dir_down && m_rotPos[j].getY() - m_snake[i].getY() == 0) {
						aux.setY(pos2.getY());
					}
					if (aux == m_rotPos[j]) {
						m_snake[i] = aux;
					}
					else {
						m_snake[i] = pos;
					}
					if (aux.getY() == m_rotPos[j].getY() && m_rotPos[j].getX() - pos2.getX() >= 1) {
						pos2.setX(pos2.getX() + 1);

					}
					else if (aux.getY() == m_rotPos[j].getY() && m_rotPos[j].getX() - pos2.getX() < 1 && m_rotPos[j].getX() - pos2.getX() > 0) {
						pos2.setX(pos2.getX() + (m_rotPos[j].getX() - pos2.getX() ));

					}
					else if (aux.getY() <= m_rotPos[j].getY() && m_dirBefore == dir_up) {
						pos2.setY(pos2.getY() - 1);

					}
					else if (aux.getY() >= m_rotPos[j].getY() && m_dirBefore == dir_down) {
						pos2.setY(pos2.getY() + 1);

					}
				/*	if (aux.getX() != m_rotPos[j].getX() && aux.getY() != m_rotPos[j].getY()) {
						m_snake[i] = pos;
					}*/
				}
			}
			else {
				m_snake[i] = pos;
				if (m_tailPosition.getX() - pos2.getX() >= 1) {
					pos2.setX(pos2.getX() + 1);

				}
				else if (m_tailPosition.getX() - pos2.getX() < 1 && m_tailPosition.getX() - pos2.getX() > 0)
				{
					pos2.setX(pos2.getX() + (m_tailPosition.getX() - pos2.getX()));
				}
			}
			if (i != m_snakeLength - 1) {
				pos = pos2;
				aux = pos;

			}


		}
		m_tailPosition = pos;
		if (!m_rotPos.empty())
		{
			if (m_rotPos[0] == m_tailPosition)
			{
				for (int i = 0; i < m_rotPos.size(); i++)
				{
					if (i != m_rotPos.size() - 1)
					{
						rotPosAux.push_back(m_rotPos.back());
					}
					m_rotPos.pop_back();
				}
				for (int j = 0; j < rotPosAux.size(); j++)
				{
					m_rotPos.push_back(rotPosAux.back());
					rotPosAux.pop_back();
				}
			}
		}
	}
	else
	{
		if (m_direction == dir_up) {
			aux.setY((int)aux.getY() + 1);
		}
		else if (m_direction == dir_down) {
		
			aux.setY((int)aux.getY());
		}
		if (m_headPosition.hasDecimal(aux))
		{
			m_rotPos.push_back(m_headPosition);
			m_dirBefore = m_direction;
			m_direction = m_directionAfter;
		}
		else
		{
			if (m_direction == dir_down)
			{
				m_dirAux = dir_down;
				moveDown();
			}
			else if (m_direction == dir_up)
			{
				m_dirAux = dir_up;
				moveUp();
			}
			else if (m_direction == dir_right)
			{
				m_dirAux = dir_right;
				moveRight();
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
	   // m_tailPosition = Position(m_tailPosition.getX() - 0.041, m_tailPosition.getY());
		m_snake.push_back(m_tailPosition);
	}
	else
	{
		m_snakeLength--;
		m_snake.pop_back();
		//m_tailPosition = m_snake[m_snakeLength - 1];
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
	m_snake.pop_back();
}

void Snake::draw()
{
	updatePos();
	//1. Pass the object's color to OpenGL
	if (m_color == "red")
	{
		TextureManager::getInstance()->useTexture("SnakeRed.png");
		//glColor3f(1,0,0);
	}
	else if (m_color == "green")
	{
		TextureManager::getInstance()->useTexture("SnakeGreen.png");
		//glColor3f(0,1,0);
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
		glTexCoord2f(0, 0);
		glVertex3f(-11, -11, -1);
		glTexCoord2f(1, 0);
		glVertex3f(-9, -11, -1);
		glTexCoord2f(0, 1);
		glVertex3f(-11, -9, -1);
		glTexCoord2f(1, 1);
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
	switch (m_directionAfter)
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

Position Snake::getHeadPosition()
{
	return m_headPosition;
}

void Snake::eatBomb()
{
	//snake muere
	m_snakeLength = 0;
	m_snake.clear();
}

char Snake::getDirection()
{
	return m_direction;
}

void Snake::setDirectionAfter(char direction) 
{
	m_directionAfter = direction;
}

//choca contra pared
void Snake::borderCollision()
{
	m_snakeLength = 0;
	m_snake.clear();
}