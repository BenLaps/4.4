#include "pch.h"
#include "CppUnitTest.h"
#include "../4.4/4.4.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::IsTrue(SecondTXT("a","b",3,3) == 0);
		}
	};
}
