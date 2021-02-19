#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>

class Product {
private:
	const char* name;
	int count;
	float price;
public:
	Product() : name("NULL"), count(0), price(0.0) {}; // default constructor
	Product(const char* _name, int _count, float _price); // param constructor
	~Product() = default;

	void Print(); // print item 
	void Input(const char* _name, int _count, float _price); // input item

	friend std::ostream& operator<< (std::ostream& msg, const Product& item) {
			if (item.name == "NULL")
				throw ("Invalid item in <<");
			msg << "\nproduct name: " << item.name << std::endl;
			msg << "product count: " << item.count << std::endl;
			msg << "product price: " << item.price << std::endl;
	}

	bool operator==(const Product& b);
	bool operator!=(const Product& b);

};

#endif // !PRODUCT_H
