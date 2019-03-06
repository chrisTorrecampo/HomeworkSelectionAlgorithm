#pragma once
#include "Scheduler.h" //needs stuff from Scheduler and Scheduler contatins ScheduleStrategy

class FIFO_Strategy : public ScheduleStrategy {
public:

	FIFO_Strategy();
	void run();
	void schedule();
	void addThread();
};