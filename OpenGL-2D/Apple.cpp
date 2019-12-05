#include "stdafx.h"
#include "Apple.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "Sprite.h"
Apple::Apple(string color, Position pos)
{
	m_appleColor = color;
	m_pos = pos;
}

Apple::~Apple() 
{
}

string Apple::getColor()
{
	return m_appleColor;
}

Position Apple::getPosition() 
{
	return m_pos;
}

bool Apple::isTheSameColor(string snakeColor)
{
	if (m_appleColor.compare(snakeColor)==0) //--> Comparación de strings
	//if (m_appleColor == snakeColor)
		return true;
	else
		return false;
}

void Apple::draw()
{
	//1. Pass the object's color to OpenGL
	if (m_appleColor == "red")
	{
		glColor3f(1, 0, 0);
	}
	else if (m_appleColor == "green")
	{
		glColor3f(0, 1, 0);
	}
	//2. save the current transformation matrix
	glPushMatrix();
	//3. Set the transformation matrix of the quad using position, size and angle
	glTranslatef(m_pos.getX()*0.042, m_pos.getY()*0.042, -1);
	glScalef(0.02, 0.02, 1);
	glRotatef(0.0, 0, 0, 1);
	//4. Draw the quad centered in [0,0] with coordinates: [-1,-1], [1,-1], [1,1] and [-1,1]
	glTranslatef(m_pos.getX()*0.042, m_pos.getY()*0.042, -1);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-11, -11, -1);
	glVertex3f(-9, -11, -1);
	glVertex3f(-11, -9, -1);
	glVertex3f(-9, -9, -1);
	glEnd();
	//5. restore the transformation matrix
	glPopMatrix();
}
string Apple::getName()
{
	return m_appleColor;
}

