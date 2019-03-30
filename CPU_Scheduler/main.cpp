#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <list>

#include "Scheduler.h"
#include "Perceptron_FitnessStrategy.h"
#include "Population.h"

int main(int argc, char *argv[]){
	
	srand(time(NULL));

	std::list<std::shared_ptr<Homework>> dataSet;

	for (int i = 0; i < 5; i++) {

		dataSet.push_back(std::make_shared<Homework>(1, 0.5, 1, 0.5, 1, 0.5, 1, "dummy Homework"));
		//dataSet->push_back((size_t)(rand() % 5 + 1));
	}

	Population p = Population(11, dataSet, 3);

	p.addRandomPops(100, 0, 10);
	p.runGenerations(500);

	int x;
	std::cin >> x;
	//wait for imput so we can see console

	//system("pause"); //lazy way that requires windows
}