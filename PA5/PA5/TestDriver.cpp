#include "scheduler.h"

int main()
{
	int totalprocs = 20;
	Scheduler newScheduler(totalprocs);

newScheduler.run();

	return 0;
}