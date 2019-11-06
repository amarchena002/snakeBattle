#pragma once

#include "Drawable.h"

#include <string>
using namespace std;

class Snake : public Drawable
{
	int headPosX;
	int headPosY;


public:

	Snake();
	~Snake();
	
};