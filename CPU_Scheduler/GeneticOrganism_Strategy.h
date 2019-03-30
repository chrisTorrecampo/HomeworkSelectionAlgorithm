#pragma once
#include "Scheduler.h" //needs stuff from Scheduler and Scheduler contatins ScheduleStrategy
#include "FitnessStrategy.h"

class GeneticOrganism_Strategy : public ScheduleStrategy {
public:
	GeneticOrganism_Strategy(std::shared_ptr<FitnessStrategy>, int ft);
	~GeneticOrganism_Strategy();
	void schedule();
	void setContext(std::shared_ptr<Context> c);

private:
	int fitTime;//how often do we check fitness? low numbers are potentially very costly //GENE?

	std::shared_ptr<FitnessStrategy> fit;

	void prempt(std::shared_ptr<Homework>);
};

