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

double Scheduler::getMeanGPA() {
	/*   //TODO: do this
	if (homeworkToDo->size() == 0) {
		return 1;
	}
	double meanWaitTime = 0;
	for (Course c : homeworkToDo) {
		meanWaitTime += c.getGPA();
	}

	return meanWaitTime / courses.size();
	*/

	return 0;
}

/*
//TODO: this needs to go in 

double Scheduler::getMeanGPA() {
	if (finishedList->size() == 0) {
		//TODO: something went wrong. Throw something here
		std::cout << "ERROR: / 0\n";
	}
	double meanWaitTime = 0;
	std::list<std::shared_ptr<Thread>>::iterator it;
	for (it = finishedList->begin(); it != finishedList->end(); ++it) {
		meanWaitTime += (*it)->waitingTime;
	}

	return meanWaitTime / finishedList->size();
}

*/

void Scheduler::reset(){
	courses.clear();
}
