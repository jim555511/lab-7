// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the LAB7TREEDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// LAB7TREEDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef LAB7TREEDLL_EXPORTS
#define LAB7TREEDLL_API __declspec(dllexport)
#else
#define LAB7TREEDLL_API __declspec(dllimport)
#endif
#include <string>
#include <vector>

//Basic node class for tree with all basic utilities
class LAB7TREEDLL_API Node {
private:
	Node* left;
	Node* right;
	std::string val;

public:
	Node(Node* Left, Node* Right, std::string Val);
	Node(std::string Val);
	Node();
	void setVal(std::string Val);
	void setLeft(Node* Left);
	void setRight(Node* Right);
	std::string getVal();
	Node* getLeft();
	Node* getRight();

	virtual ~Node();

};

// Some basic Rules for the tree:
//1.) The first object put in is our middle, objects that go to the left are smaller,
//and objects that go to the right are bigger
//2.) Objects inserted after should always go to the left or right of the next object 
//depending on if it's bigger or smaller, this makes it easy to search for items
class LAB7TREEDLL_API BinaryTree {
public:
	BinaryTree(Node* Top); //Constructor if we have a node to start with
	BinaryTree(); //default constructor
	~BinaryTree();
	bool insert(std::string valToInsert);
	Node * Find(std::string valToFind);
	int Size();
	std::vector<Node*> getAllAscending();
	std::vector<Node*> getAllDescending();
	bool EmptyTree();
	bool remove(std::string valToRemove);

private:
	Node* top; //our top node
};


/*░░░░░░░░░▄░░░░░░░░░░░░░░▄░░░░
░░░░░░░░▌▒█░░░░░░░░░░░▄▀▒▌░░░
░░░░░░░░▌▒▒█░░░░░░░░▄▀▒▒▒▐░░░
░░░░░░░▐▄▀▒▒▀▀▀▀▄▄▄▀▒▒▒▒▒▐░░░
░░░░░▄▄▀▒░▒▒▒▒▒▒▒▒▒█▒▒▄█▒▐░░░
░░░▄▀▒▒▒░░░▒▒▒░░░▒▒▒▀██▀▒▌░░░ 
░░▐▒▒▒▄▄▒▒▒▒░░░▒▒▒▒▒▒▒▀▄▒▒▌░░
░░▌░░▌█▀▒▒▒▒▒▄▀█▄▒▒▒▒▒▒▒█▒▐░░
░▐░░░▒▒▒▒▒▒▒▒▌██▀▒▒░░░▒▒▒▀▄▌░
░▌░▒▄██▄▒▒▒▒▒▒▒▒▒░░░░░░▒▒▒▒▌░
▀▒▀▐▄█▄█▌▄░▀▒▒░░░░░░░░░░▒▒▒▐░
▐▒▒▐▀▐▀▒░▄▄▒▄▒▒▒▒▒▒░▒░▒░▒▒▒▒▌
▐▒▒▒▀▀▄▄▒▒▒▄▒▒▒▒▒▒▒▒░▒░▒░▒▒▐░
░▌▒▒▒▒▒▒▀▀▀▒▒▒▒▒▒░▒░▒░▒░▒▒▒▌░
░▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▒░▒░▒▒▄▒▒▐░░
░░▀▄▒▒▒▒▒▒▒▒▒▒▒░▒░▒░▒▄▒▒▒▒▌░░
░░░░▀▄▒▒▒▒▒▒▒▒▒▒▄▄▄▀▒▒▒▒▄▀░░░
░░░░░░▀▄▄▄▄▄▄▀▀▀▒▒▒▒▒▄▄▀░░░░░
░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▀▀░░░░░░░░*/

