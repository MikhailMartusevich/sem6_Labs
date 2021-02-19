#include "Product.h"

Product::Product(const char* _name, int _count, float _price) {
	name = _name;
	count = _count;
	price = _price;
}

void Product::Print() {
	std::cout << "Product name: " << name << std::endl;
	std::cout << "Product count: " << count << std::endl;
	std::cout << "Product price: " << price << std::endl;
}

bool Product::operator==(const Product& b) {
		if (this->name == "NULL" || b.name == "NULL") // if item is empty
			throw ("Invalid item in =="); // throw exception

		if (this->name == b.name && this->count == b.count && this->price == b.price)
			return true;
		else return false;
}

bool Product::operator!=(const Product& b) {
	return !(*this == b);
}

void Product::Input(const char* _name, int _count, float _price) {
	name = _name;
	count = _count;
	price = _price;
}
