#pragma once
#include <memory>
#include "Homework.h"

class FitnessContext{
public:
	FitnessContext(size_t nb, size_t ebt, size_t rls, size_t bls, size_t fls, size_t tslp, size_t tsls) {
		numBursts = nb;
		expectedBurstTime = ebt;

		BL_RL_S = ((double)bls) / ((double)rls);
		FL_RL_S = ((double)fls) / ((double)rls);
		FL_BL_S = ((double)fls) / ((double)bls);
		if (rls == 0) { //TODO: make this cleaner
			BL_RL_S = FL_RL_S = 0;
		}
		if (bls == 0) {
			FL_BL_S = 0;
		}

		timeSinceLastPremption = tslp;
		timeSinceLastSwitched = tsls;
	}

	size_t numBursts;
	size_t expectedBurstTime;
	double BL_RL_S;
	double FL_RL_S;
	double FL_BL_S;
	size_t timeSinceLastPremption;
	size_t timeSinceLastSwitched;
	//TODO: time spent in IO?
};