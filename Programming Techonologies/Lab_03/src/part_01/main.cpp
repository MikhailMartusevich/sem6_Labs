#include <iostream>
#include <fstream>
#include <string>
#include "errorHandler.h"

void Run(const char* file_name);

int main() {

	try {
		std::cout << "Ahh shit, here we go again..." << std::endl;
		Run("f.txt");
		std::cout << "Files complete" << std::endl;
	}
	catch (errorHandler &exp) {
		std::cerr << "Error: " << exp.print();
		exit(1);
	}
	return 0;
}

void Run(const char* file_name) {
	std::ifstream in_file;
	std::ofstream out_file;

	std::string g_file_str;
	std::string h_file_str;

	char sym;

	in_file.open(file_name, std::ios::in);

	if (!in_file.is_open())
		throw errorHandler(errors::input_error);

	while (!in_file.fail()) {
		if (in_file.good()) {
			in_file.get(sym);
			if (std::isdigit(static_cast<unsigned char>(sym))) {
				if ((sym - '0') % 2 == 0 && (sym - '0') % 4 == 0 && (sym - '0') % 6 != 0) {
					g_file_str.push_back(sym);
				}
				else
					h_file_str.push_back(sym);
			}
			else if(std::isalpha(static_cast<unsigned char>(sym)))
				throw errorHandler(errors::invalid_symbol);
		}
		else
			throw errorHandler(errors::read_failure);
	}
	in_file.close();

	out_file.open("g.txt", std::ios::out | std::ios::trunc);
	if (!out_file.is_open())
		throw errorHandler(errors::output_error);

	for (int i = 0; i < g_file_str.length(); i++) {
		out_file << g_file_str[i] << " ";
	}
	out_file.close();

	out_file.open("h.txt", std::ios::out | std::ios::trunc);
	if (!out_file.is_open())
		throw errorHandler(errors::output_error);

	for (int i = 0; i < h_file_str.length(); i++) {
		out_file << h_file_str[i] << " ";
	}
	out_file.close();

}