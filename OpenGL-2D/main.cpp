#include "stdafx.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Snake.h"
#include "World.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "Snake.h"
#include "World.h"
#include "Menu.h"
#include "iostream"

using namespace std;




int main(int argc, char** argv)
{
	Renderer renderer;
	Position pos = Position(0.15, 0.15);
	


	Menu menu;

	int stateMachine = menu.getState();
	// MENU = 0;	INSTRUCTIONS = 1;	PLAYING = 2;	WINNER = 3;		GAMEOVER = 4;	ABOUT = 5;	EXIT = 6;





		
	if (stateMachine!=6) {  // Is Not EXIT
		

		//press here -->		processKeyboardByMenu

		switch (stateMachine) {
		case 0: //MENU
			printf("MENU: \n");
			printf("--------------------------------------------------------------- \n");
			// printf("Presiona 'm' para ver el Menu Principal \n"); --> Menu en Menu NO
			printf("Presiona 'n' para Empezar el Juego \n");
			printf("Presiona 'h' para Ayuda e Instrucciones \n");
			//printf("Presiona 'q' para Salir del Juego \n");
			printf(" \n");
		

		case 1: //INSTRUCTIONS
			printf("INSTRUCCIONES: \n");
			printf("--------------------------------------------------------------- \n");
			printf("Cada serpiente debe comer manzanas de su propio color, \n");
			printf("con cuidado de no chocar con las piedras ni de que exploten las bombas. \n");
			printf(" \n");
			printf("Jugador 1 - VERDE: 'w' arriba, 's' abajo, 'a' izquierda, 'd' derecha \n");
			printf(" \n");
			printf("Jugador 2 - ROJO: 'i' arriba, 'k' abajo, 'j' izquierda, 'l' derecha \n");
			printf(" \n");
			printf("Presiona 'm' para ver el Menu Principal \n");
			printf("Presiona 'n' para Empezar el Juego \n");
			//printf("Presiona 'h' para Ayuda e Instrucciones \n");
			//printf("Presiona 'q' para Salir del Juego \n");
			printf(" \n");
			printf("©2019 SnakeBattle \n");
			
			break;


		case 2: //PLAYING
			//Todo el código anterior....

			//World world;

			//Hast aquí
			break;

		case 4: //GAMEOVER
			printf("GAME OVER: \n");
			printf("--------------------------------------------------------------- \n");
			printf(" \n");
			printf("Presiona 'm' para ver el Menu Principal \n");
			//printf("Presiona 'n' para Empezar el Juego \n");
			//printf("Presiona 'h' para Ayuda e Instrucciones \n");
			printf("Presiona 'q' para Salir del Juego \n");
			printf("");
			break;
		case 27: exit(0);

		}//switch(stateMachine)




	}
	//stateMachine==6
	if (stateMachine == 6) {
		//Close all and Exit

	}
		
		

	//Todo este código
	World world;
	InputHandler inputHandler(renderer, world);
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