#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "Scheduler.h"
#include "FIFO_Strategy.h"
#include "RoundRobin_Strategy.h"
#include "Perceptron_FitnessStrategy.h"
#include "Population.h"

int main(int argc, char *argv[]){
	/*
	std::shared_ptr<Scheduler> s = std::make_shared<Scheduler>();
	s->setStrat(std::make_shared<RoundRobin_Strategy>(4));

	for (int i = 0; i < 10; i++) {
		s->addNewThread(std::vector<size_t>{10});
	}

	while (!s->isFinished()) {
		s->run();

	std::cout << s->numFinished() << "\n";
	}
	*/
	
	srand(time(NULL));

	std::vector<size_t> dataSet;

	for (int i = 0; i < 5; i++) {
		dataSet.push_back((size_t)(rand() % 5 + 1));
	}

	/*
	std::shared_ptr<Scheduler> s = std::make_shared<Scheduler>();
	std::shared_ptr<Perceptron_FitnessStrategy> pFit = std::make_shared<Perceptron_FitnessStrategy>();
	s->setStrat(std::make_shared<GeneticOrganism_Strategy>(pFit, 1));

	for (size_t i = 0; i < dataSet.size(); i++) {
		s->addNewThread(std::vector<size_t>{dataSet[i]});
	}

	while (!s->isFinished()) {
		s->run();

		std::cout << s->numFinished() << "\n";
	}

	std::cout << s->getMeanWaitTime() << "\n";
	std::cout << s->getMeanSquaredWaitTime() << "\n";

	*/

	Population p = Population(11, dataSet);

	p.addRandomPops(10, 0, 10);
	p.runGenerations(10);

	int x;
	std::cin >> x;
	//wait for imput so we can see console

	//system("pause"); //lazy way that requires windows
}