#include "phonebook.h"
#include <iostream>
#include <string>
#include <ctime>


std::istream& operator>>(std::istream& in, phoneBook& ph) {
	std::cout << "Enter the last name of user: ";
	in >> ph.lastName;
	std::cout << "\nEnter street: ";
	in >> ph.street;
	std::cout << "\nEnter house number: ";
	in >> ph.houseNumber;
	std::cout << "\nEnter year of release: ";
	in >> ph.releaseYear;
	return in;
}

std::ostream& operator<<(std::ostream& out, phoneBook& ph) {
	if (ph.lastName == "")
		throw errorHandler(errors::free_store_err);

	out << "\nUser number: " << ph.phoneNumber;
	out << "\nUser last name: " << ph.lastName;
	out << "\nUser street: " << ph.street;
	out << "\nUser house number: " << ph.houseNumber;
	out << "\nRelease year of number: " << ph.releaseYear;
	return out;
}

phoneBook::phoneBook() {
	strcpy_s(lastName, "");
	strcpy_s(street, "");
	houseNumber = 0;
	releaseYear = 0;
	phoneNumber = rand() % 899999 + 100000;
}

phoneBook::phoneBook(const char* _lastname, const char* _street, int _number, int _year) {
	strcpy_s(lastName, _lastname);
	strcpy_s(street, _street);
	houseNumber = _number;
	releaseYear = _year;
	phoneNumber = rand() % 899999 + 100000;
}

