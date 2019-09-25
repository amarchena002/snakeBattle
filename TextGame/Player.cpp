#include "stdafx.h"
#include "Player.h"

int x;
int y;
int coins;

//int position = 0; Hay que cargarlo desde el archivo


Player::Player()
{

}


Player::~Player()
{
	coins = 0;	// inicializado a 0
	x = 0;		// lo tiene que coger desde el archivo
	y = 0;
}


void Player::moveUp()
{
	x = x - 1;
	if (true) { //m_cell.hasCoin --> tiene que indicar el world si la casilla contiene moneda o no
		coins++;
	}
}

void Player::moveDown()
{
	x = x + 1;
}

void Player::moveRight()
{
	y = y + 1;
}

void Player::moveLeft()
{
	y = y - 1;
}


int getX()
{
	return x;
}

int getY() {
	return y;
}

int getcoin()
{
	return coins;
}

void addcoin()
{
	coins++;
}
