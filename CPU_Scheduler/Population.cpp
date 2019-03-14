#include <algorithm>

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

Population::Population(size_t ng, std::vector<std::shared_ptr<Gene>> g) {
	numGenes = ng;
	getSeed();
	pop = g;
}

Population::Population(size_t ng, FILE file) {
	numGenes = ng;
	getSeed();
	//TODO: import from file
}

Population::~Population() {
}

void Population::addRandomPops(size_t numPops) {
	for (size_t i = 0; i < numPops; i++) {
		std::vector<double> genes = {};
		for (size_t j = 0; j < numGenes; j++) {
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

	for (size_t i = 0; i < numPops; i++) {
		std::vector<double> genes = {};
		for (size_t j = 0; j < numGenes; j++) {
			genes.push_back(rand() % max + min + 1);
		}
		addPop(genes);
	}
}

void Population::addPop(std::vector<double> genes) {
	pop.push_back(std::make_shared<Gene>(genes));
}

void Population::outputFile(FILE file) {
	//TODO: do this
}

void Population::runGenerations(size_t gens) {
	for (size_t i = 0; i < gens; i++) {
		generation();
	}
}

void Population::getSeed() {
	srand(time(NULL));
}

void Population::testPop() {
	for (size_t i = 0; i < pop.size(); i++) {
		pop[i]->fitness = gaFit.fitness(pop[i]);
	}
}

void Population::evolvePop() {
	//sort by fitness
	std::sort(pop.begin(), pop.end(), &Population::fitSort);

	//kill bottom percent 
	kill(0.1);

	//scramble //TODO
	std::random_shuffle(pop.begin(), pop.end());

	//breed good ones
	size_t currMax = pop.size();
	for (size_t i = 0; i < currMax - 1; i += 2) {
		pop.push_back(breed(pop[1]->genes, pop[i+1]->genes));
	}
	
	//mutate
	mutation(0.2);
}

void Population::kill(double percent) {
	size_t numKilled = (size_t)(pop.size() * percent);
	for (size_t i = 0; i < numKilled; i++) {
		pop.pop_back();
	}
}

void Population::mutation(double percent) {
	size_t numMutations = (size_t)(pop.size() * percent);
	for (size_t i = 0; i < numMutations; i++) {
		size_t randIndex = rand() % pop.size();
		mutate(pop[randIndex]->genes);
	}
}

void Population::generation() {
	testPop();
	evolvePop();
	//TODO: print? send to file?
}

std::shared_ptr<Gene> Population::breed(std::vector<double> a, std::vector<double> b) {
	size_t maxSize = a.size() < b.size() ? a.size() : b.size(); //take the smaller size as max
	std::vector<double> out(maxSize);
	for (size_t i = 0; i < maxSize; i ++) {
		if (rand() % 2) {
			out[i] = a[i];
		} else {
			out[i] = b[i];
		}
	}

	return std::make_shared<Gene>(out);
}

void Population::cross(std::vector<double>& a, std::vector<double>& b) {
	size_t maxSize = a.size() < b.size() ? a.size() : b.size(); //take the smaller size as max
	size_t crossPoint = rand() % (maxSize-1) + 1;
	for (size_t i = 0; i < crossPoint; i++) {
		double temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
	for (size_t i = crossPoint; i < maxSize; i++) {
		double temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

void Population::mutate(std::vector<double> a) {
	size_t mutationMutex = rand() % a.size();
	a[mutationMutex] = rand();
}

bool Population::fitSort(const std::shared_ptr<Gene> &a, const std::shared_ptr<Gene> &b) {//TODO: more pointer problems :/
	return a->fitness < b->fitness;
}
