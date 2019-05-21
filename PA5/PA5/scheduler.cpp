#include "scheduler.h"

Scheduler::Scheduler(int procs)
{
	this->availProcs = procs;
	this->totalProcs = procs;
	this->totalJobs = 0;
}

Scheduler::~Scheduler()
{
	while (!pQueue.empty())
	{
		pQueue.pop();
	}
}

void Scheduler::insertJob(Job & newJob)
{
	if (newJob.getDesc() == "NULL")
	{
		return;
	}
	else if ((newJob.getProcs() >= 0) && (newJob.getTicks() >= 0))
	{
		pQueue.push(newJob);
		allJobs.push_back(newJob);
		cout << "Inserted: " << newJob.getDesc() << endl;
	}
	else
	{
		cout << "INVALID! " << newJob.getDesc() << " is not added" << endl;
	}
}

Job Scheduler::findShortest()
{
	return pQueue.top();
}

Job Scheduler::deleteShortest()
{
	Job shortDelete = findShortest();
	pQueue.pop(); //pop off the shortest one
	return shortDelete;
}

bool Scheduler::checkAvailability(int procs)
{
	return (availProcs >= procs);
}

void Scheduler::decrementTimer()
{
	std::vector<Job>::iterator it = allJobs.begin();
	int tracker = 0;

	for (it; it != allJobs.end(); it++)
	{
		if (it->getTimer() > 0)
		{
			it->decrTimer(); //from the job class and decrements the timer
		}

		if ((it->getID() == 0) && (it->getTimer() == 0)) //if ever it decrements to the first thing on heap
		{
			std::vector<Job>::iterator deleteit = it;
			releaseProcs(it->getProcs());
			allJobs.erase(deleteit);
			tracker++;
			break;
		}

		if (it->getTimer() == 0)
		{
			std::vector<Job>::iterator deleteit = it;
			releaseProcs(it->getProcs());
			it--;
			allJobs.erase(deleteit);
		}
	}

}

void Scheduler::releaseProcs(int procs)
{
	availProcs += procs; //adds the procs back to all the remaining procs
}

void Scheduler::runJob()
{
	int procs = pQueue.top().getProcs();

	if (checkAvailability(procs) && pQueue.top().getID() != -1)
	{
		availProcs -= procs;
		Job pushed = deleteShortest();
		allJobs.push_back(pushed); //puts the shortest one back in the vector list

		cout << "Removed " << pushed.getDesc() << " from the Priority Queue" << endl;
		cout << "Job Done!" << endl;
	}
}


void Scheduler::promptJobs()
{
	string desc;
	int procs = 0, ticks = 0;

	cout << "Enter job description: " << endl;
	cin >> desc;
	cout << "Enter number of processors: " << endl;
	cin >> procs;
	cout << "Enter number of ticks: " << endl;
	cin >> ticks;


	if (procs != 0)
	{
		Job newJob = Job(totalJobs++, procs, ticks, desc);
		insertJob(newJob);
	}

}

void Scheduler::tick(int mode, int loop)
{
	//for text file
	if (mode == 0)
	{
		string desc, sTicks, sProcs;
		int ticks = 0, procs = 0;

		while (!infile.eof())
		{
			std::getline(infile, desc, ' ');
			std::getline(infile, sProcs, ' ');
			std::getline(infile, sTicks, '\n');

			procs = stoi(sProcs);
			ticks = stoi(sTicks);

			Job newJob = Job(totalJobs++, procs, ticks, desc);

			insertJob(newJob);
		}

	}
	else
	{
		Job newJob = Job(-1, totalProcs, 0, "NULL");
		insertJob(newJob);
	}

	//for manually putting jobs
	if (mode == 1)
	{ 
		if (loop == 0)
		{
			bool done = false;
			int question;
			do
			{

				promptJobs();

				cout << "Are you done? [0] Yes [1] No" << endl;
				cin >> question;

				if (question == 0)
				{
					done = true;
				}
				else
				{
					done = false;
				}
			} while (!done);
		}
	}

	if (!pQueue.empty())
	{
		runJob();
	}

	if (!allJobs.empty())
	{
		decrementTimer();
	}

	if (!pQueue.empty())
	{
		runJob();
	}
}

void Scheduler::run()
{
	int mode = 0, loop = 0;

	cout << "Would you like to get jobs from File [0] or enter jobs [1]" << endl;
	cin >> mode;

	infile.open("input.txt");
	do
	{
		tick(mode, loop);
		loop++;
	} while (!pQueue.empty());

	system("pause");
	system("cls");

	infile.close();
}