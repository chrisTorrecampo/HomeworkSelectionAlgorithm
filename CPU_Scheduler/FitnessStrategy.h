#pragma once
#include "FitnessContext.h"

class FitnessStrategy {
public:

	//pure virtual
	virtual double hwFitness(std::shared_ptr<Homework>, std::shared_ptr<FitnessContext> fc
	) = 0;

protected:
	std::shared_ptr<FitnessContext> fitnessContext;

	FitnessStrategy() {}
};