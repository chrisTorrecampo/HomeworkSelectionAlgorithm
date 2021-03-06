#pragma once
#include <memory>
#include <vector>

class FitnessContext {
public:
	FitnessContext(size_t t, double d, size_t p, double w, int c) {
		time = t;
		diff = d;
		points = p;
		willingness = w;
		category = c;
	}

	FitnessContext(const FitnessContext &c) { //TODO: I think the problem is here
		time = c.time;
		diff = c.diff;
		points = c.points;
		willingness = c.willingness;
		category = c.category;
	}

	FitnessContext& operator=(const FitnessContext &c) {
		if (this != &c) {
			time = c.time;
			diff = c.diff;
			points = c.points;
			willingness = c.willingness;
			category = c.category;
		}
		return *this;
	}

	//Homework Public Vars
	size_t time;
	double diff;
	size_t points;
	double willingness;
	int category;

	/*
	void printUI(std::vector<std::shared_ptr<Homework>> readOrder) {
		int count = 1;
		std::cout << "-------------------------------------------------------" << std::endl;
		std::cout << "-------------- Chapter Selection Program --------------" << std::endl;
		std::cout << "-------------------------------------------------------" << std::endl << std::endl;

		std::cout << "You should read the following chapters in this order: " << std::endl;

		for (std::vector<std::shared_ptr<Homework>>::iterator it = readOrder.begin(); it != readOrder.end(); ++it)
		{
			std::cout << count << "- " << (*it).get()->name << std::endl;
			count++;
		}

		std::cout << std::endl << "This program determines the best possible* order of chapters" << std::endl;
		std::cout << "to efficiently learn a subject based on a set of criteria" << std::endl;
	}
	*/
};