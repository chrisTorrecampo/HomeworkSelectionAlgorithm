#include <vector>
#include <limits>

#include "GA_Fitness.h"
#include "Scheduler.h"
#include "Perceptron_FitnessStrategy.h"
#include "GeneticOrganism_Strategy.h"

GA_Fitness::GA_Fitness(std::vector<size_t> ds) {
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
	for (size_t i = 0; i < dataSet.size(); i++) { //input data
		schedule->addNewThread(std::vector<size_t>{ dataSet });
	}

	while (!schedule->isFinished()) {
		schedule->run();
		//std::cout << s->numFinished() << "\n";
	}

	double out = schedule->getMeanWaitTime();
	//double out = schedule->getMeanSquaredWaitTime();

	schedule->reset();

	if (out == 0) {
		return std::numeric_limits<double>::max();
	}

	return 1 / out;
}

/*
void GA_Fitness::inputData(std::vector<std::vector<size_t>> dataSet) { //TODO: actually use vectors
	for (int i = 0; i < dataSet.size(); i++) {
		schedule->addNewThread(dataSet[i]);
	}
}
*/

void GA_Fitness::inputData(std::vector<size_t> ds) {
	dataSet = ds;
}