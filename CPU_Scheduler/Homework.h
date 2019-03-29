#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

class Homework {
public:
	size_t time;
	double diff;
	size_t points;
	double willingness;
	std::string name;
	std::vector<std::pair<std::string, double>> abilities;

	Homework() {
		time = 0;
		diff = 0;
		points = 0;
		willingness = 0;
		name = "";
	}

	Homework(size_t t, double d, size_t p, double w, std::string n, std::vector<std::pair<std::string, double>> a) {
		time = t;
		diff = d;
		points = p;
		willingness = w;
		name = n;
		abilities = a;
	}

	~Homework() {

	}

	//Shallow Copy
	Homework(const Homework &h) {
		time = h.time;
		diff = h.diff;
		points = h.points;
		willingness = h.willingness;
		name = h.name;

		abilities = h.abilities;
	}

	Homework& operator=(const Homework &h) {
		if (this != &h) {
			time = h.time;
			diff = h.diff;
			points = h.points;
			willingness = h.willingness;
			name = h.name;

			abilities = h.abilities;
		}

		return *this;
	}
};
