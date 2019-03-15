#include "Perceptron_FitnessStrategy.h"
#include <iostream>


Perceptron_FitnessStrategy::Perceptron_FitnessStrategy() {
	fitnessPerceptron = std::make_shared<Perceptron>(std::vector<double>{0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01});
}

Perceptron_FitnessStrategy::Perceptron_FitnessStrategy(std::vector<double> weights) {
	fitnessPerceptron = std::make_shared<Perceptron>(weights);
}


Perceptron_FitnessStrategy::~Perceptron_FitnessStrategy() {

}

double Perceptron_FitnessStrategy::threadFitness(std::shared_ptr<Thread>, size_t waitTime, double posOnRL, std::shared_ptr<FitnessContext> fc) {
	return fitnessPerceptron->getValue(std::vector<double>{(double) waitTime,
															(double) posOnRL,
															0.0,
															0.0,
															(double) fc->numBursts,
															(double) fc->expectedBurstTime,
															fc->BL_RL_S,
															fc->FL_RL_S,
															fc->FL_BL_S,
															(double) fc->timeSinceLastPremption,
															(double) fc->timeSinceLastSwitched
															}
	);
}

double Perceptron_FitnessStrategy::cpuFitness(std::shared_ptr<Thread>, size_t currentBT, size_t contextSwitchTime, std::shared_ptr<FitnessContext> fc) {
	/*
	std::cout << "cpu fitness: " << fitnessPerceptron->getValue(std::vector<double>{0.0,
		0.0,
		(double)currentBT,
		(double)contextSwitchTime,
		(double)fc->numBursts,
		(double)fc->expectedBurstTime,
		fc->BL_RL_S,
		fc->FL_RL_S,
		fc->FL_BL_S,
		(double)fc->timeSinceLastPremption,
		(double)fc->timeSinceLastSwitched
	}) << "\n";
	*/
	return fitnessPerceptron->getValue(std::vector<double>{0.0,
															0.0,
															(double) currentBT,
															(double) contextSwitchTime,
															(double) fc->numBursts,
															(double) fc->expectedBurstTime,
															fc->BL_RL_S,
															fc->FL_RL_S,
															fc->FL_BL_S,
															(double) fc->timeSinceLastPremption,
															(double) fc->timeSinceLastSwitched
	}
	);
}
