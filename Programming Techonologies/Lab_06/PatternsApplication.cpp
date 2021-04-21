#include "Library.h"
#include "PublicLibraryStrategy.h"
#include "UniversityLibraryStrategy.h"
#include "PurchaseCheapStrategy.h"
#include "PurchaseExpensiveStrategy.h"
#include "PurchaseAverageStrategy.h"
#include "Student.h"
#include "Lecturer.h"
#include "ItemFactory.h"
#include <windows.h>
#include "LibraryItem.h"
#include <iostream>
#include "Book.h"
#include "Journal.h"
#include "Newspaper.h"

//
// �������� ��������� ���������� � ���� � ���
//
void Show(Library& lib);

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "rus");
	//
	// ���������� � ���������� �����������
	//
	Library vlsuLibrary(
		std::string("���������� ����"),
		new PurchaseAverageStrategy(2),
		new UniversityLibraryStrategy(50));
	Library regionLibrary(
		std::string("��������� ����������"),
		new PurchaseExpensiveStrategy(4),
		new PublicLibraryStrategy(65));

	//
	// �������� ��������� ���������
	//
	Student st1(std::string("������"), 1);
	Student st2(std::string("������"), 4);
	Student st3(std::string("�������"), 5);

	Lecturer lec1(std::string("�������"), std::string("������"));
	Lecturer lec2(std::string("�������"), std::string("���������"));

	Graduate gr1(std::string("��������"), std::string("�����"));
	Graduate gr2(std::string("�������"), std::string("�����"));
	Graduate gr3(std::string("�������"), std::string("�������"));

	//
	// ������������ ��������� � �����������. ��������� �� ��������� -
	// � ���������� �����������
	//
	vlsuLibrary.AddReader(&st1);
	vlsuLibrary.AddReader(&st2);
	regionLibrary.AddReader(&st3);

	vlsuLibrary.AddReader(&lec1);
	vlsuLibrary.AddReader(&lec2);
	regionLibrary.AddReader(&lec1);
	regionLibrary.AddReader(&lec2);

	vlsuLibrary.AddReader(&gr1);
	vlsuLibrary.AddReader(&gr3);
	regionLibrary.AddReader(&gr2);
	

	//
	// ������������ ��������� �������� ������� � "�������" �� �����������
	//
	for (int i = 0; i < 10; i++) {
		IItem* item;

		// � �������� ������� (i - ������) ����� ��������� �������,
		// � �������� - �����
		if (i % 2 == 0) {
			// ������� ��������� �������
			item = ItemFactory::Instance().CreateJournal();
		}
		else if (i % 3 == 0){
			// ������� ��������� �����
			item = ItemFactory::Instance().CreateBook();
		}
		else {
			item = ItemFactory::Instance().CreateNewspaper();
		}

		//
		// ���������� ���������� �������� �������� �������� �������
		//
		bool isSold = false;

		if (!isSold) {
			isSold = vlsuLibrary.PurchaseItem(item);
		}
		if (!isSold) {
			isSold = regionLibrary.PurchaseItem(item);
		}


		//
		// ���� ��������� �� ������, ���� ��� ����������, ����� �� ����
		// ������ (� ������������ ������, � �� � ������ ������)
		//
		if (!isSold) {
			delete item;
		}

	}

	//
	// ���������� ������ �������� ������� ���������
	//
	vlsuLibrary.LetLibItemOut(vlsuLibrary.GetLibItems()[0], &st1);
	vlsuLibrary.LetLibItemOut(vlsuLibrary.GetLibItems()[1], &gr1);
	vlsuLibrary.LetLibItemOut(vlsuLibrary.GetLibItems()[2], &gr3);
	//vlsuLibrary.LetLibItemOut(vlsuLibrary.GetLibItems()[3], &gr3);
	regionLibrary.LetLibItemOut(regionLibrary.GetLibItems()[0], &st3);

	vlsuLibrary.LetLibItemOut(vlsuLibrary.GetLibItems()[3], &lec1);
	regionLibrary.LetLibItemOut(regionLibrary.GetLibItems()[1], &lec1);
	regionLibrary.LetLibItemOut(regionLibrary.GetLibItems()[2], &gr2);

	//
	// �������� ��������� ��������� � ����
	//

	Show(vlsuLibrary);
	Show(regionLibrary);

	return 0;
}


void Show(Library& lib) {
	//
	// �������� � ����������
	//
	std::cout << "\n" << "�������� ����������: " << lib.GetName() << std::endl;

	//
	// �������� � ���� ��������� ����������
	//
	std::cout << "\n" << "��������:" << std::endl;
	std::vector<Reader*> readers = lib.GetReaders();
	for (int iReader = 0; iReader < readers.size(); iReader++) {
		std::cout << iReader << ") " << readers[iReader]->GetName() << std::endl;
	}


	//
	// �������� � ������
	//
	std::cout << "\n" << "����������:" << std::endl;
	std::vector<LibraryItem*> items = lib.GetLibItems();
	for (int i = 0; i < items.size(); i++) {
		std::cout << i + 1 << ") " << items[i]->GetTitle();

		// ������� ����������, ������������� ��� ����������� ���� �������
		Book* book = dynamic_cast<Book*>(items[i]->GetItem());
		Journal* journal = dynamic_cast<Journal*>(items[i]->GetItem());
		Newspaper* newspaper = dynamic_cast<Newspaper*>(items[i]->GetItem());

		if (book != NULL) {
			std::cout << " ����� " << book->GetAuthor();
		}
		else {
			if (journal != NULL) {
				std::cout << " ����� " << journal->GetVolume();
			}
			if (newspaper != NULL) {
				std::cout << newspaper->GetEdition();
			}
		}

		if (items[i]->GetReader() != NULL) {
			std::cout << " �� �����: "
				<< items[i]->GetReader()->GetName()
				<< " �� " << items[i]->GetHoldPeriod() << " ����" << std::endl;
		}
		else {
			std::cout << " �� �����" << std::endl;
		}

		std::cout
			<< "���.� " << items[i]->GetInventoryNumber()
			<< " ��������� " << items[i]->GetPrice() << std::endl;

	}
}
