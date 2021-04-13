#include <iostream>
const int N = 3;
const float M = 1;



int main() {

	int result = 0; // result of scalar multiply
	
	int vectorA[N];
	int vectorB[N];

	std::cout << "Enter first vector:\n";
	for (int i = 0; i < N; i++)
		std::cin >> vectorA[i];

	std::cout << "Enter second vector:\n";
	for (int i = 0; i < N; i++)
		std::cin >> vectorB[i];


	int proc_count = (N / M == 0) ? 1 : (N / M);										// all processes

	int childs_count = proc_count - 1;													// childs

	int elem_count = (childs_count == 0) ? N : (N / childs_count);						// elements per child

	int parent_elem_count = (childs_count == 0) ? N : (N - elem_count * childs_count);	// elements for parent

	for (int i = 0; i < parent_elem_count; i++) {
		result += vectorA[N - 1 - i] * vectorB[N - 1 - i];
	}

	for (int i = 0; i < childs_count; i++) {
		for (static int i = 0; i < N - parent_elem_count; i++) {
			result += vectorA[i] * vectorB[i];
		}
	}
	
	std::cout << "Result of scalar multiply: " << result;


	return 0;
}
