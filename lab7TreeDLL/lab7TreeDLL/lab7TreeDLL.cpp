// lab7TreeDLL.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "lab7TreeDLL.h"
#include <string>
using namespace std;

Node::Node() {
	val = "";
	left = nullptr;
	right = nullptr;
}

//Empty for now until we've used it a bit
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

}

BinaryTree::BinaryTree(Node* Top) {
	top = Top;
}

BinaryTree::~BinaryTree() {

}

bool BinaryTree::insert(string valToInsert) {
	return false;
}

Node* BinaryTree::Find(string valToFind) {
	return nullptr;
}

int BinaryTree::Size() {
	return 0;
}

Node* BinaryTree::getAllAscending() {
	return nullptr;
}

Node* BinaryTree::getAllDescending() {
	return nullptr;
}

bool BinaryTree::EmptyTree() {
	return false;
}

bool BinaryTree::remove(string valToRemove) {
	return false;
}


