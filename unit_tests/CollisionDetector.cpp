#include <list>
#include <cstdio>
#include "stdafx.h"
#include "CppUnitTest.h"
#include "Circle.h"
#include "CollisionDetector.h"
#include "LoadCollisionMap.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(DetectFullCollision)
		{
			Circle c1(1,1,10);
			Circle c2(2,2,10);

			list<Circle> l1;
			l1.push_back(c1);

			list<Circle> l2;
			l2.push_back(c2);

			CollisionDetector cd;
			
			Assert::AreEqual(cd.hasCollision(l1,l2), true);
		}

		TEST_METHOD(DetectCircleCollision)
		{
			Circle c1(1,1,10);
			Circle c2(2,2,10);
			
			CollisionDetector cd;

			Assert::AreEqual(cd.hasCircleCollision(c1,c2), true);
		}

		TEST_METHOD(DetectCollisionOnScene)
		{
			LoadCollisionMap lcm;
			list<Circle> circlesList;

			circlesList = lcm.load("fixtures/cenario1.csv");

			Circle c1(1,1,10);
			Circle c2(2,2,10);
			Circle c3(1111,519,127);

			list<Circle> l1;
			l1.push_back(c1);
			l1.push_back(c2);

			list<Circle> l2;
			l2.push_back(c1);
			l2.push_back(c2);
			l2.push_back(c3);

			CollisionDetector cd;

			Assert::AreEqual(cd.hasCollision(l1, circlesList), false);
			Assert::AreEqual(cd.hasCollision(l2, circlesList), true);
		}

	};
}