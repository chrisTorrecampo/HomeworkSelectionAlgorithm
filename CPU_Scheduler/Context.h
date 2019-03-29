#pragma once

#include <List>
#include <memory>
#include <vector>

#include "Thread.h"

class Scheduler;

class Context {
public:

	std::vector<Course> courses;

	std::shared_ptr<Scheduler> scheduler;
	
	Context(std::vector<Course> c, std::shared_ptr<Scheduler> s) {
		courses = c;
		scheduler = s;
	}

	Context(std::vector<Course> c) {
		courses = c;
	}

	Context(const Context &c) { //TODO: I think the problem is here
		courses = c.courses;
		scheduler = c.scheduler;
	}

	Context& operator=(const Context &c) {
		if (this != &c) {
			courses = c.courses;
			scheduler = c.scheduler;
		}
		return *this;
	}
};