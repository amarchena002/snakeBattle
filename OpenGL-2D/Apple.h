#pragma once
class Apple
{
	char appleColor;
	int posX;
	int posY;
public:

	Apple();
	Apple(char appleColor, int x, int y);
	~Apple();

	char getColor();
	int getX();
	int getY();
	bool isTheSameColor(char snakeColor);
};