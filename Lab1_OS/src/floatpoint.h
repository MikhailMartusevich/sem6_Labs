#ifndef FLOATPOINT_H
#define FLOATPOINT_H

#include <iostream>

class floatPoint {
public:
	floatPoint();
	floatPoint(int t_left, int t_right);
	~floatPoint();


	void operator=(const float val);
	float operator/(const floatPoint& val);
	float operator/(const double val);
	float operator/(const int val);
	friend std::ostream& operator<<(std::ostream& msg, const floatPoint& val) {
		try {
			if (val.size < 2)
				throw ("Can't print out free store");

			msg << val.value[0] << '.' << val.value[1];
			return msg;
		}
		catch (const char* exp) {
			std::cerr << "<E> Catch exception in <<: " << exp << std::endl;
			exit(-229);
		}	
	}

private:
	size_t size{ 0 };
	int* value;

	int checkFractional(int right_value);
};

#endif // !FLOATPOINT_H

