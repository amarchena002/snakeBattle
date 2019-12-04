#pragma once

class Drawable;
#include "Drawable.h"
#include <vector>
#include "TextureManager.h"
using namespace std;

class Renderer
{
	TextureManager* texturemanager;
	static Renderer* m_pRenderer;
	int m_windowWidth = 0, m_windowHeight = 0;

	vector <Drawable*> m_objects2D;

	void set2DMatrix();
public:
	Renderer();
	~Renderer();

	void initialize(int argc, char** argv);

	static Renderer* get(); //this method returns the only instance to the renderer. Needs to be called after the constructor
	Drawable* getByName(string name);

	void drawScene();
	void addObject(Drawable* pObj);
	void reshapeWindow(int x, int y);

	static void __drawScene();
	static void __reshapeWindow(int x, int y);
	virtual string getName();
};

