#include "RoundRobin_Strategy.h"



RoundRobin_Strategy::RoundRobin_Strategy(int tq) : ScheduleStrategy() {
	timeQuantum = tq;
}


RoundRobin_Strategy::~RoundRobin_Strategy() {

}

void RoundRobin_Strategy::run() {
	if (time_since_last_prempt >= timeQuantum) {
		prempt();
	} else {
		time_since_last_prempt++;
	}
}

void RoundRobin_Strategy::schedule() {
	time_since_last_prempt = 0;

	std::shared_ptr<Thread> threadToSchedule = eraseCurr();

	std::shared_ptr<Thread> lastThread = context->scheduler->preempt(threadToSchedule); //move scheduled thread to CPU and save the last thread
	if (lastThread != NULL) {
		context->scheduler->finishThread(lastThread);
	}
}

void RoundRobin_Strategy::addThread() {
	if (!initialized) {
		nextToSchedule = context->ReadyList->begin();
	}
}

void RoundRobin_Strategy::setContext(std::shared_ptr<Context> c) {
	context = c;
	nextToSchedule = context->ReadyList->begin();
}

std::shared_ptr<Thread> RoundRobin_Strategy::getNext() {
	if (context->ReadyList->end() == nextToSchedule) {
		nextToSchedule = context->ReadyList->begin();
	} else {
		++nextToSchedule;
	}

	return *nextToSchedule;
}

std::shared_ptr<Thread> RoundRobin_Strategy::eraseCurr() {
	std::shared_ptr<Thread> erasedThread = *nextToSchedule;

	context->ReadyList->erase(nextToSchedule++);
	if (nextToSchedule == context->ReadyList->end()) {
		nextToSchedule = context->ReadyList->begin();
	}

	return erasedThread;
}

void RoundRobin_Strategy::prempt(){
	time_since_last_prempt = 0;

	std::shared_ptr<Thread> threadToSchedule = eraseCurr();

	std::shared_ptr<Thread> lastThread = context->scheduler->preempt(threadToSchedule); //move scheduled thread to CPU and save the last thread
	if (lastThread != NULL) {
		if (lastThread->burstTime.size() > 0) {
			context->scheduler->addNewThread(lastThread);
			return;
		}
	}

	context->scheduler->finishThread(lastThread);
}
