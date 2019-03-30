#pragma once

#include <List>
#include <memory>
#include <vector>

#include "ScheduleStrategy.h" //predefines Context
#include "Context.h"          //predefines Scheduler
#include "FitnessContext.h"

class Scheduler : public std::enable_shared_from_this<Scheduler>
{
public:
	Scheduler();
	Scheduler(std::shared_ptr<ScheduleStrategy> s);
	~Scheduler();

	Scheduler(const Scheduler &s);
	Scheduler& operator=(const Scheduler &s);

	void run();

	void addNewHW(std::shared_ptr<Homework> hw);
	void addNewHW(std::list<std::shared_ptr<Homework>> hws);
	//std::shared_ptr<Thread> preempt(std::shared_ptr<Thread> thread);//preempt the current thread on the CPU //if we do partial HW this may be useful
	void readHW(std::shared_ptr<Homework> hw);//move a specific hw from to ReadOrder

	void setStrat(std::shared_ptr<ScheduleStrategy> s);

	std::shared_ptr<Context> getContext();
	//std::shared_ptr<Context> getContext(Scheduler* s);

	std::shared_ptr<Context> context;
	std::shared_ptr<ScheduleStrategy> strat;

	std::shared_ptr<FitnessContext> getFitnessContext(std::shared_ptr<Homework> hw);

	double getKnowledge();

	void reset();

	bool isFinished();

	std::list<std::shared_ptr<Homework>> homeworkToDo;
	std::vector<std::shared_ptr<Homework>> readOrder;
	size_t timeMax;
};

