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
			Position pos = Position(1, 1);
			Stone stone(pos);

			int stoneX = stone.GetPosition().getX();
			int stoneY = stone.GetPosition().getY();

			Assert::AreEqual(1, stoneX);
			Assert::AreEqual(1, stoneY);
		}
	};
}