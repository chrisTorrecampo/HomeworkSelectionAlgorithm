#pragma once
#include <vector>
#include <memory>

#include "Gene.h"
#include "Scheduler.h"
#include "Perceptron_FitnessStrategy.h"

class GA_Fitness{
public:
	GA_Fitness();

	double fitness(std::shared_ptr<Gene> in);
	void inputData(std::vector<size_t> dataSet);

private:
	std::shared_ptr<Scheduler> schedule; 
	std::shared_ptr<Perceptron_FitnessStrategy> pFit;
	const size_t timeQuantum = 1;
	std::vector<size_t> dataSet;
};