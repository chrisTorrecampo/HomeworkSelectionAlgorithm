#include "Population.h"


Population::Population(size_t ng) {
	numGenes = ng;
	getSeed();
}

Population::Population(size_t ng, size_t popsToInitialize) {
	numGenes = ng;
	getSeed();
	addRandomPops(popsToInitialize);
}

Population::Population(size_t ng, std::vector<std::vector<double>> p) {
	numGenes = ng;
	getSeed();
	pop = p;
}

Population::Population(size_t ng, FILE file) {
	numGenes = ng;
	getSeed();
	//TODO: import from file
}

Population::~Population() {
}

void Population::addRandomPops(size_t numPops) {
	for (int i = 0; i < numPops; i++) {
		std::vector<double> genes = {};
		for (int j = 0; j < numGenes; j++) {
			genes.push_back(rand());
		}
		addPop(genes);
	}
}

void Population::addRandomPops(size_t numPops, size_t min, size_t max) {
	if (min > max) {
		//TODO: bad stuff happened 
		return;
	}

	for (int i = 0; i < numPops; i++) {
		std::vector<double> genes = {};
		for (int j = 0; j < numGenes; j++) {
			genes.push_back(rand() % max + min + 1);
		}
		addPop(genes);
	}
}

void Population::addPop(std::vector<double> genes) {
	pop.push_back(genes);
}

void Population::outputFile(FILE file) {
	//TODO: do this
}

void Population::runGenerations(size_t gens) {
	for (int i = 0; i < gens; i++) {
		generation();
	}
}

void Population::getSeed() {
	srand(time(NULL));
}

void Population::testPop() {
	fitness = std::vector<double>(pop.size());
	for (int i = 0; i < pop.size(); i++) {
		//fitness[i] = Fit(pop[i]) //TODO: hook this in
	}
}

void Population::evolvePop() {
	//TODO: evolve
	//sort by fitness
	kill(0.1); // kill bottom percent 
	//breed good ones
	//mutate
	mutation(0.2);
}

void Population::kill(double percent) {
	size_t numKilled = pop.size() * percent;
	for (int i = 0; i < numKilled; i++) {
		pop.pop_back();
	}
}

void Population::mutation(double percent) {
	size_t numMutations = pop.size() * percent;
	for (int i = 0; i < numMutations; i++) {
		size_t randIndex = rand() % pop.size();
		mutate(pop[randIndex]);
	}
}

void Population::generation() {
	testPop();
	evolvePop();
	//TODO: print? send to file?
}

std::vector<double> Population::breed(std::vector<double> a, std::vector<double> b) {
	size_t maxSize = a.size() < b.size() ? a.size() : b.size(); //take the smaller size as max
	std::vector<double> out(maxSize);
	for (int i = 0; i < maxSize; i ++) {
		if (rand() % 2) {
			out[i] = a[i];
		} else {
			out[i] = b[i];
		}
	}

	return out;
}

void Population::cross(std::vector<double>& a, std::vector<double>& b) {
	size_t maxSize = a.size() < b.size() ? a.size() : b.size(); //take the smaller size as max
	size_t crossPoint = rand() % (maxSize-1) + 1;
	for (int i = 0; i < crossPoint; i++) {
		double temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
	for (int i = crossPoint; i < maxSize; i++) {
		double temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

void Population::mutate(std::vector<double>& a) {
	size_t mutationMutex = rand() % a.size();
	a[mutationMutex] = rand();
}
