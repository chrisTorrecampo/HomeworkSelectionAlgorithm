#pragma once
#include "Scheduler.h" //needs stuff from Scheduler and Scheduler contatins ScheduleStrategy

class RoundRobin_Strategy : public ScheduleStrategy {
public:
	RoundRobin_Strategy(int tq);
	~RoundRobin_Strategy();
	void run();
	void schedule();
	void addThread();
	void setContext(std::shared_ptr<Context> c);

private:
	int timeQuantum;
	int time_since_last_prempt;

	std::list<std::shared_ptr<Thread>>::const_iterator nextToSchedule; //this gets initialized when we recieve context.

	void getNext();
	void prempt();
};

