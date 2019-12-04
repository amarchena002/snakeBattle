#include "stdafx.h"
#include "Sprite.h"
#include "Bomb.h"
#include "position.h"
#include "../3rd-party/SOIL/src/SOIL.h"
#include "TextureManager.h"

Bomb::Bomb(Position pos)
{
	m_pos = pos;
	TextureManager::getInstance()->create2DTexture("img/bomb.png");
}

Bomb::~Bomb()
{
}

Position Bomb::getPosition()
{
	return m_pos;
}

void Bomb::draw()
{
	//texture
	TextureManager::getInstance()->useTexture("img/bomb.png");

	//1. Pass the object's color to OpenGL
	glColor3f(0, 0, 0); // black
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