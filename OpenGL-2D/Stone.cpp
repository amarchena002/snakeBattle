#include "stdafx.h"
#include "Sprite.h"
#include "Stone.h"
#include "position.h"
#include "../3rd-party/SOIL/src/SOIL.h"

Stone::Stone(Position pos)
{
	m_pos = pos;
	//texture
	TextureManager::getInstance()->create2DTexture("Stone.jpg");
}

Stone::~Stone()
{
}

Position Stone::getPosition()
{
	return m_pos;
}

void Stone::draw() 
{
	//texture
	TextureManager::getInstance()->useTexture("Stone.jpg");
	
	//1. Pass the object's color to OpenGL
	glColor3f(0.5, 0.5, 0.5); // 1/2 intensity gray
	//2. save the current transformation matrix
	glPushMatrix();
	//3. Set the transformation matrix of the quad using position, size and angle
	glTranslatef(m_pos.getX()*0.042, m_pos.getY()*0.042, -1);
	glScalef(0.02, 0.02, 1);
	glRotatef(0.0, 0, 0, 1);
	//4. Draw the quad centered in [0,0] with coordinates: [-1,-1], [1,-1], [1,1] and [-1,1]
	glTranslatef(m_pos.getX()*0.042, m_pos.getY()*0.042, -1);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-11, -11, -11);
	glVertex3f(-9, -11, -11);
	glVertex3f(-11, -9, -11);
	glVertex3f(-9, -9, -11);
	glEnd();
	//5. restore the transformation matrix
	glPopMatrix();
}