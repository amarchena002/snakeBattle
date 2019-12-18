#include "stdafx.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Snake.h"
#include "World.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "Snake.h"
#include "World.h"
#include "iostream"

using namespace std;




int main(int argc, char** argv)
{
	Renderer renderer;
	Position pos = Position(0.15, 0.15);
	

	//Start of Menu

	system("Color 0A");
	cout << " \n";
	
	printf("\t  SSSS                       kk                   BBBBBB               tt       tt      ll                \n");
	printf("\t SS   SS                     kk                   BB   BB              tt       tt      ll                \n");
	printf("\t SS   SS                     kk                   BB   BB            tttttt   tttttt    ll                \n");
	printf("\t SS        nnnnn     aaaa    kk  kk    eeee       BB   BB     aaaa     tt       tt      ll        eeee    \n");
	printf("\t  SSS      nn  nn   aa  aa   kk kk    ee  ee      BBBBB      aa  aa    tt       tt      ll       ee  ee   \n");
	printf("\t    SSS    nn  nn     aaaa   kkkk     eeeeee      BBBBB        aaaa    tt       tt      ll       eeeeee   \n");
	printf("\t      SS   nn  nn    aa aa   kkk      ee          BB   BB     aa aa    tt       tt      ll       ee       \n");
	printf("\t SS   SS   nn  nn   aa  aa   kkkk     ee          BB   BB    aa  aa    tt       tt      ll       ee       \n");
	printf("\t SS   SS   nn  nn   aa  aa   kk kk    ee  ee      BB   BB    aa  aa    tt       tt      ll       ee  ee   \n");
	printf("\t  SSSSS    nn  nn    aaaaa   kk  kk    eeee       BBBBBB      aaaaa     tttt     tttt    lllll    eeee    \n\n");

	cout << " \n \t \t INSTRUCCIONES: \n";
	cout << "\t \t --------------------------------------------------------------- \n";
	
	cout << "\t \t Cada serpiente debe comer manzanas de su propio color, \n";
	cout << "\t \t con cuidado de no chocar con las piedras ni de que exploten las bombas. \n";
	cout << "\t \t Jugador 1 - VERDE: 'w' arriba, 's' abajo, 'a' izquierda, 'd' derecha \n";
	cout << "\t \t Jugador 2 - ROJO: 'i' arriba, 'k' abajo, 'j' izquierda, 'l' derecha \n";
	cout << " \n \n \n";
	cout << "\t \t Presiona Enter para empezar el juego...";
	cout << " \n \n \n ";
	cout << "\t \t \t \t \t ©2019 SnakeBattle";
	cin.get();

	//End of Menu


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

