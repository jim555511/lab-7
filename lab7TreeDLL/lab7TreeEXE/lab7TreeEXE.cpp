
#include <iostream>
#include "..\..\lab7TreeDLL\lab7TreeDLL\lab7TreeDLL.h"

int main()
{
	BinaryTree myTree;
	myTree.insert("Star");
	myTree.insert("planet");
	myTree.insert("moon");
	std::cout<< myTree.size() <<std::endl;
	myTree.emptyTree();
	std::cout << myTree.size();
	myTree.~BinaryTree();


}
