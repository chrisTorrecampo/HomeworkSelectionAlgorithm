#include <iostream>
#include <list>
#include "Homework.h"

class Course {
public:
	double curGrade;
	double goalGrade;
	std::string name;
	std::list<Homework> hList;

	Course() {
		curGrade = 0.0;
		goalGrade = 0.0;
		name = "";
	}

	Course(double cGr, double gGr, std::string n, std::list<Homework> hL) {
		curGrade = cGr;
		goalGrade = gGr;
		name = n;
		hList = hL;
	}

	~Course() {

	}

	Course(const Course &c) {
		curGrade = c.curGrade;
		goalGrade = c.goalGrade;
		name = c.name;

		hList.assign(c.hList.begin(), c.hList.end());
	}

	Course& operator=(const Course &c) {
		if (this != &c) {
			curGrade = c.curGrade;
			goalGrade = c.goalGrade;
			name = c.name;

			hList.assign(c.hList.begin(), c.hList.end());
		}

		return *this;
	}

	double getGPA();

	void addHW(std::shared_ptr<Homework> h);
};