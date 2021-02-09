#include "floatpoint.h"
#include "string"

floatPoint::floatPoint() { // default constructor
	size = 0; 
	value = new int[size]; // initialization of empty array
}

floatPoint::floatPoint(int t_left, int t_right) { // parameterized constructor
	try {
		size = 2;
		value = new int[size];					// initialization of array
		value[0] = t_left;						// integer part of floatpoint number
		value[1] = checkFractional(t_right);	// fractional part of floatpoint number, if valid, return number, else throw exception
	}
	catch (const std::exception& exp) {			// catching exception from checkFractional()
		std::cerr << "<E> Catch exception in constructor: " << exp.what();
		exit(-228);
	}
}

floatPoint::~floatPoint() {
	delete [] value;	// clear value memory
	value = NULL;		// value == null pointer
}

/* Division operator "/"
*	
*  Divide two "floatPoint" class variables
*	
*  @in param - "floatPoint" class variable
*  @out - returns the result of division - "floatPoint" / "floatPoint" == float
*/
float floatPoint::operator/(const floatPoint& val) {
	try {
		if (val.size == NULL || this->size == NULL)					// if one of variables is empty
			throw ("operations with free store can't be done");		// throw exception of empty memory

		if (val.value[0] == 0 && val.value[1] == 0)					// if quotinent is 0
			throw ("division by zero");								// throw exception of division by zero
		
		float this_value = this->value[0] + (float)this->value[1] / 10 * std::to_string(this->value[1]).size();		// convert to float type

		float that_value = val.value[0] + (float)val.value[1] / 10 * std::to_string(val.value[1]).size();			// convert to float type

		return this_value / that_value; // return result of division
	}
	catch (const char* exp) { // catch exceptions
		std::cout << "<E> Catch exception in division: " << exp;
		exit(-231);
	}
}


/* Division operator "/"
*
*  Divide "floatPoint" class and float type variables
*
*  @in param - float or double type variable
*  @out - returns the result of division - "floatPoint" / float == float 
*/
float floatPoint::operator/(const double val) {
	try {
		if (this->size == NULL)										// if variable is empty
			throw ("operations with free store can't be done");		// throw exception of empty memory

		if (val == 0)												// if quotinent is 0
			throw ("division by zero");								// throw exception of division by zero

		float this_value = this->value[0] + (float)this->value[1] / 10 * std::to_string(this->value[1]).size(); // convert to float type
		
		return this_value / val; // return result of division
	}
	catch (const char* exp) { // catch exceptions 
		std::cout << "<E> Catch exception in division: " << exp;
		exit(-231);
	}
}


/* Division operator "/"
*
*  Divide "floatPoint" class and integer type variables
*
*  @in param - float or double type variable
*  @out - returns the result of division - "floatPoint" / integer == float
*/
float floatPoint::operator/(const int val) {
	try {
		if (this->size == NULL)										// if variable is empty
			throw ("operations with free store can't be done");		// throw exception of empty memory

		if (val == 0)												// if quotinent is 0
			throw ("division by zero");								// throw exception of division by zero

		float this_value = this->value[0] + (float)this->value[1] / 10 * std::to_string(this->value[1]).size(); // convert to float type
		
		return this_value / (float)val; // return result
	}
	catch (const char* exp) { // catch exceptions
		std::cout << "<E> Catch exception in division: " << exp;
		exit(-231);
	}
}


/* int checkFunctional(int)
*
*  Check the validity of fractional part of number
*
*  @in param - integer type variable "value[1]"
*  @out - returns integer type number if it's valid
*		  else throwing an exception of invalid number
*/
int floatPoint::checkFractional(int right_value) {
	try {
		if (right_value < 0)	// if fractional part < 0
			throw right_value;	// throw this value 
		else return right_value; // else return this value 
	} 
	catch (int err_val) { // catch this value 
		std::cerr << "Fractional part of float number must be positive instead " << err_val << std::endl; // print this value on screen
		throw std::invalid_argument("Invalid fractional part\n"); // throw exception of invalid argument
	}
}
