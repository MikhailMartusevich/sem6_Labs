#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <errno.h>
#include <iostream>
#include <ctime>

const int n = 4;

int main () {
	srand(time(0));
	int* array;
	int shmid;
	int new_ = 1;
	char pathname[] = "/home/linux/Desktop/test";
	key_t key;

	key = ftok(pathname, 0);
	if (key == -1) {
		std::cout << "Can't generate key" << std::endl;
	}

	if ((shmid = shmget(key, sizeof(int) * n * n, 0666 | IPC_CREAT | IPC_EXCL)) < 0) {
		if (errno != EEXIST) {
			std::cout << "Can't create shared memory" << std::endl;
		} else {
			if ((shmid = shmget(key, sizeof(int) * n * n, 0)) < 0) {
				std::cout << "Can't find shared memory" << std::endl;
			}
			new_ = 0;
		}		
	}
	
	if ((array = (int*)shmat(shmid, NULL, 0)) == (int*)(-1)) {
		std::cout << "Can't attach shared memory" << std::endl;
	}
	
	if (new_ == 1) {
		std::cout << "Enter array values: " << std::endl;
		for(int i = 0; i < n*n; i++) {
			std::cin >> array[i];
		}
	}

	std::cout << "Origin array" << std::endl;
	for (int i = 0; i < n*n; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << "\n";
	
	if (shmdt(array) < 0) {
		std::cout << "Can't detach shared memory" << std::endl;
	}
	
	return 0;
}
