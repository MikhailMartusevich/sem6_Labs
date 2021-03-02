#include <iostream>
#include <vector>
#include "phoneBook.h"

int main() {
	std::vector<phoneBook> v;
	phoneBook first = phoneBook("Ivanov", "Nikitina", 4, 2005);
	phoneBook second = phoneBook("Petrov", "Nikitina", 8, 2003);
	phoneBook third = phoneBook("Borisov", "Nikitina", 1, 2009);
	phoneBook four = phoneBook("Glupov", "Nikitina", 1, 2003);

	v.push_back(first);
	v.push_back(second);
	v.push_back(third);
	v.push_back(four);

	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i].phoneNumber << "\n";
	}

	return 0;
}