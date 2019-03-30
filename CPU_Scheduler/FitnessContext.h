#pragma once
#include <memory>
#include <vector>


class FitnessContext{
public:
	FitnessContext(size_t t, double d, size_t p, double w, std::vector<std::pair<std::string, double>> a) {
		time = t;
		diff = d;
		points = p;
		willingness = w;
		abilities = a;
	}

	//Homework Public Vars
	size_t time;
	size_t diff;
	size_t points;
	double willingness;
	std::vector<std::pair<std::string, double>> abilities;

};