#include "Menu.h"


//States machine:
static const int MENU = 0;
static const int INSTRUCTIONS = 1;
static const int PLAYING = 2;
static const int WINNER = 3;
static const int GAMEOVER = 4;
static const int ABOUT = 5;
static const int EXIT = 6;


Menu::Menu()
{
	m_state = MENU;
}

Menu::~Menu()
{
}


int Menu::getState() 
{
	return m_state;
}

void Menu::setState(int state)
{
	m_state = state;
}

