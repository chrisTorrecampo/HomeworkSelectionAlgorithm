#pragma once
#include <vector>

#include "FitnessStrategy.h"
#include <stdlib.h>
#include <time.h>

class Population
{
public:
	Population(size_t ng);                                       //empty
	Population(size_t ng, size_t popsToInitialize);              //initialize x random organisms
	Population(size_t ng, std::vector<std::vector<double>> p);   //initialize from vector
	Population(size_t ng, FILE file);                            //initialize from file
	~Population();

	void addRandomPops(size_t numPops);
	void addRandomPops(size_t numPops, size_t min, size_t max);
	void addPop(std::vector<double> genes);
	void outputFile(FILE file);
	void runGenerations(size_t gens);

private:
	std::vector<std::vector<double>> pop = {};
	std::vector<double> fitness;
	size_t numGenes;

	void getSeed();

	void testPop();
	void evolvePop();
	void kill(double percent);
	void mutation(double percent);
	void generation();

	std::vector<double> breed(std::vector<double> a, std::vector<double> b);
	void cross(std::vector<double> &a, std::vector<double> &b);
	void mutate(std::vector<double> &a);
};

