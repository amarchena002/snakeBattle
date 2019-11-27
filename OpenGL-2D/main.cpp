#include "stdafx.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Snake.h"
#include "World.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "Snake.h"
#include "World.h"



int main(int argc, char** argv)
{
	Renderer renderer;
	Position pos = Position(0.15, 0.15);
	/*Snake *snake = new Snake(pos, "u", "red");*/
	World world;
	/*renderer.addObject(snake);*/
	

	InputHandler inputHandler(renderer,world);
	
	renderer.initialize(argc, argv);
	inputHandler.initialize();
	renderer.addObject(&world);
	
	


	while (1)
	{
		//UPDATE////////////////////
		////////////////////////////
		//process queued events
		glutMainLoopEvent();


		//RENDER////////////////////
		////////////////////////////
		glutPostRedisplay();
		glutSwapBuffers();
	}
   
	return 0;

}