#pragma once

class FitnessStrategy {
public:

	//pure virtual
	virtual double threadFitness(std::shared_ptr<Thread>) = 0;
	virtual double cpuFitness(std::shared_ptr<Thread>) = 0;

protected:

	//std::shared_ptr<Context> context;

	FitnessStrategy() {}
};