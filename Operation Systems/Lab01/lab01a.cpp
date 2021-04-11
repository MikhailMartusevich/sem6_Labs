#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>

void scalarSum(int _n, int _m);

int main() {
	
	int n, m = 0;

	std::cin >> n >> m;

	scalarSum(n, m);
	
	return 0;
}

void scalarSum(int _n, int _m) {
	int vectorA[_n];
	int vectorB[_n];

	
}
