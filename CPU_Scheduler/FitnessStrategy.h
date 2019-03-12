#pragma once
#include "FitnessContext.h"

class FitnessStrategy {
public:

	//pure virtual
	virtual double threadFitness(std::shared_ptr<Thread>,
									size_t waitTime,
									double posOnRL,
									std::shared_ptr<FitnessContext> fc
	) = 0;
	virtual double cpuFitness(std::shared_ptr<Thread>,
								size_t currentBT,
								size_t contextSwitchTime,
								std::shared_ptr<FitnessContext> fc
	) = 0;

protected:

	std::shared_ptr<FitnessContext> fitnessContext;

	FitnessStrategy() {}
};