#pragma once
#include <string>
using namespace std;
class Drawable
{
public:
	virtual void draw() = 0;

	//interfaz que hereda
	virtual string getName() = 0;
};