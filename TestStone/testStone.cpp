#include "stdafx.h"
#include "CppUnitTest.h"
#include "../OpenGL-2D/position.h"
#include "../OpenGL-2D/Stone.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestStone
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(GeneratedStone)
		{
			Position pos = Position(1.0f, 1.0f);
			Stone stone(pos);

			float stoneX = stone.getPosition().getX();
			float stoneY = stone.getPosition().getY();

			Assert::AreEqual(1.0f, stoneX);
			Assert::AreEqual(1.0f, stoneY);
		}
	};
}