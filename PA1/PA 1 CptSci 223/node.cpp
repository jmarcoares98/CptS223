#include "node.h"

Node::Node(int number)
{

}

Node::~Node()
{

}

int Node::getNumbers()
{
	return this->mNumbers;
}

Node  *& Node::getNext()
{
	return this->mNext;
}

void Node::setNumbers(int newNum)
{
	this->mNumbers = newNum;
}

void Node::setNext(Node * newNext)
{
	this->mNext = newNext;
}

void Node::insertNode(Node *p)
{
	p->mNext = this->mNext;
	this->mNext = p;
}

fstream & operator >> (fstream &lhs, Node &rhs)
{
	string sNumber = "";
	int iNumber = 0;

	std::getline(lhs, sNumber, '\n');

	iNumber = std::stoi(sNumber);

	rhs.setNumbers(iNumber);

	return lhs;
}