#pragma once
#include <vector>

class Perceptron {
public:
	Perceptron(std::vector<double> w) {
		weights = w;
	}

	double getValue(std::vector<double> input) {
		if (input.size() < weights.size()) {
			//bad things happened
			return -1;
		}
		double sum = 0;
		for (size_t i = 0; i < weights.size(); i++) {
			sum += weights[i] * input[i];
		}

		//activation func would go here if we ever want to add that
		return sum;
	}
private:
	std::vector<double> weights;
};