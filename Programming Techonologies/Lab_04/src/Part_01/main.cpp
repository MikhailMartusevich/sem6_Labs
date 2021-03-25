#include <iostream>
#include <fstream>
#include <vector>
#include "binfStream.h"
#include "errorHandler.h"

void Run(const char* file_name, int count);

int main() {
	try {

		Run("numbers.dat", 15);

	}
	catch (errorHandler& exp) {
		std::cout << "Error: " << exp.print();
	}
	
	return 0;
}

void Run(const char* file_name, int count) {
	srand(time(NULL));
	std::vector<int> numbers;
	bin_outstream bin_out(file_name);
	if (!bin_out.is_open())
		throw errorHandler(errors::input_error);
	
	int temp = 0;

	for (int i = 0; i < count; i++) {
		temp = rand() % 100 - 50;
		bin_out << temp;
	}
	bin_out.seekp(0, std::ios::beg);
	bin_out.close();

	bin_instream bin_in(file_name);
	if (!bin_in)
		throw errorHandler(errors::output_error);

	std::cout << "Original file:\t";
	while (bin_in >> temp) {
		std::cout << temp << " ";
		if (temp % 2 == 0)
			numbers.push_back(0);
		else
			numbers.push_back(temp);
	}
	bin_in.seekg(0, std::ios::beg);
	bin_in.close();

	bin_out.open(file_name);
	if (!bin_out)
		throw errorHandler(errors::input_error);

	for (int i = 0; i < numbers.size(); i++) {
		bin_out << numbers[i];
	}
	bin_out.seekp(0, std::ios::beg);
	bin_out.close();

	bin_in.open(file_name);
	if (!bin_in)
		throw errorHandler(errors::output_error);
	int temp2 = 0;
	std::cout << "\nFinal file:\t";
	while (bin_in >> temp2) {
		std::cout << temp2 << " ";
	}
	bin_in.seekg(0, std::ios::beg);
	bin_in.close();
}
