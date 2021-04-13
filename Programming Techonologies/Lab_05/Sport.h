#ifndef SPORT_H
#define SPORT_H

#include <iostream>
#include <vector>
#include "Sportsmen.h"
#include "Result.h"

class Sport {
public:
	Sport() {};
	virtual ~Sport() {};

	void getAllSportsmen();
	void addNewSportsmen(Sportsmen& men);


private:
	std::vector<Sportsmen> activeSportsmen;

};

void Sport::getAllSportsmen() {
	for (int i = 0; i < activeSportsmen.size(); i++) {
		activeSportsmen[i].getName();
		activeSportsmen[i].getAllResults();
	}
}

void Sport::addNewSportsmen(Sportsmen& men) {
	activeSportsmen.push_back(men);
}


#endif // !SPORT_H
