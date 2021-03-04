#include <iostream>
#include <vector>
#include "phoneBook.h"
#include "errorHandler.h"

void FindNumber(std::vector<phoneBook> v1);
void SinceYear(std::vector<phoneBook> v1);
void NumbersOnStreet(std::vector<phoneBook> v1);


int main() {
	try {
		phoneBook a = phoneBook("Petrov", "Gorkogo", 25, 2003);
		phoneBook b = phoneBook("Sidorov", "Lenina", 11, 2013);
		phoneBook c = phoneBook("Pidorov", "Mira", 4, 2011);
		phoneBook d = phoneBook("Smirnov", "Gorkogo", 25, 2007);
		phoneBook e = phoneBook();

		std::cin >> e;

		std::vector<phoneBook> v;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		v.push_back(d);
		v.push_back(e);

		NumbersOnStreet(v);
		std::cout << std::endl;
		SinceYear(v);
		std::cout << std::endl;
		FindNumber(v);
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << b;

	}
	catch (errorHandler &exp) {
		std::cout << "Error: " << exp.print();
		exit(1);
	}

	return 0;
}

void FindNumber(std::vector<phoneBook> v1) {
	if (v1.size() == 0)
		throw errorHandler(errors::empty_vector_err);

	std::string flastname;
	std::cout << "Enter last name of user: ";
	std::cin >> flastname;

	for (int i = 0; i < v1.size(); i++) {
		if (flastname == v1[i].lastName) {
			std::cout << "User: " << flastname << "\nNumber: " << v1[i].phoneNumber;
			return;
		}
	}

	throw errorHandler(errors::find_err);
}

void SinceYear(std::vector<phoneBook> v1) {
	if (v1.size() == 0)
		throw errorHandler(errors::empty_vector_err);

	int fyear{ 0 };
	int count{ 0 };
	std::cout << "Enter year: ";
	std::cin >> fyear;

	if (fyear < 0)
		throw errorHandler(errors::invalid_year);

	for (int i = 0; i < v1.size(); i++) {
		if (v1[i].releaseYear >= fyear)
			count++;
	}

	std::cout << "\nCount of numbers installed since " << fyear << " is " << count << std::endl;
}

void NumbersOnStreet(std::vector<phoneBook> v1) {
	if (v1.size() == 0)
		throw errorHandler(errors::empty_vector_err);

	std::string fstreet;
	int fnumber{ 0 };
	int count = v1.size();
	std::cout << "Enter street: ";
	std::cin >> fstreet;
	std::cout << "Enter house number: ";
	std::cin >> fnumber;

	std::cout << "Number on street " << fstreet << " house number " << fnumber << std::endl;

	for (int i = 0; i < v1.size(); i++) {
		if (v1[i].street == fstreet && v1[i].houseNumber == fnumber)
			std::cout << v1[i].phoneNumber << "  ";
		else
			count--;
	}
	if (count == 0)
		throw errorHandler(errors::find_err);
}
