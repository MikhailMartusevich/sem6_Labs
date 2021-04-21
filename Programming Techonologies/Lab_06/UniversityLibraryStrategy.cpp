#include "UniversityLibraryStrategy.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

UniversityLibraryStrategy::UniversityLibraryStrategy(int averagePeriod) : _averagePeriod(averagePeriod) {}

UniversityLibraryStrategy::~UniversityLibraryStrategy() {}

int UniversityLibraryStrategy::HoldPeriod(const Reader& reader) const {
	// ��� ���� ���������� ��������� ��������� ����� ������ ������� ��������
	int result = _averagePeriod;

	//
	// ����������, ������ ������ ����������� ��������: ������� ��� 
	// �������������.
	//

	const Student* student = dynamic_cast<const Student*>(&reader);
	const Lecturer* lecturer = dynamic_cast<const Lecturer*>(&reader);
	const Graduate* graduate = dynamic_cast<const Graduate*>(&reader);


	if (student != NULL) {
		if (student->GetClass() < 3) {
			// ������� ����
			result = _averagePeriod / 2;
		}
		else {
			// ������� ����
			result = _averagePeriod;
		}
	}
	else if (lecturer != NULL) {
		if (_averagePeriod != NULL) {
			// ��� �������������
			result = _averagePeriod * 2;
		}
	}
	else if (graduate != NULL) {
		if (graduate->GetForm() == (std::string)"�����") {  // �������� �� ����� ����� ��������
			result = _averagePeriod;
		}
		else if (graduate->GetForm() == (std::string)"�������") { // �������� �� ������� ����� ��������
			result = _averagePeriod / 2;
		}
	}

	return result;
}
