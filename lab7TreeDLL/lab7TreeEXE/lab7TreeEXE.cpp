
#include <iostream>
#include "..\..\lab7TreeDLL\lab7TreeDLL\lab7TreeDLL.h"

int main()
{



	// NOTICE: EXTENSIVE TESTING CAN BE FOUND IN THE UNIT TESTS


	BinaryTree spaceTree;
	spaceTree.insert("Star Wars");
	spaceTree.insert("Star Trek");
	spaceTree.insert("Space Balls");
	spaceTree.insert("Galaxy Quest");
	spaceTree.printTree();
	std::cout<< "SIZE BEFORE DELETE:" << spaceTree.size() <<std::endl;
	spaceTree.emptyTree();
	std::cout << "SIZE AFTER DELETE:" << spaceTree.size() << std::endl << std::endl;
	spaceTree.~BinaryTree();

	BinaryTree disneyTree;
	disneyTree.insert("Cars");
	disneyTree.insert("Monsters , Inc");
	disneyTree.insert("The Incredibles");
	disneyTree.insert("Wall-E");
	disneyTree.printTree();
	std::cout << "SIZE BEFORE DELETE:" << disneyTree.size() << std::endl;
	disneyTree.emptyTree();
	std::cout << "SIZE AFTER DELETE:" <<  disneyTree.size() << std::endl << std::endl;
	disneyTree.~BinaryTree();

	BinaryTree spookyTree;
	spookyTree.insert("Halloween");
	spookyTree.insert("A Nightmare On Elm Street");
	spookyTree.insert("Hocus Pocus");
	spookyTree.insert("Beetlejuice");
	spookyTree.printTree();
	std::cout << "SIZE BEFORE DELETE:" << spookyTree.size() << std::endl;
	spookyTree.emptyTree();
	std::cout << "SIZE AFTER DELETE:" << spookyTree.size() << std::endl << std::endl;
	spookyTree.~BinaryTree();




}
