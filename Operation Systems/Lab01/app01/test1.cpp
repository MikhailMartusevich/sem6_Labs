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
	char s[15];
	int fd;
	mkfifo("/home/linux/Desktop/mypipe", S_IFIFO | 0666);
	fd = open("/home/linux/Desktop/mypipe", O_RDONLY);

	read(fd, &s, 15);
	std::cout << "Read: " << s << std::endl;
	
	close(fd);
	unlink("/home/linux/Desktop/mypipe");

 	return 0;
}
