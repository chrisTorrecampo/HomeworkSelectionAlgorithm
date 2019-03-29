#include "Course.h"

double Course::getGPA() { 
	if (hList.size() == 0) {
		std::cout << "ERROR: No Homework";

		return 0;
	}

	double gpa = 0.0;

	std::list<Homework>::iterator it;
	for (it = hList.begin(); it != hList.end(); ++it) {
		gpa += (*it).points;
	}

	return gpa / hList.size();
}

void Course::addHW(std::shared_ptr<Homework> h) {
	hList.push_back(*h.get());
}
