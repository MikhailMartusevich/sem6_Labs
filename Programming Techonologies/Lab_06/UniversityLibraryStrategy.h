#ifndef UNIVERSITYLIBRARYSTRATEGY_H
#define UNIVERSITYLIBRARYSTRATEGY_H

#include "IDeliveryStrategy.h"
#include "Student.h"
#include "Lecturer.h"
#include "GraduateSt.h"

class UniversityLibraryStrategy : public IDeliveryStrategy {
public:
	UniversityLibraryStrategy(int averagePeriod);
	virtual ~UniversityLibraryStrategy();

	int HoldPeriod(const Reader& reader) const;

private:
	int _averagePeriod;


};


#endif // !UNIVERSITYLIBRARYSTRATEGY_H

