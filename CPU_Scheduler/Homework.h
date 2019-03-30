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
	int category;
	std::string name;

	Homework() {
		chapterNum = 0;
		liquidKnowledge = 0.0;

		time = 0;
		diff = 0;
		points = 0;
		willingness = 0;
		category = 0;
		name = "";
	}

	Homework(int cN, double lK, size_t t, double d, size_t p, double w, int c, std::string n) {
		chapterNum = cN;
		liquidKnowledge = lK;

		time = t;
		diff = d;
		points = p;
		willingness = w;
		category = c;
		name = n;
	}

	~Homework() {

	}

	Homework(const Homework &h) {
		chapterNum = h.chapterNum;
		liquidKnowledge = h.liquidKnowledge;

		time = h.time;
		diff = h.diff;
		points = h.points;
		willingness = h.willingness;
		category = h.category;
		name = h.name;
	}

	Homework& operator=(const Homework &h) {
		if (this != &h) {
			chapterNum = h.chapterNum;
			liquidKnowledge = h.liquidKnowledge;

			time = h.time;
			diff = h.diff;
			points = h.points;
			willingness = h.willingness;
			category = h.category;
			name = h.name;
		}
		return *this;
	}

	int getchapterNum();

	double getLiquidKnowldge();
};
