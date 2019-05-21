#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::fstream;
using std::endl;
using std::string;

class Node
{
public:
	//constructors
	Node(int numbers = 0);
	//destructor
	~Node();

	//getters
	int getNumbers();
	Node *& getNext();

	//setters
	void setNumbers(int newNum);
	void setNext(Node * newNum);

	void insertNode(Node *p);

private:
	Node * mpHead;
	Node * mNext;

	int mNumbers;
};

//for loading and reading txt files
fstream & operator >> (fstream &lhs, Node &rhs);

#endif
