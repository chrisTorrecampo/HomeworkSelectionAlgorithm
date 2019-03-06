#include <algorithm>

#include "Scheduler.h"
#include "FIFO_Strategy.h"

Scheduler::Scheduler() { //needs Strategy assigned after the constructor because strategy needs a pointer the the scheduler
	cpu = std::make_shared<CPU>();
	//strat = std::make_shared<FIFO_Strategy>(getContext(this));
}

Scheduler::Scheduler(std::shared_ptr<CPU> c, std::shared_ptr<ScheduleStrategy> s){
	cpu = c;
	strat = s;
}

Scheduler::~Scheduler() {
	//TODO: do wee need to do this?
}

Scheduler::Scheduler(const Scheduler & s) {
	cpu = s.cpu;
	strat = s.strat;
	context = s.context;

	readyList = s.readyList;
	blockedList = s.blockedList;
	finishedList = s.finishedList;
}

Scheduler & Scheduler::operator=(const Scheduler & s) {
	if (this != &s) {
		cpu = s.cpu;
		strat = s.strat;
		context = s.context;

		readyList = s.readyList;
		blockedList = s.blockedList;
		finishedList = s.finishedList;
	}
	return *this;
}

void Scheduler::run() {
	if (!cpu->run()) { //run cpu; if thread has completed: 
		strat->schedule();
		return;
	}

	//otherwise run the strategy to see if we preempt
	strat->run();
}

void Scheduler::addNewThread(std::shared_ptr<Thread> thread) {
	readyList->push_back(thread);
	strat->addThread(); //TODO: should the strategy be allowed to push the added thread?
}

void Scheduler::addNewThread(std::vector<size_t> burstT) {
	std::shared_ptr<Thread> newThread(new Thread(cpu->getClockTime(), burstT));
	readyList->push_back(newThread);
	strat->addThread(); //TODO: should the strategy be allowed to push the added thread?
}

void Scheduler::readyThread(std::shared_ptr<Thread> thread) { //move a specific thread from Blocked List to Ready List
	if (std::find(blockedList->begin(), blockedList->end(), thread) != blockedList->end()) { //TODO: use the iterator to make this more effecient
		blockedList->remove(thread);
		readyList->push_back(thread);
	}
}

void Scheduler::blockThread(std::shared_ptr<Thread> thread) { //move a specific thread from Ready List to Blocked List
	if (std::find(readyList->begin(), readyList->end(), thread) != readyList->end()) { //TODO: use the iterator to make this more effecient
		readyList->remove(thread);
		blockedList->push_back(thread);
	}
}

std::shared_ptr<Thread> Scheduler::preempt(std::shared_ptr<Thread> thread) { //preempt the current thread on the CPU
	return cpu->setWorkingThread(thread);
}

void Scheduler::finishThread(std::shared_ptr<Thread> thread) { //move a specific thread from Ready List to Finished List
	//if (std::find(readyList->begin(), readyList->end(), thread) != readyList->end()) { //TODO: use the iterator to make this more effecient
		readyList->remove(thread);
		finishedList->push_back(thread);
	//}
}

bool Scheduler::isFinished(){
	return readyList->size() == 0 && blockedList->size() == 0;
}

size_t Scheduler::numFinished(){
	return finishedList->size();
}

void Scheduler::setStrat(std::shared_ptr<ScheduleStrategy> s){
	strat = s;
	strat->context = getContext();
}

/*
std::shared_ptr<Context> Scheduler::getContext() {
	if (context == NULL) {
		context = std::make_shared<Context>(finishedList, readyList, blockedList);
																				  //use this here because we can't get a shared_ptr from this until after contruction
	}

	return context;
}
*/

std::shared_ptr<Context> Scheduler::getContext() {
	if (context == NULL) {
		context = std::make_shared<Context>(finishedList, readyList, blockedList, shared_from_this());
		//This can't be done until after construction because we can't get a shared_ptr from this until after contruction
	}

	return context;
}