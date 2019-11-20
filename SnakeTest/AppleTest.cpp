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
			string color = "Red";
			Position pos = Position(1, 1);
			Apple apple(color, pos);
			Assert::AreEqual(color, apple.getColor());

		}
		TEST_METHOD(isTheSameColor)
		{
			string color = "Red";
			Position pos = Position (1, 1);
			Apple apple(color, pos);
			Assert::AreEqual(true, apple.isTheSameColor("Red"));
			Assert::AreEqual(false, apple.isTheSameColor("Blue"));

		}
		//coment
		TEST_METHOD(getPos)
		{
			Position pos = Position(1, 2);
			Apple apple("Red", pos);
			Assert::AreEqual(1, apple.getPosition().getX());
			Assert::AreEqual(2, apple.getPosition().getY());

		}
	};
}