#include "job.h"

Job::Job(int id, int procs, int ticks, string desc)
{
	jobID = id;
	nProcs = procs;
	nTicks = ticks;
	jobDescription = desc;
	jobTimer = ticks;
}

Job::~Job()
{

}

void Job::setID(int id)
{
	jobID = id;
}

void Job::setProcs(int procs)
{
	nProcs = procs;
}

void Job::setTicks(int ticks)
{
	nTicks = ticks;
}

void Job::setDesc(string desc)
{
	jobDescription = desc;
}

void Job::setTimer(int timer)
{
	jobTimer = timer;
}

int Job::getID() const
{
	return this->jobID;
}

int Job::getProcs() const
{
	return this->nProcs;
}

int Job::getTicks() const
{
	return this->nTicks;
}

string Job::getDesc() const
{
	return this->jobDescription;
}

int Job::getTimer()
{
	return this->jobTimer;
}

void Job::decrTimer()
{
	--jobTimer;
}

bool operator > (const Job &lhs, const Job &rhs)
{
	return lhs.getProcs() > rhs.getProcs();
}