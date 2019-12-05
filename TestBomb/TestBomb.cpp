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
			Position pos = Position(2.0f, 1.0f);
			Bomb bomb(pos);

			float bombX = bomb.getPosition().getX();
			float bombY = bomb.getPosition().getY();

			Assert::AreEqual(2.0f, bombX);
			Assert::AreEqual(1.0f, bombY);
		}

	};
}