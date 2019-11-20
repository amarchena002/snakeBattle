#pragma once

class Drawable
{
public:
	virtual void draw() = 0;

	//interfaz que hereda
	string getName();
};