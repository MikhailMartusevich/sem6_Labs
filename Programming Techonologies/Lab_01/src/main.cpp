#include <iostream>
#include "floatpoint.h"

int main() {

	// TEST

	float first_float = 1.5;
	float second_float = 0.5;

	floatPoint a = floatPoint(1, 5);
	floatPoint b = floatPoint(4, -5);

	std::cout << a / b;
	

	/*std::cout << "\t\t\t\t\tTEST\n\n";
	std::cout << "\t\tStandart float type\t\tCustom float type\n\n";
	std::cout << "1.5 / 0.5\t\t" << first_float / second_float << "\t\t\t\t" << my_float1 / my_float2 << "\n\n";

	first_float = 3.0;
	second_float = 0.3;
	
	floatPoint my_float3 = floatPoint(3, 0);
	floatPoint my_float4 = floatPoint(0, 3);
	
	std::cout << "3.0 / 0.3\t\t" << first_float / second_float << "\t\t\t\t" << my_float3 / my_float4 << "\n\n";

	first_float = 2.5;
	second_float = 1.1;

	floatPoint my_float5 = floatPoint(2, 5);
	floatPoint my_float6 = floatPoint(1, 1);

	std::cout << "2.5 / 1.1\t\t" << first_float / second_float << "\t\t\t\t" << my_float5 / my_float6 << "\n\n";

	first_float = 0.1;
	second_float = 3.5;

	floatPoint my_float7 = floatPoint(0, 1);
	floatPoint my_float8 = floatPoint(3, 5);
	
	std::cout << "0.1 / 3.5\t\t" << first_float / second_float << "\t\t\t" << my_float7 / my_float8 << "\n\n";*/

	return 0;
}
