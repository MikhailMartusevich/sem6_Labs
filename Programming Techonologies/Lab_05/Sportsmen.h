#ifndef SPORTSMEN_H
#define SPORTSMEN_H

#include <iostream>
#include <vector>
#include "Result.h"

class Sportsmen {
public:
	Sportsmen(const char* name, int dob, const char* sportType, const char* country) : _name(name), _dateOfBirth(dob), _typeOfSport(sportType), _country(country) {} ;
	void getName();
	void getAllResults();
	void addNewResult(Result* res);
private:
	const char* _name;
	int _dateOfBirth;
	const char* _typeOfSport;
	const char* _country;

	std::vector<Result*> activeResults;

};

void Sportsmen::getName() {
	std::cout << "Name: " << _name;
	std::cout << "\nDate of birth: " << _dateOfBirth;
	std::cout << "\nSport: " << _typeOfSport;
	std::cout << "\nCountry: " << _country << std::endl;
}

void Sportsmen::getAllResults() {
	for (int i = 0; i < activeResults.size(); i++) {
		activeResults[i]->getData();
	}
}

void Sportsmen::addNewResult(Result* res) {
	activeResults.push_back(res);
}

#endif // !SPORTSMEN_H

