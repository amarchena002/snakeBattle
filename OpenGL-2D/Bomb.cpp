#include "stdafx.h"
#include "Sprite.h"
#include "Bomb.h"
#include "position.h"

Bomb::Bomb(Position pos)
{
	m_pos = pos;
}

Bomb::~Bomb()
{
}

Position Bomb::GetPosition()
{
	return m_pos;
}