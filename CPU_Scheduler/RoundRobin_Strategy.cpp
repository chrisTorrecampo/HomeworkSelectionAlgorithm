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
	prempt();
}

void RoundRobin_Strategy::addThread() {
	//nothing needed here for RR
}

void RoundRobin_Strategy::setContext(std::shared_ptr<Context> c) {
	context = c;
	nextToSchedule = context->ReadyList->begin();
}

void RoundRobin_Strategy::getNext() {
	if (context->ReadyList->end == nextToSchedule) {
		nextToSchedule = context->ReadyList->begin();
	} else {
		++nextToSchedule;
	}

}

void RoundRobin_Strategy::prempt(){
	time_since_last_prempt = 0;
	//TODO: do stuff here 
}
