#include "stdafx.h"
#include "CppUnitTest.h"
#include "../OpenGL-2D/position.h"
#include "../OpenGL-2D/Bomb.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestBomb
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(GenerateBomb)
		{
			Position pos = Position(2, 1);
			Bomb bomb(pos);

			int bombX = bomb.GetPosition().getX();
			int bombY = bomb.GetPosition().getY();

			Assert::AreEqual(2, bombX);
			Assert::AreEqual(1, bombY);
		}

	};
}