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

	char resstr[10];
	std::vector<char> symbols;
	char sym;
	int fd[2];	
	
	std::cout << "Waiting string from app01." << std::endl;

	for (int i = 0; i < 10; i++) {
		fd[0] = open("/home/linux/Desktop/pipe2", O_RDONLY);
		read(fd[0], &resstr, 10);
		close(fd[0]);

		std::cout << "Recieved string from app01: " << std::endl;
		std::cout << resstr << std::endl;
		
		int count = 0;
		int max_count = -1;
		char max;
		bool copy = false;

		for (int i = 0; i < 10; i++) {
			copy = false;
			for (int m = 0; m < symbols.size(); m++) {
				if (symbols[m] == resstr[i]) 
					copy = true;
			}

			if (!copy) {
				count = 0;
				for (int j = i; j < 10; j++) {
					if (resstr[j] == resstr[i])
						count++;
				}
				if (count > max_count) {
					max_count = count;
					max = resstr[i];
				}
			}

		}

		std::cout << "\nmax symbol: " << max << std::endl;

		bool sym_copy = false;
		std::cout << "Enter symbol: ";
		std::cin >> sym;
		for (int i = 0; i < symbols.size(); i++) {
			if (symbols[i] == sym)
				sym_copy = true;
		}

		if (!sym_copy) {
			symbols.push_back(sym);

			for (int i = 0; i < 10; i++) {
				if (resstr[i] == max)
					resstr[i] = sym;
			}
		} 
		

		std::cout << "\n result string: " << resstr << std::endl;
	
		fd[1] = open("/home/linux/Desktop/pipe1", O_WRONLY);
		write(fd[1], &resstr, 10); // app#2 returns result string to app#1	
		close(fd[1]);
	}
	
	
	unlink("/home/linux/Desktop/pipe1");
	unlink("/home/linux/Desktop/pipe2");
	return 0;
}
