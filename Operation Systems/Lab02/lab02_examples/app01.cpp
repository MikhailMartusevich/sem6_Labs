#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <errno.h>
#include <iostream>

int main () {
	
	int* array;
	int shmid;
	int n = 1;
	char pathname[] = "/home/linux/Desktop/test";
	key_t key;

	key = ftok(pathname, 0);
	if (key == -1) {
		std::cout << "Can't generate key" << std::endl;
	}

	if ((shmid = shmget(key, sizeof(int) * 3, 0666 | IPC_CREAT | IPC_EXCL)) < 0) {
		if (errno != EEXIST) {
			std::cout << "Can't create shared memory" << std::endl;
		} else {
			if ((shmid = shmget(key, sizeof(int) * 3, 0)) < 0) {
				std::cout << "Can't find shared memory" << std::endl;
			}
			n = 0;
		}		
	}
	
	if ((array = (int*)shmat(shmid, NULL, 0)) == (int*)(-1)) {
		std::cout << "Can't attach shared memory" << std::endl;
	}

	if (n == 1) {
		array[0] = 1;
		array[1] = 0;
		array[2] = 1;
	} else {
		array[0] += 1;
		array[2] += 1;
	}

	std::cout << "App 01 was spawn " << array[0] 
		<< " times, App 02 - " << array[1] << "times, total" << array[2] << " times" <<std::endl;
	
	if (shmdt(array) < 0) {
		std::cout << "Can't detach shared memory" << std::endl;
	}
	
	return 0;
}
