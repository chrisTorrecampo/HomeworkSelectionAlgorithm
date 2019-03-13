#pragma once

#include <List>
#include <memory>

#include "CPU.h"

#include "ScheduleStrategy.h" //predefines Context
#include "Context.h"          //predefines Scheduler
#include "FitnessContext.h"

class Scheduler : public std::enable_shared_from_this<Scheduler>
{
public:
	Scheduler();
	Scheduler(std::shared_ptr<CPU> c, std::shared_ptr<ScheduleStrategy> s, size_t cst);
	~Scheduler();

	Scheduler(const Scheduler &s);
	Scheduler& operator=(const Scheduler &s);

	void run();

	void addNewThread(std::shared_ptr<Thread> thread);
	void addNewThread(std::vector<size_t> burstT);
	void readyThread(std::shared_ptr<Thread> thread);//move a specific thread from Blocked List to Ready List
	void blockThread(std::shared_ptr<Thread> thread);//move a specific thread from Ready List to Blocked List
	std::shared_ptr<Thread> preempt(std::shared_ptr<Thread> thread);//preempt the current thread on the CPU
	void finishThread(std::shared_ptr<Thread> thread);//move a specific thread from Ready List to Finished List

	bool isFinished();
	size_t numFinished();

	void setStrat(std::shared_ptr<ScheduleStrategy> s);

	std::shared_ptr<Context> getContext();
	//std::shared_ptr<Context> getContext(Scheduler* s);

	std::shared_ptr<Context> context;
	std::shared_ptr<ScheduleStrategy> strat;

	std::shared_ptr<Thread> getCurrentWorkingThread();
	std::shared_ptr<FitnessContext> getFitnessContext(std::shared_ptr<Thread> thread);
	size_t getLengthOfCurrentBurst();

	size_t getContextSwitchTime() { return contextSwitchTime; }

	double getMeanWaitTime();
	double getMeanSquaredWaitTime();

private:
	std::shared_ptr<CPU> cpu;
	std::shared_ptr<std::list<std::shared_ptr<Thread>>> finishedList = std::make_shared<std::list<std::shared_ptr<Thread>>>();;
	std::shared_ptr<std::list<std::shared_ptr<Thread>>> readyList = std::make_shared<std::list<std::shared_ptr<Thread>>>();;
	std::shared_ptr<std::list<std::shared_ptr<Thread>>> blockedList = std::make_shared<std::list<std::shared_ptr<Thread>>>();;

	size_t contextSwitchTime;
};

