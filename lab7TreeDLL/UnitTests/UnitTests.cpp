#include "pch.h"
#include "CppUnitTest.h"
#include "..\..\lab7TreeDLL\lab7TreeDLL\lab7TreeDLL.h"
#include <vector>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		//Insert tests also test find
		TEST_METHOD(ConstructorNoArguements)
		{
			BinaryTree testTree = BinaryTree();

			Assert::IsNotNull(&testTree);
		}
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

		TEST_METHOD(DeleteTree) {
			BinaryTree testTree;
			testTree.insert("test1");
			testTree.insert("test2");
			testTree.insert("test3");
			testTree.insert("test4");
			testTree.insert("test5");
			testTree.insert("test6");
			Assert::AreEqual(6, testTree.size());
			testTree.emptyTree();
			Assert::AreEqual(0, testTree.size());
		}

		TEST_METHOD(DeleteNothing) {
			BinaryTree testTree;
			testTree.emptyTree();
			Assert::AreEqual(0, testTree.size());
		}

		TEST_METHOD(RemoveNoChildren)
		{
			BinaryTree testTree;
			testTree.insert("test");
			testTree.insert("test2");
			testTree.insert("tes");
			testTree.insert("test1");
			testTree.insert("test3");
			testTree.insert("test4");
			testTree.insert("te");
			testTree.insert("t");

			Assert::AreEqual(8, testTree.size());
			testTree.remove("test4");

			//Make sure that something was removed
			Assert::AreEqual(7, testTree.size());
			//Make sure that "test4" is not in tree
			Assert::IsNull(testTree.find("test4"));
		}

		TEST_METHOD(RemoveOneChildren)
		{
			BinaryTree testTree;
			testTree.insert("test");
			testTree.insert("test2");
			testTree.insert("tes");
			testTree.insert("test1");
			testTree.insert("test3");
			testTree.insert("test4");
			testTree.insert("te");
			testTree.insert("t");

			Assert::AreEqual(8, testTree.size());
			testTree.remove("te");

			//Make sure that something was removed
			Assert::AreEqual(7, testTree.size());
			//Make sure that "test4" is not in tree
			Assert::IsNull(testTree.find("te"));
		}

		TEST_METHOD(RemoveManyChildren)
		{
			BinaryTree testTree;
			testTree.insert("test");
			testTree.insert("test2");
			testTree.insert("tes");
			testTree.insert("test1");
			testTree.insert("test3");
			testTree.insert("test4");
			testTree.insert("te");
			testTree.insert("t");

			Assert::AreEqual(8, testTree.size());
			testTree.remove("test2");

			//Make sure that something was removed
			Assert::AreEqual(7, testTree.size());
			//Make sure that "test4" is not in tree
			Assert::IsNull(testTree.find("test2"));
		}

		TEST_METHOD(RemoveInvalidKey)
		{
			BinaryTree testTree;
			testTree.insert("test");
			testTree.insert("test2");
			testTree.insert("tes");
			testTree.insert("test1");
			testTree.insert("test3");
			testTree.insert("test4");
			testTree.insert("te");
			testTree.insert("t");

			Assert::AreEqual(8, testTree.size());
			testTree.remove("apple");

			//Make sure that something was removed
			Assert::AreEqual(8, testTree.size());
			//Make sure that "test4" is not in tree
			Assert::IsNull(testTree.find("apple"));
		}

		TEST_METHOD(FindValid)
		{
			BinaryTree testTree;
			testTree.insert("test");
			testTree.insert("test2");
			testTree.insert("tes");
			testTree.insert("test1");
			testTree.insert("test3");
			testTree.insert("test4");
			testTree.insert("te");
			testTree.insert("t");
			
			Node expectedNode = Node("t");
			Node* expectedNodePointer = &expectedNode;
			Node* givenNodePointer = testTree.find("t");

			Assert::IsTrue(givenNodePointer->getVal() == expectedNodePointer->getVal());
		}

		TEST_METHOD(FindInvalid)
		{
			BinaryTree testTree;
			testTree.insert("test");
			testTree.insert("test2");
			testTree.insert("tes");
			testTree.insert("test1");
			testTree.insert("test3");
			testTree.insert("test4");
			testTree.insert("te");
			testTree.insert("t");

			Assert::IsNull(testTree.find("Apple"));
		}
		TEST_METHOD(GetAscending)
		{
			//Assign
			BinaryTree testTree;
			testTree.insert("test");
			testTree.insert("test2");
			testTree.insert("tes");
			testTree.insert("test1");
			testTree.insert("test3");
			testTree.insert("test4");
			testTree.insert("te");
			testTree.insert("t");

			std::vector<Node*> givenVec;
			std::vector<Node*> expectedVec;
			expectedVec.push_back(testTree.find("t"));
			expectedVec.push_back(testTree.find("te"));
			expectedVec.push_back(testTree.find("tes"));
			expectedVec.push_back(testTree.find("test"));
			expectedVec.push_back(testTree.find("test1"));
			expectedVec.push_back(testTree.find("test2"));
			expectedVec.push_back(testTree.find("test3"));
			expectedVec.push_back(testTree.find("test4"));

			//Act
			givenVec = testTree.getAllAscending();

			//Assert
			Assert::IsTrue(givenVec == expectedVec);
		}

		TEST_METHOD(GetDescending)
		{
			//Assign
			BinaryTree testTree;
			testTree.insert("test");
			testTree.insert("test2");
			testTree.insert("tes");
			testTree.insert("test1");
			testTree.insert("test3");
			testTree.insert("test4");
			testTree.insert("te");
			testTree.insert("t");

			std::vector<Node*> givenVec;
			std::vector<Node*> expectedVec;
			expectedVec.push_back(testTree.find("test4"));
			expectedVec.push_back(testTree.find("test3"));
			expectedVec.push_back(testTree.find("test2"));
			expectedVec.push_back(testTree.find("test1"));
			expectedVec.push_back(testTree.find("test"));
			expectedVec.push_back(testTree.find("tes"));
			expectedVec.push_back(testTree.find("te"));
			expectedVec.push_back(testTree.find("t"));

			//Act
			givenVec = testTree.getAllDescending();

			//Assert
			Assert::IsTrue(givenVec == expectedVec);
		}

		TEST_METHOD(SizeTest)
		{
			BinaryTree testTree;
			int size;

			testTree.insert("test");
			testTree.insert("test2");
			testTree.insert("tes");
			testTree.insert("test1");
			testTree.insert("test3");
			testTree.insert("test4");
			testTree.insert("te");
			testTree.insert("t");

			
			size = testTree.size();
			Assert::AreEqual(8, size);

			testTree.remove("test");
			testTree.remove("te");
			size = testTree.size();
			Assert::AreEqual(6, size);

			testTree.insert("ahead");
			testTree.insert("beatboxing");
			testTree.insert("shadowboxing");
			size = testTree.size();
			Assert::AreEqual(9, size);
		}
	};
}
