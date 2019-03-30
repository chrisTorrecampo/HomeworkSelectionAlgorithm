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

double Perceptron_FitnessStrategy::hwFitness(std::shared_ptr<Homework>, std::shared_ptr<FitnessContext> fc) {
	return fitnessPerceptron->getValue(std::vector<double>{});
}
