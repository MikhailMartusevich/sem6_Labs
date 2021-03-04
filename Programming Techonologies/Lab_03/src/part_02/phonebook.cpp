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

	out << "User number: " << ph.phoneNumber;
	out << "\nUser last name: " << ph.lastName;
	out << "\nUser street: " << ph.street;
	out << "\nUser house number: " << ph.houseNumber;
	out << "\nRelease year of number: " << ph.releaseYear;
	return out;
}

phoneBook::phoneBook() {
	std::string lastName = "";
	std::string street = "";
	int houseNumber = 0;
	int releaseYear = 0;
	phoneNumber = std::to_string(rand() % 899999 + 100000);
}

phoneBook::phoneBook(const char* _lastname, const char* _street, int _number, int _year) {
	lastName = _lastname;
	street = _street;
	houseNumber = _number;
	releaseYear = _year;
	phoneNumber = std::to_string(rand() % 899999 + 100000);
}
