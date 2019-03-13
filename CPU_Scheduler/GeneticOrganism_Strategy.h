#pragma once
#include "Scheduler.h" //needs stuff from Scheduler and Scheduler contatins ScheduleStrategy
#include "FitnessStrategy.h"

class GeneticOrganism_Strategy : public ScheduleStrategy {
public:
	GeneticOrganism_Strategy(std::shared_ptr<FitnessStrategy>, int ft);
	~GeneticOrganism_Strategy();
	void run();
	void schedule();
	void addThread();
	void setContext(std::shared_ptr<Context> c);
	void checkFitness();

private:
	int fitTime;//how often do we check fitness? low numbers are potentially very costly //GENE?
	int time_since_last_fitness = 0;
	int time_since_last_prempt = 0;

	std::shared_ptr<FitnessStrategy> fit;

	void prempt(std::shared_ptr<Thread>);
};

