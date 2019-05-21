#ifndef JOB_H
#define JOB_H

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>

using namespace std;

class Job
{
public:
	//consturcutor
	Job(int id = 0, int procs = 0, int ticks = 0, string descr = NULL);

	//destructor
	~Job();

	//setters and getters
	void setID(int id);
	void setProcs(int procs);
	void setTicks(int ticks);
	void setDesc(string desc);
	void setTimer(int timer);

	int getID() const;
	int getProcs() const;
	int getTicks() const;
	string getDesc() const;
	int getTimer();

	void decrTimer();

private:

	string jobDescription;
	int nProcs;
	int nTicks;
	int jobID;
	int jobTimer;
};

bool operator > (const Job &lhs, const Job &rhs);

#endif