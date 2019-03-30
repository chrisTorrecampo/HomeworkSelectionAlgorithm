#pragma once
#include "FitnessStrategy.h"
#include "Perceptron.h"

class Perceptron_FitnessStrategy : public FitnessStrategy {
public:
	Perceptron_FitnessStrategy();
	Perceptron_FitnessStrategy(std::vector<double> weights);
	~Perceptron_FitnessStrategy();

	virtual double hwFitness(std::shared_ptr<Homework>, std::shared_ptr<FitnessContext> fc);

private:
	std::shared_ptr<Perceptron> fitnessPerceptron;
};

