#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "job.h"

class Scheduler
{
public:
	//construcor
	Scheduler(int procs);

	//destructor
	~Scheduler();

	void tick(int mode, int loop);
	void run();

	void insertJob(Job & newJob);

	//event 2: the job wait queue is not empty
	Job findShortest();
	Job deleteShortest();
	bool checkAvailability(int procs); //checks if there are at least pi processors currently available
	void runJob();

	//event 3: the running job queue is not empty
	void decrementTimer();

	//event 4: a job that was running state completed during this tick
	void releaseProcs(int procs);

	//prompting user for jobs
	void promptJobs();


private:
	std::priority_queue<Job, std::vector<Job>, std::greater<Job>> pQueue;
	std::vector<Job> allJobs;
	int totalJobs;
	int totalProcs;
	int availProcs;
	fstream infile;
};
#endif // !SCHEDULER_H
