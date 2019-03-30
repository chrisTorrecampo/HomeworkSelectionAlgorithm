#pragma once
#include <vector>
#include <memory>

#include "Gene.h"
#include "Scheduler.h"
#include "Perceptron_FitnessStrategy.h"

class GA_Fitness{
public:
	GA_Fitness() {};//never use this
	GA_Fitness(std::shared_ptr<std::list<std::shared_ptr<Homework>>> ds);
	GA_Fitness(const GA_Fitness &ga);
	GA_Fitness& operator=(const GA_Fitness &ga);

	double fitness(std::shared_ptr<Gene> in);
	void inputData(std::shared_ptr<std::list<std::shared_ptr<Homework>>> dataSet);

private:
	std::shared_ptr<Scheduler> schedule; 
	std::shared_ptr<Perceptron_FitnessStrategy> pFit;
	size_t timeQuantum = 1;
	std::shared_ptr<std::list<std::shared_ptr<Homework>>> dataSet;
};