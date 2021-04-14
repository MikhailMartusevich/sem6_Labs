#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
const int N = 3;
const float M = 2;



int main() {

	int result = 0; // result of scalar multiply
	int fd[2];
	if (pipe(fd) < 0) {
		std::cout << "Can't create pipe" << std::endl;
		return 1;
	}
	
	int vectorA[N];
	int vectorB[N];

	std::cout << "Enter first vector:\n";
	for (int i = 0; i < N; i++)
		std::cin >> vectorA[i];

	std::cout << "Enter second vector:\n";
	for (int i = 0; i < N; i++)
		std::cin >> vectorB[i];


	int proc_count = (N / M == 0) ? 1 : (N / M);						// all processes

	int childs_count = proc_count - 1;							// childs

	int elem_count = (childs_count == 0) ? N : (N / childs_count);			// elements per child

	int parent_elem_count = (childs_count == 0) ? N : (N - elem_count * childs_count);	// elements for parent
	

	if (childs_count > 0) {
		for (static int i = 0; i < childs_count; i++) {
			if (fork() == 0) {
				int r = 0;
				for (static int i = 0; i < N - parent_elem_count; i++) {
					r += vectorA[i] * vectorB[i];
				}
				write(fd[1],&r, sizeof(r));
				exit(0);
			}
		}
		wait(0);
	}
	if (childs_count > 0)
		read(fd[0], &result, sizeof(result));

	for (int i = 0; i < parent_elem_count; i++) {
		result += vectorA[N - 1 - i] * vectorB[N - 1 - i];
	}
	
	std::cout << "Result of scalar multiply: " << result;

	close(fd[0]);
	close(fd[1]);
	
	return 0;
}
