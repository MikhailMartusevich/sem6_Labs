#include <iostream>
#include "List.h"
#include "Product.h"

int main() {
	try {
		Product a = Product("Milk", 2, 2.4);
		Product b = Product("Water", 3, 0.99);

		List<Product> test1;
		test1.push_back(a);
		test1.push_back(a);
		test1.push_back(a);

		List<Product> test2;
		test2.push_back(a);
		test2.push_back(a);
		test2.push_back(b);

		test1 + b;

		std::cout << test1 << std::endl;

		--test1;

		std::cout << test1 << std::endl;
	}
	catch (const char* error) {
		std::cout << "Error: " << error << std::endl;
		exit(-100500);
	}
	return 0;
}