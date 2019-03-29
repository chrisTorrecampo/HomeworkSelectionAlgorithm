#pragma once

#include <List>
#include <memory>

class Context;

class ScheduleStrategy {
public:

	//first three are pure virtual
	virtual void schedule() = 0; //Runs every time we need a new HW

	virtual void setContext(std::shared_ptr<Context> c) { context = c; }

protected:

	std::shared_ptr<Context> context;

	ScheduleStrategy(){}
};