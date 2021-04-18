#include <iostream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

int main() {
	
	char str[10];
	int fd[2];	
	std::cout << "Enter string: " << std::endl;
	std::cin >> str;
	
	mkfifo("/home/linux/Desktop/pipe1", S_IFIFO | 0666);
	mkfifo("/home/linux/Desktop/pipe2", S_IFIFO | 0666);
	

	for (int i = 0; i < 10; i++) {

		fd[1] = open("/home/linux/Desktop/pipe2", O_WRONLY | O_CREAT, O_TRUNC);	
		write(fd[1], &str, 10);
		close(fd[1]);
		
		fd[0] = open("/home/linux/Desktop/pipe1", O_RDONLY | O_CREAT, O_TRUNC);
		read(fd[0], &str, 10);
		close(fd[0]);

		std::cout << "Recieved string from app02: " << std::endl;
		std::cout << str << std::endl;	
	}
	unlink("/home/linux/Desktop/pipe1");
	unlink("/home/linux/Desktop/pipe2");
	return 0;
}
