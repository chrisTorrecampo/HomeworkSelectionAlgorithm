#include "GeneticOrganism_Strategy.h"

#include <limits>
constexpr double lowest_double = std::numeric_limits<double>::lowest();

GeneticOrganism_Strategy::GeneticOrganism_Strategy(std::shared_ptr<FitnessStrategy> fs, int ft){
	fit = fs;
	fitTime = ft;
}


GeneticOrganism_Strategy::~GeneticOrganism_Strategy(){

}

void GeneticOrganism_Strategy::run(){
	time_since_last_fitness--;
	if (time_since_last_fitness <= 0) {
		time_since_last_fitness = fitTime;
		checkFitness();
	}
}

void GeneticOrganism_Strategy::schedule(){
	std::shared_ptr<Thread> mostFit = context->ReadyList->front();
	double greatestFitness = lowest_double;
	std::list<std::shared_ptr<Thread>>::iterator it;
	size_t pos = 0;
	for (it = context->ReadyList->begin(); it != context->ReadyList->end(); ++it) {
		pos++;
		double threadFitness = fit->threadFitness(*it,
												(*it)->waitingTime,
												((double)pos)/context->ReadyList->size(),
												context->scheduler->getFitnessContext((*it))
		);
		if (threadFitness > greatestFitness) {
			greatestFitness = threadFitness;
			mostFit = *it;
		}
	}

	prempt(mostFit);
}

void GeneticOrganism_Strategy::addThread(){
	//nothing here
}

void GeneticOrganism_Strategy::setContext(std::shared_ptr<Context> c){
	context = c;
}

void GeneticOrganism_Strategy::checkFitness() {
	std::shared_ptr<Thread> mostFit = context->ReadyList->front();
	double greatestFitness = lowest_double;
	std::list<std::shared_ptr<Thread>>::iterator it;
	size_t pos = 0;
	for (it = context->ReadyList->begin(); it != context->ReadyList->end(); ++it) {
		pos++;
		double posRatio = ((double)pos) / context->ReadyList->size();
		if (context->ReadyList->size() == 0) {
			//TODO: somthing went horribly wrong if we got here
			posRatio = 0;
		}
		double threadFitness = fit->threadFitness(*it,
			(*it)->waitingTime,
			posRatio,
			context->scheduler->getFitnessContext((*it))
		);
		if (threadFitness > greatestFitness) {
			greatestFitness = threadFitness;
			mostFit = *it;
		}
	}
	
	double cpuFitness = fit->cpuFitness(context->scheduler->getCurrentWorkingThread(),
										context->scheduler->getLengthOfCurrentBurst(),
										context->scheduler->getContextSwitchTime(),
										context->scheduler->getFitnessContext(context->scheduler->getCurrentWorkingThread())
	);
	if (greatestFitness > cpuFitness) {
		prempt(mostFit);
	}
	//else keep current thread on cpu
}

void GeneticOrganism_Strategy::prempt(std::shared_ptr<Thread> threadToSchedule){

	std::shared_ptr<Thread> lastThread = context->scheduler->preempt(threadToSchedule); //move scheduled thread to CPU and save the last thread
	if (lastThread != NULL) {
		if (lastThread->burstTime.size() > 0) {
			context->scheduler->addNewThread(lastThread);
			return;
		}
		else {
			context->scheduler->finishThread(lastThread);
		}
	}

	context->ReadyList->remove(threadToSchedule);
}
