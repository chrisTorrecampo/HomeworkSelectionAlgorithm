#include <vector>
#include <limits>

#include "GA_Fitness.h"
#include "Scheduler.h"
#include "Perceptron_FitnessStrategy.h"
#include "GeneticOrganism_Strategy.h"

GA_Fitness::GA_Fitness(std::list<std::shared_ptr<Homework>> ds) {
	schedule = std::make_shared<Scheduler>();	
	dataSet = ds;
}

GA_Fitness::GA_Fitness(const GA_Fitness & ga) {
	schedule = ga.schedule;
	pFit = ga.pFit;
	timeQuantum = ga.timeQuantum;
	dataSet = ga.dataSet;
}

GA_Fitness & GA_Fitness::operator=(const GA_Fitness & ga) {
	if (this != &ga) {
		schedule = ga.schedule;
		pFit = ga.pFit;
		timeQuantum = ga.timeQuantum;
		dataSet = ga.dataSet;
	}

	return *this;
}

double GA_Fitness::fitness(std::shared_ptr<Gene> in) {
	pFit = std::make_shared<Perceptron_FitnessStrategy>(in->genes);
	schedule->setStrat(std::make_shared<GeneticOrganism_Strategy>(pFit, timeQuantum));
	
	schedule->addNewHW(dataSet);

	while (!schedule->isFinished()) {
		schedule->run();
	}

	double out = schedule->getKnowledge();
	//double out = schedule->getMeanSquaredWaitTime();

	schedule->reset();

	return out;
}

/*
void GA_Fitness::inputData(std::vector<std::vector<size_t>> dataSet) { //TODO: actually use vectors
	for (int i = 0; i < dataSet.size(); i++) {
		schedule->addNewThread(dataSet[i]);
	}
}
*/

void GA_Fitness::inputData(std::list<std::shared_ptr<Homework>> ds) {
	dataSet = ds;
}