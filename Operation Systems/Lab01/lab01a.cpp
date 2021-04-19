#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
const int N = 3;
const float M = 1;



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


	int proc_count = (N / M <= 1) ? 1 : (N / M);						// all processes

	int childs_count = proc_count - 1;							// childs

	int elem_count = (childs_count == 0) ? 0 : (N / childs_count);			// elements per child

	int parent_elem_count = (childs_count == 0) ? N : (N - elem_count * childs_count);	// elements for parent

	static int k_index; //child coefficent

	std::cout << "Total proc count: " << proc_count << std::endl;	
	std::cout << "Childs count: " << childs_count << std::endl;
	std::cout << "Childs elems count: " << elem_count << std::endl;
	std::cout << "Parent elems count: " << parent_elem_count << std::endl;

	if (childs_count > 0) {
		for (int i = 0; i < childs_count; i++) {
			if (fork() == 0) {
				std::cout << "Opened child with pid: " << getpid() << std::endl;
				int r;
				if (i > 0)
					read(fd[0], &r, sizeof(r));
				else 
					r = 0;
				for (int i = 0; i < elem_count; i++) {
					r += vectorA[i + k_index] * vectorB[i + k_index];
				}
				std::cout << "Child result: " << r << std::endl;
				std::cout << "Static index: " << k_index << std::endl;
				write(fd[1],&r, sizeof(r));
				exit(0);
			}
			
			k_index += elem_count;
		}
	}

	for (int i = 0; i < childs_count; i++) 
		wait(0);	
	
	if (childs_count > 0)
		read(fd[0], &result, sizeof(result));

	for (int i = 0; i < parent_elem_count; i++) {
		result += vectorA[N - 1 - i] * vectorB[N - 1 - i];
	}
	
	std::cout << "Result of scalar multiply: " << result << std::endl;

	close(fd[0]);
	close(fd[1]);
	
	return 0;
}
