#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <list>

#include "Scheduler.h"
#include "Perceptron_FitnessStrategy.h"
#include "Population.h"

int main(int argc, char *argv[]){
	
	srand(time(NULL));

	std::list<std::shared_ptr<Homework>> dataSet;

	for (int i = 0; i < 5; i++) {

		dataSet.push_back(std::make_shared<Homework>(1, 0.5, 1, 0.5, 1, 0.5, 1, "dummy Homework"));
		//dataSet->push_back((size_t)(rand() % 5 + 1));
	}

	Population p = Population(11, dataSet);

	p.addRandomPops(100, 0, 10);
	p.runGenerations(500);

	int x;
	std::cin >> x;
	//wait for imput so we can see console

	//system("pause"); //lazy way that requires windows
}

void fileIO()
{
	//I/o Vars
	std::vector<Homework> hList;
	std::string line = "";
	std::ifstream dataFile("data.txt");
	std::string delim = "=";

	//Homework Vars
	int chapterNum;
	double liquidKnowledge;
	size_t time;
	double diff;
	size_t points;
	double willingness;
	int category;
	std::string name;

	std::string datArr[9];
	int count = 1;

	if (dataFile.is_open())
	{
		std::cout << "Reading File: " << std::endl;

		while (getline(dataFile, line))
		{
			datArr[count - 1] = line;
			count++;

			if (count % 10 == 0) {
				chapterNum = stoi(datArr[0]);
				liquidKnowledge = stod(datArr[1]);
				time = stod(datArr[2]);
				diff = stod(datArr[3]);
				points = stod(datArr[4]);
				willingness = stod(datArr[5]);
				category = stoi(datArr[6]);
				name = datArr[7];

				Homework hTemp = Homework(chapterNum, liquidKnowledge, time, diff, points, willingness, category, name);
				hList.insert(hList.end(), hTemp);
				count = 1;
			}

			std::cout << std::endl;
		}

		dataFile.close();
	}

	else
		std::cout << "Unable to open file";
}