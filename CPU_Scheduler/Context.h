#pragma once

#include <List>
#include <memory>
#include <vector>

#include "Homework.h"

class Scheduler;

class Context {
public:

	std::list<std::shared_ptr<Homework>> homeworkToDo;

	std::shared_ptr<Scheduler> scheduler;
	
	Context(std::list<std::shared_ptr<Homework>> h, std::shared_ptr<Scheduler> s) {
		homeworkToDo = h;
		scheduler = s;
	}

	Context(std::list<std::shared_ptr<Homework>> h) {
		homeworkToDo = h;
	}

	Context(const Context &c) { //TODO: I think the problem is here
		homeworkToDo = c.homeworkToDo;
		scheduler = c.scheduler;
	}

	Context& operator=(const Context &c) {
		if (this != &c) {
			homeworkToDo = c.homeworkToDo;
			scheduler = c.scheduler;
		}
		return *this;
	}
};