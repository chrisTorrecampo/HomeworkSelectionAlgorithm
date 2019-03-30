#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

class Homework {
private:
	int chapterNum;
	double liquidKnowledge;

public:
	size_t time;
	double diff;
	size_t points;
	double willingness;
	std::string name;
	std::vector<std::pair<std::string, double>> abilities;

	Homework() {
		chapterNum = 0;
		liquidKnowledge = 0.0;

		time = 0;
		diff = 0;
		points = 0;
		willingness = 0;
		name = "";
	}

	Homework(int cN, double lK, size_t t, double d, size_t p, double w, std::string n, std::vector<std::pair<std::string, double>> a) {
		chapterNum = cN;
		liquidKnowledge = lK;

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
		chapterNum = h.getchapterNum;
		liquidKnowledge = h.getLiquidKnowldge;

		time = h.time;
		diff = h.diff;
		points = h.points;
		willingness = h.willingness;
		name = h.name;

		abilities = h.abilities;
	}

	Homework& operator=(const Homework &h) {
		if (this != &h) {
			chapterNum = h.getchapterNum;
			liquidKnowledge = h.getLiquidKnowldge;

			time = h.time;
			diff = h.diff;
			points = h.points;
			willingness = h.willingness;
			name = h.name;

			abilities = h.abilities;
		}
		return *this;
	}

	int getchapterNum();

	double getLiquidKnowldge();
};
