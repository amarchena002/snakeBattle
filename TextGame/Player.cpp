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


int Player::getX()
{
	return x;
}

int Player::getY()
{
	return y;
}

int Player::getcoin()
{
	return coins;
}

void Player::addcoin()
{
	coins++;
}
