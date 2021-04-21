//#define _CRT_SECURE_NO_WARNINGS
#include "ItemFactory.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// ������������� ������������ ���� ������,
// ��� ���� ����� ������� ����������� ��� ����������
ItemFactory ItemFactory::s_instance;

ItemFactory::ItemFactory() : _counter(0) {}

ItemFactory::~ItemFactory() {}

ItemFactory& ItemFactory::Instance() {
	return s_instance;
}

Book* ItemFactory::CreateBook() {
	_counter++;

	// �������������� ����� � ������
	char buffer[10];
	_itoa_s(_counter, buffer, 10);

	const std::string title = std::string("������� ����������� �� �++. ��� ") + std::string(buffer);
	const double price = _counter;
	std::string author = std::string("���������� �.");

	return new Book(title, price, author);
}

Newspaper* ItemFactory::CreateNewspaper() {
	_counter++;

	// �������������� ����� � ������
	char buffer[10];
	_itoa_s(_counter, buffer, 10);

	const std::string title = std::string("������������� ������");
	const double price = _counter;
	std::string edition = std::string(" ����� 4561") + std::string(buffer);

	return new Newspaper(title, price, edition);
}

Journal* ItemFactory::CreateJournal() {
	_counter++;

	// �������������� ����� � ������
	char buffer[5];
	_itoa_s(_counter, buffer, 5);

	std::string title = std::string("��������");
	double price = _counter;
	std::string volume = std::string(buffer);

	return new Journal(title, price, volume);

}
