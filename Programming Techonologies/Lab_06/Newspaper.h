#ifndef NEWSPAPER_H
#define NEWSPAPER_H

#include "IItem.h"

class Newspaper : public IItem {
public:
	Newspaper(const std::string& title, double price, const std::string& edition);
	virtual ~Newspaper();

	// ���������� ���������� ��������� �������
	std::string GetTitle() const { return _title; }

	// ���������� ���������� ��������� �������
	double GetPrice() const { return _price; }

	// �������� ����� ������ ������. 
	// ����������� �����, ������������� ��� ������
	std::string GetEdition() const { return _edition; }

private:
	std::string _title;
	double _price;
	std::string _edition;
};

#endif // !NEWSPAPER_H

