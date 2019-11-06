#pragma once
class Apple
{
	char appleColor;
	
public:

	Apple(char appleColor);
	~Apple();

	char getColor();
	bool isTheSameColor(char snakeColor);
};