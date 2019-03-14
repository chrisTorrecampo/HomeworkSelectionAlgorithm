#pragma once
#include <vector>
#include <memory>

class Gene {
public:
	Gene(std::vector<double> g) {
		genes = g;
	}

	Gene(const Gene &g) {
		fitness = g.fitness;
		genes = g.genes;
	}

	Gene& operator=(const Gene &g) {
		fitness = g.fitness;
		genes = g.genes;
	}

	double fitness = 0;
	std::vector<double> genes;
};