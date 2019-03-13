#include <iostream>
#include <vector>
#include "Scheduler.h"
#include "FIFO_Strategy.h"
#include "RoundRobin_Strategy.h"
#include "Perceptron_FitnessStrategy.h"
#include "GeneticOrganism_Strategy.h"

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
	
	std::shared_ptr<Scheduler> s = std::make_shared<Scheduler>();
	std::shared_ptr<Perceptron_FitnessStrategy> pFit = std::make_shared<Perceptron_FitnessStrategy>();
	s->setStrat(std::make_shared<GeneticOrganism_Strategy>(pFit, 5));

	for (int i = 0; i < 10; i++) {
		s->addNewThread(std::vector<size_t>{10});
	}

	while (!s->isFinished()) {
		s->run();

		std::cout << s->numFinished() << "\n";
	}


	int x;
	std::cin >> x;
	//wait for imput so we can see console

	//system("pause"); //lazy way that requires windows
}