#include "CPU.h"

CPU::CPU(){

}


CPU::~CPU()
{
}

bool CPU::run() {//run this every clock tick
	if (getStatus()) {
		currTime++; //TODO: change this to use a real time datatype at some point
		burstTimeLeft--;
		return true;
	} else {
		return false;
	}
}

bool CPU::getStatus() {
	if (burstTimeLeft <= 0) {//TODO: this will become more important if/when we actually use a proper time datatype
		return false;
	}
	else {
		return true;
	}
}

size_t CPU::getLengthOfCurrentBurst(){
	return currTime - currBurstStart;
}

std::shared_ptr<Thread> CPU::setWorkingThread(std::shared_ptr<Thread> newThread) {
	if (currThread == NULL) {//if this is the first thread
		if (newThread != NULL) {
			currThread = newThread;
			newThread->addWaitTime(currTime);
			if (currThread->burstTime.size() == 0) {
				burstTimeLeft = 0; //this shoulden't ever get here but if it ever does the best that CPU can do is just ask for another thread next time
				return NULL;
			}
			burstTimeLeft = currThread->burstTime.back();
			currBurstStart = currTime;
		}
		return NULL;
	}

	if (newThread == NULL) {//Stop executing
		std::shared_ptr<Thread> oldThread = currThread;
		currThread = NULL;
		burstTimeLeft = 0;
		return oldThread;
	}

	if (burstTimeLeft <= 0) {//TODO: this will become more important if/when we actually use a proper time datatype
		currThread->burstTime.pop_back();
		currThread->timeSinceLastSwitched;
	} else {
		currThread->burstTime.at(currThread->burstTime.size() - 1) = burstTimeLeft;
		currThread->timeSinceLastPremption = currTime;
	}
	
	std::shared_ptr<Thread> oldThread = currThread;
	currThread = newThread;
	newThread->addWaitTime(currTime);
	if (currThread->burstTime.size() == 0) {
		burstTimeLeft = 0; //this shoulden't ever get here but if it ever does the best that CPU can do is just ask for another thread next time
		return oldThread;
	}

	burstTimeLeft = currThread->burstTime.back();
	currBurstStart = currTime;

	return oldThread;
}

std::shared_ptr<Thread> CPU::getWorkingThread() {
	return currThread;
}