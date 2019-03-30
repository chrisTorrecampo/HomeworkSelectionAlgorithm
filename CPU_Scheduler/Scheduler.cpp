#include <algorithm>
#include <iostream>

#include "Scheduler.h"

Scheduler::Scheduler() { //needs Strategy assigned after the constructor because strategy needs a pointer the the scheduler
	//strat = std::make_shared<FIFO_Strategy>(getContext(this));
}

Scheduler::Scheduler(std::shared_ptr<ScheduleStrategy> s){
	strat = s;
}

Scheduler::~Scheduler() {
	//TODO: do wee need to do this?
}

Scheduler::Scheduler(const Scheduler & s) {
	strat = s.strat;
	context = s.context;

	homeworkToDo = s.homeworkToDo;
}

Scheduler & Scheduler::operator=(const Scheduler & s) {
	if (this != &s) {
		strat = s.strat;
		context = s.context;

		homeworkToDo = s.homeworkToDo;
	}
	return *this;
}

void Scheduler::run() {
	strat->schedule();
}


void Scheduler::addNewHW(std::shared_ptr<Homework> hw) {
	homeworkToDo->push_back(hw);
}

void Scheduler::readHW(std::shared_ptr<Homework> hw) {
	readOrder.push_back(hw);
	homeworkToDo->remove(hw);
}


//std::shared_ptr<Thread> Scheduler::preempt(std::shared_ptr<Thread> thread) { //preempt the current thread on the CPU
//	thread->numBursts++;
//	return cpu->setWorkingThread(thread);
//}

void Scheduler::setStrat(std::shared_ptr<ScheduleStrategy> s){
	strat = s;
	strat->setContext(getContext());
}

std::shared_ptr<Context> Scheduler::getContext() {
	if (context == NULL) {
		context = std::make_shared<Context>(homeworkToDo, shared_from_this());
		//This can't be done until after construction because we can't get a shared_ptr from this until after contruction
	}

	return context;
}

std::shared_ptr<FitnessContext> Scheduler::getFitnessContext(std::shared_ptr<Homework> hw) {
	return std::make_shared<FitnessContext>();//TODO: do this
}

double Scheduler::getKnowledge() {
	bool prerequisites = new bool[readOrder.size()];
	


	return 0;
}

void Scheduler::reset(){
	homeworkToDo->clear();
}
