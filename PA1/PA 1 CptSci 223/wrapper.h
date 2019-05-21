#ifndef WRAPPER_H
#define WRAPPER_H

#include "list.h"
#include "node.h"

#include <chrono>

using namespace std::chrono; //for calculating time

class Wrapper
{
public:
	//constructor & destructor
	Wrapper(int numMin = 0,
		int numMax = 0,
		int numMed = 0);
	~Wrapper();

	//for the program
	string displayMenu();
	bool readFile1();
	bool readFile2();

	bool findMin();
	bool findMax();
	bool findMed(int middle);

	void runApp();

private:
	int numMin;
	int numMax;
	int numMed;

	Node *mpHead;
};


#endif

