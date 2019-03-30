#include "GeneticOrganism_Strategy.h"

#include <limits>
constexpr double lowest_double = std::numeric_limits<double>::lowest();

GeneticOrganism_Strategy::GeneticOrganism_Strategy(std::shared_ptr<FitnessStrategy> fs){
	fit = fs;
	//maxTime = mt;
}


GeneticOrganism_Strategy::~GeneticOrganism_Strategy(){

}

void GeneticOrganism_Strategy::schedule(){
	if (context->scheduler->homeworkToDo.size() == 0) {
		return;//TODO: this should never happen but it does
	}
	std::shared_ptr<Homework> mostFit = context->scheduler->homeworkToDo.front(); //This is precisely the moment where I said "Hey it's a hackathon screw doing it the right way"
	double greatestFitness = lowest_double;
	std::list<std::shared_ptr<Homework>>::iterator it;
	size_t pos = 0;
	for (it = context->scheduler->homeworkToDo.begin(); it != context->scheduler->homeworkToDo.end(); ++it) {
		double hwFitness = fit->hwFitness(*it, context->scheduler->getFitnessContext((*it))
		);
		if (hwFitness > greatestFitness) {
			greatestFitness = hwFitness;
			mostFit = *it;
		}
	}

	prempt(mostFit);
}

void GeneticOrganism_Strategy::setContext(std::shared_ptr<Context> c){
	context = c;
}

void GeneticOrganism_Strategy::prempt(std::shared_ptr<Homework> hwToSchedule){

	context->scheduler->readHW(hwToSchedule);
	
	/*
	if (lastThread != NULL) {
		if (lastThread->burstTime.size() > 0) {
			context->scheduler->addNewThread(lastThread);
			context->ReadyList->remove(threadToSchedule);
			return;
		}
		context->scheduler->finishThread(lastThread);
	}

	*/
	context->homeworkToDo.remove(hwToSchedule);
}
