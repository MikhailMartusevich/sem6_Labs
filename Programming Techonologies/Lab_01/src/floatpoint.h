#ifndef FLOATPOINT_H
#define FLOATPOINT_H

#include <iostream>

class floatPoint {
public:
	floatPoint();								// default constructor
	floatPoint(int t_left, int t_right);		// param constructor
	~floatPoint();

	// different types of division
	float	operator/(const floatPoint& val);	// custom float / custom float
	float	operator/(const double val);		// custom float / c++ float
	float	operator/(const int val);			// custom float / c++ integer

	// << operator
	friend std::ostream& operator<<(std::ostream& msg, const floatPoint& val) {
		try {
			if (val.size < 2)							// if array is empty
				throw ("Can't print out free store");	// throw exception

			msg << val.value[0] << '.' << val.value[1];
			return msg;
		}
		catch (const char* exp) {
			std::cerr << "<E> Catch exception in <<: " << exp << std::endl;
			exit(-229);
		}	
	}

private:
	size_t size{ 0 }; // array size
	int* value; 

	int checkFractional(int right_value); // valid fractional part function
};

#endif // !FLOATPOINT_H

