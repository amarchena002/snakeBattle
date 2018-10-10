#include "stdafx.h"
#include "Sprite.h"


Sprite::Sprite()
{
}


Sprite::~Sprite()
{
}

void Sprite::setColor(float r, float g, float b)
{
	//When this method is called, we only store internally what this object's color will be
	//but, we need to pass the color to OpenGL every time the object is drawn
	m_r = r;
	m_g = g;
	m_b = b;

}

void Sprite::setPosition(double x, double y)
{
	//This method only updates internally the object's position. It still needs to be passed to OpenGL before drawing it
	m_x = x;
	m_y = y;
}

void Sprite::setDepth(double depth)
//El ha puesto que la profundidad es de -1 a -20, por lo que debe tener el signo en negativo
{
	//This method only updates internally the object's depth. It still needs to be passed to OpenGL before drawing it
	m_depth = depth;

}

void Sprite::setRotation(double angle)
{
	//This method only updates internally the object's rotation. It still needs to be passed to OpenGL before drawing it
	m_angle = angle;
}

void Sprite::setSize(double size)
{
	//This method only updates internally the object's size. It still needs to be passed to OpenGL before drawing it
	m_size = size;
}

void Sprite::draw()
{
	//DONE:

	//1. Pass the object's color to OpenGL

	glColor3f(m_r, m_g, m_b);

	//2. Save the current transformation matrix

	glPushMatrix();

	//3. Set the transformation matrix of the quad using position, size and angle

	glTranslatef(m_x,m_y,0);
	glRotatef(m_angle, 0, 0, 1);


	//4. Draw the quad centered in [0,0] with coordinates: [-1,-1], [1,-1], [1,1] and [-1,1]

	glBegin(GL_QUADS);
	glVertex3f(-1.0, -1.0, -m_depth);
	glVertex3f(1.0, -1.0, -m_depth);
	glVertex3f(1.0, 1.0, -m_depth);
	glVertex3f(-1.0, 1.0, -m_depth);
	glEnd();
	
	//5. Restore the transformation matrix

	glPopMatrix();
}