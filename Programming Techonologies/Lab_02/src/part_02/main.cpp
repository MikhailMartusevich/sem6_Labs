#include <iostream>
#include "List.h"
#include "Product.h"

int main() {
	try {
		Product a = Product("Milk", 2, 2.4);
		Product b = Product("Water", 3, 0.99);
		Product c = Product("Cheese", 5, 1.5);

		List<Product> test1;
		test1.push_back(a);
		test1.push_back(a);
		test1.push_back(a);

		List<Product> test2;
		test2.push_back(a);
		test2.push_back(a);
		test2.push_back(b);

		List<int> test3;
		test3.push_back(1);
		test3.push_back(2);
		test3.push_back(3);

		List<int> test4;
		test4.push_back(1);
		test4.push_back(2);
		test4.push_back(3);
		
		List<float> test5;
		test5.push_back(5.4);
		test5.push_back(2.1);
		test5.push_back(7.8);

		List<float> test6;
		test6.push_back(1.2);
		test6.push_back(5.1);
		test6.push_back(8.1);

		std::cout << "\t\t\t TEST\n" << std::endl;

		/*bool result = test3 == test4;
		std::cout << "\nList<int>{1, 2, 3} == List<int>{1, 2, 3}: \t\t\t\t" << result << std::endl;

		result = test5 == test6;
		std::cout << "\nList<float>{5.4, 2.1, 7.8} == List<float>{1.2, 5.1, 8.1}: \t\t" << result << std::endl;

		result = test1 == test2;
		std::cout << "\nList<Product>{Milk, Milk, Milk} == List<Product>{Milk, Milk, Water}: \t" << result << std::endl;*/

		/*std::cout << "Original List<int>: " << test3 << std::endl;
		std::cout << "Original List<float>: " << test5 << std::endl;
		std::cout << "Original List<Product>: " << test1 << std::endl;

		std::cout << "\n\n\t\t\tlist + item\n" << std::endl;

		test3 + 229;
		test5 + 2.14;
		test1 + c;

		std::cout << "List<int>: " << test3 << std::endl;
		std::cout << "List<float>: " << test5 << std::endl;
		std::cout << "List<Product>: " << test1 << std::endl;

		std::cout << "\n\n\t\t\t--list, --list\n" << std::endl;

		--test3; --test3;
		--test5; --test5;
		--test1; --test1;

		std::cout << "List<int>: " << test3 << std::endl;
		std::cout << "List<float>: " << test5 << std::endl;
		std::cout << "List<Product>: " << test1 << std::endl;*/

		Product sugar = Product("Sugar", 1, 15.3);
		Product empty = Product();

		List<Product> test10;
		test10.push_back(sugar);

		List<Product> test11;

		--test10; --test10;
		
		std::cout << test10;
		
	}
	catch (const char* error) {
		std::cout << "Error: " << error << std::endl;
		exit(-100500);
	}
	return 0;
}