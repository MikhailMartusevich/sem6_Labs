#include <iostream>
#include "Sport.h"

int main() {

	Sport tournament;
	
	Result* tre = new Olympic("11,2", 2001);

	Result* ru = new Worldwide("124,5", 2020421);

	Sportsmen a("Markelov", 1998, "Wrestling", "Russia");
	a.addNewResult(tre);
	a.addNewResult(ru);
	
	Sportsmen b("Glupov", 2000, "Darts", "England");
	b.addNewResult(ru);
	b.addNewResult(ru);

	tournament.addNewSportsmen(a);
	tournament.addNewSportsmen(b);
	tournament.getAllSportsmen();


	return 0;
}