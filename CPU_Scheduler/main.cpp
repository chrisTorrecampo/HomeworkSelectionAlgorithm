#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include "Scheduler.h"
#include "FIFO_Strategy.h"
#include "RoundRobin_Strategy.h"
#include "Perceptron_FitnessStrategy.h"
#include "Population.h"
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
    std::string path = "tests/t50/t50.txt"; // default


	if (argc >= 2){
        path = argv[1];
    }
	srand(time(NULL));

	std::vector<size_t> dataSet;

    for (int i = 0; i < 5; i++) {
        dataSet.push_back((size_t)(rand() % 5 + 1));
    }
//    for (int i = 0; i < 5; i++) {
//        dataSet.push_back((size_t)(i+1023 % 5 + 1));
//    }
    // check dataset
    for (int i = 0; i < dataSet.size(); i++) {
        printf("[main][add new thread] intput:%zu\n", dataSet[i]);
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
    
    // training with random small data
    Population p = Population(11, dataSet);
    p.addRandomPops(100, 0, 10);
    p.runGenerations(100);
    
    std::shared_ptr<std::list<std::shared_ptr<Thread>>> beforeReady =  std::make_shared<std::list<std::shared_ptr<Thread>>>();;


    // read test data
    int ThreadsCounter = 0;
    std::ifstream fin;
    std::vector<size_t> burstTimes = {};
    fin.open(path);
    if(!fin){
        // no file
        printf("[main] found no file\n");
        return 0;
    } else {
        std::string line;
        
        while(getline(fin,line,'\n')){
            std::vector<size_t> burstTime;
            std::stringstream linestream(line);
            std::string element;
            int lineCount = 0;
            int arrive = 0, priority = 1;
            size_t burst = 0;
            
            // read each line, assume each line only has [arriveTime,priority, burstTime]
            burstTimes = {};
            while(getline(linestream,element,',')) {
                if (lineCount == 0) {
                    arrive = stod(element);
                } else if (lineCount == 1) {
                    priority = stod(element);
                } else if (lineCount >= 2) {
                    burst = stod(element);
                    burstTime.push_back(burst);
                    burstTimes.push_back(burst);
                } else {
                    break;
                }
                lineCount++;
            }
            
            std::shared_ptr<Thread> newThread(new Thread(arrive, burstTimes));
            printf("input burst size: %zu \n", burstTimes.size());
            beforeReady->push_back(newThread);
            ThreadsCounter++;
        }
        
    }
    fin.close();
    
    //    std::shared_ptr<Scheduler> s = std::make_shared<Scheduler>();
    //    s->setStrat(std::make_shared<RoundRobin_Strategy>(4));
    std::shared_ptr<Perceptron_FitnessStrategy> fit = std::make_shared<Perceptron_FitnessStrategy>();
    std::shared_ptr<Scheduler> s = std::make_shared<Scheduler>();
    s->setStrat(std::make_shared<GeneticOrganism_Strategy>(fit, 50));

    while (!s->isFinished()  or ThreadsCounter> 0) {
        // check arriveTime
        if(beforeReady->front()!=NULL) {
            while( ThreadsCounter> 0 &&s->getCPUtime() >= beforeReady->front()->arriveTime) {
                s->addNewThread(beforeReady->front());
                beforeReady->pop_front();
                ThreadsCounter--;
            }
        }
        
        s->run();
    }
    
    std::cout << "test Fitness: " << 1 / s->getMeanWaitTime() << "\n";
    std::cout << "mean waiting time: " << s->getMeanWaitTime() << "\n";

    //    int x;
    //    std::cin >> x;
	//wait for imput so we can see console

	//system("pause"); //lazy way that requires windows
}
