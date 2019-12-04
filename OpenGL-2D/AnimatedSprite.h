#pragma once
#include "Sprite.h"
#include <string>
using namespace std;

class AnimatedSprite :
	public Sprite
{
	double animationPoint = 0.0;
	string m_dirimg;
public:
	AnimatedSprite(const char* textureFilename, int numImagesX, int numImagesY, bool loop);
	virtual ~AnimatedSprite();

	virtual void draw(double dt);
};

