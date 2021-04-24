#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sched.h>

#define NUMSTACK 5000

int A[100];
int SUM = 0;
char stack[10][NUMSTACK];

int func(void *param) {
	int i, sum = 0;
	
	int p = *(int*)param;
	p = p*10;
	for (i=p; i < p + 10; i++) {
		if (A[i] % 2 == 0)
			sum += A[i];
	}
	SUM += sum;
	return 1;
}

int main() {

	for (int i = 0; i < 100; i++)
		if (i % 2  == 0) 
			A[i] = 1;
		else 
			A[i] = 2;
	
	int param[10];
	
	for (int i = 0; i < 9; i++) {
		param[i] = i;
		char *tostack = stack[i];
		clone(func, (void*)(tostack + NUMSTACK - 1), CLONE_VM, (void*)(param+i));
	}
	
	param[9] = 9;
	char *tostack = stack[9];
	
	clone(func, (void*)(tostack+NUMSTACK-1), CLONE_VM | CLONE_VFORK, (void*)(param+9));
	sleep(1);
	
	std::cout << "Result: " << SUM << std::endl;
	

	return 1;

}
