#include "UniversityLibraryStrategy.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

UniversityLibraryStrategy::UniversityLibraryStrategy(int averagePeriod) : _averagePeriod(averagePeriod) {}

UniversityLibraryStrategy::~UniversityLibraryStrategy() {}

int UniversityLibraryStrategy::HoldPeriod(const Reader& reader) const {
	// Для всех неучтенных категорий читателей будет задано среднее значение
	int result = _averagePeriod;

	//
	// Определить, какому классу принадлежит читатель: студент или 
	// преподаватель.
	//

	const Student* student = dynamic_cast<const Student*>(&reader);
	const Lecturer* lecturer = dynamic_cast<const Lecturer*>(&reader);
	const Graduate* graduate = dynamic_cast<const Graduate*>(&reader);


	if (student != NULL) {
		if (student->GetClass() < 3) {
			// Младший курс
			result = _averagePeriod / 2;
		}
		else {
			// Старший курс
			result = _averagePeriod;
		}
	}
	else if (lecturer != NULL) {
		if (_averagePeriod != NULL) {
			// Для преподавателя
			result = _averagePeriod * 2;
		}
	}
	else if (graduate != NULL) {
		if (graduate->GetForm() == (std::string)"Очная") {  // Аспирант на очной форме обучения
			result = _averagePeriod;
		}
		else if (graduate->GetForm() == (std::string)"Заочная") { // Аспирант на заочной форме обучения
			result = _averagePeriod / 2;
		}
	}

	return result;
}
