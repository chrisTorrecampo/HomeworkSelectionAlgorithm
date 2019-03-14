#pragma once
#include <memory>

#include "Thread.h"

class CPU
{
public:
	CPU();
	~CPU();

	bool run();//run this every clock tick
	bool getStatus();
	size_t getLengthOfCurrentBurst();
	std::shared_ptr<Thread> setWorkingThread(std::shared_ptr<Thread> newThread);
	std::shared_ptr<Thread> getWorkingThread();

	size_t getClockTime() { return currTime; }

	size_t expectedBurstLeft() {
		return burstTimeLeft; //TODO: make this more real life by taking the average of past bursts or something
	}

	void clear();

private:
	std::shared_ptr<Thread> currThread = NULL;
	size_t burstTimeLeft = 0;

	size_t currTime = 0;
	size_t currBurstStart = 0;
};

