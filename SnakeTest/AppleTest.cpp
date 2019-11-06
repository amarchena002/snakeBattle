#include "stdafx.h"
#include "CppUnitTest.h"
#include "../OpenGL-2D/Apple.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SnakeTest
{		
	TEST_CLASS(AppleTest)
	{
	public:
	
		TEST_METHOD(GetColor)
		{
			char color = 'R';
			Apple apple(color);
			Assert::AreEqual(color, apple.getColor());

		}
		TEST_METHOD(isTheSameColor)
		{
			char colorRed = 'R';
			Apple apple(colorRed);
			Assert::AreEqual(true, apple.isTheSameColor('R'));
			Assert::AreEqual(false, apple.isTheSameColor('B'));

		}
	};
}