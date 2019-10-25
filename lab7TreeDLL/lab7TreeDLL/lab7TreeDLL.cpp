// lab7TreeDLL.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "lab7TreeDLL.h"
using namespace std;

Node::Node() {
	val = "";
	left = nullptr;
	right = nullptr;
}

//Since children are mainly controlled by the tree we may not need this
Node::~Node() {

}

Node::Node(string Val) {
	val = Val;
	left = nullptr;
	right = nullptr;
}

Node::Node(Node* Left, Node* Right, string Val) {
	left = Left;
	right = Right;
	val = Val;
}

Node* Node::getLeft() {
	return left;
}

Node* Node::getRight() {
	return right;
}

string Node::getVal() {
	return val;
}

void Node::setLeft(Node* Left) {
	left = Left;
}

void Node::setRight(Node* Right) {
	right = Right;
}

void Node::setVal(string Val) {
	val = Val;
}

BinaryTree::BinaryTree() {
	top = nullptr;
}

BinaryTree::BinaryTree(Node* Top) {
	top = Top;
}

//basically just call our empty tree method to destroy the tree
BinaryTree::~BinaryTree() {
	emptyTree();
}

//Equal leaves will be put on the left, mainly itterates through the tree looking for our leaf
//If the tree is empty then assign top to new leaf
//Compares via string compare
bool BinaryTree::insert(string valToInsert) {
	Node* addNode = new Node(valToInsert);
		Node* temp = top;
		Node* beforeTemp = NULL;
		while (temp != NULL) {
			beforeTemp = temp;
			if (temp->getVal().compare(addNode->getVal()) < 0) {
				temp = temp->getRight();
			}
			else {
				temp = temp->getLeft();
			}
		}
		if (beforeTemp == NULL) {
			top = addNode;
			return true;
		}
		else if (beforeTemp->getVal().compare(addNode->getVal()) < 0) {
			beforeTemp->setRight(addNode);
			return true;
		}
		else {
			beforeTemp->setLeft(addNode);
			return true;
		}
}

Node* BinaryTree::find(string valToFind) {
	Node* temp = top;
	while(temp != NULL){
		if (temp->getVal() == valToFind) {
			return temp;
		}
		else if (temp->getVal().compare(valToFind) < 0) {
			temp = temp->getRight();
		}
		else {
			temp = temp->getLeft();
		}
	}
	return nullptr;
}

//makes it so that we can get the size without knowing the root
int BinaryTree::size() {
	int size = sizeHelper(top);
	return size;
}

//Code taken from here: https://www.geeksforgeeks.org/write-a-c-program-to-calculate-size-of-a-tree/
//and changed to fit our needs
int BinaryTree::sizeHelper(Node* starter) {
	if (starter == NULL) {
		return 0;
	}
	else {
		return 1 + sizeHelper(starter->getRight()) + sizeHelper(starter->getLeft());
	}
}

vector<Node*> BinaryTree::getAllAscending() {
	vector<Node*> heyBois;
	return heyBois;
}

vector<Node*> BinaryTree::getAllDescending() {
	vector<Node*> byeBois;
	return byeBois;
}

bool BinaryTree::emptyTree() {
	emptyTreeHelper(top);
	top = NULL; //Need to set top to null to avoid read access violations
	return true;
}

//Code found from: https://www.geeksforgeeks.org/write-a-c-program-to-delete-a-tree/
//Recursively deletes each left and right node of every branch
void BinaryTree::emptyTreeHelper(Node* nodeToFree) {
	if (nodeToFree == NULL) {
		return;
	}
	emptyTreeHelper(nodeToFree->getLeft());
	emptyTreeHelper(nodeToFree->getRight());

	delete nodeToFree;


}

//For node with no children, remove and do nothing pretty much
//For node with one child, remove and then bridge the gap between the node behind and the child
//For node with two children, search down the nodes righthand subtree
//Find the nodes smallest child in the righthand subtree, 
//then replace their values and delete the node on with no children
//TODO: delete comment block and replace with a description
bool BinaryTree::remove(string valToRemove) {
	return false;
}


