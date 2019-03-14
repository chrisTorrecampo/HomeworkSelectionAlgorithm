#pragma once
#include <memory>

class GA_Fitness{
public:
	GA_Fitness();

	double fitness();

private:
	std::shared_ptr<Scheduler> schedule; 
};