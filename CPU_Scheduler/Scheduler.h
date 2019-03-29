#pragma once

#include <List>
#include <memory>
#include <vector>

#include "ScheduleStrategy.h" //predefines Context
#include "Context.h"          //predefines Scheduler
#include "FitnessContext.h"

#include "Homework.h"
#include "Course.h"

class Scheduler : public std::enable_shared_from_this<Scheduler>
{
public:
	Scheduler();
	Scheduler(std::shared_ptr<ScheduleStrategy> s);
	~Scheduler();

	Scheduler(const Scheduler &s);
	Scheduler& operator=(const Scheduler &s);

	void run();

	void addNewCourse(Course c);
	void addNewHW(int index, std::shared_ptr<Homework> hw);
	//std::shared_ptr<Thread> preempt(std::shared_ptr<Thread> thread);//preempt the current thread on the CPU //if we do partial HW this may be useful
	void finishHW(std::shared_ptr<Homework> hw);//move a specific hw from to Finished List

	void setStrat(std::shared_ptr<ScheduleStrategy> s);

	std::shared_ptr<Context> getContext();
	//std::shared_ptr<Context> getContext(Scheduler* s);

	std::shared_ptr<Context> context;
	std::shared_ptr<ScheduleStrategy> strat;

	std::shared_ptr<FitnessContext> getFitnessContext(std::shared_ptr<Homework> hw);

	double getMeanGPA();

	void reset();

private:

	std::vector<Course> courses;
	size_t timeMax;
};

