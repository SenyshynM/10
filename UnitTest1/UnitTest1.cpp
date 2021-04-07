#include "pch.h"
#include "CppUnitTest.h"
#include "../10.1/10.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char s[100] = "123cc3aa123";
			Assert::AreEqual(true, search(s));
		}

		TEST_METHOD(TestMethod2)
		{
			char s[100] = "123123123";
			Assert::AreEqual(false, search(s));
		}
	};
}
