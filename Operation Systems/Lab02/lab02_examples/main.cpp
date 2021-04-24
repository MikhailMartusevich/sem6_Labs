#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <iostream>
#include <unistd.h>
	

int A[100];
struct my_mem {
	int sum;
} *mem_sum;


int main () {
	
	int shmid = shmget(IPC_PRIVATE, 2, IPC_CREAT | 0666);

	if (shmid < 0) {
		std::cout << "Error" << std::endl;
		return 1;
	}

	mem_sum = (my_mem*)shmat(shmid, NULL, 0);

	A[2] = 5;
	A[56] = 90;
	A[4] = 6;
	
	int pid, sum = 0;
	
	pid = fork();
	
	if (pid == 0) {
		for (int i = 0; i < 50; i++)
			sum += A[i];
		mem_sum->sum = sum;
	}
	
	if (pid != 0) {
		for (int i = 50; i < 100; i++)
			sum += A[i];
		wait(0);
		std::cout << "Result = " << sum + mem_sum->sum << std::endl;
	}
	
	return 0;
}
