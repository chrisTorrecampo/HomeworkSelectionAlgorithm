#pragma once
#include "FitnessStrategy.h"
#include "Perceptron.h"

class Perceptron_FitnessStrategy : public FitnessStrategy {
public:
	Perceptron_FitnessStrategy();
	Perceptron_FitnessStrategy(std::vector<double> weights);
	~Perceptron_FitnessStrategy();

	virtual double threadFitness(std::shared_ptr<Thread>,
		size_t waitTime,
		double posOnRL,
		std::shared_ptr<FitnessContext> fc
	);

	virtual double cpuFitness(std::shared_ptr<Thread>,
		size_t currentBT,
		size_t contextSwitchTime,
		std::shared_ptr<FitnessContext> fc
	);

private:
	std::shared_ptr<Perceptron> fitnessPerceptron;
};

