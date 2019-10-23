#include "pch.h"
#include "CppUnitTest.h"
#include "..\..\lab7TreeDLL\lab7TreeDLL\lab7TreeDLL.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		//Insert tests also test find
		TEST_METHOD(InsertTest1)
		{
			BinaryTree testTree;
			testTree.insert("test");
			Assert::AreEqual((std::string)"test", testTree.find("test")->getVal());
		}

		TEST_METHOD(InsertTestMultiple) {
			BinaryTree testTree;
			testTree.insert("test");
			testTree.insert("test1");
			testTree.insert("test2");
			testTree.insert("test3");
			Assert::AreEqual((std::string)"test3", testTree.find("test3")->getVal());
		}
		//Also tests size functionS
		TEST_METHOD(InsertTestSize) {
			BinaryTree testTree;
			testTree.insert("test1");
			testTree.insert("test2");
			testTree.insert("test3");
			testTree.insert("test4");
			testTree.insert("test5");
			testTree.insert("test6");
			testTree.insert("test7");
			Assert::AreEqual(7, testTree.size());
		}
	};
}
