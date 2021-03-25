#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "phoneBook.h"
#include "errorHandler.h"

void writeToFile(std::string file_path, std::vector<phoneBook> v1);
void readFile(std::string file_path);
void FindNumber(std::string file_path);
void SinceYear(std::string file_path);
void NumbersOnStreet(std::string file_path);


int main() {
	try {
		std::string path = "structures.dat";

		phoneBook a("Petrov", "Gorkogo", 25, 2003);
		phoneBook b("Sidorov", "Lenina", 11, 2013);
		phoneBook c("Ivanov", "Mira", 4, 2011);
		phoneBook d("Smirnov", "Gorkogo", 25, 2007);
		phoneBook e;

		std::vector<phoneBook> v1{ a,b,c,d };
		std::cin >> e;
		v1.push_back(e);

		writeToFile(path, v1);
		readFile(path);

		//FindNumber(path);
		//SinceYear(path);
		//NumbersOnStreet(path);
		
		return 0;
	}
	catch (errorHandler &exp) {
		std::cout << "Error: " << exp.print();
		exit(1);
	}
}

void writeToFile(std::string file_path, std::vector<phoneBook> v1) {
	std::ofstream fout;
	fout.open(file_path, std::ofstream::out | std::ofstream::binary);
	if (!fout.is_open())
		throw errorHandler(errors::output_err);

	for (int i = 0; i < v1.size(); i++) {
		fout.write((char*)&v1[i], sizeof(phoneBook));
	}
	fout.close();
}

void readFile(std::string file_path) {
	std::ifstream fin;
	fin.open(file_path, std::ifstream::in | std::ofstream::binary);
	if (!fin.is_open())
		throw errorHandler(errors::input_err);

	std::vector<phoneBook> v1;
	phoneBook temp;
	while (fin.read((char*)&temp, sizeof(phoneBook))) {
		temp.Print();
	}
	fin.close();
}

void FindNumber(std::string file_path) {
	std::ifstream fin;
	fin.open(file_path, std::ifstream::in);
	if (!fin.is_open())
		throw errorHandler(errors::input_err);

	std::vector<phoneBook> v1;
	phoneBook temp;
	while (fin.read((char*)&temp, sizeof(phoneBook))) {
		v1.push_back(temp);
	}
	fin.close();

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

void SinceYear(std::string file_path) {
	std::ifstream fin;
	fin.open(file_path, std::ifstream::in | std::ofstream::binary);
	if (!fin.is_open())
		throw errorHandler(errors::input_err);

	std::vector<phoneBook> v1;
	phoneBook temp;
	while (fin.read((char*)&temp, sizeof(phoneBook))) {
		v1.push_back(temp);
	}
	fin.close();

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

void NumbersOnStreet(std::string file_path) {
	std::ifstream fin;
	fin.open(file_path, std::ifstream::in | std::ofstream::binary);
	if (!fin.is_open())
		throw errorHandler(errors::input_err);

	std::vector<phoneBook> v1;
	phoneBook temp;
	while (fin.read((char*)&temp, sizeof(phoneBook))) {
		v1.push_back(temp);
	}
	fin.close();

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
