#pragma once

class FitnessContext{
public:
	FitnessContext(bool pr, size_t nb, size_t ebt, size_t rls, size_t bls, size_t fls, size_t tslp, size_t tsls) {
		premptedRecently = pr;
		numBursts = nb;
		expectedBurstTime = ebt;

		BL_RL_S = ((double)bls) / ((double)rls);
		FL_RL_S = ((double)fls) / ((double)rls);
		FL_BL_S = ((double)fls) / ((double)bls);

		timeSinceLastPremption = tslp;
		timeSinceLastSwitched = tsls;
	}

	bool premptedRecently;
	size_t numBursts;
	size_t expectedBurstTime;
	double BL_RL_S;
	double FL_RL_S;
	double FL_BL_S;
	size_t timeSinceLastPremption;
	size_t timeSinceLastSwitched;
	//TODO: time spent in IO?
};