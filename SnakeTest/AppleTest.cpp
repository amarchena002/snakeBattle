#include "stdafx.h"
#include "CppUnitTest.h"
#include "../OpenGL-2D/Apple.h"
#include "../OpenGL-2D/position.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SnakeTest
{		
	TEST_CLASS(AppleTest)
	{
	public:
		
		TEST_METHOD(GetColor)
		{
			char color = 'R';
			Position pos = Position(1, 1);
			Apple apple(color, pos);
			Assert::AreEqual(color, apple.getColor());

		}
		TEST_METHOD(isTheSameColor)
		{
			char colorRed = 'R';
			Position pos = Position (1, 1);
			Apple apple(colorRed, pos);
			Assert::AreEqual(true, apple.isTheSameColor('R'));
			Assert::AreEqual(false, apple.isTheSameColor('B'));

		}
	
		TEST_METHOD(getPos)
		{
			Position pos = Position(1, 2);
			Apple apple('R', pos);
			Assert::AreEqual(1.0f, apple.getPosition().getX());
			Assert::AreEqual(2.0f, apple.getPosition().getY());

		}
	};
}