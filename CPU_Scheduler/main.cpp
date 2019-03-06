#include <iostream>
#include <vector>
#include "Scheduler.h"
#include "FIFO_Strategy.h"

int main(int argc, char *argv[]){
	std::shared_ptr<Scheduler> s = std::make_shared<Scheduler>();
	s->setStrat(std::make_shared<FIFO_Strategy>());

	for (int i = 0; i < 10; i++) {
		s->addNewThread(std::vector<size_t>{10});
	}

	while (!s->isFinished()) {
		s->run();

	std::cout << s->numFinished() << "\n";
	}


	int x;
	std::cin >> x;
	//wait for imput so we can see console

	//system("pause"); //lazy way that requires windows
}