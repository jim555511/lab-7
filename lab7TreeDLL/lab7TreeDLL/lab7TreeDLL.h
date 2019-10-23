
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
	Node * find(std::string valToFind);
	int size();
	std::vector<Node*> getAllAscending();
	std::vector<Node*> getAllDescending();
	bool emptyTree();
	bool remove(std::string valToRemove);

private:
	int sizeHelper(Node* starter);
	void emptyTreeHelper(Node* nodeToFree);
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

