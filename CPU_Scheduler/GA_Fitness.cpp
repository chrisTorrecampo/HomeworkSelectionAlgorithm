#include "GA_Fitness.h"
#include <vector>

#include "Scheduler.h"
#include "FIFO_Strategy.h"
#include "RoundRobin_Strategy.h"
#include "Perceptron_FitnessStrategy.h"
#include "GeneticOrganism_Strategy.h"

GA_Fitness::GA_Fitness() {
	const size_t timeQuantum = 1;

	schedule = std::make_shared<Scheduler>();
	std::shared_ptr<Perceptron_FitnessStrategy> pFit = std::make_shared<Perceptron_FitnessStrategy>();
	schedule->setStrat(std::make_shared<GeneticOrganism_Strategy>(pFit, timeQuantum));
}

double GA_Fitness::fitness() {
	return 0.0;
}
