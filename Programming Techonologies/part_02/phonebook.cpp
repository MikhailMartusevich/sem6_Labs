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
	return out;
}

phoneBook::phoneBook() {
	std::string lastName = "";
	std::string street = "";
	int houseNumber = 0;
	int releaseYear = 0;
}

phoneBook::phoneBook(const char* _lastname, const char* _street, int _number, int _year) {
	lastName = _lastname;
	street = _street;
	houseNumber = _number;
	releaseYear = _year;
	phoneNumber = std::to_string(rand() % 899999 + 100000);
}
