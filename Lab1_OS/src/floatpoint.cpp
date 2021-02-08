#include "floatpoint.h"
#include "string"

floatPoint::floatPoint() {
	size = 0;
	value = new int[size];
}

floatPoint::floatPoint(int t_left, int t_right) {
	try {
		size = 2;
		value = new int[size];
		value[0] = t_left;
		value[1] = checkFractional(t_right);
	}
	catch (const std::exception& exp) {
		std::cerr << "<E> Catch exception in constructor: " << exp.what();
		exit(-228);
	}
}

floatPoint::~floatPoint() {
	delete [] value;
	value = NULL;
}

void floatPoint::operator=(const float val) {
	size = 2;
	int* new_value = new int[size];
	try {
		new_value[0] = (int)val;
		new_value[1] = checkFractional((round(val*1000000)/1000000 - (int)val) * 1000000);
		delete[] value;
		value = new_value;
	}
	catch (const std::exception& exp) {
		std::cerr << "<E> Catch error in assignment: " << exp.what() << std::endl;
		exit(-230);
	}
}

float floatPoint::operator/(const floatPoint& val) {
	try {
		if (val.size == NULL || this->size == NULL)
			throw ("operations with free store can't be done");
		if (val.value[0] == 0 && val.value[1] == 0)
			throw ("division by zero");
		
		float this_value = this->value[0] + (float)this->value[1] / 10 * std::to_string(this->value[1]).size();

		float that_value = val.value[0] + val.value[1] / 10 * std::to_string(val.value[1]).size();

		return this_value / that_value;
	}
	catch (const char* exp) {
		std::cout << "<E> Catch exception in division: " << exp;
		exit(-231);
	}
}

float floatPoint::operator/(const double val) {
	try {
		if (this->size == NULL)
			throw ("operations with free store can't be done");
		if (val == NULL)
			throw ("division by zero");

		float this_value = this->value[0] + (float)this->value[1] / 10 * std::to_string(this->value[1]).size();
		
		return this_value / val;
	}
	catch (const char* exp) {
		std::cout << "<E> Catch exception in division: " << exp;
		exit(-231);
	}
}

float floatPoint::operator/(const int val) {
	try {
		if (this->size == NULL)
			throw ("operations with free store can't be done");
		if (val == 0)
			throw ("division by zero");

		float this_value = this->value[0] + (float)this->value[1] / 10 * std::to_string(this->value[1]).size();
		
		return this_value / (float)val;
	}
	catch (const char* exp) {
		std::cout << "<E> Catch exception in division: " << exp;
		exit(-231);
	}
}

int floatPoint::checkFractional(int right_value) {
	try {
		if (right_value < 0)
			throw right_value;
		else return right_value;
	} 
	catch (int err_val) {
		std::cerr << "Fractional part of float number must be positive instead " << err_val << std::endl;
		throw std::invalid_argument("Invalid fractional part\n");
	}
}
